#include "include/boundaryconstraint.h"

void BoundaryConstraint::apply(VerletParticle& particle)
{
    sf::Vector2f pos{ particle.getPosition() };
    bool         corrected{ false };

    if (pos.x < m_bounds.left)
    {
        pos.x     = m_bounds.left;
        corrected = true;
    }

    if (pos.x > m_bounds.left + m_bounds.width)
    {
        pos.x     = m_bounds.left + m_bounds.width;
        corrected = true;
    }

    if (pos.y < m_bounds.top)
    {
        pos.y     = m_bounds.top;
        corrected = true;
    }

    if (pos.y > m_bounds.top + m_bounds.height)
    {
        pos.y     = m_bounds.top + m_bounds.height;
        corrected = true;
    }

    if (corrected)
    {
        particle.setPosition(pos);
        particle.setPreviousPostion(pos);
    }
}
