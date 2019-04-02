#include "Particles.h"
#include <stdlib.h>
#include <math.h>

Particles::Particles(): m_x(0), m_y(0)
{
//    m_x = ((2.0 * rand())/RAND_MAX) - 1; // ar 2.0 * palielinam range no 0 - 1 uz 0 - 2 // ar -1 nomainam to uz -1 lidz 1
//    m_y = ((2.0 * rand())/RAND_MAX) - 1;

//    m_xSpeed = 0.01 * (((2.0 * rand())/RAND_MAX) - 1); // aizvietos ar jaunam f-jam, jo japariet uz cirkularo kustibu
//    m_ySpeed = 0.01 * (((2.0 * rand())/RAND_MAX) - 1);
   init();
}

Particles::~Particles()
{
    //dtor
}

void Particles::init(){
    m_x = 0;
    m_y = 0;
    m_direction = (2 * 3.14529 * rand())/RAND_MAX;
    m_speed = (0.02 * rand())/RAND_MAX;

    m_speed *= m_speed;
}

//void Particles::start(){  mana ideja ka radit eksploziju // visas start f-jas
//    m_x = 0.0;
//    m_y = 0.0;
//}

void Particles::update(int interval)
{
//    m_x += m_xSpeed; // ari tiks aizvietota
//    m_y += m_ySpeed;
//
//    if(m_x <= -1.0 || m_x >= 1.0){
//        m_xSpeed = -m_xSpeed;
//    }
//    if(m_y <= -1.0 || m_y >= 1.0){
//        m_ySpeed = -m_ySpeed;
//    }

    m_direction += interval * 0.0008;

    double xSpeed = m_speed * cos(m_direction);
    double ySpeed = m_speed * sin(m_direction);

    m_x += xSpeed * interval;
    m_y += ySpeed * interval;

    if(m_x < -1 || m_x > 1 || m_y < -1 || m_y > 1){
        init();
    }
    if(rand() < RAND_MAX/1000){
        init();
    }
}
