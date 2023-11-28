#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <iostream>
#include "player.h"
#include "enemy.h"
#include "goblin.h"
#include "interactions.h"

int main()
{
    //Player p2;
    Goblin g1;
    sf::RenderWindow window(sf::VideoMode(1200, 600), "Window name");
    while(window.isOpen())
    {
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

    return 0;
}