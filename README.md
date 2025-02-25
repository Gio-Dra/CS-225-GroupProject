# Game of Life - CS225 Project  

## Project Overview  
This project is an implementation of Conway’s Game of Life in C++, demonstrating key Object-Oriented Programming (OOP) concepts such as classes, inheritance, operator overloading, file I/O, and exception handling.  

## Features  
- Grid-based simulation of Conway’s Game of Life  
- User-defined initial configurations  
- Step-by-step evolution of the grid based on the rules  
- File input and output for saving and loading configurations  
- Exception handling for invalid input  
- Modular design following good coding practices  

## Concepts Implemented  
This project demonstrates:  
- Thoughtful selection of variable names, function names, and class names  
- Code division into multiple header and source files  
- Use of if statements and loops (while, do-while, for)  
- Function definitions and class structures  
- Constructors and destructors  
- Operator overloading  
- Object composition  
- Inheritance and polymorphism  
- Exception handling  
- File I/O for saving and loading grid states  
- A UML diagram for project structure  
- A C++ concept not covered in class  

## Code Structure  
```
/GameOfLife  
│── src/  
│   ├── main.cpp  
│   ├── game.cpp  
│   ├── grid.cpp  
│── include/  
│   ├── game.h  
│   ├── grid.h  
│── assets/  
│   ├── sample_config.txt  
│── docs/  
│   ├── UML_Diagram.pdf  
│── README.md  
│── Makefile  
```

## How to Compile and Run  
1. Clone the repository  
2. Navigate to the project directory  
3. Compile using `make`  
4. Run the program using `./GameOfLife`  

## Usage  
- Users can input an initial configuration or load one from a file  
- The simulation runs step-by-step, showing changes in the grid  
- Users can save the grid state to a file  

## Style Guide  
This project follows a consistent coding style inspired by the Google C++ Style Guide. All naming conventions, indentation, and documentation align with best practices.  

## Contributions  
This project was developed as part of the CS225 group project. All work adheres to academic integrity guidelines.  

## License  
This project is for educational purposes and follows the guidelines set by the CS225 course.  
