#include "Reel.h"
#include <iostream>

Reel::Reel(int numSlots)
    : m_numSlots(numSlots), 
      m_speed(1500.0f),
      m_originalY(0.0f)
{
    m_reelBorder.setSize(sf::Vector2f(150, 450));
    m_reelBorder.setFillColor(sf::Color::Transparent);
    m_reelBorder.setOutlineThickness(1.0f);
    m_reelBorder.setOutlineColor(sf::Color::Black);

    for (int i = 0; i < m_numSlots; ++i)
    {
        m_slots.push_back(Slot());
    }
}

std::vector<Slot>& Reel::getSlots() 
{
    return m_slots;
}

void Reel::setPos(float x, float y)
{
    m_reelBorder.setPosition(x, y + 150);

    size_t cnt = 0;
    for (float px = y; cnt < 5; px += 150, ++cnt)
    {
        m_slots[cnt].setPos(x, px);
    }
}

void Reel::spin(float deltaTime)
{
    for (auto& slot : m_slots)
    {
        sf::Vector2f position = slot.getSlotPos();
        position.y += m_speed * deltaTime;

        if (position.y > m_reelBorder.getPosition().y + m_reelBorder.getSize().y)
        {
            position.y -= m_slots.size() * slot.getSlotBorder().getSize().y;

            slot.setRandomFigureType();
        }

        slot.setPos(position.x, position.y);
    }
}

void Reel::slowDown(float deltaTime)
{
    if (m_speed > 0)
    {
        m_speed -= 10.0f * deltaTime;
        
    }
    else 
    {
        m_speed = 0;
    }

    for (auto& slot : m_slots)
    {
        sf::Vector2f position = slot.getSlotPos();
        position.y += m_speed * deltaTime;

        if (position.y > m_reelBorder.getPosition().y + m_reelBorder.getSize().y)
        {
            position.y -= m_slots.size() * slot.getSlotBorder().getSize().y;
            slot.setRandomFigureType();
        }

        slot.setPos(position.x, position.y);
    }
}

bool Reel::isStopped() const
{
    return m_speed <= 0.0f;
}

void Reel::saveOriginalPosition()
{
    m_originalY = m_slots[0].getSlotPos().y;
}

void Reel::resetToOriginalPosition()
{
    float slotHeight = m_slots[0].getSlotBorder().getSize().y;
    float currentY = m_slots[0].getSlotPos().y;
    float offset = std::fmod(currentY - m_originalY, slotHeight);

    if (offset > slotHeight / 2.0f)
        offset -= slotHeight;

    for (auto& slot : m_slots)
    {
        slot.setPos(slot.getSlotPos().x, slot.getSlotPos().y - offset);
    }
}

void Reel::drawSlots(sf::RenderWindow& window)
{
    for (auto& slot : m_slots)
    {
        slot.draw(window);
    }
}

void Reel::drawBorder(sf::RenderWindow& window) 
{
    window.draw(m_reelBorder);
}