FLAGG = `sdl2-config --cflags --libs`\

all:
	mkdir -p test
	g++ -o test/main.o src/main.cpp src/Window/*.cpp src/Game/*.cpp $(FLAGG)
	./test/main.o