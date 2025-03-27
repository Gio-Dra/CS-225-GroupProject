#include <iostream>
#include <string>

using namespace std;

// Validates input: must be a number and within [min, max] range
void errorCheckInt(int &x, int min, int max, const string &prompt) {
    bool valid = false;

    while (!valid) {
        try {
            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                throw "Input must be a number.";
            }

            if (x < min || x > max) {
                throw "Input is out of range.";
            }

            valid = true; // If we pass both checks, input is valid

        } catch (const char* msg) {
            cout << "Error: " << msg << endl;
            cout << prompt;
            cin >> x; // Retry
        }
    }
}
