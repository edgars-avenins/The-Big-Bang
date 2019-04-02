#ifndef SWARM_H
#define SWARM_H

#include "Particles.h"

class Swarm
{
public:
    const static int NPARTICLES = 10000;
private:
    Particles *m_pParticles;
    int lastTime;

public:
    Swarm();
    virtual ~Swarm();

    const Particles *const getParticles(){ return m_pParticles;};
    void update(int elapsed);
    //void start();
};

#endif // SWARM_H
