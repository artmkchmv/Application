#ifndef WAITSTATE_H
#define WAITSTATE_H

#include "State.h"

class SlotMachine;

class WaitState : public State
{
public:
    WaitState(SlotMachine* machineptr);
    ~WaitState();

    void handle(sf::RenderWindow& window) override;

private:
    SlotMachine* m_machineptr;
};

#endif // !WAITSTATE_H
