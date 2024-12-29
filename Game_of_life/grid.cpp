#include "grid.h"
#include <iostream>
#include <conio.h> // Для использования функции _getch()

using namespace std;

const int WIDTH = 60;  // Ширина поля
const int HEIGHT = 20; // Высота поля

void printGrid(const vector<vector<bool>>& grid, int cursorX, int cursorY) {
    system("cls"); // Очистка экрана (для Windows), для Linux или macOS используйте system("clear")

    // Верхняя граница
    for (int x = 0; x < WIDTH + 2; ++x) {
        cout << '#';
    }
    cout << endl;

    for (int y = 0; y < HEIGHT; ++y) {
        cout << '#'; // Левая граница
        for (int x = 0; x < WIDTH; ++x) {
            if (x == cursorX && y == cursorY) {
                cout << (grid[y][x] ? 'X' : '+'); // 'X' для живых клеток под курсором, '+' для мертвых клеток под курсором
            }
            else {
                cout << (grid[y][x] ? 'O' : ' ');
            }
        }
        cout << '#'; // Правая граница
        cout << endl;
    }

    // Нижняя граница
    for (int x = 0; x < WIDTH + 2; ++x) {
        cout << '#';
    }
    cout << endl;

    cout << "Используйте W, A, S, D для перемещения курсора и Enter для установки/удаления клетки. Нажмите Q для завершения ввода." << endl;
    cout << "Нажмите P для паузы, R для продолжения." << endl;
}

int countLiveNeighbors(const vector<vector<bool>>& grid, int x, int y) {
    int liveNeighbors = 0;
    for (int dy = -1; dy <= 1; ++dy) {
        for (int dx = -1; dx <= 1; ++dx) {
            if (dx == 0 && dy == 0) continue;
            int nx = (x + dx + WIDTH) % WIDTH;
            int ny = (y + dy + HEIGHT) % HEIGHT;
            liveNeighbors += grid[ny][nx];
        }
    }
    return liveNeighbors;
}

void updateGrid(vector<vector<bool>>& grid) {
    vector<vector<bool>> newGrid = grid;
    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            int liveNeighbors = countLiveNeighbors(grid, x, y);
            if (grid[y][x]) {
                newGrid[y][x] = (liveNeighbors == 2 || liveNeighbors == 3);
            }
            else {
                newGrid[y][x] = (liveNeighbors == 3);
            }
        }
    }
    grid = newGrid;
}

void initializeGrid(vector<vector<bool>>& grid) {
    int cursorX = WIDTH / 2, cursorY = HEIGHT / 2;
    char ch;
    while (true) {
        printGrid(grid, cursorX, cursorY);
        ch = _getch();
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
        else if (ch == 'q' || ch == 'Q') {
            break;
        }
    }
}
