#include "WaitState.h"
#include "SlotMachine.h"

WaitState::WaitState(SlotMachine* machineptr)
    : m_machineptr(machineptr) {}

WaitState::~WaitState() {}

void WaitState::handle(sf::RenderWindow& window) {}
