#include "Game.h"

// Game Constructor
Game::Game(const Grid &board) : Grid(board), iterations(0), aliveCellCount(0), deadCellCount(width * height) {
    for (Cell &cell : cells) { // loops through every Cell in the "cells" vector, & refrences the actual cell
        aliveCellCount += cell.isAlive();
        deadCellCount -= cell.isAlive();
    }
}

// Updates the game to the next generation based on Conway's Game of Life rules
void Game::update() {
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

    // Game Class Updating
    aliveCellCount = 0;
    deadCellCount = width * height;
    for (Cell &cell : cells) { // loops through every Cell in the "cells" vector, & refrences the actual cell
        aliveCellCount += cell.isAlive();
        deadCellCount -= cell.isAlive();
    }
    iterations++;
}

// Displays the game
void Game::display() const {
    system("clear");  // Use "cls" for Windows
    cout << "\033[2J\033[1;1H";
    cout << "Iterations: " << iterations << endl;
    cout << "Number of Alive Cells: " << aliveCellCount << endl;
    cout << "Number of Dead Cells: " << deadCellCount << endl;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // Access the cell at (x, y) using the index() function to convert 2D coords to 1D,
            // then check if that specific cell is currently alive (returns true if alive, false if dead)
            cout << cells[index(x, y)] << " ";
        }
        cout << endl;
    }
}


