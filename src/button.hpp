#pragma once
#include <SFML/Graphics.hpp>
#include <functional>
#include <iostream>
class Button : public sf::Drawable
{
private:
    enum class ButtonState 
    {
        NotFocused,
        Focused,
        Hover,
        HoverFocused,
        Pressed
    };
    ButtonState state;
    sf::Vector2i position;
    sf::Vector2i size;
    std::vector<std::function<void()>> *callbacks;
    sf::Font font;
    sf::Text text;
    sf::RectangleShape frame;
    sf::Color textColor;
    sf::Color frameColor;
    sf::Color borderColor;
    int textSize = -1;

    void updateText();
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        switch (state)
        {
        case ButtonState::NotFocused:
            target.draw(frame,states);
            //target.draw(text,states);
            target.draw(text,states);
            break;
        
        default:
            break;
        }
    }

public:

    Button(sf::Vector2i pos, sf::Vector2i size ,const char* text);
    ~Button();
    void setPosition(sf::Vector2i position);
    void setSize(sf::Vector2i size);
    void setTextFont(sf::Font font);
    void setTextFont(const char* name);
    void setText(const char *text);
    void setText(const wchar_t *text);
    void setFrameColor(sf::Color color);
    void setTextColor(sf::Color color);
    void setBorderColor(sf::Color color);
    void setTextSize(int textSize);

    sf::Vector2i getPosition();
    sf::Vector2i getSize();
    sf::Font getFont();
    const char *getText();
    sf::Color getFrameColor();
    sf::Color getTextColor();
    sf::Color getBorderColor();
    int getTextSize();

    bool contains(sf::Vector2f);

    void addCallback(std::function<void()> callback);
    void removeCall(std::function<void()> callback);
    void triggerCallbacks();
};
