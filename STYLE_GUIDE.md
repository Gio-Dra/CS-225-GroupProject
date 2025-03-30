# Conway's Game of Life - Style Guide

## General Formatting
- Every file should begin with a boilerplate header comment including file name, author, purpose, version, and references.
- Use 4 spaces per indentation level.
- Line length should not exceed 100 characters.
- Use camelCase for variable and function names.
- Class names should be in PascalCase.

## File Structure
- Separate code into `.h` (header) and `.cpp` (source) files.
- Each class should have its own header file.
- Use header guards (#ifndef, #define, #endif) or #pragma once in all .h files.

## Naming Conventions
- **Variables:** `lowerCamelCase` (e.g., `isAlive`, `cellCount`).
- **Functions:** `lowerCamelCase` (e.g., `countNeighbors()`, `updateGrid()`).
- **Classes:** `PascalCase` (e.g., `Cell`, `Grid`).
- **Constants:** `UPPER_SNAKE_CASE` (e.g., `MAX_WIDTH`).

## Comments & Documentation
- Use `//` for single-line comments.
- Use `/* */` for multi-line comments if needed.
- Every function should have a brief comment explaining its purpose.

## Control Structures
- Use `for` loops for iterating through arrays or lists.
- Use `while` loops for the game loop.
- Use `if-else` statements with curly brackets, even for single-line conditions.

## Functions & Methods
- Keep functions short and focused on one task.
- Pass objects by reference when possible to avoid unnecessary copies.
- Use `const` where applicable.

## Error Handling
- Use `try-catch` blocks for file I/O operations.
- Return error codes where applicable.

## Testing Debugging 
- Avoid leaving debugging artifacts (e.g., commented-out code, stray `cout`s) in final submission.
- 
