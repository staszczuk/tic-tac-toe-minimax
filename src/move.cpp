#include "move.h"

Move::Move(unsigned int row, unsigned int col)
    : row(row), col(col) {}

std::ostream &operator<<(std::ostream &os, const Move &move)
{
    os << '[' << move.row << ' ' << move.col << ']';
}
