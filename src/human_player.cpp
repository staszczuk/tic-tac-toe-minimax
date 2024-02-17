#include "human_player.h"

HumanPlayer::HumanPlayer() {}

void HumanPlayer::make_move(Board *board) const
{
    std::vector<Move> available_moves = board->get_available_moves();
    std::cout << "Choose move:\n";
    for (unsigned int i = 0; i < available_moves.size(); i++)
    {
        std::cout << i << ' ' << available_moves[i];
        if (i + 1 != available_moves.size())
        {
            std::cout << ", ";
        }
        else
        {
            std::cout << '\n';
        }
    }
    std::cout << "Choice (0 - " << available_moves.size() << "): ";
    unsigned int move_index;
    std::cin >> move_index;
    board->make_move(available_moves.at(move_index), this->mark);
}
