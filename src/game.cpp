#include "game.hpp"
game::game()
{
    window = new sf::RenderWindow(sf::VideoMode().getDesktopMode(), "Cerraria");
    event = new sf::Event();
    stateData.stateStack = &this->stateStack;
}

game::~game()
{
}

void game::init()
{
    GameState = States::RUNING;
    MainMenu *menu = new MainMenu(&stateData);
    stateStack.push(menu);
    run();
}

void game::eventHandler()
{
    while (window->pollEvent(*event))
    {
        if (event->type == sf::Event::Closed)
            GameState = States::STOP;
        else if (!stateStack.empty())
            stateStack.top()->eventHandler(event, window);
    }
}

void game::update()
{
    if (!stateStack.empty())
    {
        stateStack.top()->update();
        if (stateStack.top()->getQuit())
        {
            stateStack.top()->endState();
            delete stateStack.top();
            stateStack.pop();
        }
    }
    else
    {
        GameState = States::STOP;
    }
}

void game::render()
{
    window->clear();

    if (!stateStack.empty())
        stateStack.top()->render(*window);

    window->display();
}

void game::run()
{
    while (GameState == States::RUNING)
    {
        eventHandler();
        update();
        render();
    }
    if (GameState == States::STOP)
    {
        window->close();
    }
}
