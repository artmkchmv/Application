#include <string>
#include "MainWindow.h"
#include "WaitState.h"
#include "SpinState.h"

MainWindow::MainWindow()
    : m_width(1920),
      m_height(1080),
      m_window(sf::VideoMode(m_width, m_height), "Application", sf::Style::Fullscreen),
      m_startButton(),
      m_stopButton(),
      m_machine()
{
    m_font.loadFromFile("assets/Arial.ttf");

    m_startButton = Button(sf::RectangleShape(sf::Vector2f(200, 100)), sf::Text("START", m_font));
    m_startButton.setColor(sf::Color::Black);
    m_startButton.setText("START", 50, sf::Color::White);

    m_stopButton = Button(sf::RectangleShape(sf::Vector2f(200, 100)), sf::Text("STOP", m_font));
    m_stopButton.setColor(sf::Color::Black);
    m_stopButton.setText("STOP", 50, sf::Color::White);

    m_winText.setFont(m_font);
    m_winText.setCharacterSize(50);
    m_winText.setFillColor(sf::Color::Black);
    m_winText.setString("");

    setPositions(m_width, m_height);
}

void MainWindow::setPositions(unsigned int width, unsigned int height)
{
    float scaleX = static_cast<float>(width) / m_width;
    float scaleY = static_cast<float>(height) / m_height;

    m_startButton.setPos(1470.0f * scaleX, 315.0f * scaleY);
    m_stopButton.setPos(1470.0f * scaleX, 665.0f * scaleY);
    m_machine.setPos(350.0f * scaleX, 165.0f * scaleY);
    m_winText.setPosition(1470.0f * scaleX, 200.0f * scaleY);

    m_startButton.setSize(200.0f * scaleX, 100.0f * scaleY);
    m_stopButton.setSize(200.0f * scaleX, 100.0f * scaleY);
}

void MainWindow::mainWindowProcess()
{
    sf::Clock spinClock;

    while (m_window.isOpen())
    {
        sf::Event event;
        while (m_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                m_window.close();
        }

        sf::Vector2i mousePos = sf::Mouse::getPosition(m_window);

        if (dynamic_cast<WaitState*>(m_machine.getState()) && 
            m_startButton.isClicked(mousePos, m_window))
        {
            spinClock.restart();
            m_winText.setString("");
            m_machine.startSpin();
        }

        if (dynamic_cast<SpinState*>(m_machine.getState()) && 
            (m_stopButton.isClicked(mousePos, m_window) ||
            spinClock.getElapsedTime().asSeconds() >= 10))
        {
            m_machine.stopSpin();
            int winNum = m_machine.getWinNum();
            m_winText.setString("Your win: " + std::to_string(winNum));
            m_machine.clearWinNum();
        }

        m_machine.handle(m_window);

        m_window.clear(sf::Color::White);

        m_startButton.draw(m_window);
        m_stopButton.draw(m_window);
        m_window.draw(m_winText);
        m_machine.draw(m_window);

        m_window.display();
    }
}
