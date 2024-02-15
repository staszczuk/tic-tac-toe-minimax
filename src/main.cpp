#include <iostream>

#include "board.h"
#include "human_player.h"
#include "mark.h"

int main()
{
    std::cout << "tic-tac-toe\n";
    Player *player_x = new HumanPlayer(Mark::x);
    Board *board = new Board();
    player_x->make_move(board);
    std::cout << *board << '\n';
    return 0;
}
