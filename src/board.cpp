#include "board.h"

Board::Board(unsigned int rows, unsigned int cols, unsigned int k_in_a_row)
    : rows(rows), cols(cols), k_in_a_row(k_in_a_row)
{
    this->fields = new Mark *[this->rows];
    for (unsigned int row = 0; row < this->rows; row++)
    {
        this->fields[row] = new Mark[this->cols];
        for (unsigned int col = 0; col < this->cols; col++)
        {
            this->fields[row][col] = Mark::empty;
        }
    }
}

void Board::make_move(Move move, Player *player) const
{
    if (move.row >= this->rows or move.col >= this->cols)
    {
        throw InvalidMoveException();
    }
    if (this->fields[move.row][move.col]->player != nullptr)
    {
        throw InvalidMoveException();
    }
    this->fields[move.row][move.col]->player = player;
}

std::ostream &operator<<(std::ostream &os, const Board &board)
{
    for (unsigned int row = 0; row < board.rows; row++)
    {
        if (row != 0)
        {
            os << '\n';
        }
        for (unsigned int col = 0; col < board.cols; col++)
        {
            os << board.fields[row][col] << ' ';
        }
    }
    return os;
}

Board::~Board()
{
    for (unsigned int row = 0; row < this->rows; row++)
    {
        delete[] this->fields[row];
    }
    delete[] this->fields;
}
