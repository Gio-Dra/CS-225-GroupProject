#ifndef GAME_H
#define GAME_H

#include "Grid.h"

class Game : public Grid {
    private:
    int aliveCellCount;
    int deadCellCount;
    int iterations;

    public:
    Game(const Grid &board);

    // Updates the game to the next generation based on Conway's Game of Life rules
    void update();

    // Displays the game
    void display() const;
};

#endif