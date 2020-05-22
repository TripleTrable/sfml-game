#include "game.hpp"
int main()
{
    Game *game = new Game();
    game->init();
    delete game;
    return 0;
}