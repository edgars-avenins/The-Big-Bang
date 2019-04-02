#include <iostream>
#include <SDL.h>
#include <cstring>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#include "Screen.h"
#include "Swarm.h"

using std::cout;
using std::endl;

int main(int argc, char* argv[])
{

    srand(time(NULL));


    Screen screen;
    screen.init();
    // int maxVal = 0;
    Swarm swarm;

    while(true)
    {
        /*
            * Update particles
            * Draw particles
            * Check for messages/events
        */
        int elapsed = SDL_GetTicks();

        swarm.update(elapsed);




        unsigned char red = (1 + sin(elapsed * 0.0005)) * 128;
        unsigned char green = (1 + sin(elapsed * 0.0004)) * 128;
        unsigned char blue = (1 + sin(elapsed * 0.0003)) * 128;



        const Particles *const pParticles = swarm.getParticles();
        for(int i = 0; i < Swarm::NPARTICLES; i++)
        {
            Particles particles = pParticles[i];



            int x = (particles.m_x + 1) * (Screen::SCREEN_WIDTH/2);
            int y = (particles.m_y * Screen::SCREEN_WIDTH/2 + Screen::SCREEN_HEIGHT/2);

            screen.setPixel(x, y, red, green, blue);
        }
        screen.boxBlur();
        screen.update();

        if(!screen.processEvents())
        {
            break;
        }
    }
    screen.close();
    return 0;
}
