#include <iostream>

#include "board.h"
#include "player.h"

int main()
{
    std::cout << "tic-tac-toe\n";
    Player *player_1 = new Player('x');
    Player *player_2 = new Player('o');
    Board *board = new Board();
    board->make_move(Move(0, 1), player_1);
    std::cout << *board << '\n';
    delete player_1, player_2, board;
    return 0;
}
