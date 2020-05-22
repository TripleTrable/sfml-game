#pragma once
#include <SFML/Graphics.hpp>
#include <stack>

class State;

class StateData
{

public:
    StateData() {}
    std::stack<State *> *stateStack;
    sf::Window *window;
};

class State
{
protected:
    std::stack<State *> *stateStack;
    StateData *stateData;
    sf::Window *window;

private:
    bool quit = false;

public:
    State(StateData *stateData);
    ~State();

    virtual void update() = 0;
    virtual void render(sf::RenderWindow &window) = 0;
    virtual void eventHandler(sf::Event *event, sf::RenderWindow *window) = 0;
    void endState();
    bool getQuit();
};
