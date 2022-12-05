cmake_minimum_required(VERSION 3.16)

project(gitserv C CXX)

set(cpp_src src/main.cpp)

add_executable(gitserv ${cpp_src})
set(CMAKE_CXX_FLAGS "-fpic -pthread")
add_link_options(-pthread)

target_link_libraries(gitserv link)
