#pragma once

namespace engine
{
class Window
{
  public:
    Window(int width, int height, const char *title);
    ~Window();
    bool shouldClose() const;
    void beginDrawing() const;
    void endDrawing() const;
};
} // namespace engine
