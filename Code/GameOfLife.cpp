#include "Grid.h"
#include "ErrorCheck.h"
#include <thread> // Stole from stack overflow to get a pause cycle going
#include <chrono> //https://stackoverflow.com/questions/68055404/does-linuxs-chronoduration-also-include-the-time-a-thread-is-paused

using namespace std;  // Added to avoid std:: prefix

int main() {
    srand(time(0));  // Seed the random number generator

    const int width = 200;
    const int height = 100;
    Grid game(width, height);

    // **(Daniel's Mode Selection Menu)**
    int mode;
    cout << "1) Manual Preset\n2) Random Preset\n3) Other Presets\n";
    string modePrompt = "Enter the number of the mode you would like: ";
    cout << modePrompt;
    cin >> mode;
    errorCheckInt(mode, 1, 3, modePrompt);  // Ensures valid input

    if (mode == 1) {  // **Manual Mode (Daniel's implementation)**
        int aliveCellCount;
        string manualPrompt = "Enter the number of alive cells: ";
        cout << manualPrompt;
        cin >> aliveCellCount;
        errorCheckInt(aliveCellCount, 0, width * height, manualPrompt);  // Ensures valid count
        game.manualPreset(aliveCellCount);  // Calls function to set live cells manually

    } else if (mode == 2) {  // **Random Mode (Daniel's logic)**
        game.randomize(); //Randomize is defined in Grid.h btw lol

    } else {  // **Other Presets Placeholder**
        cout << "Other presets haven't been implemented yet.\n";
    }

    // **Game Loop**
    while (true) {
        game.display(); //Contained in grid.h
        game.update(); //Contained in... ...grid.h lol
        this_thread::sleep_for(chrono::milliseconds(200)); // The stack overflow part
    }

    return 0;
}
