#ifndef GAME_H
#define GAME_H

#include "Grid.h"

class Game : public Grid {
    private:
    int mode;
    int aliveCellCount;
    int deadCellCount;

    public:
    Game(int w, int h) : Grid(w, h) {}
    void update() {}
    void display() {}
};

#endif