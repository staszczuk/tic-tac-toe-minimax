#include "random_player.h"

RandomPlayer::RandomPlayer() {}

void RandomPlayer::make_move(Board *board) const
{
    std::vector<Move> available_moves = board->get_available_moves();
    std::random_device random_dev;
    std::default_random_engine random_eng(random_dev());
    std::uniform_int_distribution<unsigned int>
        uniform_dist(0, available_moves.size() - 1);
    unsigned int move_index = uniform_dist(random_eng);
    board->make_move(available_moves.at(move_index), this->mark);
}
