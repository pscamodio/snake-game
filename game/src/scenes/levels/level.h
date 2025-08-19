#pragma once
#include "../../objects/grid.h"
#include "../../objects/snake.h"
#include "../scene.h"

struct LevelDescription
{
    Grid grid;
    CellIndex startingPosition;
    float speed;
    uint32_t targetScore;
};

class Level : public Scene
{
  public:
    Level(const LevelDescription &description);
    ~Level() override;
    void update(Game &game, float deltaTime) override;

    void render(Game &game) override;

  private:
    LevelDescription m_levelDescription;
    Snake m_snake;
    CellIndex m_food;

    bool m_alive = true;
    uint16_t m_score = 0;
    float m_timer = 0;
};
