#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <string>

class Game
{
    public:
        Game(int winSizeX, int winSizeY, std::string gameName);
        ~Game(){}
        void events();
        void display();
        unsigned int getWindowSize(std::string xy);
        bool isRunning();
        void draw(sf::Sprite &s);
        void draw(sf::Text &t);
        void draw(sf::RectangleShape &r);
        void clear();
        sf::Event e;
        sf::RenderWindow window;
};

#endif