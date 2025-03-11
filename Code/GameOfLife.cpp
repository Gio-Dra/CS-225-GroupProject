#include <iostream>
#include <climits>
#include <string>
#include <time.h>
#include <vector>
//#include "Cell.h"
//#include "BaseGrid.h"
//#include "Grid.h"
//#include "ErrorCheck.h"
using namespace std;

//Classes
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

class BaseGrid {
protected:
  vector<Cell> cells;  // 2D vector of Cell objects
  int width;
  int height;
public:
  // Constructor and Destructor
  BaseGrid(int w, int h);
  virtual ~BaseGrid() {}
  // Pure virtual functions (must be implemented in derived classes)
  virtual void update() = 0;
  virtual void display() = 0;
};

class Grid : public BaseGrid {
public:
    // Constructor and Destructor
    Grid();
    ~Grid();
    // Randomly initializes the grid state
    void randomize();
    // Counts the number of live neighbors for a given cell
    int countNeighbors(int x, int y) const;
    // Updates the grid based on the Game of Life rules
    void update();
    // Displays the grid in the terminal
    void display();
    // Saves the current grid state to a file
    void saveToFile(const string& filename) const;
};

//Function Declarations
void errorCheckInt(int &x, int min, int max, string prompt);

int main() {
    int aliveCellCount = 20;
    srand(time(NULL));
    Grid b;
    int mode;
    cout << "1) Manual Preset\n2) Random Preset\n3) Other Presets\n";
    string modePrompt = "Enter the number of the mode you would like: ";
    cout << modePrompt;
    cin >> mode;
    errorCheckInt(mode, 1, 3, modePrompt);
    if (mode == 1) {
        string manualPrompt = "Enter the number of alive cells: ";
        cout << manualPrompt;
        cin >> aliveCellCount;
        errorCheckInt(aliveCellCount, 0, /*widthDummyVar*heightDummyVar*/400, manualPrompt);
        for (int i = 0; i < aliveCellCount; i++) {
            cout << "Enter alive cell #" << i + 1 << " coordinates in the form \"x y\": ";
            //cout << "Woah, this code hasn't been written yet!";
        }
    } else if (mode == 2) {
        int chance = .5*100;
        for (int i = 0; i < aliveCellCount; i++) {
            if ((rand() % 100) < chance) {
                //cellInstanceDummyVar[i].state = 1;
            } else {
                //cellInstanceDummyVar[i].state = 0;
            }
        }
        //cout << "Woah, this code hasn't been written yet!";
    } else {
        //cout << "Woah, this code hasn't been written yet!";
    }
    
    return 0;
}

//Functions
void errorCheckInt(int &x, int min, int max, string prompt) {
    while ((!cin)||((x < min)||(x > max))) {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "Error, try again." << endl << prompt;
        cin >> x;
    }
}

void Grid::display() {
    for (int i = 0; i < BaseGrid::height; i++) {
        for (int j = 0; j < BaseGrid::width; j++) {
            cout << (BaseGrid::cells[i][j].isAlive() ? '#' : ' ') << " ";
        }
        cout << endl;
    }
}



