#include <iostream>
#include <string>
#include <climits>
#include "ErrorCheck.h"
using namespace std;

void errorCheckInt(int &x, int min, int max, string prompt) {
    while ((!cin)||((x < min)||(x > max))) {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "Error, try again." << endl << prompt;
        cin >> x;
    }
}