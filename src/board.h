#ifndef BOARD_H
#define BOARD_H

#include <vector>

#include "game_state.h"
#include "invalid_move_exception.h"
#include "mark.h"
#include "move.h"

const unsigned int def_rows = 3;
const unsigned int def_cols = 3;
const unsigned int def_k_in_a_row = 3;

class Board
{
public:
    Board(unsigned int rows = def_rows, unsigned int cols = def_cols,
          unsigned int k_in_a_row = def_k_in_a_row);

    GameState check_win() const;

    std::vector<Move> get_available_moves() const;

    void make_move(Move move, Mark mark) const;

    friend std::ostream &operator<<(std::ostream &os, const Board &board);

    ~Board();

private:
    const unsigned int rows, cols, k_in_a_row;
    Mark **fields;
};

#endif
