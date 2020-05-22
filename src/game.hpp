#pragma once
#include <SFML/Graphics.hpp>
#include <stack>
#include "state.hpp"
#include "mainMenu.hpp"
class game
{
private:
    void eventHandler();
    void update();
    void render();
    void run();

    sf::RenderWindow *window;
    sf::Event *event;
    std::stack<State*> stateStack;

    StateData stateData;

public:
    enum class States
    {
        RUNING,
        PAUSE,
        STOP
    };


    game();
    ~game();
    void init();

    States GameState;

};
