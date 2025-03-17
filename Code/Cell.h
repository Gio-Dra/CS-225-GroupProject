#ifndef CELL_H
#define CELL_H

class Cell {
private:
    bool alive;

public:
    // Constructor initializes the cell as dead
    Cell() : alive(false) {}

    // Set and check cell state
    void setAlive(bool state) { alive = state; }
    bool isAlive() const { return alive; }
};

#endif // CELL_H
