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
