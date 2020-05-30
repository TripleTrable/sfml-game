#include "hspinner.hpp"

template <typename T>
HSpinner<T>::HSpinner(sf::Vector2i pos, sf::Vector2i size)
{
    position = pos;
    this->size = size;
    lButton = new Button(position, sf::Vector2i(size.y, size.y), "<");
    lButton->setTextColor(textColor);
    lButton->setFrameColor(frameColor);
    lButton->setBorderColor(borderColor);
    lButton->addCallback(std::bind(&HSpinner<T>::leftButtonPress,this));
    rButton = new Button(position + this->size - sf::Vector2i(size.y, size.y), sf::Vector2i(size.y, size.y), ">");
    rButton->setTextColor(textColor);
    rButton->setFrameColor(frameColor);
    rButton->setBorderColor(borderColor);
    rButton->addCallback(std::bind(&HSpinner<T>::rightButtonPress,this));

    if(font.loadFromFile("fonts/OTF/SF-Pro-Text-Regular.otf"))
        text.setFont(font);
    text.setFillColor(textColor);
    text.setOutlineColor(textColor);
    updateText();
}

template <typename T>
void HSpinner<T>::leftButtonPress()
{
    if(selectedItem - items.begin() > 0)
    selectedItem--;
    text.setString(*selectedItem);
    updateText();
    std::cout << *selectedItem << std::endl;
}
template <typename T>
void HSpinner<T>::rightButtonPress()
{
    if(items.end() != selectedItem +1)
        selectedItem++;
    text.setString(*selectedItem);
    updateText();
    std::cout << *selectedItem << std::endl;
}
template <typename T>
HSpinner<T>::~HSpinner()
{
}

template <typename T>
void HSpinner<T>::setPosition(sf::Vector2i pos)
{
    position = pos;
}

template <typename T>
void HSpinner<T>::setSize(sf::Vector2i size)
{
    this->size = size;
}
template <typename T>
void HSpinner<T>::setItems(std::vector<T> items)
{
    this->items = items;
    selectedItem = this->items.begin();
    text.setString(*selectedItem);
    updateText();
}

template <typename T>
void HSpinner<T>::setSelected(T item)
{
    throw std::logic_error("Not implemented jet.");
}

template <typename T>
void HSpinner<T>::setTextColor(sf::Color color)
{
    textColor = color;
    lButton->setTextColor(color);
    rButton->setTextColor(color);
    text.setFillColor(color);
    text.setOutlineColor(color);
}

template <typename T>
void HSpinner<T>::setFrameColor(sf::Color color)
{
    frameColor = color;
    lButton->setFrameColor(color);
    rButton->setFrameColor(color);
    text.setFillColor(color);
    text.setOutlineColor(color);
}

template <typename T>
void HSpinner<T>::setborderColor(sf::Color color)
{
    borderColor = color;
    rButton->setBorderColor(color);
    lButton->setBorderColor(color);
    text.setFillColor(color);
    text.setOutlineColor(color);
}

template <typename T>
sf::Vector2i HSpinner<T>::getPosition()
{
    return position;
}

template <typename T>
sf::Vector2i HSpinner<T>::getSize()
{
    return size;
}

template <typename T>
std::vector<T> HSpinner<T>::getItems()
{
    return items;
}

template <typename T>
T HSpinner<T>::getSelected()
{
    return selectedItem;
}

template <typename T>
sf::Color HSpinner<T>::getTextColor()
{
    return textColor;
}

template <typename T>
sf::Color HSpinner<T>::getFrameColor()
{
    return frameColor;
}

template <typename T>
sf::Color HSpinner<T>::getborderColor()
{
    return borderColor;
}

template <typename T>
void HSpinner<T>::updateText()
{
    if (textSize == -1)
        text.setCharacterSize(size.y);
    else
        text.setCharacterSize(textSize);
    int xt = text.getLocalBounds().width / 2;
    int yt = text.getLocalBounds().height / 2;
    int xOff = size.x / 2 - xt - text.getLocalBounds().left;
    int yOff = size.y / 2 - yt - text.getLocalBounds().top;
    int x = xOff + position.x; //+ lButton->getSize().x;
    int y = yOff + position.y; // + lButton->getSize().y;
    text.setPosition(sf::Vector2f(x, y));
}

template <typename T>
void HSpinner<T>::eventHandle(sf::Event* e, sf::RenderWindow* w)
{
    if(e->type == sf::Event::MouseButtonPressed)
    {
        if (lButton->contains(w->mapPixelToCoords(sf::Mouse::getPosition(*w)))) lButton->triggerCallbacks();
        if (rButton->contains(w->mapPixelToCoords(sf::Mouse::getPosition(*w)))) rButton->triggerCallbacks();
    }
}