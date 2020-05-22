#ifndef __JEU_H
#define __JEU_H

#include <stdio.h>
#include <stdlib.h> //Pour importer randint et malloc
#include <time.h>
#include "de.h"


typedef struct Game{
	struct de *main; //la main
	int Stock[3]; //le Stock de dés
	int nb_cerveaux; //nombre de cerveaux
	int nb_fusils; //nombre de fusils
}Game;

int action_joueur();
int jouer2(int IA, int nb_de);
Game new_game(int nb_de);
void destroy_game(Game g);

#endif  // __JEU_H
