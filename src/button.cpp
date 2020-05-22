#include "button.hpp"

Button::Button(sf::Vector2i pos, sf::Vector2i size, const char *text)
{
    frame.setSize(sf::Vector2f(size));
    frame.setOutlineColor(sf::Color::Green);
    frame.setOutlineThickness(1.f);
    state = ButtonState::NotFocused;
    this->text.setString(text);
    callbacks = new std::vector<std::function<void()>>;
    if (font.loadFromFile("fonts/OTF/SF-Pro-Text-Regular.otf"))
        this->text.setFont(font);
    setSize(size);
    setPosition(pos);
    this->text.setString(text);
}

Button::~Button()
{
}

void Button::setPosition(sf::Vector2i position)
{
    this->position = position;
    frame.setPosition((sf::Vector2f)this->position);
    updateText();
}

void Button::setSize(sf::Vector2i size)
{
    this->size = size;
    frame.setSize((sf::Vector2f)size);
    updateText();
}

void Button::setTextFont(sf::Font font)
{
    this->font = font;
    text.setFont(font);
}

void Button::setTextFont(const char *name)
{
    font.loadFromFile(name);
    text.setFont(font);
}

void Button::setText(const char *text)
{
    this->text.setString(text);
}

void Button::setFrameColor(sf::Color color)
{
    frameColor = color;
    frame.setFillColor(frameColor);
}
void Button::setTextColor(sf::Color color)
{
    textColor = color;
    text.setFillColor(textColor);
    text.setOutlineColor(textColor);
}
void Button::setBorderColor(sf::Color color)
{
    borderColor = color;
    frame.setOutlineColor(borderColor);
}

void Button::setTextSize(int textSize)
{
    this->textSize = textSize;
    updateText();
}

sf::Vector2i Button::getPosition()
{
    return position;
}

sf::Vector2i Button::getSize()
{
    return size;
}

sf::Font Button::getFont()
{
    return *text.getFont();
}

const char *Button::getText()
{
    return ((std::string)text.getString()).c_str();
}

sf::Color Button::getFrameColor()
{
    return frameColor;
}
sf::Color Button::getTextColor()
{
    return textColor;
}
sf::Color Button::getBorderColor()
{
    return borderColor;
}

int Button::getTextSize()
{
    return textSize;
}

bool Button::contains(sf::Vector2f pos)
{
    if (frame.getGlobalBounds().contains(pos))
        return true;
    return false;
}

void Button::triggerCallbacks()
{
    for (auto var : *callbacks)
    {
        var();
    }
}

void Button::addCallback(std::function<void()> callback)
{
    callbacks->push_back(callback);
}

void Button::removeCall(std::function<void()> callback)
{
}

void Button::updateText()
{
    if (textSize == -1)
        text.setCharacterSize(size.y);
    else
        text.setCharacterSize(textSize);
    int xt = text.getGlobalBounds().width / 2;
    int yt = text.getGlobalBounds().height / 2;
    int xOff = size.x / 2 - xt;
    int yOff = size.y / 2 - yt * 2;
    int x = xOff + position.x;
    int y = yOff + position.y;
    text.setPosition(sf::Vector2f(x, y));
}