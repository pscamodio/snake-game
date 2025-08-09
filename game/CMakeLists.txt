add_executable(game
    src/main.cpp
)

target_link_libraries(game PRIVATE engine)
target_include_directories(game PRIVATE ${CMAKE_SOURCE_DIR}/engine/include)
