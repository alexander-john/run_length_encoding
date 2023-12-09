cmake_minimum_required(VERSION 3.26)
project(run_length_encoding)

set(CMAKE_CXX_STANDARD 17)

add_executable(run_length_encoding main.cpp
        run-length-enc.h)
