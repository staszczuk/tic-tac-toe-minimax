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

Board::Board(const Board &board)
    : rows(board.rows), cols(board.cols), k_in_a_row(board.k_in_a_row)
{
    this->fields = new Mark *[this->rows];
    for (unsigned int row = 0; row < this->rows; row++)
    {
        this->fields[row] = new Mark[this->cols];
        for (unsigned int col = 0; col < this->cols; col++)
        {
            this->fields[row][col] = board.fields[row][col];
        }
    }
}

GameState Board::check_win() const
{
    // rows
    for (unsigned int row = 0; row < this->rows; row++)
    {
        Mark current = Mark::empty;
        unsigned int in_a_row = 0;
        for (unsigned int col = 0; col < this->cols; col++)
        {
            if (this->fields[row][col] == current)
            {
                in_a_row++;
                if (in_a_row == this->k_in_a_row)
                {
                    switch (current)
                    {
                    case Mark::x:
                        return GameState::player_x_won;
                        break;
                    case Mark::o:
                        return GameState::player_o_won;
                        break;
                    default:
                        break;
                    }
                }
            }
            else
            {
                current = this->fields[row][col];
                in_a_row = 1;
            }
        }
    }

    // cols
    for (unsigned int col = 0; col < this->cols; col++)
    {
        Mark current = Mark::empty;
        unsigned int in_a_row = 0;
        for (unsigned int row = 0; row < this->rows; row++)
        {
            if (this->fields[row][col] == current)
            {
                in_a_row++;
                if (in_a_row == this->k_in_a_row)
                {
                    switch (current)
                    {
                    case Mark::x:
                        return GameState::player_x_won;
                        break;
                    case Mark::o:
                        return GameState::player_o_won;
                        break;
                    default:
                        break;
                    }
                }
            }
            else
            {
                current = this->fields[row][col];
                in_a_row = 1;
            }
        }
    }

    for (unsigned int row = 0; row < this->rows - this->k_in_a_row + 1; row++)
    {
        // anti-diagonals
        for (unsigned int col = 0; col < this->cols - this->k_in_a_row + 1; col++)
        {
            Mark current = this->fields[row][col];
            bool won = true;
            for (unsigned int i = 1; i < this->k_in_a_row; i++)
            {
                if (this->fields[row + i][col + i] != current)
                {
                    won = false;
                    break;
                }
            }
            if (won)
            {
                switch (current)
                {
                case Mark::x:
                    return GameState::player_x_won;
                    break;
                case Mark::o:
                    return GameState::player_o_won;
                    break;
                default:
                    break;
                }
            }
        }

        // diagonals
        for (unsigned int col = this->cols - 1; col >= this->k_in_a_row - 1; col--)
        {
            Mark current = this->fields[row][col];
            bool won = true;
            for (unsigned int i = 1; i < this->k_in_a_row; i++)
            {
                if (this->fields[row + i][col - i] != current)
                {
                    won = false;
                    break;
                }
            }
            if (won)
            {
                switch (current)
                {
                case Mark::x:
                    return GameState::player_x_won;
                    break;
                case Mark::o:
                    return GameState::player_o_won;
                    break;
                default:
                    break;
                }
            }
        }
    }

    // tie
    if (this->get_available_moves().size() == 0)
    {
        return GameState::tie;
    }

    // no winner
    return GameState::unresolved;
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

void Board::undo_move(Move move) const
{
    if (move.row >= this->rows or move.col >= this->cols)
    {
        throw InvalidMoveException();
    }
    this->fields[move.row][move.col] = Mark::empty;
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
