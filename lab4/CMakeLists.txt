cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
project(lab4)

add_compile_options(-Wall -Wextra -Wpedantic)

add_library(animal STATIC include/lab4-task1/animal.hpp src/lab4-task1/animal.cpp)
target_include_directories(animal PRIVATE include/lab4-task1)
target_sources(animal PRIVATE
    src/lab4-task1/animal.cpp
    src/lab4-task1/bird.cpp
    src/lab4-task1/mammal.cpp
    src/lab4-task1/store.cpp
)

add_library(files STATIC include/lab4-task2/files.hpp src/lab4-task2/files.cpp)
target_include_directories(files PRIVATE include/lab4-task2)
target_sources(files PRIVATE
    src/lab4-task2/files.cpp
)

add_library(binary STATIC include/lab4-task3/binary.hpp src/lab4-task3/binary.cpp)
target_include_directories(binary PRIVATE include/lab4-task3)
target_sources(binary PRIVATE
    src/lab4-task3/binary.cpp
)

add_executable("${PROJECT_NAME}" src/main.cpp)
target_link_libraries("${PROJECT_NAME}" animal files binary)
file(INSTALL text/ DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/text")
