#include <iostream>
#include <string>

using namespace std;

// Keeps asking until x is a number and within range [min, max]
void errorCheckInt(int &x, int min, int max, string prompt) {
    while (true) {
        if (cin.fail()) {
            // If input wasn't a number
            cin.clear();                // Clear the error state
            cin.ignore(1000, '\n');     // Flush the garbage input
            cout << "Error: Input must be a number." << endl;
        } else if (x < min || x > max) {
            // If input was a number but outside the valid range
            cout << "Error: Input must be between " << min << " and " << max << "." << endl;
        } else {
            // Valid input — break out of the loop
            break;
        }

        // Prompt again
        cout << prompt;
        cin >> x;
    }
}


