#include "../include/connection_pool.h"
#include "../include/public.h"

#define TEMP_SIZE 1024

//线程安全的懒汉单例函数接口
ConnectionPool* ConnectionPool::getConnectionPool()
{
    //当程序运行到此时才会生成对象实例
    static ConnectionPool pool;
    //LOG("生成对象实例");
    return &pool;
}

//给外部提供的接口，返回可用的空闲连接
std::shared_ptr<Connection_sql> ConnectionPool::get_connect()
{   
    //LOG("获取空闲连接");
    std::unique_lock<std::mutex> lock(_queueMutex);
    while(_connectionQue.empty())
    {
        if(std::cv_status::timeout == cv.wait_for(lock, std::chrono::milliseconds(connection_timeout_)))
        {
            if(_connectionQue.empty())
            {
                LOG("get connection timeout ...");
                return nullptr;
            }
        }
    }

    //需要重新定义 shared_ptr 删除器
    std::shared_ptr<Connection_sql> ret(_connectionQue.front(), [&](Connection_sql *ptr){
    std::unique_lock<std::mutex> lock(_queueMutex);
    ptr->refreshAliveTime();   //刷新一下 开始空闲的起始时间
    _connectionQue.push(ptr);
});
    _connectionQue.pop();
    if(_connectionQue.empty())
    {
        //无连接可用，通知生产线程去生产
        cv.notify_all();
    }
    return ret;


}

ConnectionPool::ConnectionPool()
{
    //加载配置项
    if(!load_configure())
    {
        LOG("configure file error!");
        return;
    }

    
    //LOG("创建初始连接");

    //创建初始数量连接

    for(int i = 0; i < init_size_; i++)
    {
        Connection_sql *p = new Connection_sql();
        if(p->connectsql(ip_, port_, user_, password_, dbname_) == false)
        {
            //std::cout << "connect error !" << std::endl;
            LOG("connect fail");
        }
        //else{LOG("connect success");}
        p->refreshAliveTime();          //刷新 一下 开始空闲的起始时间
        _connectionQue.push(p);
        _connectionCnt ++;
    }

    //启动一个新线程，作为连接生产者
    std::thread conncet_producer(std::bind(&ConnectionPool::produceConnectionTask, this));
    conncet_producer.detach();

    //启动新线程扫描空闲连接，超过max freetime时间的空闲连接，进行连接回收
    std::thread scaner(std::bind(&ConnectionPool::scan_connection, this));
    scaner.detach();
}

//加载配置文件
bool ConnectionPool::load_configure()
{
    FILE *pf = fopen("../configure/mysql.conf", "r");
    if(pf == nullptr)
    {
        LOG("mysql.conf is not exist");
        return false;
    }

    while(!feof(pf))
    {
        char line[TEMP_SIZE] = {0};
        std::fgets(line, TEMP_SIZE, pf);
        std::string str = line;
        int index = str.find('=', 0);
        if(index == -1)
        {
            continue;
        }
        
        int endix = str.find('\n', index);
        std::string key = str.substr(0, index);
        std::string value = str.substr(index + 1, endix - index - 1);

        if(key == "ip")
        {
            ip_ = value;
            //LOG(ip_);
        }
        else if(key == "port")
        {
            port_ = atoi(value.c_str());
            //LOG(port_);
        }
        else if(key == "user")
        {
            user_ = value;
            //LOG(user_);
        }
        else if(key == "password")
        {
            password_ = value;
            //LOG(password_);
        }
        else if(key == "init_size")
        {
            init_size_ = atoi(value.c_str());
        }
        else if(key == "max_size")
        {
            max_size_ = atoi(value.c_str());
        }
        else if(key == "max_freeTime")
        {
            max_freeTime = atoi(value.c_str());
        }
        else if(key == "connect_timeout")
        {
            connection_timeout_ = atoi(value.c_str());
        }
        else if(key == "dbname")
        {
            dbname_ = value;
            //LOG(dbname_);
        }
    }
    return true;
}


//运行独立的线程，专门负责生产新的连接
void ConnectionPool::produceConnectionTask()
{
    for(;;)
    {
        std::unique_lock<std::mutex> lock(_queueMutex);
        while(!_connectionQue.empty())
        {
            cv.wait(lock);
        }

        //还没有到达最大值，可以创建
        if(_connectionCnt < max_size_)
        {
            Connection_sql *p = new Connection_sql();
            p->connectsql(ip_, port_, user_, password_, dbname_);
            p->refreshAliveTime();
            _connectionQue.push(p);
            _connectionCnt++;
        }

        //通知消费者线程 可以消费了
        cv.notify_all();
    }
}

//释放空闲连接
void ConnectionPool::scan_connection()
{
    for(;;)
    {
        //通过sleep模型定时效果
        std::this_thread::sleep_for(std::chrono::seconds(max_freeTime));

        //扫描队列，释放多余连接
        std::unique_lock<std::mutex> lock(_queueMutex);
        while(_connectionCnt > init_size_)
        {
            Connection_sql *p = _connectionQue.front();
            if(p->getAliveTime() > max_freeTime * 1000)
            {
                _connectionQue.pop();
                delete p;   //释放连接
                _connectionCnt--;
            }
        }
    }
}


