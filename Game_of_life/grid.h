#ifndef GRID_H
#define GRID_H

#include <vector>

void printGrid(const std::vector<std::vector<bool>>& grid, int cursorX, int cursorY);
int countLiveNeighbors(const std::vector<std::vector<bool>>& grid, int x, int y);
void updateGrid(std::vector<std::vector<bool>>& grid);
void initializeGrid(std::vector<std::vector<bool>>& grid);

#endif // GRID_H
