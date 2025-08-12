CPMAddPackage("gh:raysan5/raylib#5.5")
add_library(raygui INTERFACE IMPORTED)
target_include_directories(raygui SYSTEM INTERFACE "${raylib_SOURCE_DIR}/examples/shapes")
