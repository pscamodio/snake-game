#pragma once
#include "../scene.h"

class Snake : public Scene
{
  public:
    Snake();
    ~Snake() override;
    void update(Game &game, float deltaTime) override;

    void render(Game &game) override;
};
