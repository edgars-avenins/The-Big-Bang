#ifndef PARTICLES_H
#define PARTICLES_H


struct Particles
{
    double m_x;
    double m_y;

    double m_speed;
    double m_direction;
public:
    Particles();
    virtual ~Particles();
    void update(int interval);
    void init();
    //void start();
};

#endif // PARTICLES_H
