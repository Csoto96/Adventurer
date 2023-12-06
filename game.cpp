/**
 * @file game.cpp
 * @author chris
 * @brief game class functions file
 * @version 0.1
 * @date 2023-12-01
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "game.h"
/**
 * @brief Construct a new Game:: Game object
 * 
 * @param winSizeX 
 * @param winSizeY 
 * @param gameName 
 */
Game::Game(int winSizeX, int winSizeY, std::string gameName){
    window.create(sf::VideoMode(winSizeX,winSizeY), gameName);
}
/**
 * @brief handles events from window
 * 
 */
void Game::events(){
    while(window.pollEvent(e)){
        if (e.type == e.Closed){
            window.close();
            exit(0);
        }
    }
}
/**
 * @brief displays what is drawn to window
 * 
 */
void Game::display(){
    window.display();
}
/**
 * @brief returns window size for functions
 * 
 * @param xy 
 * @return unsigned int 
 */
unsigned int Game::getWindowSize(std::string xy){
    if(xy == "x"){
        return window.getSize().x;
    } else if(xy == "y"){
        return window.getSize().y;
    }
    return 0;
}
/**
 * @brief determines if window is open 
 * 
 * @return true 
 * @return false 
 */
bool Game::isRunning(){
    if(window.isOpen())
        return true;
    
    return false;
}
/**
 * @brief draws sprites to window
 * 
 * @param s 
 */
void Game::draw(sf::Sprite &s){
    window.draw(s);
}
/**
 * @brief draws rectangles to window
 * 
 * @param r 
 */
void Game::draw(sf::RectangleShape &r){
    window.draw(r);
}
/**
 * @brief clears window of drawings
 * 
 */
void Game::clear(){
    window.clear(sf::Color::Black);
}
/**
 * @brief draws text to window
 * 
 * @param t 
 */
void Game::draw(sf::Text &t){
    window.draw(t);
}