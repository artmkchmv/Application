#ifndef SLOTMACHINE_H
#define SLOTMACHINE_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include "State.h"
#include "Reel.h"

class State;

class SlotMachine
{
public:
	SlotMachine();
	~SlotMachine() = default;

	std::vector<std::unique_ptr<State>>& getStates();
	State* getState() const;
	void setState(State* state);
	int getWinNum() const;
	void clearWinNum();
	void handle(sf::RenderWindow& window);
	void updateReels();
	void startSpin();
	void stopSpin();
	void calculateWin();
	void setPos(float x, float y);
	void draw(sf::RenderWindow& window);

private:
	sf::RectangleShape m_slotMachineUpBorder;
	sf::RectangleShape m_slotMachineDownBorder;
	sf::Clock m_clock;
	sf::Clock m_reelStartClock;
	std::vector<sf::Time> m_reelStartDelays;
	std::vector<std::unique_ptr<State>> m_states;
	std::vector<Reel> m_reels;
	State* m_currentState;
	int m_winNum;
};

#endif // !#SLOTMACHINE_H
