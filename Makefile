CC=g++
CFLAGS=-W -Wall -ansi -pedantic -std=c++11
LDFLAGS=
EXEC=game unittest

all: $(EXEC)

game: game.o main.o
	$(CC) -o $@ $^ $(LDFLAGS)

unittest: game.o unittest1.o
	$(CC) -o $@ $^ $(LDFLAGS)
	
game.o: game.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

main.o: main.cpp game.h
	$(CC) -o $@ -c $< $(CFLAGS)
	
unittest1.o: unittest1.cpp game.h
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
	
test:
	./unittest.exe