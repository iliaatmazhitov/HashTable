cmake_minimum_required(VERSION 3.28)
project(lab3b)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab3b main.cpp
        KeySpace.h
        Person.h
        UI.cpp
        UI.h
)
