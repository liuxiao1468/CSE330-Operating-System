cmake_minimum_required(VERSION 3.15)
project(proj_1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(proj_1
    proj_1.cpp
    q.h)
