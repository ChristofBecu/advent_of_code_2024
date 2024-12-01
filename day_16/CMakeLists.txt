cmake_minimum_required(VERSION 3.10)

# Set the project name
project(AOC2024)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(OUTPUT_DIR "output") 

# Add the executables
add_executable(part1 part1.cpp)
add_executable(part2 part2.cpp)

# Set the output directory for the executables
set_target_properties(part1 PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${OUTPUT_DIR})
set_target_properties(part2 PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${OUTPUT_DIR})
