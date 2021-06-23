#include "../include/mysql_curd.h"
#include "../include/public.h"
Connection_sql::Connection_sql()
{
    //初始化数据库连接
    _conn = mysql_init(nullptr);


}

Connection_sql::~Connection_sql()
{
    //释放数据库连接资源
    if(_conn != nullptr)
    mysql_close(_conn);
}

bool Connection_sql::connectsql(std::string ip, unsigned short port, std::string user, std::string password,
                                std::string dbname)
{
    //连接数据库
    MYSQL *p = mysql_real_connect(_conn, ip.c_str(), user.c_str(),
                                password.c_str(), dbname.c_str(), port, nullptr, 0);
    return p != nullptr;
}

bool Connection_sql::update(std::string sql)
{
    //更新操作
    if(mysql_query(_conn, sql.c_str()))
    {
        LOG("更新失败：" + sql);
        return false;
    }
    return true;
}

MYSQL_RES* Connection_sql::query(std::string sql)
{
    //查询操作
    if(mysql_query(_conn, sql.c_str()))
    {
        //LOG("查询失败: " +  sql);
        return nullptr;
    }
    return mysql_use_result(_conn);
}
