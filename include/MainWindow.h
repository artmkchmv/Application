#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Button.h"
#include "SlotMachine.h"

class MainWindow
{
public:
	MainWindow();
	~MainWindow() = default;

	void setPositions(unsigned int width, unsigned int height);
	void mainWindowProcess();

private:
	sf::RenderWindow m_window;
	sf::Font m_font;
	sf::Text m_winText;
	Button m_startButton;
	Button m_stopButton;
	SlotMachine m_machine;
	unsigned int m_width;
	unsigned int m_height;
};

#endif // !MAINWINDOW_H
