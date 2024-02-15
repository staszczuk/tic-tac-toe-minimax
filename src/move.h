#ifndef MOVE_H
#define MOVE_H

#include <iostream>

struct Move
{
    Move(unsigned int row, unsigned int col);

    friend std::ostream &operator<<(std::ostream &os, const Move &move);

    unsigned int row, col;
};

#endif
