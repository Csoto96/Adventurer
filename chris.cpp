#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <iostream>
#include "player.h"
#include "enemy.h"
#include "goblin.h"
#include "interactions.h"
<<<<<<< HEAD
const time_t GLOBAL_TIME = time(nullptr);
int main()
{
    
    //Player p2;
=======
#include "game.h"

int main()
{
    Game game(1200,600,"Adventurer");
    Player p2;
>>>>>>> 8d18521f98b638d11d88c747544823e26d744593
    Goblin g1;
    int screenEvent = 0;
    while(game.isRunning())
    {
<<<<<<< HEAD
        std::cout << time(nullptr) - GLOBAL_TIME;
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
            // Close window button clicked.
                window.close();
            }
        }
        window.clear();
        // Draw here.
        window.draw(g1.gob);
        window.display();
    }
    // int turnOrder = 1;
    // attack(p2,e2,turnOrder); //1
    // changeTurn(turnOrder);//2
    // e2.eBlock();//2
    // changeTurn(turnOrder);//1
    // attack(p2,e2,turnOrder);//1
    // changeTurn(turnOrder);//2
    // attack(p2,e2,turnOrder);//2
    // changeTurn(turnOrder);//1
    // p2.pBlock();//1
    // changeTurn(turnOrder);//2
    // attack(p2,e2,turnOrder);//2
=======
        game.events();
>>>>>>> 8d18521f98b638d11d88c747544823e26d744593

    }
    return 0;
}