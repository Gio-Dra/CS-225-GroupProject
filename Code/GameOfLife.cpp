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
#include <thread> // Stole from stack overflow to get a pause cycle going
#include <chrono> //https://stackoverflow.com/questions/68055404/does-linuxs-chronoduration-also-include-the-time-a-thread-is-paused

using namespace std;

int main() {
    srand(time(0));  // Seed the random number generator

    const int width = 100;
    const int height = 200;
    Grid board(width, height);

    // **(Daniel's Mode Selection Menu)**
    int mode;
    cout << "1) Manual Preset\n2) Random Preset\n3) Other Presets\n";
    string modePrompt = "Enter the number of the mode you would like: "; //Used for errorCheckInt
    cout << modePrompt;
    cin >> mode;
    errorCheckInt(mode, 1, 4, modePrompt);  // Exception Handling

    if (mode == 1) {  // **Manual Mode (Daniel's implementation)**
        int aliveCellCount;
        string manualPrompt = "Enter the number of alive cells: "; //Used for errorCheckInt
        cout << manualPrompt;
        cin >> aliveCellCount;
        errorCheckInt(aliveCellCount, 0, width * height, manualPrompt);  // Ensures valid count
        board.manualPreset(aliveCellCount);  // Calls function to set live cells manually

    } else if (mode == 2) {  // **Random Mode (Daniel's logic)**
        board.randomize(); //Randomize is defined in Grid.h btw lol

    } else if (mode == 3) {  // **Other Presets Placeholder**
        cout << "1) Spaceship\n2) F Pentomino\n3) Gun\n";
        modePrompt = "Enter the number of the preset you would like: "; //Used for errorCheckInt
        cout << modePrompt;
        cin >> mode;
        errorCheckInt(mode, 1, 3, modePrompt);  // Exception Handling
    }else if (mode == 4) {
        board.randomize();  // or board.manualPreset(...) if you want to add that option too

        int iterations;
        string iterPrompt = "Enter the number of iterations to simulate: ";
        cout << iterPrompt;
        cin >> iterations;
        errorCheckInt(iterations, 1, 1000000, iterPrompt);

        for (int i = 0; i < iterations; ++i) {
            board.update();
            this_thread::sleep_for(chrono::milliseconds(200));
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

    cout << "Here is your starting board, press enter to continue." << endl;
    board.display();
    char user_input;
    cin >> user_input;
    while (user_input != '\n') {
        cin >> user_input;
    }

    Game game(board);

    // **Game Loop**
    while (true) {
        game.display(); //Contained in grid.h
        game.update(); //Contained in... ...grid.h lol
        // Pause execution for 200 milliseconds to slow down the loop
        // This makes the animation human-readable instead of blazing by at CPU speed

        // this_thread::sleep_for(...) pauses the current thread
        // chrono::milliseconds(200) creates a duration object of 200 milliseconds
        // Combined, this line tells the CPU: "Wait 200ms before doing the next update"
        this_thread::sleep_for(chrono::milliseconds(200));

        // Refrences:
        // "sleep_for" https://cplusplus.com/reference/thread/this_thread/sleep_for/
        // "chrono"  https://en.cppreference.com/w/cpp/chrono
        // "this_thread" https://en.cppreference.com/w/cpp/thread/this_thread


    }

    return 0;
}