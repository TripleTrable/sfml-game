#include "settings.hpp"
Settings::Settings(StateData* stateData) : State(stateData)
{
}

Settings::~Settings()
{
}

void Settings::update()
{
}

void Settings::render(sf::RenderWindow &window)
{
    
}

void Settings::eventHandler(sf::Event *event, sf::RenderWindow *window)
{
    if (event->type == sf::Event::MouseButtonPressed)
    {
    }
}
