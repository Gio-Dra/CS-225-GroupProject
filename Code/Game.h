#ifndef GAME_H
#define GAME_H

#include "Grid.h"

class Game : public Grid {
    private:
    int aliveCellCount;
    int deadCellCount;
    int iterations;

    public:
    Game(int w, int h) : Grid(w, h), aliveCellCount(0), deadCellCount(width * height), iterations(0) {}

    void writeToFile(std::ostream& out) ;


    // Updates the game to the next generation based on Conway's Game of Life rules
    void update();

    // Displays the game
    void display() const;
};

#endif