#ifndef SPINSTATE_H
#define SPINSTATE_H

#include "State.h"

class SlotMachine;

class SpinState : public State
{
public:
    SpinState(SlotMachine* machineptr);
    ~SpinState();

    void handle(sf::RenderWindow& window) override;

private:
    SlotMachine* m_machineptr;
};

#endif // !SPINSTATE_H
