#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <conio.h> 
#include <atomic>

#include "grid.h"
#include "input.h"

using namespace std;

const int WIDTH = 60;  // ������ ����
const int HEIGHT = 20; // ������ ����
atomic<bool> isPaused(false);

int main() {
    setlocale(LC_CTYPE, "Russian");
    vector<vector<bool>> grid(HEIGHT, vector<bool>(WIDTH, false));

    // ������������� ���������� ���������
    initializeGrid(grid);

    // ������ ������ ��� ��������� �����
    thread inputThread(inputHandler, ref(grid));
    inputThread.detach();

    while (true) {
        if (!isPaused) {
            printGrid(grid, -1, -1); // �������� -1 ��� �������, ����� ��� �� ����������
            updateGrid(grid);
        }
        this_thread::sleep_for(chrono::milliseconds(250)); // �������� ����� �����������
    }

    return 0;
}
