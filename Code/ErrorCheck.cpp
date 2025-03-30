/****************************************************************************
* File: ErrorCheck.cpp
* Author: Daniel Warkentine, Gianni Dragos
* Purpose: Provides a reusable function `errorCheckInt` to validate integer
* input from the user. Ensures the input is numeric and within a
* specified range, re-prompts on failure using try-catch logic.
*
* Version: 1.0 - Feb 28, 2025
*
* Resources:
*   - CS225 Canvas (Exception Handling, User Input Validation)
*   - https://cplusplus.com/reference/iostream/istream/fail/
*
*******************************************************************************/


#include <iostream>
#include "ErrorCheck.h"

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