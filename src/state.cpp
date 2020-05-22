#include "state.hpp"

State::State(StateData* stateData)
{
    this->stateData = stateData;
    this->stateStack = stateData->stateStack;
    this->window = stateData->window;
}

State::~State()
{
}

void State::endState()
{
    quit = true;
}

bool State::getQuit()
{
    return quit;
}