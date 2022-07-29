cmake_minimum_required(VERSION 2.8.12)
project(Logger)

add_compile_options(-std=c++17 -g)

include_directories(include)

add_executable(logger src/main.cpp src/logger.cpp)
target_link_libraries(logger)