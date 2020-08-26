#pragma once
#include "state.hpp"
class GameState : public State
{
private:
    
public:
    GameState(StateData* stateData);
    ~GameState();
    
    void update();
    void render(sf::RenderWindow &window);
    void eventHandler(sf::Event *event,sf::RenderWindow *window);
};
