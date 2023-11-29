#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <iostream>
#include "player.h"
#include "enemy.h"
#include "goblin.h"
#include "interactions.h"
#include "game.h"

int main()
{
    Game game(1200,600,"Adventurer");
    Player p2;
    Goblin g1;
    int screenEvent = 0;
    while(game.isRunning())
    {
        game.events();

    }
    return 0;
}