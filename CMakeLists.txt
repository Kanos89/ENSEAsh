cmake_minimum_required(VERSION 3.30)
project(ENSEAsh C)

set(CMAKE_C_STANDARD 11)

add_executable(ENSEAsh main.c
        question1.c
        question1.h
        main.h
        question2.c
        question2.h
        question3.c
        question3.h
)
