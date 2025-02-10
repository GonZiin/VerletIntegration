#ifndef VERLETPARTICLE_H
#define VERLETPARTICLE_H

#include <SFML/Graphics.hpp>

class VerletParticle
{
public:
    VerletParticle() = default;
    VerletParticle(const sf::Vector2f& initialPosition);

    // Getters
    const sf::Vector2f& getPosition() const;
    const sf::Vector2f& getPreviousPostion() const;
    const sf::Vector2f& getAcceleration() const;

    // Setters
    void setPosition(const sf::Vector2f& pos);
    void setPreviousPostion(const sf::Vector2f& pos);
    void addAcceleration(const sf::Vector2f& a);
    void clearAcceleration();

private:
    sf::Vector2f m_currentPosition{};
    sf::Vector2f m_previousPosition{};
    sf::Vector2f m_acceration{};
};

#endif
