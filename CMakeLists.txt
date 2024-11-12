cmake_minimum_required(VERSION 3.29)
project(aide C)

set(CMAKE_C_STANDARD 11)

add_executable(aide main.c
        Aide.c
        Aide.h)
