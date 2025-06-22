cmake_minimum_required(VERSION 3.10)
project(rsh C)

# Recursively collect all .c files
file(GLOB_RECURSE SRC_FILES src/*.c)

set(CMAKE_C_FLAGS_DEBUG "-g -O0 -Wall -Wextra")
add_executable(rsh ${SRC_FILES})

# Add include directories (assumes include/ is adjacent to src/)
target_include_directories(rsh
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include
)

