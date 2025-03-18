# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    CMakeLists.txt                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/18 10:34:03 by jeportie          #+#    #+#              #
#    Updated: 2025/03/18 10:34:41 by jeportie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

cmake_minimum_required(VERSION 3.10)

# Check if project name is passed via -DNAME=...
if(NOT DEFINED NAME OR "${NAME}" STREQUAL "")
    message(STATUS "No project name given, prompting interactively...")
    set(NAME "default_project" CACHE STRING "Project name")
    set(prompt_message "Please enter your project name: ")
    message(${prompt_message})
    file(READ "/dev/stdin" NAME_INPUT LIMIT 255)
    string(STRIP "${NAME_INPUT}" NAME)
endif()

project(${NAME} LANGUAGES CXX)

# Set C++ standard and compilation flags
set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror")

# Find all .cpp sources starting from root, explicitly excluding 'build' directory
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/*.cpp")
list(FILTER SOURCES EXCLUDE REGEX "^${CMAKE_SOURCE_DIR}/build/.*")
list(FILTER SOURCES EXCLUDE REGEX "^${CMAKE_SOURCE_DIR}/tests/.*") # Exclude tests

# Define executable and sources
add_executable(${PROJECT_NAME} ${SOURCES})

# Set output directories to match your Makefile structure
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

# Create a custom target equivalent to your "run" Makefile rule
add_custom_target(run
    COMMAND ${PROJECT_NAME}
    DEPENDS ${PROJECT_NAME}
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

# Create a custom target equivalent to your "build_and_run" Makefile rule
add_custom_target(build_and_run
    COMMAND ${PROJECT_NAME}
    DEPENDS ${PROJECT_NAME}
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

### GOOGLE TEST INTEGRATION ###
include(FetchContent)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.14.0
)

FetchContent_MakeAvailable(googletest)

enable_testing()

# Test executable
file(GLOB TEST_SOURCES "tests/*.cpp")

add_executable(test_megaphone ${TEST_SOURCES})

target_link_libraries(test_megaphone
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(test_megaphone)
