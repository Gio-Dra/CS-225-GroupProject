#include "Cell.h"

ostream& operator<<(ostream& out, const Cell& cell) {
    if (cell.isAlive()) {
        out << '#';
    } else {
        out << ' ';
    }
    return out;
}