#include "FinishState.h"
#include "SlotMachine.h"

FinishState::FinishState(SlotMachine* machineptr)
    : m_machineptr(machineptr) {}

FinishState::~FinishState() {}

void FinishState::handle(sf::RenderWindow& window)
{
    m_machineptr->calculateWin();
    m_machineptr->setState(m_machineptr->getStates()[0].get());
}
