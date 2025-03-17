#include <iostream>
#include <string>
using namespace std;

void errorCheckInt(int &x, int min, int max, string prompt) { // Daniels Code
    while (cin.fail() || x < min || x > max) {               // G Code \|/
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input. " << prompt;
        cin >> x;
    }
}