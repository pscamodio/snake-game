cmake_minimum_required(VERSION 3.10)
project(snake)
# Include clang-format logic
include(${CMAKE_SOURCE_DIR}/cmake/clang-format.cmake)

include(cmake/cmake-format.cmake)
include(cmake/get_cpm.cmake)
include(cmake/dependencies.cmake)
include(cmake/warnings.cmake)

add_subdirectory(engine)
add_subdirectory(game)
