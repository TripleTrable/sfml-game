#pragma once
#include "state.hpp"
#include "button.hpp"

class Settings : public State
{
private:
    /* data */
public:
    Settings(StateData* stateData);
    ~Settings();
    void update();
    void render(sf::RenderWindow &window);
    void eventHandler(sf::Event *event,sf::RenderWindow *window);
};