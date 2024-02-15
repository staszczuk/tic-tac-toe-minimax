#ifndef BOARD_H
#define BOARD_H

#include "field.h"

const unsigned int def_rows = 3;
const unsigned int def_cols = 3;
const unsigned int def_k_in_a_row = 3;

class Board
{
public:
    Board(unsigned int rows = def_rows, unsigned int cols = def_cols,
          unsigned int k_in_a_row = def_k_in_a_row);

    friend std::ostream &operator<<(std::ostream &os, const Board &board);

    ~Board();

private:
    const unsigned int rows, cols, k_in_a_row;
    Field ***fields;
};

#endif
