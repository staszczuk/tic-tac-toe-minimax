#include "game.h"

Game::Game(Player *player_x, Player *player_o, bool player_x_plays_first)
    : player_x(player_x), player_o(player_o)
{
    this->board = new Board();
    if (player_x_plays_first)
    {
        this->current_player = player_x;
    }
    else
    {
        this->current_player = player_o;
    }
    this->player_x->set_mark(Mark::x);
    this->player_o->set_mark(Mark::o);
}

void Game::start()
{
    while (true)
    {
        std::cout << *this->board << '\n';
        this->current_player->make_move(this->board);
        this->switch_players();
        GameState game_state = board->check_game_state();
        if (game_state != GameState::in_progress)
        {
            std::cout << *board << '\n';
            switch (game_state)
            {
            case GameState::player_x_won:
                std::cout << "Player x won\n";
                break;
            case GameState::player_o_won:
                std::cout << "Player o won\n";
                break;
            case GameState::draw:
                std::cout << "Draw\n";
                break;
            }
            break;
        }
    }
}

void Game::switch_players()
{
    if (this->current_player == this->player_x)
    {
        this->current_player = player_o;
    }
    else
    {
        this->current_player = player_x;
    }
}

Game::~Game()
{
    delete this->board;
}
