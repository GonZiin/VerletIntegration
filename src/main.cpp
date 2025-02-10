#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Vector2.hpp>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "include/particle.h"
#include "include/verletintegrator.h"
#include "include/boundaryconstraint.h"

int main()
{
    const unsigned int windowWidth{ 800 };
    const unsigned int windowHeight{ 600 };
    const sf::Vector2f gravity{ 0, 981 };

    // Setting up antialiasing and settings object
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    // Create window object
    sf::RenderWindow window(
        sf::VideoMode({ 800, 600 }), "VerletIntegration", sf::Style::Default, settings);
    window.setFramerateLimit(60);

    VerletParticle particle(sf::Vector2f(windowWidth / 2.f, windowHeight / 2.f));

    sf::CircleShape circle(20.0f);
    circle.setOrigin(20.0f, 20.0f);
    circle.setPointCount(100);

    sf::FloatRect bounds(
        0.f, 0.f, static_cast<float>(windowWidth), static_cast<float>(windowHeight));
    BoundaryConstraint boundaryConstraint(bounds);

    sf::Clock clock;

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

        float dt = clock.restart().asSeconds();

        particle.addAcceleration(gravity);

        VerletIntegrator::integrate(particle, dt);

        boundaryConstraint.apply(particle);

        circle.setPosition(particle.getPosition());

        window.clear(sf::Color(23, 23, 22));
        window.draw(circle);
        window.display();
    }


    return 0;
}
