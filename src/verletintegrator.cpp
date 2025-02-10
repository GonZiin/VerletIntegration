#include "include/verletintegrator.h"

void VerletIntegrator::integrate(VerletParticle& particle, float dt)
{
    sf::Vector2f currentPosition = particle.getPosition();

    sf::Vector2f newPosition = currentPosition + (currentPosition - particle.getPreviousPostion())
                               + particle.getAcceleration() * (dt * dt);

    particle.setPreviousPostion(currentPosition);
    particle.setPosition(newPosition);

    particle.clearAcceleration();
}
