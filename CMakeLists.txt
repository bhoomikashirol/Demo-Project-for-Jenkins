cmake_minimum_required(VERSION 3.10)
project(DemoProject)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable testing
enable_testing()

# Download and unpack googletest
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Add googletest directly to our build
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
                 ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
                 EXCLUDE_FROM_ALL)

# Specify the exact locations of the source files
set(MAIN_SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/Code.cpp)
set(TEST_SOURCE /var/lib/jenkins/workspace/PipelineDemo/code-branch/CodeTest.cpp)

# Add the executables
add_executable(DemoProject ${MAIN_SOURCE})
add_executable(DemoTest ${MAIN_SOURCE} ${TEST_SOURCE})

# Link the test executable with Google Test
target_link_libraries(DemoTest gtest_main)

# Add the test
add_test(NAME DemoTest COMMAND DemoTest)
