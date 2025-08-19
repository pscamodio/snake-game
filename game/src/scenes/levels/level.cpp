#include "level.h"
#include "../../utils/rendering.h"
#include "../menu/menu.h"
#include "levels.h"
#include "raygui.h"

Level::Level(const LevelDescription &description)
    : m_levelDescription(description), m_snake({{description.startingPosition}, {1, 0}}),
      m_food(getRandomFreePosition(description.grid, m_snake.body))
{
    // Initialize level 1
}

Level::~Level()
{
    // Cleanup level 1
}

void Level::update([[maybe_unused]] Game &game, [[maybe_unused]] float deltaTime)
{
    if (!m_alive)
        return;
    auto state = game.gameState();

    const auto hasMoved = updateSnakeDirectionFromKeyboard(m_snake);

    m_timer += deltaTime;
    if (m_timer < m_levelDescription.speed || hasMoved)
        return;

    m_timer = 0;
    const auto nextCell = m_snake.body.back() + m_snake.direction;
    m_alive = isInsideGrid(m_levelDescription.grid, nextCell) &&
              !isObstacle(m_levelDescription.grid, nextCell) && !willEatSelf(m_snake, nextCell);
    if (m_alive)
    {
        if (nextCell == m_food)
        {
            m_snake.body.push_back(nextCell);
            m_food = getRandomFreePosition(m_levelDescription.grid, m_snake.body);
            m_score += 1;
            state.score += 1;
            if (m_score >= m_levelDescription.targetScore)
            {
                state.level += 1;
                game.pushGameState(state);
                game.queueSceneChange(std::make_unique<Level>(LEVELS[state.level % LEVELS.size()]));
            }
        }
        else
        {
            move(m_snake);
        }
    }
}

void Level::render(Game &game)
{
    Rectangle stopButtonRect;
    stopButtonRect.x = 24;
    stopButtonRect.y = 24;
    stopButtonRect.width = 120;
    stopButtonRect.height = 30;

    if (GuiButton(stopButtonRect, "Restart") > 0)
    {
        game.queueSceneChange(std::make_unique<Level>(m_levelDescription));
    }

    const auto &grid = m_levelDescription.grid;

    renderGrid(grid, game.settings());
    renderSnake(grid, m_snake, game.settings());
    renderFood(grid, m_food, game.settings());

    if (!m_alive)
    {
        DrawText("Game Over", 350, 250, 20, RED);
    }
}
