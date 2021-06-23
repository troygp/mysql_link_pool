cmake_minimum_required(VERSION 3.5)
project(link_test)

# 设置so库的生成路径
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

# 设置调试信息
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++11 -fPIC")

# 加载子目录
add_subdirectory(example)
add_subdirectory(link_pool)
