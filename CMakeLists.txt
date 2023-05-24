cmake_minimum_required(VERSION 3.5.1)

project(gitserv C CXX)

# ---- Add cmake directory ----
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")

# ---- Modules ----
find_library(LINK_LIBRARY NAMES link)
include(FeatureSummary)

# ---- Build options ----

feature_summary(WHAT ALL)

add_subdirectory(libgit2)

set(cpp_src src/main.cpp
			src/init.cpp
			src/setup.cpp
			src/git/git.cpp)

include_directories(src)

add_executable(gitserv ${cpp_src})
set(CMAKE_CXX_FLAGS "-fpic -pthread")
add_link_options(-pthread)

if (LINK_LIBRARY)
	target_link_libraries(gitserv ${LINK_LIBRARY} git2)
else()
	message(FATAL_ERROR "link library not found")
endif()