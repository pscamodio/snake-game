cmake_minimum_required(VERSION 3.10)
project(snake)

include(cmake/cmake-format.cmake)
include(cmake/get_cpm.cmake)
include(cmake/dependencies.cmake)
include(cmake/warnings.cmake)

add_subdirectory(engine)
add_subdirectory(game)
