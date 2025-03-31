# Conway's Game of Life - CS225 Project

## Structure
---
```
| File             | Description                                                               |
|------------------|---------------------------------------------------------------------------|
| `GameOfLife.cpp` | Entry point of the game. Manages mode selection, game loop, and animation |
| `Game.h/cpp`     | Inherits from `Grid`. Adds iteration tracking and enhanced display         |
| `Grid.h/cpp`     | Manages the 2D grid logic using a 1D vector; applies Conway’s rules        |
| `Cell.h/cpp`     | Defines each individual cell’s alive/dead state                            |
| `ErrorCheck.h/cpp` | Exception-based input validation for integer prompts                     |
```
---

## UML Diagram 
![UML Diagram](/Pretty/UMLFinal.png)

## Features Implemented

###  Exception Handling

Custom input validation using `try`, `throw`, `catch` (then simplified):
---
```
void errorCheckInt(int &x, int min, int max, string prompt);
```
---
###   Operator Overloading
```
std::ostream& operator<<(std::ostream& out, const Cell& cell);
```
Allows clean output 
```
std::cout << cells[index[idx]];
```
---
### Manual & Random Modes
- **Manual**: Enter coordinates for alive cells
- **Random**: 50% chance of each cell being alive
- **Preset Selector**: Placeholders for custom patterns
- **Silent Simulation Mode**: Run for N iterations, save result to file
---
### 1D Grid Logic (Flattened 2D)
A 2D grid is flattened to a 1D vector:
```
int index(int x, int y) const {
    return y * width + x;
}
```
###  Game Engine Logic
The `Game` class extends `Grid` to track:
- Alive/Dead cell counts
- Iteration count
- Enhanced display with metadata

---

## Object-Oriented Design

- **Encapsulation**: `Cell` hides internal state
- **Inheritance**: `Game` inherits from `Grid`
- **Polymorphism**: `update()` and `display()` can be overridden
- **Friend Functions**: Used for operator overloading
- **File I/O**: Supports saving grid state via `writeToFile()`

---
