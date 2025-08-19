#include "../objects/grid.h"
#include "../objects/snake.h"
#include "../state/settings.h"

void renderGrid(const Grid &grid, const Settings &settings);
void renderSnake(const Grid &grid, const Snake &snake, const Settings &settings);
void renderFood(const Grid &grid, const CellIndex &food, const Settings &settings);