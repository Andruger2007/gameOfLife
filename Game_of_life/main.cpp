#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <conio.h> 
#include <atomic>

#include "grid.h"
#include "input.h"

using namespace std;

const int WIDTH = 60;  // Ширина поля
const int HEIGHT = 20; // Высота поля
atomic<bool> isPaused(false);

int main() {
    setlocale(LC_CTYPE, "Russian");
    vector<vector<bool>> grid(HEIGHT, vector<bool>(WIDTH, false));

    // Инициализация начального состояния
    initializeGrid(grid);

    // Запуск потока для обработки ввода
    thread inputThread(inputHandler, ref(grid));
    inputThread.detach();

    while (true) {
        if (!isPaused) {
            printGrid(grid, -1, -1); // Передаем -1 для курсора, чтобы его не отображать
            updateGrid(grid);
        }
        this_thread::sleep_for(chrono::milliseconds(250)); // Задержка между поколениями
    }

    return 0;
}
