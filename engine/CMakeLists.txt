file(
  GLOB_RECURSE
  ENGINE_SOURCES
  CONFIGURE_DEPENDS
  ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h)
add_library(engine STATIC ${ENGINE_SOURCES})

target_include_directories(engine PUBLIC include)
target_link_libraries(engine PUBLIC raylib)
target_configure_warnings(engine)
target_configure_sanitizers(engine)
