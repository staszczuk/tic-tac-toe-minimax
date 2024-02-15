#include "player.h"

Player::Player(Mark mark) : mark(mark) {}

std::ostream &operator<<(std::ostream &os, const Player &player)
{
    os << player.mark;
    return os;
}
