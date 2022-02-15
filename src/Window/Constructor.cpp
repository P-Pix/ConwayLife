#include "../../include/Window.hpp"

Window::Window(const char* title, int x, int y, int w, int h) {
    this->m_Window = SDL_CreateWindow(title, x, y, w, h, SDL_WINDOW_SHOWN);
    if (this->m_Window == NULL) {
        std::cout << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
    }
    this->m_Renderer = SDL_CreateRenderer(this->m_Window, -1, SDL_RENDERER_ACCELERATED);
    if (this->m_Renderer == NULL) {
        std::cout << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
    }
    this->m_Width = w;
    this->m_Height = h;
}
Window::~Window() {
    SDL_DestroyRenderer(this->m_Renderer);
    SDL_DestroyWindow(this->m_Window);
}

void Window::clear() {
    SDL_RenderClear(this->m_Renderer);
}
void Window::update(bool **matrix) {
    for (int i = 0; i < this->m_Height; i++) {
        for (int j = 0; j < this->m_Width; j++) {
            if (matrix[i][j]) {
                SDL_SetRenderDrawColor(this->m_Renderer, 0x00, 0x00, 0x00, 0xFF);
            } else {
                SDL_SetRenderDrawColor(this->m_Renderer, 0xFF, 0xFF, 0xFF, 0xFF);
            }
            SDL_RenderDrawPoint(this->m_Renderer, j, i);
        }
    }
    SDL_RenderPresent(this->m_Renderer);
}