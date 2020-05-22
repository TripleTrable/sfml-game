#include "mainMenu.hpp"
#include "settings.hpp"
#include <iostream>
MainMenu::MainMenu(StateData *stateData) : State(stateData)
{
    initButtons();
}

MainMenu::~MainMenu()
{
    for (Button *btn : buttons)
    {
        delete btn;
    }
}

void MainMenu::initButtons()
{
    Button *newGame = new Button(sf::Vector2i(window->getSize().x / 2 - 125, 100), sf::Vector2i(250, 50), (char *)"New Game");
    newGame->setTextColor(sf::Color::Black);
    newGame->setFrameColor(sf::Color(0xc5,0xc8,0xc6));
    newGame->setBorderColor(sf::Color(0x75,0x80,0x80));
    newGame->addCallback(std::bind(&MainMenu::StartGame, this));
    buttons.insert(buttons.end(), newGame);

    Button *settings = new Button(sf::Vector2i(window->getSize().x / 2 - 125, 200), sf::Vector2i(250, 50), (char *)"Settings");
    settings->setTextColor(sf::Color::Black);
    settings->setFrameColor(sf::Color(0xc5,0xc8,0xc6));
    settings->setBorderColor(sf::Color(0x75,0x80,0x80));
    settings->addCallback([this]() {stateStack->push(new Settings(stateData));});
    buttons.insert(buttons.end(), settings);

    Button *end = new Button(sf::Vector2i(window->getSize().x / 2 - 125, 300), sf::Vector2i(250, 50), (char *)"Quit");
    end->setTextColor(sf::Color::Black);
    end->setFrameColor(sf::Color(0xc5,0xc8,0xc6));
    end->setBorderColor(sf::Color(0x75,0x80,0x80));
    end->addCallback(std::bind(&MainMenu::EndGame, this));
    buttons.insert(buttons.end(), end);
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
    endState();
}