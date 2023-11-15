#include "button.h"
/**
 * @brief Construct a new Button:: Button object
 * 
 * @param s string for text object
 * @param position of button
 * @param size of button
 * @param color of button
 */
Button::Button(std::string s, sf::Vector2f position, sf::Vector2f size, sf::Color color)
{
    if (!mTexture.loadFromFile("button.png"))
    {
        std::cout<<"Error opening file\n";
        exit(1);
    }
    //create sprite that look like a button
    mButton.setTexture(mTexture);
    
    //get size of image
    sf::Vector2u imageSize=mTexture.getSize();
    //change origin to the center of the image (makes rotation easy)
    mButton.setOrigin(imageSize.x/2, imageSize.y/2);
    //set position

    mButton.setPosition(position.x,position.y);
    //choose color
    mButton.setColor(color);
    //set size as a ration of original size
    mButton.setScale(size.x/imageSize.x, size.y/imageSize.y);
    //Make label

    if (!mFont.loadFromFile("college.ttf"))
    {
        std::cout<<"Error opening file\n";
        exit(2);
    }
    mText.setFont(mFont);
    //choose the font size based on button size (I choose half)
    unsigned int fontSize = mButton.getGlobalBounds().height/2;
    mText.setCharacterSize(fontSize);
    //set label
    mText.setString(s);
    //set origin to the middle
    mText.setOrigin(mText.getGlobalBounds().width/2, mText.getGlobalBounds().height/2);
    //set position at the middle of the button
    mText.setPosition(position.x, position.y-fontSize/4);
    //choose colors
    mTextNormal = sf::Color::Green;
    mTextHover = sf::Color::Red;
    mText.setFillColor(mTextNormal);
}
/**
 * @brief displays the button object
 * 
 * @param target 
 * @param states 
 */
void Button::draw(sf::RenderTarget& target,sf::RenderStates states) const
{
    target.draw(mButton, states);
    target.draw(mText, states);
}
/**
 * @brief detects mouse interaction with button, and updates state
 * 
 * @param e mouse event object
 * @param window app object
 */
void Button::update(sf::Event& e, sf::RenderWindow& window)
{
    //get position of the mouse
    //sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
    sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
    sf::Vector2f worldPos = window.mapPixelToCoords(pixelPos);
    bool mouseInButton =    worldPos.x >= mButton.getPosition().x - mButton.getGlobalBounds().width/2
                            && worldPos.x <= mButton.getPosition().x + mButton.getGlobalBounds().width/2
                            && worldPos.y >= mButton.getPosition().y - mButton.getGlobalBounds().height/2
                            && worldPos.y <= mButton.getPosition().y + mButton.getGlobalBounds().height/2;
    if(e.type == sf::Event::MouseMoved)
    {
        if(mouseInButton)
        {
            mBtnState = state::hovered;
        }
        else
        {
            mBtnState = state::normal;
        }
    }
    if (e.type == sf::Event::MouseButtonPressed)
    {
        if(e.mouseButton.button==sf::Mouse::Left)
        {
            if(mouseInButton)
            {
                mBtnState = state::clicked;
            }
            else
            {
                mBtnState = state::normal;
            }
        }
    }
    if (e.type == sf::Event::MouseButtonReleased)
    {
        if (e.mouseButton.button==sf::Mouse::Left)
        {
            if(mouseInButton)
            {
                mBtnState = state::hovered;
            }
            else
            {
                mBtnState = state::normal;
            }
        }
    }
    switch(mBtnState)
    {
        case state::normal:
        {
            mButton.setRotation(0);
            mText.setFillColor(mTextNormal);
            break;
        }
        case state::hovered:
        {
            mButton.setRotation(0);
            mText.setFillColor(mTextHover);
            break;
        }
        case state::clicked:
        {
            mButton.setRotation(180);
            mText.setFillColor(mTextHover);
            break;
        }

    }
}
/**
 * @brief Construct a new Button:: Button object
 * 
 */
Button::Button()
{
    if (!mTexture.loadFromFile("button.png"))
    {
        std::cout<<"Error opening file\n";
        exit(1);
    }
    //create sprite that look like a button
    mButton.setTexture(mTexture);
    
    //get size of image
    sf::Vector2u imageSize=mTexture.getSize();
    //change origin to the center of the image (makes rotation easy)
    mButton.setOrigin(imageSize.x/2, imageSize.y/2);
    //set position

    mButton.setPosition(300,100);
    //choose color
    mButton.setColor(sf::Color::White);
    //set size as a ration of original size
    mButton.setScale(1, 1);
    //Make label

    if (!mFont.loadFromFile("college.ttf"))
    {
        std::cout<<"Error opening file\n";
        exit(2);
    }
    mText.setFont(mFont);
    //choose the font size based on button size (I choose half)
    unsigned int fontSize = mButton.getGlobalBounds().height/2;
    mText.setCharacterSize(fontSize);
    //set label
    mText.setString("Push me!");
    //set origin to the middle
    mText.setOrigin(mText.getGlobalBounds().width/2, mText.getGlobalBounds().height/2);
    //set position at the middle of the button
    mText.setPosition(mButton.getPosition().x, mButton.getPosition().y-fontSize/4);
    //choose colors
    mTextNormal = sf::Color::Green;
    mTextHover = sf::Color::Red;
    mText.setFillColor(mTextNormal);

}
/**
 * @brief sets text in button
 * 
 * @param s string
 */
void Button::setText(std::string s)
{
    mText.setString(s);
}
/**
 * @brief sets position of button and text
 * 
 * @param position 
 */
void Button::setPosition(sf::Vector2f position)
{
    mButton.setPosition(position);
    unsigned int fontSize = mButton.getGlobalBounds().height/2;
    mText.setPosition(mButton.getPosition().x, mButton.getPosition().y-fontSize/4);
}
/**
 * @brief sets size of button and text
 * 
 * @param size 
 */
void Button::setSize(sf::Vector2f  size)
{
    sf::Vector2u imageSize=mTexture.getSize();
    mButton.setScale(size.x/imageSize.x, size.y/imageSize.y);


    unsigned int fontSize = mButton.getGlobalBounds().height/2;
    mText.setCharacterSize(fontSize);
    mText.setOrigin(mText.getGlobalBounds().width/2, mText.getGlobalBounds().height/2);
    mText.setPosition(mButton.getPosition().x, mButton.getPosition().y-fontSize/double(4));
}
/**
 * @brief sets color of button member
 * 
 * @param btnColor 
 */
void Button::setColor(sf::Color btnColor)
{
    mButton.setColor(btnColor);
}

