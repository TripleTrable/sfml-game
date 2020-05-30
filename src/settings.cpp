#include "settings.hpp"
#include "hspinner.cpp"
Settings::Settings(StateData* stateData) : State(stateData)
{
    resolution = new HSpinner<const char*>(sf::Vector2i(100,100),sf::Vector2i(500,100));
    resolution->setItems(std::vector<const char*> {"test","test2","test3"});
    resolution->setFrameColor(sf::Color::White);
    resolution->setborderColor(sf::Color::Black);
    resolution->setTextColor(sf::Color::Black);
}

Settings::~Settings()
{
}

void Settings::update()
{
}

void Settings::render(sf::RenderWindow &window)
{
   window.draw(*resolution); 
}

void Settings::eventHandler(sf::Event *event, sf::RenderWindow *window)
{
    if (event->type == sf::Event::MouseButtonPressed)
    {
        resolution->eventHandle(event,window);
    }
}
