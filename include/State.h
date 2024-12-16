#ifndef STATE_H
#define STATE_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class State 
{
public:
    virtual ~State() = default;

    virtual void handle(sf::RenderWindow& window) = 0;
};

#endif // !STATE_H
