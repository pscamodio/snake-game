#include "menu.h"
#include "../snake/snake.h"
#include "raygui.h"

Menu::Menu()
{
    // Initialize menu
}

Menu::~Menu()
{
    // Cleanup menu
}

void Menu::update([[maybe_unused]] Game &game, [[maybe_unused]] float deltaTime)
{
    // Update menu logic
}

void Menu::render(Game &game)
{
    const auto &settings = game.settings();
    int buttonWidth = 200;
    int buttonHeight = 50;
    int centerX = (settings.screenWidth / 2) - (buttonWidth / 2);
    int centerY = (settings.screenHeight / 2) - (buttonHeight / 2);

    if (GuiButton({(float)centerX, (float)centerY, (float)buttonWidth, (float)buttonHeight},
                  "Play Snake") > 0)
    {
        game.queueSceneChange(std::make_unique<Snake>());
    }
}
