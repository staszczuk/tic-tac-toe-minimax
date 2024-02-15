#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>

#include "mark.h"

class Player
{
public:
    Player(Mark mark);

    Mark get_mark() const;

    friend std::ostream &operator<<(std::ostream &os, const Player &player);

private:
    const Mark mark;
};

#endif
