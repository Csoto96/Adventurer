#include "player.h"

Player::Player()
{
    srand((unsigned) time(NULL));
    hp = 100;
    att = 10;
    armor = 12;
    blocking = false;
    name = "";
}

// Player::~Player()
// {

// }

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
