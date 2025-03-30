/****************************************************************************
* File: ErrorCheck.h
* Author: Daniel Warkentine, Gianni Dragos
* Purpose: Declares the errorCheckInt function, which validates that a user
*          input is a number and falls within a specified range. Used for
*          robust input handling in interactive console applications.
*
* Version: 1.0 - Feb 28, 2025
*
* Resources:
*   - CS225 Canvas Slides (Function Declarations, Exception Handling)
*
*******************************************************************************/

#include <string>

// Validates input: must be a number and within [min, max] range
void errorCheckInt(int &x, int min, int max, const string &prompt);