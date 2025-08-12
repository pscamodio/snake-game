#pragma once

#include "../game.h"

class Scene
{
  public:
    virtual ~Scene() = default;
    virtual void update(Game &game, float deltaTime) = 0;
    virtual void render(Game &game) = 0;
};
