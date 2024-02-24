#include "Game.h"
#include <iostream>
int main()
{
    Game game;

    while (game.isRunning())
    {
        game.pollEvent();

        game.update();

        game.render();
    }

    return 0;
}

