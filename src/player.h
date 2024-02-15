#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>

#include "board.h"
#include "mark.h"

class Player
{
public:
    Player(Mark mark);

    Mark get_mark() const;

    virtual void make_move(Board *board) const = 0;

    friend std::ostream &operator<<(std::ostream &os, const Player &player);

private:
    const Mark mark;
};

#endif
