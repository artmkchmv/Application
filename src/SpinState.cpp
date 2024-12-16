#include "SpinState.h"
#include "SlotMachine.h"

SpinState::SpinState(SlotMachine* machineptr)
    : m_machineptr(machineptr) {}

SpinState::~SpinState() {}

void SpinState::handle(sf::RenderWindow& window)
{
    m_machineptr->updateReels();
}
