# clang-tidy.cmake - Add a target to run clang-tidy on all C/C++ files in the project
find_program(CLANG_TIDY_BIN clang-tidy)

file(GLOB_RECURSE ALL_CLANG_TIDY_FILES
    "${CMAKE_SOURCE_DIR}/engine/include/*.h"
    "${CMAKE_SOURCE_DIR}/engine/src/*.cpp"
    "${CMAKE_SOURCE_DIR}/game/src/*.cpp"
)

if(CLANG_TIDY_BIN)
    add_custom_target(clang-tidy
        COMMAND ${CLANG_TIDY_BIN} -p build ${ALL_CLANG_TIDY_FILES}
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        COMMENT "Running clang-tidy on all C/C++ files"
    )
else()
    message(WARNING "clang-tidy not found! Please install it to enable the run-clang-tidy target.")
endif()
