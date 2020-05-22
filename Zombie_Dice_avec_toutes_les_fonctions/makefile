
CC= gcc -std=c99 -Wall -Wextra

all: de.o jeu.o main.o
	$(CC) -o Zombie de.o jeu.o main.o

main.o: de.h jeu.h main.c
	$(CC) -c main.c

de.o: de.h de.c
	$(CC) -c de.c

jeu.o: jeu.h jeu.c
	$(CC) -c jeu.c

clear: .
	rm *.o
