FLAGG = `sdl2-config --cflags --libs`\

all:
	g++ -o test/main src/main.cpp src/Window/*.cpp src/Game/*.cpp $(FLAGG)