
CC= gcc -std=c99 -Wall -Wextra
INCLUDE= `sdl2-config --cflags`
LIBS= `sdl2-config --libs`

all: de.o sprite.o interface.o jeu.o main.o
	$(CC) -o Zombie de.o sprite.o interface.o jeu.o main.o $(LIBS)

main.o: de.h jeu.h main.c
	$(CC) -c main.c

de.o: de.h de.c
	$(CC) -c de.c

jeu.o: interface.h jeu.h jeu.c
	$(CC) -c jeu.c

interface.o: sprite.h interface.h interface.c
	$(CC) $(INCLUDE) -c interface.c

sprite.o: sprite.h sprite.c
	$(CC) $(INCLUDE) -c sprite.c

clear: .
	rm *.o
