cmake_minimum_required(VERSION 3.11)

project(study_cv LANGUAGES CXX)

#
# Options
#

option(LCV_DEV_MODE "Developer mode" OFF)
option(LCV_BUILD_TEST "Build test" OFF)
option(LCV_BUILD_CXXOPTS "Build cxxopts" OFF)
option(LCV_BUILD_GTEST "Build google test" OFF)

message(STATUS "Option list")
message(STATUS "  * LCV_DEV_MODE        : ${LCV_DEV_MODE}")
message(STATUS "  * LCV_BUILD_TEST      : ${LCV_BUILD_TEST}")
message(STATUS "  * LCV_BUILD_CXXOPTS   : ${LCV_BUILD_CXXOPTS}")
message(STATUS "  * LCV_BUILD_GTEST     : ${LCV_BUILD_GTEST}")

#
# Developer's settings
#

if(LCV_DEV_MODE)
  set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
  add_custom_target(cp_compile_commands ALL COMMENT "Copy compile_commands.json")
  add_custom_command(
    TARGET cp_compile_commands
    PRE_BUILD
    COMMAND ${CMAKE_COMMAND} -E create_symlink ${CMAKE_BINARY_DIR}/compile_commands.json
            ${CMAKE_CURRENT_SOURCE_DIR}/compile_commands.json
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Copy compile_commands.json to base directory.")
endif()

#
# Libraries
#

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/deps.cmake)

#
# Subdirectories
#

add_subdirectory(src)
add_subdirectory(apps)

#
# Tests
#

if(LCV_BUILD_TEST)
  enable_testing()
  include(GoogleTest)
  add_subdirectory(tests)
endif()
