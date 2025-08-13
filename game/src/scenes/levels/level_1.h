#pragma once
#include "../scene.h"

class Level1 : public Scene
{
  public:
    Level1();
    ~Level1() override;
    void update(Game &game, float deltaTime) override;

    void render(Game &game) override;
};
