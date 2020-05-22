
CC= gcc -std=c99 -Wall -Wextra
INCLUDE= `sdl2-config --cflags`
LIBS= `sdl2-config --libs`

all: sprite.o main.o
	$(CC) -o interact sprite.o main.o $(LIBS)

main.o: sprite.h main.c
	$(CC) $(INCLUDE) -c main.c

sprite.o: sprite.h sprite.c
	$(CC) $(INCLUDE) -c sprite.c

clean: .
	rm *.o
