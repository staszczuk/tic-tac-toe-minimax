#include <iostream>

#include "human_player.h"
#include "mark.h"
#include "minimax_player.h"
#include "game.h"

int main()
{
    std::cout << "tic-tac-toe\n";
    Player *player_x = new HumanPlayer();
    Player *player_o = new MinimaxPlayer();
    Game *game = new Game(player_x, player_o);
    game->start();
    return 0;
}
