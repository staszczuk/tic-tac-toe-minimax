#ifndef RANDOM_PLAYER_H
#define RANDOM_PLAYER_H

#include <random>

#include "player.h"

class RandomPlayer : public Player
{
public:
    RandomPlayer();

    void make_move(Board *board) const override;
};

#endif
