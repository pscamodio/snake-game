#include "Window.h"
#include <raylib.h>

namespace engine {


Window::Window(int width, int height, const char* title) {
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(width, height, title);
}

Window::~Window() {
    CloseWindow();
}

bool Window::shouldClose() const {
    return WindowShouldClose();
}

void Window::beginDrawing() const {
    BeginDrawing();
}

void Window::endDrawing() const {
    EndDrawing();
}

} // namespace engine
