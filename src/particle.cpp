#include "include/particle.h"
#include <SFML/System/Vector2.hpp>

VerletParticle::VerletParticle(const sf::Vector2f& initialPosition)
: m_currentPosition(initialPosition)
, m_previousPosition(initialPosition)
, m_acceration(0.0f, 0.0f)
{
}

const sf::Vector2f& VerletParticle::getPosition() const { return m_currentPosition; }

const sf::Vector2f& VerletParticle::getPreviousPostion() const { return m_previousPosition; }

const sf::Vector2f& VerletParticle::getAcceleration() const { return m_acceration; }

void VerletParticle::setPosition(const sf::Vector2f& pos) { m_currentPosition = pos; }

void VerletParticle::setPreviousPostion(const sf::Vector2f& prevPos)
{
    m_previousPosition = prevPos;
}

void VerletParticle::addAcceleration(const sf::Vector2f& acc) { m_acceration += acc; }

void VerletParticle::clearAcceleration() { m_acceration = sf::Vector2f(0.f, 0.f); }
