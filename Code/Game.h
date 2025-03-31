/****************************************************************************
* File: Game.h
* Author: Daniel Warkentine, Gianni Dragos
* Purpose: Defines the Game class used in Conway’s Game of Life.
* Handles Game-wide variables such as iterations
* and the number of alive and dead cells.
* Includes logic for overriding update and display functions.
*
* Version: Final
*
* Resources:
*   - CS225 Canvas Slides (Classes, Overriding)
*
*******************************************************************************/


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

    void writeToFile(std::ostream& out) ;


    // Updates the game to the next generation based on Conway's Game of Life rules
    void update();

    // Displays the game
    void display() const;
};

#endif