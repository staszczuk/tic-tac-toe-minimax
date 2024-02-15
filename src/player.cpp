#include "player.h"

Player::Player(Mark mark) : mark(mark) {}

Mark Player::get_mark() const
{
    return this->mark;
}

std::ostream &operator<<(std::ostream &os, const Player &player)
{
    os << player.mark;
    return os;
}
