#include "game.hpp"
Game::Game()
{
    window = new sf::RenderWindow(sf::VideoMode().getDesktopMode(), "Cerraria");
    event = new sf::Event();
    stateData.stateStack = &this->stateStack;
    stateData.window = window;
}

Game::~Game()
{
}

void Game::init()
{
    GameState = States::RUNING;
    MainMenu *menu = new MainMenu(&stateData);
    stateStack.push(menu);
    run();
}

void Game::eventHandler()
{
    while (window->pollEvent(*event))
    {
        if (event->type == sf::Event::Closed)
            GameState = States::STOP;
        else if (!stateStack.empty())
            stateStack.top()->eventHandler(event, window);
    }
}

void Game::update()
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

void Game::render()
{
    window->clear(sf::Color::White);

    if (!stateStack.empty())
        stateStack.top()->render(*window);

    window->display();
}

void Game::run()
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
