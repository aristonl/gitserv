cmake_minimum_required(VERSION 3.16)

project(gitserv C CXX)

add_subdirectory(libgit2)
add_subdirectory(link)

set(cpp_src src/main.cpp
			src/init.cpp
			src/git/git.cpp)

include_directories(src)

add_executable(gitserv ${cpp_src})
set(CMAKE_CXX_FLAGS "-fpic -pthread")
add_link_options(-pthread)

# Link .so files to executable found in libgit2/ and link/
target_link_libraries(gitserv git2 link)