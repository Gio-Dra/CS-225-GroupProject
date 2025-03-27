// Commented Code means requires attention later/as it develops
#include <iostream>
#include <string>
#include <time.h>
//#include <BaseGrid>
//#include <Grid>
//#include <Cell>
#include "ErrorCheck.h"
using namespace std;

int main() {
    srand(time(NULL));
    int mode;
    cout << "1) Manual Preset\n2) Random Preset\n3) Other Presets\n";
    string modePrompt = "Enter the number of the mode you would like: ";
    cout << modePrompt;
    cin >> mode;
    errorCheckInt(mode, 1, 3, modePrompt);
    if (mode == 1) {
        manualPrompt = "Enter the number of alive cells: ";
        cout << manualPrompt;
        cin >> aliveCellCount;
        errorCheckInt(aliveCellCount, 0, /*widthDummyVar*heightDummyVar*/, manualPrompt);
        for (int i = 0; i < aliveCellCount, i++) {
            cout << "Enter alive cell #" << i + 1 << " coordinates in the form \"x y\": ";
            //cout << "Woah, this code hasn't been written yet!";
        }
    } elseif (mode == 2) {
        chance = .5*100;
        for (int i = 0; i < aliveCellCount, i++) {
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