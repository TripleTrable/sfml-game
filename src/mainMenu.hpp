#pragma once
#include "state.hpp"
#include "button.hpp"
class MainMenu : public State
{

private:
    std::vector<Button*> buttons;
public:
    MainMenu(StateData* stateData);
    ~MainMenu();
    void update();
    void render(sf::RenderWindow &window);
    void eventHandler(sf::Event *event,sf::RenderWindow *window);
    void StartGame();
    void EndGame();
};

