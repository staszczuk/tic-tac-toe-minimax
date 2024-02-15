#include "mark.h"

std::ostream &operator<<(std::ostream &os, const Mark &mark)
{
    switch (mark)
    {
    case Mark::empty:
        os << '_';
        break;
    case Mark::x:
        os << 'x';
        break;
    case Mark::o:
        os << 'o';
        break;
    }
    return os;
}
