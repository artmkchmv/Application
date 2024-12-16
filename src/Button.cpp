#include "Button.h"

Button::Button() {}

Button::Button(sf::RectangleShape shape, sf::Text text) 
    : m_shape(shape), m_text(text) {}

void Button::setColor(sf::Color color) 
{
    m_shape.setFillColor(color);
}

void Button::setText(const std::string& text, unsigned int textSize, sf::Color textColor) 
{
    m_text.setString(text);
    m_text.setCharacterSize(textSize);
    m_text.setFillColor(textColor);
}

void Button::setPos(float x, float y)
{
    m_shape.setPosition(x, y);

    sf::FloatRect textBounds = m_text.getLocalBounds();

    m_text.setPosition(x + (m_shape.getSize().x - textBounds.width) / 2.f - textBounds.left,
        y + (m_shape.getSize().y - textBounds.height) / 2.f - textBounds.top);
}

void Button::setSize(float width, float height)
{
    m_shape.setSize(sf::Vector2f(width, height));
}

bool Button::isClicked(sf::Vector2i mousePosition, sf::RenderWindow& window)
{
    return m_shape.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition)) &&
        sf::Mouse::isButtonPressed(sf::Mouse::Left);
}

void Button::draw(sf::RenderWindow& window)
{
    window.draw(m_shape);
    window.draw(m_text);
}