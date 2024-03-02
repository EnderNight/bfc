cmake_minimum_required(VERSION 3.28.3)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS on)

project(bfc LANGUAGES CXX)

add_executable(bfc main.cc)
target_compile_options(bfc PRIVATE -Wall -Wextra -Werror -Wold-style-cast -pedantic)
