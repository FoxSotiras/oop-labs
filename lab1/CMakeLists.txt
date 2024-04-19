cmake_minimum_required(VERSION 3.5.0)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
project(lab1)
set(SOURCE src/lab1-task1/book.cpp
           src/lab1-task1/lib_card.cpp
           src/lab1-task2/polynomial.cpp
           src/main.cpp)
add_executable("${PROJECT_NAME}" "${SOURCE}")
