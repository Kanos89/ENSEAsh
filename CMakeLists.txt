cmake_minimum_required(VERSION 3.30)
project(ENSEAsh C)

set(CMAKE_C_STANDARD 11)

add_executable(ENSEAsh main.c
        Question1.c
        Question1.h
        main.h
        Question2.c
        Question2.h
        Question3.c
        Question3.h
)
