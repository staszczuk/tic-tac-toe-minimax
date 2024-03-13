#ifndef PLAYER_H
#define PLAYER_H

#include "board.h"
#include "mark.h"

#include <iostream>

class Player
{
public:
    Player();

    Mark get_mark() const;

    virtual void make_move(Board *board) const = 0;

    virtual void set_mark(Mark mark);

    friend std::ostream &operator<<(std::ostream &os, const Player &player);

protected:
    Mark mark;
};

#endif
