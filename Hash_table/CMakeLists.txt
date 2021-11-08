cmake_minimum_required(VERSION 3.17)
project(Hash_table)

add_subdirectory(googletest-release-1.11.0)
include_directories(googletest-release-1.11.0/googletest/include/gtest)

add_executable(Hash_table main.cpp Hashtable.cpp Hashtable.h)
target_link_libraries(Hash_table gtest gtest_main)

set(CMAKE_CXX_STANDARD 20)