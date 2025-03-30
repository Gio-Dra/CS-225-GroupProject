/****************************************************************************
* File: Cell.h
* Author: Daniel Warkentine, Gianni Dragos
* Purpose: Defines the Cell class for Conway’s Game of Life.
*          Each Cell object tracks its own alive/dead state and
*          supports accessors, mutators, and stream insertion.
*
* Version: 1.0 - Feb 28, 2025
*
* Resources:
*   - CS225 Canvas Slides (Classes, Constructors, Friend Functions)
*   - https://cplusplus.com/reference/ostream/ostream/operator_ltlt/
*
*******************************************************************************/
#ifndef CELL_H
#define CELL_H

#include <iostream>

using namespace std;

class Cell {
private:
    bool alive;

public:
    // Constructor initializes the cell as dead
    Cell() : alive(false) {}

    // Set and check cell state
    void setAlive(bool state) { alive = state; }
    bool isAlive() const { return alive; }

    friend ostream& operator<<(ostream& out, const Cell& cell);
};

#endif // CELL_H