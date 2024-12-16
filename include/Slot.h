#ifndef SLOT_H
#define SLOT_H

#include <SFML/Graphics.hpp>
#include <memory>
#include <random>

class Slot
{
public:
	Slot();
	~Slot() = default;

	sf::RectangleShape& getSlotBorder();
	sf::Vector2f getSlotPos() const;
	void setPos(float x, float y);
	int getFigureType() const;
	void setRandomFigureType();
	void draw(sf::RenderWindow& window);

private:
	sf::RectangleShape m_slotBorder;
	std::shared_ptr<sf::Shape> m_figureShape;
	int m_figureType;
};

#endif // !SLOT_H
