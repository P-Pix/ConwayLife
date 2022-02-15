#pragma once

#include <iostream>
#include <SDL2/SDL.h>

class Window {
private:
    SDL_Window* m_Window;
    SDL_Renderer* m_Renderer;

    size_t m_Width;
    size_t m_Height;

public:
    Window(const char* title, int x, int y, int w, int h);
    ~Window();

    void clear();
    void update(bool **matrix);
};