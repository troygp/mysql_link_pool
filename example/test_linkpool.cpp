#include <iostream>
#include <mysql.h>
#include "public.h"
#include "connection_pool.h"
#include "mysql_curd.h"

int main()
{   
    clock_t begin = clock();
    // ConnectionPool *cp = ConnectionPool::getConnectionPool();
    // for(int i = 0; i < 10000; ++i){
    //     std::shared_ptr<Connection_sql> sp = cp->get_connect();
    //     char sql[1024] = {0};
    //     sprintf(sql, "insert into Name (name) values ('吴振星')");
    //     sp->update(sql);
    // }

    std::thread t1([](){
        ConnectionPool *cp = ConnectionPool::getConnectionPool();
        for(int i = 0; i < 2500; ++i){
            char sql[1024] = { 0 };
            sprintf(sql, "insert into Name (name) values ('guopeng')");
            std::shared_ptr<Connection_sql> sp = cp->get_connect();
            sp->update(sql);
    }
    });

    std::thread t2([](){
        ConnectionPool *cp = ConnectionPool::getConnectionPool();
        for(int i = 0; i < 2500; ++i){
            char sql[1024] = { 0 };
            sprintf(sql, "insert into Name (name) values ('guopeng')");
            std::shared_ptr<Connection_sql> sp = cp->get_connect();
            sp->update(sql);
    }
    });

    std::thread t3([](){
        ConnectionPool *cp = ConnectionPool::getConnectionPool();
        for(int i = 0; i < 2500; ++i){
            char sql[1024] = { 0 };
            sprintf(sql, "insert into Name (name) values ('guopeng')");
            std::shared_ptr<Connection_sql> sp = cp->get_connect();
            sp->update(sql);
    }
    });

        std::thread t4([](){
        ConnectionPool *cp = ConnectionPool::getConnectionPool();
        for(int i = 0; i < 2500; ++i){
            char sql[1024] = { 0 };
            sprintf(sql, "insert into Name (name) values ('guopeng')");
            std::shared_ptr<Connection_sql> sp = cp->get_connect();
            sp->update(sql);
    }
    });

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    clock_t end = clock();
    std::cout << (double(end - begin))/1000 << "ms" << std::endl;
    LOG("结束");

    return 0;
}