project(example)

# Create the executable
include_directories(/usr/include/mysql)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../../bin)
add_executable(${PROJECT_NAME} mytest.cpp)
target_link_libraries(${PROJECT_NAME}
    sub::lib1
    mysqlclient
)

add_executable(pool_multi_thread test_linkpool.cpp)
target_link_libraries(pool_multi_thread
    sub::lib1
    mysqlclient
    pthread
)