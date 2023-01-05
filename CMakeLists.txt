cmake_minimum_required(VERSION 3.5.1)

project(gitserv C CXX)

# ---- Add cmake directory ----
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")

# ---- Modules ----
include(findLink)
include(FeatureSummary)

# ---- Build options ----
if (LINK_FOUND)
	option(GITSERV_WEB "Build gitserv's web frontend using Link" ON)
	add_subdirectory(link)
	add_definitions(-DGITSERV_WEB)
	add_feature_info(GITSERV_WEB GITSERV_WEB "Build gitserv's web frontend using Link")
else()
	message(WARNING "Link not found, disabling web frontend")
	option(GITSERV_WEB "Build gitserv's web frontend using Link" OFF)
endif()

feature_summary(WHAT ALL)

add_subdirectory(libgit2)

set(cpp_src src/main.cpp
			src/init.cpp
			src/git/git.cpp)

include_directories(src)

add_executable(gitserv ${cpp_src})
set(CMAKE_CXX_FLAGS "-fpic -pthread")
add_link_options(-pthread)

# Link .so files to executable found in libgit2/ and link/
target_link_libraries(gitserv git2 link)