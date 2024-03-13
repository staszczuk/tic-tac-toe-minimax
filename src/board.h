#ifndef BOARD_H
#define BOARD_H

#include "game_state.h"
#include "mark.h"
#include "move.h"

#include <stdexcept>
#include <vector>

const unsigned int def_rows = 3;
const unsigned int def_cols = 3;
const unsigned int def_k_in_a_row = 3;

class Board
{
public:
    Board(unsigned int rows = def_rows, unsigned int cols = def_cols,
          unsigned int k_in_a_row = def_k_in_a_row);

    Board(const Board &board);

    GameState check_game_state() const;

    std::vector<Move> get_available_moves() const;

    void make_move(Move move, Mark mark) const;

    void undo_move(Move move) const;

    friend std::ostream &operator<<(std::ostream &os, const Board &board);

    ~Board();

private:
    const unsigned int rows, cols, k_in_a_row;
    Mark **fields;
};

#endif
