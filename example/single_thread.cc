#include <iostream>
#include <mysql.h>
#include "public.h"
#include "connection_pool.h"
#include "mysql_curd.h"

int main()
{

    Connection_sql conn;
    conn.connectsql("localhost", 0, "root", "tly13956203250", "test");

    clock_t begin = clock();
    // for(int i = 0; i < 1000; ++i){
    //     Connection_sql conn;
    //     if(conn.connectsql("localhost", 0, "root", "tly13956203250", "test"))
    //     {
    //         //std::cout<< "connect successed " << std::endl;
    //     }
    //     else std::cout<< "connect failed" << std::endl;
    //     char sql[1024] = { 0 };
    //     sprintf(sql, "insert into Name (name) values ('guopeng')");
    //     conn.update(sql);
    // }

    std::thread t1([](){
        for(int i = 0; i < 2500; ++i){
            Connection_sql conn;
            if(conn.connectsql("localhost", 0, "root", "tly13956203250", "test"))
            {
                //std::cout<< "connect successed " << std::endl;
            }
            else std::cout<< "connect failed" << std::endl;
            char sql[1024] = { 0 };
            sprintf(sql, "insert into Name (name) values ('guopeng')");
            conn.update(sql);
    }
    });

    std::thread t2([](){
        for(int i = 0; i < 2500; ++i){
            Connection_sql conn;
            if(conn.connectsql("localhost", 0, "root", "tly13956203250", "test"))
            {
                //std::cout<< "connect successed " << std::endl;
            }
            else std::cout<< "connect failed" << std::endl;
            char sql[1024] = { 0 };
            sprintf(sql, "insert into Name (name) values ('guopeng')");
            conn.update(sql);
    }
    });

    std::thread t3([](){
        for(int i = 0; i < 2500; ++i){
            Connection_sql conn;
            if(conn.connectsql("localhost", 0, "root", "tly13956203250", "test"))
            {
                //std::cout<< "connect successed " << std::endl;
            }
            else std::cout<< "connect failed" << std::endl;
            char sql[1024] = { 0 };
            sprintf(sql, "insert into Name (name) values ('guopeng')");
            conn.update(sql);
    }
    });

    std::thread t4([](){
        for(int i = 0; i < 2500; ++i){
            Connection_sql conn;
            if(conn.connectsql("localhost", 0, "root", "tly13956203250", "test"))
            {
                //std::cout<< "connect successed " << std::endl;
            }
            else std::cout<< "connect failed" << std::endl;
            char sql[1024] = { 0 };
            sprintf(sql, "insert into Name (name) values ('guopeng')");
            conn.update(sql);
        }
    });

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    clock_t end = clock();
    std::cout << double((end - begin))/1000 << "ms" << std::endl;
    return 0;
}