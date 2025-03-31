/****************************************************************************
* File: ErrorCheck.h
* Author: Daniel Warkentine, Gianni Dragos
* Purpose: Declares the errorCheckInt function, which validates that a user
*          input is a number and falls within a specified range. Used for
*          robust input handling in interactive console applications.
*
* Version: Final
*
* Resources:
*   - CS225 Canvas Slides (Function Declarations, Exception Handling)
*
*******************************************************************************/

#ifndef ERRORCHECK_H
#define ERRORCHECK_H

#include <string>

// Validates input: must be a number and within [min, max] range
void errorCheckInt(int &x, int min, int max, const std::string &prompt);

#endif