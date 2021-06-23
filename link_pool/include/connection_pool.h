#pragma once

#include <queue>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <thread>
#include <functional>


#include "mysql_curd.h"

class ConnectionPool
{
public:
    //获取连接池的对象实例
    static ConnectionPool* getConnectionPool();

    //给外部提供的接口，返回可用的空闲连接
    std::shared_ptr<Connection_sql> get_connect();

private:
    ConnectionPool();

    //加载配置文件
    bool load_configure();

    //释放空闲连接
    void scan_connection();
    
    //运行在独立的线程中，专门负责生产 新连接
    void produceConnectionTask();

    //扫描超过maxIdleTime时间的空闲连接， 进行多余的连接回收
    void scannerConnectionTask();


    std::string ip_;
    unsigned short port_;
    std::string user_;
    std::string password_;
    std::string dbname_;

    int init_size_;                 //连接池初始连接量
    int max_size_;                  //连接的最大连接量
    int max_freeTime;               //连接池的最大空闲时间
    int connection_timeout_;        //连接池获取连接的超时时间

    std::queue<Connection_sql*> _connectionQue;             // 存储mysql连接的队列
    std::mutex _queueMutex;                                 // 维护连接队列的线程安全互斥锁
    std::atomic_int _connectionCnt;                         // 记录连接所创建的connection连接的总数量
    std::condition_variable cv;                             // 设置条件变量，用于连接 生产线和 连接消费线程的通信


};


