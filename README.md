# Conway's Game of Life - CS225 Project

## Structure
```
project-root/
│-- src/
│   │-- main.cpp
│   │-- grid.h
│   │-- grid.cpp
│   │-- cell.h
│   │-- cell.cpp
│-- docs/
│   │-- UML_Diagram.png
│   │-- STYLE_GUIDE.md
│   │-- README.md
│-- build/
│-- data/
```

## UML Diagram 
![UML Diagram](CS-225-GroupProject/UMLProto.png)



## Functions
-Grid(): Constructor that initializes the grid with dead cells.

-randomize(): Randomly sets cells as alive or dead.

-countNeighbors(int x, int y) -> int: Counts the number of live neighbors for a given cell.

-update(): Applies Conway's Game of Life rules to update the grid state.

-display(): Prints the current state of the grid to the console.

-saveToFile(string filename): Saves the grid state to a file.

-loadFromFile(string filename): Loads a grid state from a file.

-BaseGrid (Abstract Base Class)

-update(): Pure virtual function for updating the grid.

-display(): Pure virtual function for displaying the grid.

-~BaseGrid(): Virtual destructor to allow proper cleanup in derived classes.

-Cell Class

-Cell(): Constructor to initialize cell state.

-~Cell(): Destructor for cleanup.



## Order of Operations

