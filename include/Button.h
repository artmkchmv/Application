#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>

class Button
{
public:
    Button();
    Button(sf::RectangleShape shape, sf::Text text);
    ~Button() = default;

    void setColor(sf::Color color);
    void setText(const std::string& text, unsigned int textSize, sf::Color textColor);
    void setPos(float x, float y);
    void setSize(float width, float height);
    bool isClicked(sf::Vector2i mousePosition, sf::RenderWindow& window);
    void draw(sf::RenderWindow& window);

private:
    sf::RectangleShape m_shape;
    sf::Text m_text;
    sf::Font m_font;
};

#endif // !BUTTON_H
