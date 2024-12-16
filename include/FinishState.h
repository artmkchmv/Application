#ifndef FINISHSTATE_H
#define FINISHSTATE_H

#include "State.h"

class SlotMachine;

class FinishState : public State
{
public:
    FinishState(SlotMachine* machineptr);
    ~FinishState();

    void handle(sf::RenderWindow& window) override;

private:
    SlotMachine* m_machineptr;
};

#endif // !FINISHSTATE_H
