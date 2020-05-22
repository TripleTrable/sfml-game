#include "mainMenu.hpp"
#include <iostream>
MainMenu::MainMenu(StateData* stateData) : State(stateData)
{
    Button *newGame = new Button(sf::Vector2i(200, 100), sf::Vector2i(200, 50), (char *)"New Game");
    newGame->setTextColor(sf::Color::Red);
    newGame->setFrameColor(sf::Color::White);
    newGame->addCallback(std::bind(&MainMenu::StartGame, this));
    buttons.insert(buttons.end(), newGame);
    Button *end = new Button(sf::Vector2i(200, 500), sf::Vector2i(200, 50), (char *)"Quit");
    end->setTextColor(sf::Color::Red);
    end->setFrameColor(sf::Color::White);
    end->addCallback(std::bind(&MainMenu::EndGame, this));
    buttons.insert(buttons.end(), end);
}

MainMenu::~MainMenu()
{
    for (Button *btn : buttons)
    {
        delete btn;
    }
}

void MainMenu::update()
{
}

void MainMenu::render(sf::RenderWindow &window)
{
    for (Button *btn : buttons)
    {
        window.draw(*btn);
    }
}

void MainMenu::eventHandler(sf::Event *event, sf::RenderWindow *window)
{
    if (event->type == sf::Event::MouseButtonPressed)
    {
        for (Button *button : buttons)
        {
            if (button->contains(window->mapPixelToCoords(sf::Mouse::getPosition(*window))))
            {
                button->triggerCallbacks();
            }
        }
    }
}

void MainMenu::StartGame()
{
    std::cout << "Start game" << std::endl;
}

void MainMenu::EndGame()
{
    std::cout << "End game" << std::endl;
    endState();
}