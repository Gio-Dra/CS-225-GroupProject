# Conway's Game of Life - CS225 Project

## Structure
---
```
| File            | Purpose                                 |
|-----------------|------------------------------------------|
| GameOfLife.cpp  | Main logic and game loop                 |
| Grid.h          | Manages the 2D grid using a 1D vector    |
| Cell.h          | Simple class representing each cell      |
| ErrorCheck.h    | Handles user input and exceptions        |
```
---

## UML Diagram 
![UML Diagram](/Pretty/UMLProto1-2.png)



## 🛠️ Files

| File            | Purpose                                 |
|-----------------|------------------------------------------|
| GameOfLife.cpp  | Main logic and game loop                 |
| Grid.h          | Manages the 2D grid using a 1D vector    |
| Cell.h          | Simple class representing each cell      |
| ErrorCheck.h    | Handles user input and exceptions        |

---

## Features Implemented

###  Exception Handling

Custom input validation using `try`, `throw`, `catch` (then simplified):
---
```
void errorCheckInt(int &x, int min, int max, string prompt);
void getValidCoordinates(int &x, int &y, int width, int height);
```
---
### Operator Overloading
```
std::ostream& operator<<(std::ostream& out, const Cell& cell);
```
Allows clean output 
```
std::cout << cells[index[idx]];
```
---
### Manual & Random Modes
#### Manual: Users input specific live cell coordinates.
---
#### Random: Grid is seeded with 50% chance of each cell being alive.
---
### 1D Grid Logic (Flattened 2D)
A 2D grid is flattened to a 1D vector:
```
int index(int x, int y) const {
    return y * width + x;
}
```

