cmake_minimum_required(VERSION 3.24)
project(in_class)

set(CMAKE_CXX_STANDARD 14)

add_executable(hello
        lecture-2023-01-10-intro/hello.cpp lecture-2023-01-10-intro/useful.h)

add_executable(func_demo
        lecture-2023-01-12-types-functions/function_demo.cpp lecture-2023-01-24-classes/Book.cpp lecture-2023-01-24-classes/Book.h)

add_executable(scope_demo
        lecture-2023-01-12-types-functions/scope_demo.cpp)

add_executable(grow
        assignments/grow.cpp)