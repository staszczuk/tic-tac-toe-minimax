#ifndef FIELD_H
#define FIELD_H

#include "player.h"

struct Field
{
    Field(unsigned int row, unsigned int col, Player *player = nullptr);

    friend std::ostream &operator<<(std::ostream &os, const Field &field);

    unsigned int row, col;
    Player *player;
};

#endif
