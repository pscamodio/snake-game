# cmake-format.cmake - CMake logic to download and run cmake-format on all CMake
# files Find system-installed cmake-format
find_program(CMAKE_FORMAT_BIN cmake-format)

# Find all CMake files in the project
file(
  GLOB_RECURSE
  ALL_CMAKE_FILES
  "${CMAKE_SOURCE_DIR}/**/CMakeLists.txt"
  "${CMAKE_SOURCE_DIR}/cmake/*.cmake")

if(CMAKE_FORMAT_BIN)
  add_custom_target(
    format-cmake
    COMMAND ${CMAKE_FORMAT_BIN} -i ${ALL_CMAKE_FILES}
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    COMMENT "Formatting all CMake files with cmake-format")
else()
  message(
    WARNING
      "cmake-format not found! Please install it with 'pip install cmake-format' to enable the format-cmake target."
  )
endif()
