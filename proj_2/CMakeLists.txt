cmake_minimum_required(VERSION 3.15)
project(proj_2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(proj_2
        q.h
        TCB.h
        thread_test.cpp
        threads.h)
