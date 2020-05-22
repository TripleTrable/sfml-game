#pragma once
#include <SFML/Graphics.hpp>
#include <stack>
class StateData
{

    public:
    StateData() {}
    std::stack<State*>* stateStack;
};

class State
{
private:
    bool quit = false;
    StateData* stateData;
    std::stack<State*>* stateStack;
public:
    State(StateData* stateData);
    ~State();

    virtual void update() = 0;
    virtual void render(sf::RenderWindow &window) = 0;
    virtual void eventHandler(sf::Event *event, sf::RenderWindow *window) = 0;
    void endState();
    bool getQuit();
};
