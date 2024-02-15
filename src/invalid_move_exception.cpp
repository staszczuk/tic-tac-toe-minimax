#include "invalid_move_exception.h"

InvalidMoveException::InvalidMoveException() {}

const char *InvalidMoveException::what() const noexcept
{
    return "Invalid move";
}
