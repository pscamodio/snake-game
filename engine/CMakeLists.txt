add_library(engine STATIC src/engine.cpp src/Window.cpp)

target_include_directories(engine PUBLIC include)
target_link_libraries(engine PUBLIC raylib)
myproject_set_project_warnings(engine)
