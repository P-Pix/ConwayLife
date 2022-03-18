#include "../../include/Game.hpp"

Game::Game(void) {
    this->initMatrix();
}

Game::Game(size_t width, size_t height) {
    this->m_Height = height;
    this->m_Width = width;
    this->initMatrix();
}

Game::~Game(void) {

}

void Game::initMatrix() {
    // init random seed
    srand(time(NULL));
    this->m_Matrix = new bool*[this->m_Height];
    for (size_t i = 0; i < this->m_Height - 0; i++) {
        this->m_Matrix[i] = new bool[this->m_Width];
        for (size_t j = 0; j < this->m_Width - 0; j++) {
            this->m_Matrix[i][j] = rand() % 2;
        }
    }
}

void Game::print(void) {
    for (size_t i = 0; i < this->m_Height; i++) {
        for (size_t j = 0; j < this->m_Width; j++) {
            std::cout << this->m_Matrix[i][j];
        }
        std::cout << std::endl;
    }
}

bool Game::allDead(void) {
    for (size_t i = 0; i < this->m_Height; i++) {
        for (size_t j = 0; j < this->m_Width; j++) {
            if (this->m_Matrix[i][j]) {
                return false;
            }
        }
    }
    return true;
}

bool **Game::getMatrix(void) {
    return this->m_Matrix;
}

void Game::update(void) {
    bool **tmp = new bool*[this->m_Height];
    for (size_t i = 0; i < this->m_Height; i++) {
        tmp[i] = new bool[this->m_Width];
        for (size_t j = 0; j < this->m_Width; j++) {
            tmp[i][j] = false;
        }
    }
    for (size_t i = 1; i < this->m_Height - 1; i++) {
        for (size_t j = 1; j < this->m_Width - 1; j++) {
            int neighbors = this->m_Matrix[i - 1][j - 1]
                + this->m_Matrix[i - 1][j]
                + this->m_Matrix[i - 1][j + 1]
                + this->m_Matrix[i][j - 1]
                + this->m_Matrix[i][j + 1]
                + this->m_Matrix[i + 1][j - 1]
                + this->m_Matrix[i + 1][j]
                + this->m_Matrix[i + 1][j + 1];
            if (this->m_Matrix[i][j]) {
                if (neighbors == 2 || neighbors == 3) {
                    tmp[i][j] = true;
                }
            } else {
                if (neighbors == 3) {
                    tmp[i][j] = true;
                }
            }
        }
    }
    for (size_t i = 0; i < this->m_Height; i++) {
        for (size_t j = 0; j < this->m_Width; j++) {
            this->m_Matrix[i][j] = tmp[i][j];
        }
    }
}