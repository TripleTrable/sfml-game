#include "gameState.hpp"

GameState::GameState(StateData *stateData) : State(stateData)
{
}

GameState::~GameState()
{
}

void GameState::update()
{
}
void GameState::render(sf::RenderWindow &window)
{
}
void GameState::eventHandler(sf::Event *event, sf::RenderWindow *window)
{
    if (event->type == sf::Event::KeyPressed)
    {
        if (event->key.code == sf::Keyboard::Q)
            endState();
    }
}