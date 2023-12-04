#ifndef LEVEL_H
#define LEVEL_H

#include <SFML/Graphics.hpp>
#include <iostream>

//universal window size of program
const int WINDOW_WIDTH = 1440;
const int WINDOW_HEIGHT = 720;
// make a class that loads the background images and displays them in the window in the correct order for a parallax effect located in the "Level Sprites" folder
class Level {
    public:
        Level();
        void loadLevel(sf::RenderWindow &window);
        void drawLevel(sf::RenderWindow &window);
        void animatePlayer(sf::RenderWindow &window);
    private:
        sf::Texture background1;
        sf::Texture background2;
        sf::Texture background3;
        sf::Texture background4;
        sf::Sprite background1Sprite;
        sf::Sprite background2Sprite;
        sf::Sprite background3Sprite;
        sf::Sprite background4Sprite;

        sf::Texture tileSheet;
        sf::Sprite block1;
        sf::Sprite block2;
        sf::Sprite block3;
        sf::Sprite block4;
        sf::Sprite block5;
        sf::Sprite block6;
        sf::Sprite block7;
        sf::Sprite block8;
        sf::Sprite block9;
        sf::Sprite block10;
        sf::Sprite block11;
        sf::Sprite block12;
        sf::Sprite block13;
        sf::Sprite block14;
        sf::Sprite block15;
        sf::Sprite block16;

        sf::Texture playerTexture;
        sf::Sprite player;
        

};


#endif
