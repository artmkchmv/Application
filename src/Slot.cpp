#include "Slot.h"

Slot::Slot() : m_slotBorder(sf::Vector2f(150.0f, 150.0f)), m_figureType(0)
{
    m_slotBorder.setFillColor(sf::Color::Transparent);
    setRandomFigureType();
}

sf::RectangleShape& Slot::getSlotBorder()
{
    return m_slotBorder;
}

sf::Vector2f Slot::getSlotPos() const
{
    return m_slotBorder.getPosition();
}

void Slot::setPos(float x, float y)
{
    m_slotBorder.setPosition(x, y);
    float centerX = x + m_slotBorder.getSize().x / 2.0f;
    float centerY = y + m_slotBorder.getSize().y / 2.0f;

    m_figureShape->setPosition(centerX - m_figureShape->getLocalBounds().width / 2.0f,
        centerY - m_figureShape->getLocalBounds().height / 2.0f);
}

int Slot::getFigureType() const
{
    return m_figureType;
}

void Slot::setRandomFigureType()
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> dist(0, 3);

    m_figureType = dist(gen);

    switch (m_figureType)
    {
    case 0: 
        m_figureShape = std::make_shared<sf::CircleShape>(0.375f * m_slotBorder.getSize().x);
        m_figureShape->setFillColor(sf::Color::Black);
        break;
    case 1:
        m_figureShape = std::make_shared<sf::RectangleShape>(sf::Vector2f(0.75f * m_slotBorder.getSize().x, 0.75f * m_slotBorder.getSize().y));
        m_figureShape->setFillColor(sf::Color::Black);
        break;
    case 2:
        m_figureShape = std::make_shared<sf::CircleShape>(0.375f * m_slotBorder.getSize().x, 5);
        m_figureShape->setFillColor(sf::Color::Black);
        break;
    case 3:
        m_figureShape = std::make_shared<sf::CircleShape>(0.375f * m_slotBorder.getSize().x, 8);
        m_figureShape->setFillColor(sf::Color::Black);
        break;
    }
}

void Slot::draw(sf::RenderWindow& window)
{
    window.draw(m_slotBorder);
    window.draw(*m_figureShape);
}
