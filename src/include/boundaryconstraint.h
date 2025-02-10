#ifndef BOUNDARYCONSTRAINT_H
#define BOUNDARYCONSTRAINT_H

#include "particle.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Rect.hpp>

class BoundaryConstraint
{
private:
    sf::FloatRect m_bounds;

public:
    explicit BoundaryConstraint(const sf::FloatRect& bounds)
    : m_bounds(bounds)
    {
    }

    void apply(VerletParticle& particle);
};

#endif
