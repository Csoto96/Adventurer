#include "enemy.h"
#include <chrono>
Enemy::Enemy()
{
    srand((unsigned) time(NULL));
    hp = 100;
    att = 10;
    armor = 10;
    blocking = false;
    name = "";
}

// Enemy::~Enemy()
// {

// }

int Enemy::eAttack()
{
    int toHit = 1 + (rand() % 20);
    std::cout << "rolled " << toHit << std::endl;
    return toHit;
}

bool Enemy::eHit(int hit)
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

void Enemy::eDam(int damage)
{
    hp = hp - damage;
}

void Enemy::eBlock()
{
    std::cout << "Enemy Blocking!" << std::endl;
    blocking = true;
}

int Enemy::getEAtt()
{
    return att;
}

int Enemy::getEHp()
{
    return hp;
}