cmake_minimum_required(VERSION 3.10)
project(snake)

include(cmake/get_cpm.cmake)
include(cmake/dependencies.cmake)

add_subdirectory(engine)
add_subdirectory(game)
