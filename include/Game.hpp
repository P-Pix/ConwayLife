#pragma once

#include <iostream>

class Game {
private:
    bool **m_Matrix;
    size_t m_Width = 0;
    size_t m_Height = 0;

    void initMatrix(void);
public:
    Game(void);
    Game(size_t width, size_t height);
    ~Game(void);

    void print(void);
    void update(void);

    bool **getMatrix(void);
    bool allDead(void);
};