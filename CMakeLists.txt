cmake_minimum_required(VERSION 4.0)
project(c_practice_skakked C)

set(CMAKE_C_STANDARD 11)

include_directories(src)

add_executable(c_practice_skakked
        src/cpractice.h
        src/main.c
        src/tests.c)
