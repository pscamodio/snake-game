cmake_minimum_required(VERSION 3.10)
project(snake)
# Enable generation of compile_commands.json for clang-tidy and tooling
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)

include(cmake/options.cmake)
include(cmake/sanitizers.cmake)
include(cmake/warnings.cmake)
include(cmake/clang-tidy.cmake)
include(cmake/clang-format.cmake)

include(cmake/cmake-format.cmake)
include(cmake/get_cpm.cmake)
include(cmake/dependencies.cmake)

add_subdirectory(engine)
add_subdirectory(game)
