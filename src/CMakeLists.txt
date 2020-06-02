cmake_minimum_required(VERSION 3.5)
project(SimpleNetwork)


set(CMAKE_CXX_FLAGS
    "${CMAKE_CXX_FLAGS} -std=c++11 $ENV{CFLAGS} -O3 -Wall"
)
set(LIBRARY_OUTPUT_PATH
    ${PROJECT_SOURCE_DIR}/../lib/
)


add_library(${PROJECT_NAME} SHARED
    ${PROJECT_SOURCE_DIR}/TCPServer.cpp
    ${PROJECT_SOURCE_DIR}/TCPClient.cpp
)

