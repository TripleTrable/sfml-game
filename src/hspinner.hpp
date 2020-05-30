#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "ihspinnerItem.hpp"
#include "button.hpp"
template <typename T>
class HSpinner : public sf::Drawable
{
    static_assert(std::is_base_of<IHSpinnerItem, T>::value || std::is_same<const char*,T>::value, "T is not derived from IHSpinnerItem");

private:
    sf::Vector2i position;
    sf::Vector2i size;
    Button* lButton;
    Button* rButton;
    sf::Font font;
    sf::Text text;
    sf::RectangleShape frame;
    sf::Color textColor;
    sf::Color frameColor;
    sf::Color borderColor;
    int textSize = -1;
    

    std::vector<T> items;
    typename std::vector<T>::iterator selectedItem = items.begin();
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const
    {
        target.draw(*lButton,states);
        target.draw(*rButton,states);
        target.draw(text,states);
    }

    void leftButtonPress();
    void rightButtonPress();

    void updateText();

public:
    void setPosition(sf::Vector2i pos);
    void setSize(sf::Vector2i size);
    void setItems(std::vector<T> items);
    void setSelected(T item);
    void setTextColor(sf::Color color);
    void setFrameColor(sf::Color color);
    void setborderColor(sf::Color color);
    
    sf::Vector2i getPosition();
    sf::Vector2i getSize();    
    std::vector<T> getItems();
    T getSelected();
    sf::Color getTextColor();
    sf::Color getFrameColor();
    sf::Color getborderColor();

    HSpinner(sf::Vector2i pos, sf::Vector2i size);
    ~HSpinner();

    void eventHandle(sf::Event* e, sf::RenderWindow* w);
};