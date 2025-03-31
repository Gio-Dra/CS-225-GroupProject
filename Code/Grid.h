/****************************************************************************
* File: Grid.h
* Author: Daniel Warkentine, Gianni Dragos
* Purpose: Defines the Grid class used in Conway’s Game of Life.
* Handles creation, display, and update of a 2D grid of Cell objects.
* Includes logic for random initialization, manual presets,
* and classic Game of Life neighbor counting and rule application.
*
* Version: Final
*
* Resources:
*   - CS225 Canvas Slides (Classes, Vector, Loops, Overloading)
*   - https://en.cppreference.com for STL vector and system() details
*
*******************************************************************************/


#ifndef GRID_H
#define GRID_H

#include "Cell.h"
#include <iostream>
#include <vector>
#include <cstdlib> // Provides rand() and srand() functions
#include <ctime> // Provides time() function

using namespace std;

class Grid {
protected:
    vector<Cell> cells;
    int width, height;

    // Converts (x, y) to 1D index so we can edit it within the code itself, simpler
    int index(int x, int y) const {
        return (y * width) + x;
    }

public:
    ~Grid();

    void writeToFile(std::ostream& out);

    Grid(int w, int h) : width(w), height(h), cells(w * h) {}

    // Daniel's Code: Random Preset Mode
    void randomize(int chance);

    // New Method for Manual Preset Mode
    // Allows users to input specific alive cell coordinates
    void setCellAlive(int x, int y);

    // Daniel's Manual Preset Mode: Allows user to specify live cells
    void manualPreset(int aliveCellCount);

    // Counts how many of the 8 neighboring cells around (x, y) are alive
    int countNeighbors(int x, int y) const;

    // Updates the grid to the next generation based on Conway's Game of Life rules
    virtual void update();

    // Displays the grid
    virtual void display() const;
};

#endif // GRID_H