#include "level.h"
#include "../../utils/rendering.h"
#include "../menu/menu.h"
#include "levels.h"
#include "raygui.h"

Level::Level(const LevelDescription &description)
    : m_levelDescription(description), m_snake({{description.startingPosition}, {1, 0}}),
      m_food(getRandomFreePosition(description.grid, m_snake.body)), m_timer(description.speed)
{
    // Initialize level 1
}

Level::~Level()
{
    // Cleanup level 1
}

void Level::update([[maybe_unused]] Game &game, [[maybe_unused]] float deltaTime)
{
    if (m_state != LevelState::Playing)
    {
        return;
    }

    const auto nextCell = checkMove(deltaTime);
    if (!isValid(nextCell))
    {
        return;
    }

    const auto hasLost =
        !isValidMove(m_levelDescription.grid, nextCell) || willEatSelf(m_snake, nextCell);
    if (hasLost)
    {
        m_state = LevelState::GameOver;
        return;
    }

    if (nextCell == m_food)
    {
        eat(game);
        return;
    }

    move(m_snake);
}

void Level::render(Game &game)
{
    const auto &grid = m_levelDescription.grid;

    renderGrid(grid, game.settings());
    renderSnake(grid, m_snake, game.settings());
    renderFood(grid, m_food, game.settings());

    if (m_state == LevelState::Playing)
    {
        return;
    }

    if (m_state == LevelState::GameOver)
    {
        DrawText("Game Over", 300, 220, 20, RED);
    }
    DrawText("Press any key to start", 300, 250, 20, BLACK);
    if (GetKeyPressed() != KEY_NULL)
    {
        if (m_state == LevelState::GameOver)
        {
            reset();
        }
        m_state = LevelState::Playing;
        m_timer.start();
    }
}

void Level::eat(Game &game)
{
    auto state = game.gameState();
    m_snake.body.push_back(m_food);
    m_food = getRandomFreePosition(m_levelDescription.grid, m_snake.body);
    m_score += 1;
    if (m_score >= m_levelDescription.targetScore)
    {
        state.level += 1;
        game.pushGameState(state);
        game.queueSceneChange(std::make_unique<Level>(LEVELS[state.level % LEVELS.size()]));
    }
}

void Level::reset()
{
    m_snake = Snake{{m_levelDescription.startingPosition}, {1, 0}};
    m_food = getRandomFreePosition(m_levelDescription.grid, m_snake.body);
    m_score = 0;
    m_timer.reset();
}

auto Level::checkMove(float deltaTime) -> CellIndex
{
    const auto hasMoved = updateSnakeDirectionFromKeyboard(m_snake);
    const auto elapsed = m_timer.update(deltaTime);

    if (!elapsed && !hasMoved)
    {
        return INVALID_CELL;
    }

    m_timer.restart();

    return m_snake.body.back() + m_snake.direction;
}
