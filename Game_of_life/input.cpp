#include "input.h"
#include "grid.h" // ���������� grid.h ��� ������� � �������� �� grid.cpp
#include <conio.h> // ���������, ��� ���������� ���������� ���������
#include <atomic>
#include <iostream>

const int WIDTH = 60;
const int HEIGHT = 20;
extern std::atomic<bool> isPaused;

void inputHandler(std::vector<std::vector<bool>>& grid) {
    int cursorX = WIDTH / 2, cursorY = HEIGHT / 2;
    char ch;
    while (true) {
        ch = _getch(); // ���������� ������� _getch()
        if (ch == 'p' || ch == 'P') {
            isPaused = true;
        }
        else if (ch == 'r' || ch == 'R') {
            isPaused = false;
        }
        else if (isPaused) {
            if (ch == 'w' || ch == 'W') {
                cursorY = (cursorY - 1 + HEIGHT) % HEIGHT;
            }
            else if (ch == 's' || ch == 'S') {
                cursorY = (cursorY + 1) % HEIGHT;
            }
            else if (ch == 'a' || ch == 'A') {
                cursorX = (cursorX - 1 + WIDTH) % WIDTH;
            }
            else if (ch == 'd' || ch == 'D') {
                cursorX = (cursorX + 1) % WIDTH;
            }
            else if (ch == '\r') { // Enter
                grid[cursorY][cursorX] = !grid[cursorY][cursorX];
            }
            printGrid(grid, cursorX, cursorY); // ���������� ������� printGrid �� grid.cpp
        }
    }
}
