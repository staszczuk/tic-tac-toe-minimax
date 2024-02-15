#include <iostream>

#include "player.h"

int main()
{
    std::cout << "tic-tac-toe\n";
    Player *player_1 = new Player('x');
    Player *player_2 = new Player('o');
    std::cout << *player_1 << ' ' << *player_2 << '\n';
    delete player_1, player_2;
    return 0;
}
