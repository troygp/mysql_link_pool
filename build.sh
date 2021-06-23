#!/bin/bash
# 以下是采用shell脚本 编译链接
#command g++ -c  mysql_curd.cc `mysql_config --cflags --libs`
#command g++ -c  connection_pool.cc `mysql_config --cflags --libs`
#command g++ -c  mytest.cc `mysql_config --cflags --libs`
#command g++ connection_pool.o mysql_curd.o mytest.o -o test $(mysql_config --cflags) $(mysql_config --libs) -lpthread
#command g++ connection_pool.o mysql_curd.o mytest.o -o test `mysql_config --cflags --libs` -lpthread
#rm connection_pool.o mysql_curd.o mytest.o
#./test

# 以下是采用shell脚本 执行make指令
command make && make clean