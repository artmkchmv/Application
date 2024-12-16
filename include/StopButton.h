#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <functional>
#include "Button.h"

class SlotMachine;

class StopButton : public Button 
{
private:
    SlotMachine* machine;
    std::function<void()> onClickAction;

public:
    StopButton(float x, float y, float width, float height,
        const std::string& buttonText, const sf::Font& buttonFont,
        const sf::Color& idle, const sf::Color& hover, const sf::Color& active,
        SlotMachine* machine, std::function<void()> onClick);

    ~StopButton();

    void update(const sf::Vector2f& mousePos) override;

    void onClick() const;
};
