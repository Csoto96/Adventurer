#include "player.h"

Player::Player()
{
    srand((unsigned) time(NULL));
    hp = 100;
    att = 10;
    armor = 12;
    blocking = false;
    name = "";
    if(!pArt.loadFromFile("Game Assets/Sprites/Player/PNG/Idle/idle-with-weapon-1.png"))
    {
        exit(1);
    }
    p1.setTexture(pArt);
    p1.setTextureRect(sf::IntRect(0,0,128,96));
    p1.setOrigin(128.f/2.f,96.f/2.f);
    p1.setPosition(250,400);
}

int Player::pAttack()
{
    int toHit = 1 + (rand() % 20);
    std::cout << "rolled " << toHit << std::endl;
    return toHit;
}

bool Player::pHit(int hit)
{
    if(blocking == true)
    {
        std::cout << "Blocked!" << std::endl;
        blocking = false;
        return false;
    }
    if(hit >= armor)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void Player::pDam(int damage)
{
    hp = hp - damage;
}

void Player::pBlock()
{
    std::cout << "Player Blocking!" << std::endl;
    blocking = true;
}

int Player::getPAtt()
{
    return att;
}

int Player::getPHp()
{
    return hp;
}

void Player::blockCheck()
{
    if(blocking == true)
    {
        blocking = false;
    }
}

void Player::skillHeal()
{
    if(hp < 100)
    {
        if(hp+10 >= 100)
        {
            hp = 100;
        } 
        else
        {
            hp = hp+10;
        }
    }
    
}
