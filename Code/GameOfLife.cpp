/****************************************************************************
* File: GameOfLife.cpp
* Author: Daniel Warkentine, Gianni Dragos
* Purpose: Implements Conway’s Game of Life using a Grid, Game, and Cell class.
* Demonstrates user input handling, basic exception checking, and
* a game loop with animation delay using std::this_thread::sleep_for.
* Features multiple initialization modes and integrates custom
* error handling through errorCheckInt.
*
* Version: 1.0 - Feb 28, 2025
*
* Resources:
*   - CS225 Canvas Slides (Multiple Inheritance, Classes, and Error Handling)
*   - https://stackoverflow.com/questions/68055404/does-linuxs-chronoduration-also-include-the-time-a-thread-is-paused
*   - https://www.geeksforgeeks.org for function overloading reference
*   - https://cplusplus.com/reference/thread/this_thread/sleep_for/
*   - https://en.cppreference.com/w/cpp/chrono
*
*******************************************************************************/


#include "Cell.h"
#include "Grid.h"
#include "Game.h"
#include "ErrorCheck.h"
#include <fstream>
#include <thread>  // From stack overflow to get a pause cycle going
#include <chrono>  // https://stackoverflow.com/questions/68055404/does-linuxs-chronoduration-also-include-the-time-a-thread-is-paused

using namespace std;

int main() {
    srand(time(0));  // Seed the random number generator

    int width = 100;
    int height = 50;
    cout << "Welcome to Conway's Game of Life!" << endl;

    string widthPrompt = "Enter the width (must be 500 at most): ";
    cout << widthPrompt;
    cin >> width;
    errorCheckInt(width, 1, 500, widthPrompt);  // Ensures valid count
    string heightPrompt = "Enter the height (must be 500 at most): ";
    cout << heightPrompt;
    cin >> height;
    errorCheckInt(height, 1, 500, heightPrompt);  // Ensures valid count

    Grid board(width, height);

    // **(Mode Selection Menu)**
    int mode;
    cout << "1) Manual Preset\n2) Random Preset\n3) Preset Presets\n4) Print to File\n";
    string modePrompt = "Enter the number of the mode you would like: "; //Used for errorCheckInt
    cout << modePrompt;
    cin >> mode;
    errorCheckInt(mode, 1, 4, modePrompt);  // Exception Handling

    if (mode == 1) {  // **Manual Mode**
        int aliveCells;
        string manualPrompt = "Enter the number of alive cells: "; //Used for errorCheckInt
        cout << manualPrompt;
        cin >> aliveCells;
        errorCheckInt(aliveCells, 0, width * height, manualPrompt);  // Ensures valid count
        board.manualPreset(aliveCells);  // Calls function to set live cells manually

    } else if (mode == 2) {  // **Random Mode**
        int chance = 50;
        string chancePrompt = "Enter the chance of a cell to be alive (%): ";
        cout << chancePrompt;
        cin >> chance;
        errorCheckInt(chance, 0, 100, chancePrompt);  // Ensures valid count
        board.randomize(chance);  // Randomize is defined in Grid.h btw lol

    } else if (mode == 3) {  // **Other Presets Placeholder**
        cout << "1) Spaceship\n2) F Pentomino\n3) Gosper Glider Gun\n";
        modePrompt = "Enter the number of the preset you would like: ";  // Used for errorCheckInt
        cout << modePrompt;
        cin >> mode;
        errorCheckInt(mode, 1, 3, modePrompt);  // Exception Handling

        if (mode == 1) {
            board.setCellAlive(1, 0);
            board.setCellAlive(2, 1);
            board.setCellAlive(0, 2);
            board.setCellAlive(1, 2);
            board.setCellAlive(2, 2);
        } else if (mode == 2) {
            board.setCellAlive(45, 14);
            board.setCellAlive(46, 14);
            board.setCellAlive(44, 15);
            board.setCellAlive(45, 15);
            board.setCellAlive(45, 16);
        } else if (mode == 3) {
            board.setCellAlive(1, 5);
            board.setCellAlive(2, 5);
            board.setCellAlive(1, 6);
            board.setCellAlive(2, 6);
            
            board.setCellAlive(11, 6);
            board.setCellAlive(11, 5);
            board.setCellAlive(11, 7);
            board.setCellAlive(12, 4);
            board.setCellAlive(12, 8);
            board.setCellAlive(13, 3);
            board.setCellAlive(13, 9);
            board.setCellAlive(14, 3);
            board.setCellAlive(14, 9);
            
            board.setCellAlive(15, 6);
            board.setCellAlive(16, 4);
            board.setCellAlive(16, 8);
            board.setCellAlive(17, 6);
            board.setCellAlive(17, 5);
            board.setCellAlive(17, 7);
            board.setCellAlive(18, 6);
            
            board.setCellAlive(21, 3);
            board.setCellAlive(22, 3);
            board.setCellAlive(21, 4);
            board.setCellAlive(22, 4);
            board.setCellAlive(21, 5);
            board.setCellAlive(22, 5);
            board.setCellAlive(23, 2);
            board.setCellAlive(23, 6);
            board.setCellAlive(25, 2);
            board.setCellAlive(25, 6);
            board.setCellAlive(25, 1);
            board.setCellAlive(25, 7);
            
            board.setCellAlive(35, 3);
            board.setCellAlive(36, 3);
            board.setCellAlive(35, 4);
            board.setCellAlive(36, 4);
        }

    }else if (mode == 4) {
        board.randomize(50);  // or board.manualPreset(...) if you want to add that option too

        int iterations;
        string iterPrompt = "Enter the number of iterations to simulate: ";
        cout << iterPrompt;
        cin >> iterations;
        errorCheckInt(iterations, 1, 1000000, iterPrompt);

        for (int i = 0; i < iterations; ++i) {
            board.update();
        }

        ofstream outFile("FinalGrid.txt");
        if (outFile.is_open()) {
            board.writeToFile(outFile);
            outFile.close();
            cout << "Final grid state written to FinalGrid.txt\n";
        } else {
            cerr << "Failed to open FinalGrid.txt for writing.\n";
        }

        return 0; // Exit the program after writing to file
        }

    cout << "Here is your starting board, press e to continue." << endl;
    board.display();
    char userInput;
    cin >> userInput;
    
    int waitTime = 200;
    string waitTimePrompt = "Enter the delay between iterations (in milliseconds): ";
    cout << waitTimePrompt;
    cin >> waitTime;
    errorCheckInt(waitTime, 0, 10000, waitTimePrompt);  // Ensures valid count
    
    Game game(board);

    // **Game Loop**
    while (true) {
        game.display(); // Contained in grid.h
        game.update(); // Contained in... ...grid.h lol
        // Pause execution for [waitTime] milliseconds to slow down the loop
        // This makes the animation human-readable instead of blazing by at CPU speed

        // this_thread::sleep_for(...) pauses the current thread
        // chrono::milliseconds(waitTime) creates a duration object of [waitTime] milliseconds
        // Combined, this line tells the CPU: "Wait [waitTime]ms before doing the next update"
        this_thread::sleep_for(chrono::milliseconds(waitTime));

        // Refrences:
        // "sleep_for" https://cplusplus.com/reference/thread/this_thread/sleep_for/
        // "chrono" https://en.cppreference.com/w/cpp/chrono
        // "this_thread" https://en.cppreference.com/w/cpp/thread/this_thread
    }

    return 0;
}