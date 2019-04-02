#ifndef SCREEN_H
#define SCREEN_H

#include <cstring>
#include <SDL.h>


//privatajiem prieksa m_ tadejadi pasakot ka tie ir privatie klases mainigie
class Screen
{
public:
        const static int SCREEN_WIDTH = 500;
        const static int SCREEN_HEIGHT = 500;
private:
        SDL_Window *m_window;
        SDL_Renderer *m_renderer;
        SDL_Texture *m_texture;
        Uint32 *m_buffer1;
        Uint32 *m_buffer2;
public:
        Screen();
        bool init();
        bool processEvents();
        void close();
        void update();
        void clear();
        void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
        void boxBlur();
};

#endif // SCREEN_H
