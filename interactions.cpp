#include "interactions.h"

void attack(Player &player,Enemy &enemy, int turn)
{
    //player turn
    if(turn == 1)
    {
        std::cout << "Player is Attacking" << std::endl;
        if(enemy.eHit(player.pAttack()) == true)
        {
            enemy.eDam(player.getPAtt());
            std::cout << "Hit " << std::endl;
            std::cout << player.getPHp() << std::endl;
            std::cout << enemy.getEHp() << std::endl;
        }
        else
        {
            std::cout <<"Miss " << std::endl;
            std::cout << player.getPHp() << std::endl;
            std::cout << enemy.getEHp() << std::endl;
        }
    }
    //enemy turn
    if(turn == 2)
    {
        std::cout << "Enemy is Attacking" << std::endl;
        if(player.pHit(enemy.eAttack()) == true)
        {
            player.pDam(enemy.getEAtt());
            std::cout << "Hit " << std::endl;
            std::cout << player.getPHp() << std::endl;
            std::cout << enemy.getEHp() << std::endl;
        }
        else
        {
            std::cout <<"Miss " << std::endl;
            std::cout << player.getPHp() << std::endl;
            std::cout << enemy.getEHp() << std::endl;
        }
    }
}

void goblinFight(Player &player, Goblin &goblin , Game &game)
{
    int turnOrder = 1;
    while(player.getPHp() > 0 || goblin.getEHp() > 0)
    {
        game.events();
        if(turnOrder == 1)
        {

            goblin.hpCheck();
            goblin.blockCheck();
            turnOrder = 2;
        }
        if(turnOrder == 2)
        {
            switch (goblin.makeDecision())
            {
            case 1:
                attack(player,goblin,turnOrder);
                break;
            case 2:
                goblin.eBlock();
                break;
            case 3:
                superAttack(player,goblin);
                break;
            default:
                break;
            }
            turnOrder = 1;
            player.blockCheck();
        }
        
    }
}

void superAttack(Player &player, Goblin &goblin)
{
    std::cout << "Enemy is Attacking" << std::endl;
        if(player.pHit(goblin.superAtt()) == true)
        {
            player.pDam(goblin.getEAtt()*2);
            std::cout << "Hit " << std::endl;
            std::cout << player.getPHp() << std::endl;
            std::cout << goblin.getEHp() << std::endl;
        }
        else
        {
            std::cout <<"Miss " << std::endl;
            std::cout << player.getPHp() << std::endl;
            std::cout << goblin.getEHp() << std::endl;
        }

}

void startScreen(Player &player, Game &game, Button &button, sf::Text &start, int &currentScreen)
{
    sf::RectangleShape background1({1200,600}), background2({1200,600}), background3({1200,600}), background4({1200,600}), background5({1200,600});
    sf::Texture b1Art , b2Art, b3Art , b4Art , b5Art;
    b1Art.loadFromFile("Game Assets/Level Sprites/background1.png");
    b2Art.loadFromFile("Game Assets/Level Sprites/background2.png");
    b3Art.loadFromFile("Game Assets/Level Sprites/background3.png");
    b4Art.loadFromFile("Game Assets/Level Sprites/background4a.png");
    b5Art.loadFromFile("Game Assets/Level Sprites/background4b.png");
    background1.setTexture(&b1Art);
    background2.setTexture(&b2Art);
    background3.setTexture(&b3Art);
    background4.setTexture(&b4Art);
    background5.setTexture(&b5Art);
    while(currentScreen == 1)
    {
        game.events(); 
        button.update(game.e,game.window);
        game.clear();
        game.draw(background1);
        game.draw(background2);
        game.draw(background3);
        game.draw(background4);
        game.draw(button.mButton);
        game.draw(start);
        game.draw(player.p1);
        game.display();
        if(button.mBtnState == clicked)
        {
            currentScreen = 2;
        }

    }
    
}