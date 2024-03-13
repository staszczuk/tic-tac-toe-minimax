#ifndef RANDOM_PLAYER_H
#define RANDOM_PLAYER_H

#include "player.h"

#include <random>

class RandomPlayer : public Player
{
public:
    RandomPlayer();

    void make_move(Board *board) const override;
};

#endif
