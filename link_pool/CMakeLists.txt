project(linkpool)

include_directories(/usr/include/mysql)
add_library(lib1 
        src/connection_pool.cpp
        src/mysql_curd.cpp
)

add_library(sub::lib1 ALIAS lib1)

target_include_directories( lib1
    PUBLIC ${PROJECT_SOURCE_DIR}/include
)

