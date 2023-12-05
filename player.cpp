#include "player.h"

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
    p1.setTexture(pArt);
    p1.setTextureRect(sf::IntRect(0,0,128,64));
    rect = sf::IntRect(0,0,128,64);
    p1.setOrigin(128.f/2.f,96.f/2.f);
    p1.setPosition(250,300);
    p1.setScale({3,3});
    frame = 0;
    isAttacking = -1;
}

int Player::pAttack()
{
    int toHit = 1 + (rand() % 20);
    std::cout << "rolled " << toHit << std::endl;
    return toHit;
    isAttacking = 9;
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

void Player::update()
{
    sf::Time elapsed = clock.getElapsedTime();
    int ms = elapsed.asMilliseconds();
    std::cout <<"attack" <<isAttacking << std::endl;
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
