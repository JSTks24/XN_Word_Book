cmake_minimum_required(VERSION 3.26)
project(XNStudyVoca C)

set(CMAKE_C_STANDARD 11)

add_executable(XNStudyVoca src/main.c
        src/VocaCtl.c
        src/IOCtl.c)
