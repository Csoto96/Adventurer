#include <SFML/Graphics.hpp>
#include "level.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH,WINDOW_HEIGHT), "SFML works!");

    Level level;
    level.loadLevel(window);
    sf::Event event;
    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();
        level.drawLevel(window);
        level.animatePlayer(window);
        window.display();
    }

    return 0;
}