#ifndef CELL_H
#define CELL_H

class Cell {
private:
    bool state;       // Current state (alive or dead)
    bool futureState; // Next state after an update

public:
    // Constructor and Destructor
    Cell();
    ~Cell() {}

    // Getters and Setters
    bool isAlive() const;
    void setState(bool newState);

    // Future state management
    void setFutureState(bool newState);
    void applyFutureState();
};

#endif // CELL_H
