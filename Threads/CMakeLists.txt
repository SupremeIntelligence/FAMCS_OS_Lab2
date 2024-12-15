cmake_minimum_required (VERSION 3.8)

add_library(Threads STATIC threads.cpp)

target_include_directories(Threads PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

