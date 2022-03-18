#include "../include/Game.hpp"
#include "../include/Window.hpp"

#include <thread>

#define MAX_LONG_LONG 9223372036854775807

int main(int argc, char *argv[]) {
    Game game(200, 200);
    Window window("Game of life", 50, 50, 600, 600);
    unsigned long long numberOfGenerations = 0;
    while (numberOfGenerations == 0) {
        std::cout << "Thanks to use my code, please enter the number of generations you want to play: ";
        std::cin >> numberOfGenerations;
    }
    if (numberOfGenerations > MAX_LONG_LONG) {
        numberOfGenerations = MAX_LONG_LONG;
    }

    unsigned long long i = 0;
    while (!game.allDead() && i < numberOfGenerations) {
        game.update();
        window.update(game.getMatrix());
        i++;
        std::this_thread::sleep_for(std::chrono::milliseconds(1 / 12));
        std::cout << "Number of Year = " << i << std::endl;
    }

    return EXIT_SUCCESS;
}