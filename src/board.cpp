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

std::vector<Move> Board::get_available_moves() const
{
    std::vector<Move> available_moves;
    for (unsigned int row = 0; row < this->rows; row++)
    {
        for (unsigned int col = 0; col < this->cols; col++)
        {
            if (this->fields[row][col] == Mark::empty)
            {
                available_moves.push_back(Move(row, col));
            }
        }
    }
    return available_moves;
}

void Board::make_move(Move move, Mark mark) const
{
    if (move.row >= this->rows or move.col >= this->cols)
    {
        throw InvalidMoveException();
    }
    if (mark == Mark::empty)
    {
        throw InvalidMoveException();
    }
    this->fields[move.row][move.col] = mark;
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
