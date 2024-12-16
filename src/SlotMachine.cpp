#include <vector>
#include "SlotMachine.h"
#include "WaitState.h"
#include "SpinState.h"
#include "FinishState.h"

SlotMachine::SlotMachine()
{
    m_slotMachineUpBorder.setFillColor(sf::Color::White);
    m_slotMachineUpBorder.setSize(sf::Vector2f(750, 300));

    m_slotMachineDownBorder.setFillColor(sf::Color::White);
    m_slotMachineDownBorder.setSize(sf::Vector2f(750, 150));

    m_states.push_back(std::make_unique<WaitState>(this));
    m_states.push_back(std::make_unique<SpinState>(this));
    m_states.push_back(std::make_unique<FinishState>(this));

    for (size_t i = 0; i < 5; ++i) 
    {
        m_reels.push_back(Reel(5));
        m_reelStartDelays.push_back(sf::seconds(i * 0.1f));
    }

    m_currentState = m_states[0].get();

    m_winNum = 0;
}

std::vector<std::unique_ptr<State>>& SlotMachine::getStates()
{
    return m_states;
}

State* SlotMachine::getState() const
{
    return m_currentState;
}

void SlotMachine::setState(State* state) 
{
    m_currentState = state;
}

int SlotMachine::getWinNum() const
{
    return m_winNum;
}

void SlotMachine::clearWinNum() 
{
    m_winNum = 0;
}

void SlotMachine::handle(sf::RenderWindow& window)
{
    m_currentState->handle(window);
}

void SlotMachine::updateReels() 
{
    float deltaTime = m_clock.restart().asSeconds();

    if (dynamic_cast<SpinState*>(m_currentState))
    {
        for (size_t i = 0; i < m_reels.size(); ++i)
        {
            if (m_reelStartClock.getElapsedTime() >= m_reelStartDelays[i])
            {
                m_reels[i].spin(deltaTime);
            }
        }
    }
    else if (dynamic_cast<FinishState*>(m_currentState))
    {
        for (auto& reel : m_reels)
        {
            reel.slowDown(deltaTime);
        }
    }
}

void SlotMachine::startSpin()
{
    setState(m_states[1].get());
    m_reelStartClock.restart();
}

void SlotMachine::stopSpin()
{
    setState(m_states[2].get());

    for (auto& reel : m_reels)
    {
        reel.resetToOriginalPosition();
    }
}

void SlotMachine::calculateWin()
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> dist(0, 100);

    m_winNum = dist(gen);
}

void SlotMachine::setPos(float x, float y) 
{
    size_t cnt = 0;
    for (float px = x; cnt < 5; px += 150, ++cnt)
    {
        m_reels[cnt].setPos(px, y);
        m_reels[cnt].saveOriginalPosition();
    }

    m_slotMachineUpBorder.setPosition(x, y - 150.0f);
    m_slotMachineDownBorder.setPosition(x, y + 600.0f);

}

void SlotMachine::draw(sf::RenderWindow& window)
{
    for (auto& reel : m_reels) 
    {
        reel.drawSlots(window);
    }

    window.draw(m_slotMachineUpBorder);
    window.draw(m_slotMachineDownBorder);

    for (auto& reel : m_reels)
    {
        reel.drawBorder(window);
    }
}
