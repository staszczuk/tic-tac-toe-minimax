#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>

#include "mark.h"

class Player
{
public:
    Player(Mark mark);

    friend std::ostream &operator<<(std::ostream &os, const Player &player);

private:
    const Mark mark;
};

#endif
