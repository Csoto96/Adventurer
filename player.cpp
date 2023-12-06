/**
 * @file player.cpp
 * @author chris/david
 * @brief player functions class file
 * @version 0.1
 * @date 2023-12-01
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "player.h"
/**
 * @brief Construct a new Player:: Player object
 * 
 */
Player::Player()
{
    srand((unsigned) time(NULL));
    hp = 100;
    att = 10;
    armor = 12;
    blocking = false;
    name = "";
    if(!pArt.loadFromFile("Game Assets/Sprites/New Player Sprite/Idle.png"))
    {
        exit(1);
    }
    if(!p1Attack.loadFromFile("Game Assets/Sprites/New Player Sprite/Attacks.png"))
    {
        exit(1);
    }
    if(!p1Dead.loadFromFile("Game Assets/Sprites/New Player Sprite/Death.png"))
    {
        exit(1);
    }
    if(!p1Win.loadFromFile("Game Assets/Sprites/New Player Sprite/Pray.png"))
    {
        exit(1);
    }
    p1.setTexture(pArt);
    p1.setTextureRect(sf::IntRect(0,0,128,64));
    rect = sf::IntRect(0,0,128,64);
    p1.setOrigin(128.f/2.f,96.f/2.f);
    p1.setPosition(250,300);
    p1.setScale({3,3});
    frame = 0;
    isAttacking = -1;
}
/**
 * @brief rolls to hit enemy minimum 1
 * 
 * @return int 
 */
int Player::pAttack()
{
    int toHit = 1 + (rand() % 20);
    return toHit;
    isAttacking = 9;
}
/**
 * @brief determines if player was hit by enemy
 * 
 * @param hit 
 * @return true 
 * @return false 
 */
bool Player::pHit(int hit)
{
    if(blocking == true)
    {
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
/**
 * @brief deals damage to player
 * 
 * @param damage 
 */
void Player::pDam(int damage)
{
    hp = hp - damage;
}
/**
 * @brief turns on blocking
 * 
 */
void Player::pBlock()
{
    blocking = true;
}
/**
 * @brief returns attack for neutral functions
 * 
 * @return int 
 */
int Player::getPAtt()
{
    return att;
}
/**
 * @brief returns hp for resetting hp
 * 
 * @return int 
 */
int Player::getPHp()
{
    return hp;
}
/**
 * @brief used to turn on animation for attacking 9 being the number of frames
 * 
 */
void Player::animationAttack()
{
    isAttacking = 9;
}
/**
 * @brief turns off block if on so block isnt always on
 * 
 */
void Player::blockCheck()
{
    if(blocking == true)
    {
        blocking = false;
    }
}
/**
 * @brief heals player for 10 but wont go over max hp
 * 
 */
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
/**
 * @brief updates player sprite for current frame in animation in sync with internal clock
 * 
 */
void Player::update()
{
    sf::Time elapsed = clock.getElapsedTime();
    int ms = elapsed.asMilliseconds();
    if (isAttacking == -1)
    {
        
         if (ms >= 200)
         {
            p1.setTexture(pArt);
            clock.restart();
            frame++;
            rect.left = frame%2 * 128;
            rect.top = ((frame/2)%4) *64;
         }
    // else if ((ms/200)%8 == 1) {rect.left = 128; rect.top = 0;}
    // else if ((ms/200)%8 == 2) {rect.left = 0; rect.top = 64;}
    // else if ((ms/200)%8 == 3) {rect.left = 128; rect.top = 64;}
    // else if ((ms/200)%8 == 4) {rect.left = 0; rect.top = 128;}
    // else if ((ms/200)%8 == 3) {rect.left = 128; rect.top = 128;}
    // else if ((ms/200)%8 == 6) {rect.left = 0; rect.top = 192;}
    // else if ((ms/200)%8 == 7) {rect.left = 128; rect.top = 192;}
    }
    else 
    {
        if (ms >= 100)
        {
            clock.restart();
            p1.setTexture(p1Attack);
            int framedistanceleft = ((9-isAttacking)%8)*128;
            int framedistancetop = ((9-isAttacking)/8)*64;
            rect.left = framedistanceleft;
            rect.top = framedistancetop;
            isAttacking--;
        }
    }
   
    p1.setTextureRect(rect);

}
/**
 * @brief sets hp for resetting
 * 
 * @param num 
 */
void Player::setHp(int num)
{
    hp = num;
}