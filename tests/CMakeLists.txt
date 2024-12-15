cmake_minimum_required (VERSION 3.8)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

add_executable (ThreadTest thread_test.cpp)

target_link_libraries(ThreadTest PRIVATE gtest gtest_main Threads)

target_include_directories(ThreadTest PRIVATE ${CMAKE_SOURCE_DIR}/Threads ${CMAKE_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/googletest)

add_test (ThreadTest ThreadTest)