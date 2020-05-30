#pragma once
#include "state.hpp"
#include "button.hpp"
#include "hspinner.hpp"
class Settings : public State
{
private:
    HSpinner<const char*>* resolution;
public:
    Settings(StateData* stateData);
    ~Settings();
    void update();
    void render(sf::RenderWindow &window);
    void eventHandler(sf::Event *event,sf::RenderWindow *window);
};