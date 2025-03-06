#ifndef BASEGRID_H
#define BASEGRID_H

#include "Cell.h"
#include <vector>
using namespace std;

class BaseGrid {
protected:
  vector<Cell> cells;  // 2D vector of Cell objects
  int width;
  int height;

public:
  // Constructor and Destructor
  BaseGrid(int w, int h);
  virtual ~BaseGrid() {}

  // Pure virtual functions (must be implemented in derived classes)
  virtual void update() = 0;
  virtual void display() = 0;
};

#endif // BASEGRID_H
