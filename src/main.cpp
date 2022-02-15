#include "../include/Game.hpp"
#include "../include/Window.hpp"

#include <thread>

#define MAX_LONG_LONG 9223372036854775807

int main(int argc, char *argv[]) {
    Game game(200, 200);
    Window window("Game of life", 50, 50, 600, 600);

    unsigned long long i = 0;
    while (!game.allDead() && i < 1000) {
        game.update();
        window.update(game.getMatrix());
        i++;
        std::this_thread::sleep_for(std::chrono::milliseconds(1 / 24));
    }

    return EXIT_SUCCESS;
}