#include "level.h"

Level::Level() {
    // Load the level


};

void Level::loadLevel(sf::RenderWindow &window) {
    // Load the background parallax background files 1 through 4
    if (!background1.loadFromFile("Level Sprites/background1.png")) {
        std::cout << "Error loading background1.png" << std::endl;
    }
    if (!background2.loadFromFile("Level Sprites/background2.png")) {
        std::cout << "Error loading background2.png" << std::endl;
    }
    if (!background3.loadFromFile("Level Sprites/background3.png")) {
        std::cout << "Error loading background3.png" << std::endl;
    }
    if (!background4.loadFromFile("Level Sprites/background4a.png")) {
        std::cout << "Error loading background4.png" << std::endl;
    }
    // Set the background sprites to the textures
    background1Sprite.setTexture(background1);
    background2Sprite.setTexture(background2);
    background3Sprite.setTexture(background3);
    background4Sprite.setTexture(background4);
    //scale the background sprites by 1.5
    background1Sprite.setScale(1.5, 1.5);
    background2Sprite.setScale(1.5, 1.5);
    background3Sprite.setScale(1.5, 1.5);
    background4Sprite.setScale(1.5, 1.5);
    //load "mainlev_build.png" into block1, block2, block3, and block4
    if (!tileSheet.loadFromFile("Level Sprites/mainlev_build.png")) {
        std::cout << "Error loading mainlev_build.png" << std::endl;
    }
    block1.setTexture(tileSheet);
    block2.setTexture(tileSheet);
    block3.setTexture(tileSheet);
    block4.setTexture(tileSheet);
    block5.setTexture(tileSheet);
    block6.setTexture(tileSheet);
    block7.setTexture(tileSheet);
    block8.setTexture(tileSheet);
    block9.setTexture(tileSheet);
    block10.setTexture(tileSheet);
    block11.setTexture(tileSheet);
    block12.setTexture(tileSheet);
    block13.setTexture(tileSheet);
    block14.setTexture(tileSheet);
    block15.setTexture(tileSheet);
    block16.setTexture(tileSheet);
    //setting the specific textures from the tile sheet to the blocks
    block1.setTextureRect(sf::IntRect(224, 367, 32, 33));
    block2.setTextureRect(sf::IntRect(336, 367, 32, 33));
    block3.setTextureRect(sf::IntRect(384, 367, 32, 33));
    block4.setTextureRect(sf::IntRect(432, 367, 32, 33));
    block1.setScale(3,3);
    block2.setScale(3,3);
    block3.setScale(3,3);
    block4.setScale(3,3);
    //more duplicate code to make more blocks
    block5.setTextureRect(sf::IntRect(224, 367, 32, 33));
    block6.setTextureRect(sf::IntRect(336, 367, 32, 33));
    block7.setTextureRect(sf::IntRect(384, 367, 32, 33));
    block8.setTextureRect(sf::IntRect(432, 367, 32, 33));
    block9.setTextureRect(sf::IntRect(224, 367, 32, 33));
    block10.setTextureRect(sf::IntRect(336, 367, 32, 33));
    block11.setTextureRect(sf::IntRect(384, 367, 32, 33));
    block12.setTextureRect(sf::IntRect(432, 367, 32, 33));
    block13.setTextureRect(sf::IntRect(336, 367, 32, 33));
    block14.setTextureRect(sf::IntRect(384, 367, 32, 33));
    block15.setTextureRect(sf::IntRect(432, 367, 32, 33));
    block16.setTextureRect(sf::IntRect(336, 367, 32, 33));
    
    block5.setScale(3,3);
    block6.setScale(3,3);
    block7.setScale(3,3);
    block8.setScale(3,3);
    block9.setScale(3,3);
    block10.setScale(3,3);
    block11.setScale(3,3);
    block12.setScale(3,3);
    block13.setScale(3,3);
    block14.setScale(3,3);
    block15.setScale(3,3);
    block16.setScale(3,3);

    block1.setPosition(0, WINDOW_HEIGHT - 32*3);
    block2.setPosition(32*3, WINDOW_HEIGHT - 32*3);
    block3.setPosition(32*6, WINDOW_HEIGHT - 32*3);
    block4.setPosition(32*9, WINDOW_HEIGHT - 32*3);
    block5.setPosition(32*12, WINDOW_HEIGHT - 32*3);
    block6.setPosition(32*15, WINDOW_HEIGHT - 32*3);
    block7.setPosition(32*18, WINDOW_HEIGHT - 32*3);
    block8.setPosition(32*21, WINDOW_HEIGHT - 32*3);
    block9.setPosition(32*24, WINDOW_HEIGHT - 32*3);
    block10.setPosition(32*27, WINDOW_HEIGHT - 32*3);
    block11.setPosition(32*30, WINDOW_HEIGHT - 32*3);
    block12.setPosition(32*33, WINDOW_HEIGHT - 32*3);
    block13.setPosition(32*36, WINDOW_HEIGHT - 32*3);
    block14.setPosition(32*39, WINDOW_HEIGHT - 32*3);
    block15.setPosition(32*42, WINDOW_HEIGHT - 32*3);
    block16.setPosition(32*45, WINDOW_HEIGHT - 32*3);
    

};

void Level::drawLevel(sf::RenderWindow &window) {

    // Draw the background sprites to the window
    window.draw(background1Sprite);
    window.draw(background2Sprite);
    window.draw(background3Sprite);
    window.draw(background4Sprite);
    // Draw the blocks to the window
    window.draw(block1);
    window.draw(block2);
    window.draw(block3);
    window.draw(block4);
    window.draw(block5);
    window.draw(block6);
    window.draw(block7);
    window.draw(block8);
    window.draw(block9);
    window.draw(block10);
    window.draw(block11);
    window.draw(block12);
    window.draw(block13);
    window.draw(block14);
    window.draw(block15);
    window.draw(block16);

    //animated the blocks to scroll to the left
    float scrollSpeed = 1.0f;  // Adjust this value to change the speed of scrolling

    // List of all blocks
    sf::Sprite* blocks[] = {&block1, &block2, &block3, &block4, &block5, &block6, &block7, &block8, &block9, &block10, &block11, &block12, &block13, &block14, &block15, &block16};

    // Move and draw each block
    for (sf::Sprite* block : blocks) {
    // Move the block to the left
    block->move(-scrollSpeed, 0);

    // If the block has moved off the screen, move it back to the right edge
    if (block->getPosition().x < -block->getGlobalBounds().width) {
        block->setPosition(window.getSize().x, block->getPosition().y);
    }

    // Draw the block to the window
    window.draw(*block);
}

};

void Level::animatePlayer(sf::RenderWindow &window) {

    player.setTexture(playerTexture);
    player.setTextureRect(sf::IntRect(46, 18, 46, 46));
    player.setScale(3,3);
    int currentFrame = 0;
    sf::Clock frameClock;
    int frameWidth = 46;
    int frameHeight = 46;
    int frameCount = 10;
    float timePerFrame = 0.1f;

    if (frameClock.getElapsedTime().asSeconds() > timePerFrame) {
    currentFrame = (currentFrame + 1) % frameCount;
    frameClock.restart();
    }
    
    if(!playerTexture.loadFromFile("New Player Sprite/Run.png")) {
        std::cout << "Error loading run.png" << std::endl;
    }

    player.setTextureRect(sf::IntRect(currentFrame * frameWidth, 0, frameWidth, frameHeight));
    player.setPosition(0, WINDOW_HEIGHT - 32*3 - 46*3);


    window.draw(player);


};