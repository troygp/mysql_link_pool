#include <iostream>
#include <mysql.h>
#include "../link_pool/include/public.h"
#include "../link_pool/include/connection_pool.h"
#include "../link_pool/include/mysql_curd.h"

int main()
{
    Connection_sql conn;
    if(conn.connectsql("127.0.0.1", 0, "root", "tly13956203250", "test"))
    {
        std::cout<< "connect successed " << std::endl;
    }
    else std::cout<< "connect failed" << std::endl;
    char sql[1024] = { 0 };
    sprintf(sql, "insert into Name (name) values ('gggggg')");
    conn.update(sql);
    clock_t begin = clock();
}