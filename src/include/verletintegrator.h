#ifndef VERLETINTEGRATOR_H
#define VERLETINTEGRATOR_H

#include "particle.h"

class VerletIntegrator
{
public:
    static void integrate(VerletParticle& particle, float dt);
};

#endif  // !VERLETINTEGRATOR_H
