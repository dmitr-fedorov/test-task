cmake_minimum_required(VERSION 3.15)

project(test-task LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_subdirectory(include)

add_subdirectory(src)