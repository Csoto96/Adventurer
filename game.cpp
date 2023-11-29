#include "game.h"

Game::Game(int winSizeX, int winSizeY, std::string gameName){
    window.create(sf::VideoMode(winSizeX,winSizeY), gameName);
}

void Game::events(){
    while(window.pollEvent(e)){
        if (e.type == e.Closed){
            window.close();
            exit(0);
        }
    }
}

void Game::display(){
    window.display();
}

unsigned int Game::getWindowSize(std::string xy){
    if(xy == "x"){
        return window.getSize().x;
    } else if(xy == "y"){
        return window.getSize().y;
    }
    return 0;
}

bool Game::isRunning(){
    if(window.isOpen())
        return true;
    
    return false;
}

void Game::draw(sf::Sprite &s){
    window.draw(s);
}

void Game::draw(sf::RectangleShape &r){
    window.draw(r);
}

void Game::clear(){
    window.clear();
}

void Game::draw(sf::Text &t){
    window.draw(t);
}