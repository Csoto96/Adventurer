#include "skeleton.h"

Skeleton::Skeleton()
{
    srand((unsigned) time(NULL));
    hp = 40;
    att = 10;
    armor = 10;
    blocking = false;
    name = "Skeleton";
    isHurt = false;
    if(!idleArt.loadFromFile("Monsters_Creatures_Fantasy/Skeleton/Idle.png") ||
       !attArt.loadFromFile("Monsters_Creatures_Fantasy/Skeleton/Attack.png") ||
       !deadArt.loadFromFile("Monsters_Creatures_Fantasy/Skeleton/Death.png") ||
       !hitArt.loadFromFile("Monsters_Creatures_Fantasy/Skeleton/Take Hit.png"))
    {
        exit(1);
    }
    skele.setTexture(idleArt);
    skele.setTextureRect(sf::IntRect(0,0,150,150));
    skele.setOrigin(150.f/2.f,150.f/2.f);
    skele.setPosition(750,275);
    skele.setScale({-3,3});
}

int Skeleton::eAttack()
{
    int store = Enemy::eAttack();
    return store;
}
int Skeleton::makeDecision()
{
    int turn = 1 + (rand() % 3);
    if(turn == 1 || (turn == 3 && isHurt == false))
    {
        return 1;
    }
    if(turn == 2)
    {
        return 2;
    }
    if(turn == 3 && isHurt == true)
    {
        return 3;
    }
    return 1;

}

int Skeleton::superAtt()
{
    int toHit = 3 + (rand() % 20);
    return toHit;
}

void Skeleton::hpCheck()
{
    if(hp <= 20)
    {
        isHurt = true;
    }
    else
    {
        isHurt = false;
    }
}

void Skeleton::blockCheck()
{
    if(blocking == true)
    {
        blocking = false;
    }
}