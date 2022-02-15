#include "../include/Game.hpp"
#include "../include/Window.hpp"

#include <thread>

#define MAX_LONG_LONG 9223372036854775807

int main(int argc, char *argv[]) {
    Game game(200, 200);
    Window window("Game", 50, 50, 200, 200);

    unsigned long long i = 0;
    while (!game.allDead() && i < 1000) {
        game.update();
        window.update(game.getMatrix());
        i++;
        // attendre 1/60 seconde
        //std::this_thread::sleep_for(std::chrono::milliseconds(16));
        //game.print();
    }

    return EXIT_SUCCESS;
}