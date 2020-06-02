cmake_minimum_required(VERSION 2.8)
project(all)


MESSAGE(STATUS "PROJECT_SOURCE_DIR: ${PROJECT_SOURCE_DIR}")


add_subdirectory(src)
add_subdirectory(example-server)
add_subdirectory(example-client)

