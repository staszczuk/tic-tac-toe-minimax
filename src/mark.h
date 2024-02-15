#ifndef MARK_H
#define MARK_H

#include <iostream>

enum class Mark
{
    empty,
    x,
    o
};

std::ostream &operator<<(std::ostream &os, const Mark &mark);

#endif
