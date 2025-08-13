#pragma once
#include "../../objects/grid.h"
#include "../../objects/snake.h"
#include "../scene.h"

class Level1 : public Scene
{
  public:
    Level1();
    ~Level1() override;
    void update(Game &game, float deltaTime) override;

    void render(Game &game) override;

  private:
    bool m_alive = true;
    Grid m_grid{10, 10};
    Snake m_snake{{{0, 0}}, {1, 0}};

    float m_timer = 0;
    const float m_secondsForCell = 0.1F;

    CellIndex m_food = {5, 5};
};
