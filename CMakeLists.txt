cmake_minimum_required(VERSION 3.10)

# Set the project name
project(DemoProject)

# Add an executable
add_executable(DemoProject ../code/Code.cpp)

# Enable testing
enable_testing()

# Find GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Add a test executable
add_executable(runTests ../Test/CodeTest.cpp)
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)

# Add a test
add_test(NAME DemoTest COMMAND runTests)
