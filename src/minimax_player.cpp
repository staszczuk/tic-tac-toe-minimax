#include "minimax_player.h"

MinimaxPlayer::MinimaxPlayer(Mark mark) : Player(mark)
{
    this->opponent_mark = this->mark == Mark::x ? Mark::o : Mark::x;
}

void MinimaxPlayer::make_move(Board *board) const
{
    int max_value = minus_inf;
    Move best_move(0, 0);
    for (Move move : board->get_available_moves())
    {
        board->make_move(move, this->mark);
        int minimax_value = this->minimax(board, false);
        std::cout << minimax_value << ' ';
        board->undo_move(move);
        if (minimax_value > max_value)
        {
            max_value = minimax_value;
            best_move = move;
        }
    }
    std::cout << '\n';
    board->make_move(best_move, this->mark);
}

int MinimaxPlayer::minimax(Board *board, bool maximizing_turn) const
{
    switch (board->check_game_state())
    {
    case GameState::player_x_won:
        return this->mark == Mark::x ? 1 : -1;
    case GameState::player_o_won:
        return this->mark == Mark::o ? 1 : -1;
    case GameState::draw:
        return 0;
    default:
        break;
    }
    if (maximizing_turn)
    {
        int value = minus_inf;
        for (Move move : board->get_available_moves())
        {
            Board *temp_board = new Board(*board);
            temp_board->make_move(move, this->mark);
            value = std::max(value, this->minimax(temp_board, false));
            delete temp_board;
        }
        return value;
    }
    else
    {
        int value = inf;
        for (Move move : board->get_available_moves())
        {
            Board *temp_board = new Board(*board);
            temp_board->make_move(move, this->opponent_mark);
            value = std::min(value, this->minimax(temp_board, true));
            delete temp_board;
        }
        return value;
    }
}
