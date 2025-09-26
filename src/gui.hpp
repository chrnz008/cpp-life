
#pragma once
#include <raylib.h>
#include <vector>
using namespace std;

const int cellSize = 10;

// Initialize the window
inline void initGUI(int rows, int cols, const char* title) {
    InitWindow(cols * cellSize, rows * cellSize, title);
    SetTargetFPS(30); // adjust speed
}

// Draw the board
inline void draw_board(const vector<vector<bool>> &realm) {
    int rows = realm.size();
    int cols = realm[0].size();

    BeginDrawing();
        ClearBackground(RAYWHITE);

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (realm[r][c])
                    DrawRectangle(c * cellSize, r * cellSize, cellSize, cellSize, BLACK);
                else
                    DrawRectangleLines(c * cellSize, r * cellSize, cellSize, cellSize, LIGHTGRAY);
            }
        }
    EndDrawing();
}

// Close the window
inline void closeGUI() {
    CloseWindow();
}
