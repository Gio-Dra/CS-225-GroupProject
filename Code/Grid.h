#ifndef GRID_H
#define GRID_H

#include "BaseGrid.h"
#include "Cell.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Grid : public BaseGrid {
public:
    // Constructor and Destructor
    Grid();
    ~Grid();

    // Randomly initializes the grid state
    void randomize();

    // Counts the number of live neighbors for a given cell
    int countNeighbors(int x, int y) const;

    // Updates the grid based on the Game of Life rules
    void update();

    // Displays the grid in the terminal
    void display();

    // Saves the current grid state to a file
    void saveToFile(const string& filename) const;

};

void display() {
    for (int i = 0; i < BaseGrid::height; i++) {
        for (int j = 0; j < BaseGrid::width; j++) {
            cout << (BaseGrid::cells[i][j].isAlive() ? '#' : ' ') << " ";
        }
        cout << endl;
    }

#endif // GRID_H
