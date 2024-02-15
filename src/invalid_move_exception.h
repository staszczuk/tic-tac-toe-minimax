#ifndef INVALID_MOVE_EXCEPTION_H
#define INVALID_MOVE_EXCEPTION_H

#include <exception>

class InvalidMoveException : public std::exception
{
public:
    InvalidMoveException();

    const char *what() const noexcept override;
};

#endif
