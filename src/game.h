#ifndef GAME_H
#define GAME_H

#include "board.h"
#include "game_state.h"
#include "player.h"

class Game
{
public:
    Game(Player *player_x, Player *player_o, bool player_x_plays_first = true);

    void start();

    void switch_players();

    ~Game();

private:
    Board *board;
    Player *player_x, *player_o, *current_player;
};

#endif
