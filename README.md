# Conway's Game of Life - CS225 Project

## Structure
```
project-root/
|   │-- STYLE_GUIDE.md
│   │-- README.md
│-- Code/
│   │-- GameOfLife.cpp
│   │-- Grid.h
│   │-- Cell.h
│-- Pretty/
│   │-- UML_Diagram.png
│-- build/
│-- data/
```

## UML Diagram 
![UML Diagram](/Pretty/UMLProto1-2.png)



## Functions
-BaseGrid (Abstract Base Class)

-BaseGrid(): Constructor to initialize the BaseGrid with dead cells.

-~BaseGrid(): Virtual destructor to allow proper cleanup in derived classes.

-update(): Pure virtual function for updating the grid.

-display(): Pure virtual function for displaying the grid.

-Grid Class

-Grid(): Constructor that initializes the grid.

-randomize(): Randomly sets cells as alive or dead.

-countNeighbors(int x, int y) -> int: Counts the number of live neighbors for a given cell.

-update(): Applies Conway's Game of Life rules to update the grid state.

-display(): Prints the current state of the grid to the console.

-saveToFile(string filename): Saves the grid state to a file.

-loadFromFile(string filename): Loads a grid state from a file.

-Cell Class

-Cell(): Constructor to initialize cell state.

-~Cell(): Destructor for cleanup.



## Order of Operations

