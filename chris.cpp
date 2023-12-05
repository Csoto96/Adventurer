#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cstdlib>
#include <iostream>
#include "player.h"
#include "enemy.h"
#include "goblin.h"
#include "skeleton.h"
#include "interactions.h"
#include "game.h"
#include "button/button.h"
#include "level.h"
const time_t GLOBAL_TIME = time(nullptr);
int main()
{
    Player p2;
    Goblin g1;
    Skeleton sk1;
    Level level;
    // sf::Music startM, battleM;
    // sf::SoundBuffer sM, bM;
    // startM.openFromFile("Game Assets/Music/Minifantasy_Dungeon_Music/Music/Goblins_Den_(Regular).wav");
    // battleM.openFromFile("Game Assets/Music/Minifantasy_Dungeon_Music/Music/Goblins_Dance_(Battle).wav");
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
    deadText.setPosition(200,100);
    winText.setFont(font);
    winText.setString("You Are Victorious!");
    winText.setCharacterSize(80);
    winText.setFillColor(sf::Color::Red);
    winText.setPosition(250,100);
    Game game(WINDOW_WIDTH,WINDOW_HEIGHT,"Adventurer");
    level.loadLevel(game.window);
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
            interlude(level,game);
            goblinFight(p2,g1,game,attackB,blockB,skillB,current);
        }
        if(current == 3)
        {
            interlude(level,game);
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
    
    return 0;
}