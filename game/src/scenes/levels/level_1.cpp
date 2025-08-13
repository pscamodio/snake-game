#include "level_1.h"
#include "../menu/menu.h"
#include "raygui.h"

Level1::Level1()
{
    // Initialize level 1
}

Level1::~Level1()
{
    // Cleanup level 1
}

void Level1::update([[maybe_unused]] Game &game, [[maybe_unused]] float deltaTime)
{
    // Update level 1 logic
}

void Level1::render(Game &game)
{
    Rectangle stopButtonRect;
    stopButtonRect.x = 24;
    stopButtonRect.y = 24;
    stopButtonRect.width = 120;
    stopButtonRect.height = 30;

    if (GuiButton(stopButtonRect, "Stop") > 0)
    {
        game.queueSceneChange(std::make_unique<Menu>());
    }
}
