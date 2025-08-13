file(
  GLOB_RECURSE
  GAME_SOURCES
  CONFIGURE_DEPENDS
  ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/*.h)

add_executable(game ${GAME_SOURCES})

target_link_libraries(game PRIVATE engine raygui)
target_include_directories(game PRIVATE ${CMAKE_SOURCE_DIR}/engine/include)
myproject_set_project_warnings(game)
