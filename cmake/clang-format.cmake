# clang-format.cmake - Add a target to format all C/C++ files in the project
find_program(CLANG_FORMAT_BIN clang-format)

file(GLOB_RECURSE ALL_CLANG_FORMAT_FILES
    "${CMAKE_SOURCE_DIR}/engine/**.h"
    "${CMAKE_SOURCE_DIR}/engine/**.cpp"
    "${CMAKE_SOURCE_DIR}/game/**.h"
    "${CMAKE_SOURCE_DIR}/game/**.cpp"
)

if(CLANG_FORMAT_BIN)
    add_custom_target(format-clang
        COMMAND ${CLANG_FORMAT_BIN} -i ${ALL_CLANG_FORMAT_FILES}
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        COMMENT "Formatting all C/C++ files with clang-format"
    )
else()
    message(WARNING "clang-format not found! Please install it to enable the format-clang target.")
endif()
