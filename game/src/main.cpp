
#include <Window.h>
#include <engine.h>

int main()
{
    engine::Window window(1280, 800, "Snake Game");
    while (!window.shouldClose())
    {
        window.beginDrawing();
        // Draw game content here
        window.endDrawing();
    }
    return 0;
}
