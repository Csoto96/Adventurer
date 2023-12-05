#include "interactions.h"

void attack(Player &player,Enemy &enemy, int turn)
{
    //player turn
    if(turn == 1)
    {
        std::cout << "Player is Attacking" << std::endl;
        player.animationAttack();
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

void goblinFight(Player &player, Goblin &goblin , Game &game, Button &abutton,Button &blbutton,Button &skbutton, int &currentScreen)
{
    sf::RectangleShape background1({1200,600}), background2({1200,600}), background3({1200,600}), background4({1200,600}), background5({1200,600});
    sf::Texture b1Art , b2Art, b3Art , b4Art , b5Art;
    sf::Text playerHp, enemyHp;
    sf::Font font;
    font.loadFromFile("button/college.ttf");
    playerHp.setFont(font);
    enemyHp.setFont(font);
    playerHp.setCharacterSize(30);
    enemyHp.setCharacterSize(30);
    playerHp.setFillColor(sf::Color::Red);
    enemyHp.setFillColor(sf::Color::Red);
    playerHp.setString(std::to_string(player.getPHp()));
    enemyHp.setString(std::to_string(goblin.getEHp()));
    playerHp.setPosition({235,165});
    enemyHp.setPosition({725,200});
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
    int turnOrder = 1;
    while(player.getPHp() > 0 || goblin.getEHp() > 0)
    {
        game.events();
        static bool lockClick;
        abutton.update(game.e,game.window);
        blbutton.update(game.e,game.window);
        skbutton.update(game.e,game.window);
        player.update();
        playerHp.setString(std::to_string(player.getPHp()));
        enemyHp.setString(std::to_string(goblin.getEHp()));
        game.clear();
        game.draw(background1);
        game.draw(background2);
        game.draw(background3);
        game.draw(background4);
        game.draw(abutton.mButton);
        game.draw(blbutton.mButton);
        game.draw(skbutton.mButton);
        game.draw(abutton.mText);
        game.draw(blbutton.mText);
        game.draw(skbutton.mText);
        game.draw(player.p1);
        game.draw(goblin.gob);
        game.draw(playerHp);
        game.draw(enemyHp);
        game.display();
        if(game.e.type == sf::Event::MouseButtonPressed)
        {
            if(game.e.mouseButton.button == sf::Mouse::Left && lockClick != true)
            {
        if(turnOrder == 1)
        {
            if(abutton.mBtnState == clicked)
            {
                attack(player,goblin,turnOrder);
                turnOrder = 2;
            }
            if(blbutton.mBtnState == clicked)
            {
                player.pBlock();
                turnOrder = 2;
            }
            if(skbutton.mBtnState == clicked)
            {
                player.skillHeal();
                turnOrder = 2;
            }
            goblin.hpCheck();
            goblin.blockCheck();
        }
                if(turnOrder == 2 )
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
            lockClick = true;
            }
        }
        if(game.e.type == sf::Event::MouseButtonReleased)
        {
            if(game.e.mouseButton.button == sf::Mouse::Left)
            {
                lockClick = false;
            }
        }
        if(player.getPHp() <= 0)
        {
            break;
        }
        if(goblin.getEHp() <= 0)
        {
            break;
        }
    }
        
    if(player.getPHp() <= 0)
    {
        currentScreen = 5;   
    }
    else
    {
        currentScreen = 3;
    }
    
}

void skeletonFight(Player &player, Skeleton &skeleton , Game &game, Button &abutton,Button &blbutton,Button &skbutton, int &currentScreen)
{
    sf::RectangleShape background1({1200,600}), background2({1200,600}), background3({1200,600}), background4({1200,600}), background5({1200,600});
    sf::Texture b1Art , b2Art, b3Art , b4Art , b5Art;
    sf::Text playerHp, enemyHp;
    sf::Font font;
    font.loadFromFile("button/college.ttf");
    playerHp.setFont(font);
    enemyHp.setFont(font);
    playerHp.setCharacterSize(30);
    enemyHp.setCharacterSize(30);
    playerHp.setFillColor(sf::Color::Red);
    enemyHp.setFillColor(sf::Color::Red);
    playerHp.setString(std::to_string(player.getPHp()));
    enemyHp.setString(std::to_string(skeleton.getEHp()));
    playerHp.setPosition({235,165});
    enemyHp.setPosition({715,165});
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
    int turnOrder = 1;
    while(player.getPHp() > 0 || skeleton.getEHp() > 0)
    {
        game.events();
        static bool lockClick;
        abutton.update(game.e,game.window);
        blbutton.update(game.e,game.window);
        skbutton.update(game.e,game.window);
        playerHp.setString(std::to_string(player.getPHp()));
        enemyHp.setString(std::to_string(skeleton.getEHp()));
        game.clear();
        game.draw(background1);
        game.draw(background2);
        game.draw(background3);
        game.draw(background4);
        game.draw(abutton.mButton);
        game.draw(blbutton.mButton);
        game.draw(skbutton.mButton);
        game.draw(abutton.mText);
        game.draw(blbutton.mText);
        game.draw(skbutton.mText);
        game.draw(player.p1);
        game.draw(skeleton.skele);
        game.draw(playerHp);
        game.draw(enemyHp);
        game.display();
        if(game.e.type == sf::Event::MouseButtonPressed)
        {
            if(game.e.mouseButton.button == sf::Mouse::Left && lockClick != true)
            {
        if(turnOrder == 1)
        {
            if(abutton.mBtnState == clicked)
            {
                attack(player,skeleton,turnOrder);
                turnOrder = 2;
            }
            if(blbutton.mBtnState == clicked)
            {
                player.pBlock();
                turnOrder = 2;
            }
            if(skbutton.mBtnState == clicked)
            {
                player.skillHeal();
                turnOrder = 2;
            }
            skeleton.hpCheck();
            skeleton.blockCheck();
        }
                if(turnOrder == 2 )
                {
                    switch (skeleton.makeDecision())
                    {
                    case 1:
                        attack(player,skeleton,turnOrder);
                        break;
                    case 2:
                        skeleton.eBlock();
                        break;
                    case 3:
                        superAttack(player,skeleton);
                        break;
                    default:
                        break;
                    }
            turnOrder = 1;
            player.blockCheck();
                } 
            lockClick = true;
            }
        }
        if(game.e.type == sf::Event::MouseButtonReleased)
        {
            if(game.e.mouseButton.button == sf::Mouse::Left)
            {
                lockClick = false;
            }
        }
        if(player.getPHp() <= 0)
        {
            break;
        }
        if(skeleton.getEHp() <= 0)
        {
            break;
        }
    }
        
    if(player.getPHp() <= 0)
    {
        currentScreen = 5;   
    }
    else
    {
        currentScreen = 4;
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

void superAttack(Player &player, Skeleton &skeleton)
{
    std::cout << "Enemy is Attacking" << std::endl;
        if(player.pHit(skeleton.superAtt()) == true)
        {
            player.pDam(skeleton.getEAtt()*2);
            std::cout << "Hit " << std::endl;
            std::cout << player.getPHp() << std::endl;
            std::cout << skeleton.getEHp() << std::endl;
        }
        else
        {
            std::cout <<"Miss " << std::endl;
            std::cout << player.getPHp() << std::endl;
            std::cout << skeleton.getEHp() << std::endl;
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
        game.draw(button.mText);
        game.draw(start);
        game.draw(player.p1);
        game.display();
        if(button.mBtnState == clicked)
        {
            currentScreen = 2;
        }

    }
    
}

void deathScreen(Player &player, Game &game, Button &rbutton,Button &ebutton, sf::Text &dead,int &currentScreen)
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
    while(currentScreen == 5)
    {
        game.events(); 
        rbutton.update(game.e,game.window);
        ebutton.update(game.e,game.window);
        game.clear();
        game.draw(background1);
        game.draw(background2);
        game.draw(background3);
        game.draw(background4);
        game.draw(rbutton.mButton);
        game.draw(rbutton.mText);
        game.draw(ebutton.mButton);
        game.draw(ebutton.mText);
        game.draw(dead);
        game.draw(player.p1);
        game.display();
        if(rbutton.mBtnState == clicked)
        {
            currentScreen = 1;
            //player.hp = 100;
        }
        if(ebutton.mBtnState == clicked)
        {
            exit(1);
        }

    }
}

void winScreen(Player &player, Game &game, Button &rbutton,Button &ebutton, sf::Text &win,int &currentScreen)
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
    while(currentScreen == 4)
    {
        game.events(); 
        rbutton.update(game.e,game.window);
        ebutton.update(game.e,game.window);
        game.clear();
        game.draw(background1);
        game.draw(background2);
        game.draw(background3);
        game.draw(background4);
        game.draw(rbutton.mButton);
        game.draw(rbutton.mText);
        game.draw(ebutton.mButton);
        game.draw(ebutton.mText);
        game.draw(win);
        game.draw(player.p1);
        game.display();
        if(rbutton.mBtnState == clicked)
        {
            currentScreen = 1;
            //player.hp = 100;
        }
        if(ebutton.mBtnState == clicked)
        {
            exit(1);
        }

    }
}

void interlude(Level &level, Game &game)
{
    sf::Clock animateTimer;
    while(1)
    {
        game.events();
        game.clear();
        level.drawLevel(game.window);
        level.animatePlayer(game.window);
        game.display();
        if(animateTimer.getElapsedTime().asSeconds() > 2)
        {
            break;
        }
    }
}