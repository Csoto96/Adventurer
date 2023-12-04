#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <iostream>
#include "player.h"
#include "enemy.h"
#include "goblin.h"
#include "skeleton.h"
#include "interactions.h"
#include "game.h"
#include "button/button.h"
const time_t GLOBAL_TIME = time(nullptr);
int main()
{
    
    //Player p2;
    //Game game(1200,600,"Adventurer");
    Player p2;
    Goblin g1;
    Skeleton sk1;
    Button startB("Start",{600,400},{200,71},sf::Color::Red);
    Button attackB("Attack",{100,400},{200,71},sf::Color::Red);
    Button blockB("Block",{350,400},{200,71},sf::Color::Red);
    Button skillB("Skill",{600,400},{200,71},sf::Color::Red);
    Button restartB("Restart",{400,400},{200,71},sf::Color::Red);
    Button exitB{"Exit",{620,400},{200,71},sf::Color::Red};
    sf::Text deadText;
    sf::Text startText;
    sf::Text winText;
    sf::Font font;
    font.loadFromFile("button/college.ttf");
    startText.setFont(font);
    startText.setString("Adventurer");
    startText.setCharacterSize(100);
    startText.setFillColor(sf::Color::Red);
    startText.setPosition(350,100);
    deadText.setFont(font);
    deadText.setString("You Have Been Slain");
    deadText.setCharacterSize(80);
    deadText.setFillColor(sf::Color::Red);
    deadText.setPosition(150,100);
    winText.setFont(font);
    winText.setString("You Are Victorious!");
    winText.setCharacterSize(80);
    winText.setFillColor(sf::Color::Red);
    winText.setPosition(250,100);
    Game game(1200,600,"Adventurer");
    int current = 1;
    while(game.isRunning())
    {
        game.events();
        
        if(current == 1)
        {
            startScreen(p2,game,startB,startText,current);
        }
        if(current == 2)
        {
            goblinFight(p2,g1,game,attackB,blockB,skillB,current);
        }
        if(current == 3)
        {
            skeletonFight(p2,sk1,game,attackB,blockB,skillB,current);
        }
        if(current == 4)
        {
            winScreen(p2,game,restartB,exitB,winText,current);
        }
        if(current = 5)
        {
            deathScreen(p2,game,restartB,exitB,deadText,current);
        }
    }
//     sf::RenderWindow window(sf::VideoMode(1200, 600), "Window name");
//     while(window.isOpen())
//     {
//         std::cout << time(nullptr) - GLOBAL_TIME;
//         sf::Event event;
//         while(window.pollEvent(event))
//         {
//         if(event.type == sf::Event::Closed)
//         {
// // Close window button clicked.
//                 window.close();
//             }
//         }
//         window.clear();
//         // Draw here.
//         window.draw(g1.gob);
//         window.draw(p2.p1);
//         window.display();
//     }
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

    // int screenEvent = 0;
    // while(game.isRunning())
    // {
    //     game.events();

    // }
    return 0;
}