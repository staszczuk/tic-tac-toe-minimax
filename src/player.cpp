#include "player.h"

Player::Player() {}

Mark Player::get_mark() const
{
    return this->mark;
}

std::ostream &operator<<(std::ostream &os, const Player &player)
{
    os << player.mark;
    return os;
}

void Player::set_mark(Mark mark)
{
    this->mark = mark;
}
