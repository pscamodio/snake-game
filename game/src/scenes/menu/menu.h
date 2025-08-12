#pragma once
#include "../scene.h"

class Menu : public Scene
{
  public:
    Menu();
    ~Menu() override;
    void update(Game &game, float deltaTime) override;

    void render(Game &game) override;
};
