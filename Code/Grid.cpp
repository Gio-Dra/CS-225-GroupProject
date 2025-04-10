#include "Grid.h"

using namespace std;

// Random Preset Mode
void Grid::randomize(int chance) {
    for (Cell &cell : cells) { // loops through every Cell in the "cells" vector, & refrences the actual cell
        if ((rand() % 100) < chance) {
            cell.setAlive(1);
        } else {
            cell.setAlive(0);
        }
    }
}

// Method for Manual Preset Mode
// Allows users to input specific alive cell coordinates
void Grid::setCellAlive(int x, int y) {
    if (x >= 0 && x < width && y >= 0 && y < height) {
        cells[index(x, y)].setAlive(true);
    }
}

// Manual Preset Mode: Allows user to specify live cells
void Grid::manualPreset(int aliveCellCount) {
    int x, y;
    for (int i = 0; i < aliveCellCount; i++) {
        cout << "Enter alive cell #" << i + 1 << " coordinates in the form \"x y\": ";
        cin >> x >> y;
        setCellAlive(x, y);
    }
}

// Counts how many of the 8 neighboring cells around (x, y) are alive
int Grid::countNeighbors(int x, int y) const {
    int count = 0; // Start with 0 living neighbors

    // Loop over a 3x3 grid centered at (x, y), including diagonals
    for (int dx = -1; dx <= 1; dx++) {          // dx shifts x-coordinate
        for (int dy = -1; dy <= 1; dy++) {      // dy shifts y-coordinate

            // Skip the center cell itself; we're only interested in its neighbors
            if (dx == 0 && dy == 0) continue;

            // Calculate neighbor coordinates (nx, ny)
            int nx = x + dx;
            int ny = y + dy;

            // Check that neighbor is within bounds of the grid
            if (nx >= 0 && nx < width && ny >= 0 && ny < height) {

                // If the neighbor cell is alive, increment our count
                if (cells[index(nx, ny)].isAlive()) {
                    count++;
                }
            }
        }
    }

    // Return the total number of living neighbors
    return count;
}

// Updates the grid to the next generation based on Conway's Game of Life rules
void Grid::update() {
    // Step 1: Create a copy of the current grid state.
    // This will hold the next generation of cell states.
    vector<Cell> nextState = cells;

    // Step 2: Loop through every cell in the grid (row by row, col by col)
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // Step 3: Count how many of the 8 neighboring cells are alive
            int liveNeighbors = countNeighbors(x, y);

            // Step 4: Convert 2D coordinates (x, y) to 1D index in the cells vector (making a 2D vector? no clue)
            int idx = index(x, y);

            // Step 5: Apply Game of Life rules:

            // RULE 1 & 2:
            // If the current cell is alive...
            if (cells[idx].isAlive()) {
                // ...it stays alive ONLY if it has 2 or 3 live neighbors.
                // Otherwise, it dies from loneliness :< (<2) or overpopulation (>3).
                nextState[idx].setAlive(liveNeighbors == 2 || liveNeighbors == 3);
            } else {
                // RULE 4:
                // If the current cell is dead...
                // ...it becomes alive ONLY if it has exactly 3 live neighbors (reproduction!)
                nextState[idx].setAlive(liveNeighbors == 3);
            }
        }
    }

    // Step 6: Update the current grid state with the new generation
    cells = nextState;
}


// Displays the grid
void Grid::display() const {
//    system("clear");  // Use "cls" for Windows
//    cout << "cls" << endl;
    cout << "\033[2J\033[1;1H";
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // Access the cell at (x, y) using the index() function to convert 2D coords to 1D,
            // then check if that specific cell is currently alive (returns true if alive, false if dead)
            cout << cells[index(x, y)] << " ";
        }
        cout << endl;
    }
}

void Grid::writeToFile(std::ostream& out) {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (cells[i * width + j].isAlive()) {
                out << '#';
            } else {
                out << ' ';
            }
        }
        out << '\n';
    }
}

//Destroy
Grid::~Grid() {
}