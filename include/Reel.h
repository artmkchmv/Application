#ifndef REEL_H
#define REEL_H

#include "Slot.h"
#include <vector>

class Reel
{
public:
	explicit Reel(int numSlots);
	~Reel() = default;

	std::vector<Slot>& getSlots();
	void setPos(float x, float y);
	void spin(float deltaTime);
	void slowDown(float deltaTime);
	bool isStopped() const;
	void saveOriginalPosition();
	void resetToOriginalPosition();
	void drawSlots(sf::RenderWindow& window);
	void drawBorder(sf::RenderWindow& window);

private:
	sf::RectangleShape m_reelBorder;
	std::vector<Slot> m_slots;
	float m_speed;
	int m_numSlots;
	float m_originalY;
};

#endif // !REEL_H
