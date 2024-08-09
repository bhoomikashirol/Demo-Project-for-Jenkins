cmake_minimum_required(VERSION 3.10)

# Set the project name
project(DemoProject)

# Add coverage flags
if(CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage")
endif()

# Add an executable
add_executable(DemoProject Code.cpp)

# Enable testing
enable_testing()

# Add a test
add_test(NAME DemoTest COMMAND DemoProject)
