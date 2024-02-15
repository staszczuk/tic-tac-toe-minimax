#include "field.h"

Field::Field(unsigned int row, unsigned int col, Player *player)
    : row(row), col(col), player(player) {}

std::ostream &operator<<(std::ostream &os, const Field &field)
{
    if (field.player != nullptr)
    {
        os << *field.player;
    }
    else
    {
        os << '_';
    }
    return os;
}
