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
    this->m_Width = w / 3;
    this->m_Height = h / 3;
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
            // draw 3 * 3 square
            if (matrix[i][j]) {
                SDL_SetRenderDrawColor(this->m_Renderer, 0, 0, 0, 255);
            } else {
                SDL_SetRenderDrawColor(this->m_Renderer, 255, 255, 255, 255);
            }
            SDL_Rect rect = {j * 3, i * 3, 3, 3};
            SDL_RenderFillRect(this->m_Renderer, &rect);
        }
    }
    SDL_RenderPresent(this->m_Renderer);
}