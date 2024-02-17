#ifndef MINIMAX_PLAYER_H
#define MINIMAX_PLAYER_H

#include "player.h"

const int inf = 2;
const int minus_inf = -2;

class MinimaxPlayer : public Player
{
public:
    MinimaxPlayer(Mark mark);

    void make_move(Board *board) const override;

private:
    int minimax(Board *board, bool maximizing_turn) const;

    Mark opponent_mark;
};

#endif
