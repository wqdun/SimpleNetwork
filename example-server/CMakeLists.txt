cmake_minimum_required(VERSION 2.8)
project(server)


set(CMAKE_CXX_FLAGS
    "${CMAKE_CXX_FLAGS} -std=c++11 $ENV{CFLAGS} -O3 -Wall"
)


include_directories(
    ${PROJECT_SOURCE_DIR}/../src/
)


add_executable(${PROJECT_NAME}
    ${PROJECT_SOURCE_DIR}/server.cpp
)
target_link_libraries(${PROJECT_NAME}
    ${PROJECT_SOURCE_DIR}/../lib/libSimpleNetwork.so
    pthread
    glog
)

