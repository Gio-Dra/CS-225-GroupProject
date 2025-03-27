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