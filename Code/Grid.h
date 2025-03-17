#ifndef GRID_H
#define GRID_H

#include "Cell.h"
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Grid {
private:
    std::vector<Cell> cells;
    int width, height;

    // Converts (x, y) to 1D index
    int index(int x, int y) const {
        return y * width + x;
    }

public:
    Grid(int w, int h) : width(w), height(h), cells(w * h) {}

    // Daniel's Code: Random Preset Mode
    void randomize() {
        srand(time(0));
        for (Cell &cell : cells) {
            cell.setAlive(rand() % 2); // 50% chance of being alive
        }
    }

    // New Method for Manual Preset Mode
    // Allows users to input specific alive cell coordinates
    void setCellAlive(int x, int y) {
        if (x >= 0 && x < width && y >= 0 && y < height) {
            cells[index(x, y)].setAlive(true);
        }
    }

    // Daniel's Manual Preset Mode: Allows user to specify live cells
    void manualPreset(int aliveCellCount) {
        int x, y;
        for (int i = 0; i < aliveCellCount; i++) {
            cout << "Enter alive cell #" << i + 1 << " coordinates in the form \"x y\": ";
            cin >> x >> y;
            setCellAlive(x, y);
        }
    }

    // Counts the number of live neighbors of a given cell
    int countNeighbors(int x, int y) const {
        int count = 0;
        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                if (dx == 0 && dy == 0) continue;
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && nx < width && ny >= 0 && ny < height) {
                    if (cells[index(nx, ny)].isAlive()) count++;
                }
            }
        }
        return count;
    }

    // Updates the grid based on Game of Life rules
    void update() {
        std::vector<Cell> nextState = cells;
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                int liveNeighbors = countNeighbors(x, y);
                int idx = index(x, y);

                if (cells[idx].isAlive()) {
                    nextState[idx].setAlive(liveNeighbors == 2 || liveNeighbors == 3);
                } else {
                    nextState[idx].setAlive(liveNeighbors == 3);
                }
            }
        }
        cells = nextState;
    }

    // Displays the grid
    void display() const {
        system("clear");  // Use "cls" for Windows
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                std::cout << (cells[index(x, y)].isAlive() ? '#' : ' ') << " ";
            }
            std::cout << std::endl;
        }
    }
};

#endif // GRID_H
