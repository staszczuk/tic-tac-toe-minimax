#include "human_player.h"

HumanPlayer::HumanPlayer() {}

void HumanPlayer::make_move(Board *board) const
{
    unsigned int row, col;
    std::cout << "your move [row col]: ";
    std::cin >> row >> col;
    for (Move move : board->get_available_moves())
    {
        if (move.row == row and move.col == col)
        {
            board->make_move(move, this->mark);
            return;
        }
    }
    std::cout << "invalid move. try again...\n";
    this->make_move(board);
}
