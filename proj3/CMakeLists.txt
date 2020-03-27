cmake_minimum_required(VERSION 3.14)
project(proj3 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(proj3
        q.h
        sem.h
        TCB.h
        thread_test.c
        threads.h)
