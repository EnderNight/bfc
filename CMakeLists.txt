cmake_minimum_required(VERSION 3.28.3)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS on)
set(CMAKE_BUILD_TYPE Debug)

project(bfc LANGUAGES CXX)

# bfc
add_executable(bfc)

target_compile_options(bfc PRIVATE -Wall -Wextra -Werror -Wold-style-cast -pedantic)
target_include_directories(bfc PRIVATE include)

add_subdirectory(src)
