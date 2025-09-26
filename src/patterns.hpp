
#pragma once
#include <vector>
#include <cstdlib>
using namespace std;

// Initialize a civilization-like pattern
void initpattern(vector<vector<bool>> &realm) {
    int size = realm.size();

    // Random clusters (~15% alive)
    for (int r = 0; r < size; r++) {
        for (int c = 0; c < size; c++) {
            if (rand() % 100 < 15) realm[r][c] = true;
        }
    }

    // Gliders
    int glider[5][2] = {{0,1},{1,2},{2,0},{2,1},{2,2}};
    int gliderCount = 10;
    for (int k = 0; k < gliderCount; k++) {
        int rBase = rand() % (size - 5);
        int cBase = rand() % (size - 5);
        for (int i = 0; i < 5; i++) {
            int r = rBase + glider[i][0];
            int c = cBase + glider[i][1];
            realm[r][c] = true;
        }
    }

    // Blocks (still lifes)
    int block[4][2] = {{0,0},{0,1},{1,0},{1,1}};
    int blocksCount = 8;
    for (int k = 0; k < blocksCount; k++) {
        int rBase = rand() % (size - 2);
        int cBase = rand() % (size - 2);
        for (int i = 0; i < 4; i++) {
            int r = rBase + block[i][0];
            int c = cBase + block[i][1];
            realm[r][c] = true;
        }
    }

    // Blinkers (oscillators)
    int blinker[3][2] = {{0,0},{0,1},{0,2}};
    int blinkerCount = 8;
    for (int k = 0; k < blinkerCount; k++) {
        int rBase = rand() % (size - 3);
        int cBase = rand() % (size - 3);
        for (int i = 0; i < 3; i++) {
            int r = rBase + blinker[i][0];
            int c = cBase + blinker[i][1];
            realm[r][c] = true;
        }
    }
}
