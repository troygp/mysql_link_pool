#pragma once
#include <mysql.h>
#include <string>
#include <ctime>

//实现MySQL数据库的操作
class Connection_sql{

public:
    //初始化
    Connection_sql();
    ~Connection_sql();

    //连接数据库
    bool connectsql(std::string ip,
                    unsigned short port,
                    std::string user,
                    std::string password,
                    std::string bdname);

    //更新数据库
    bool update(std::string sql);
    //查询操作
    MYSQL_RES * query(std::string sql);

    //刷新连接的起始的空闲时间点
    void refreshAliveTime(){
        _alivetime = clock();
    }

    //返回存活时间
    clock_t getAliveTime() const{
        return clock() - _alivetime;
    }

private:
    MYSQL* _conn;           //表示和MySQL的一条连接
    clock_t _alivetime;     //记录进入空闲状态后的起始存活时间
};