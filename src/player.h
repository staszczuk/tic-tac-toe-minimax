#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>

class Player
{
public:
    Player(char mark);

    friend std::ostream &operator<<(std::ostream &os, const Player &player);

private:
    const char mark;
};

#endif
