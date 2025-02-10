#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Window.hpp>
#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
    // Setting up antialiasing and settings object
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    // Create window object
    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "VerletIntegration", sf::Style::Default);

    // Main Program Loop
    while (window.isOpen())
    {
        sf::Event event{};
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                window.close();
            }
        }
        window.clear(sf::Color(23, 23, 22));

        window.display();
    }


    return 0;
}
