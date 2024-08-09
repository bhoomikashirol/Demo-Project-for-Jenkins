cmake_minimum_required(VERSION 3.10)

# Set the project name
project(DemoProject)

# Add an executable
add_executable(DemoProject Code.cpp)

# Enable testing
enable_testing()

# Add a test
add_test(NAME DemoTest COMMAND DemoProject)
