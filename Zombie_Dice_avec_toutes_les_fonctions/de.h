#ifndef __DE_H
#define __DE_H


#include <stdio.h>
#include <stdlib.h> //Pour importer randint
#include <time.h>

extern int Stock[2];

struct de{
	/*
	int numero_de; //Parametre devenu inutile, correspond à l'identifiant du de : chaque de a son numero de de
	*/
	int code_value; //couleur. 0:vert, 1:jaune, 2:rouge
	int resultat; //resultat du de. autre:non lance, 1:cerveau, 2:empreintes, 3:fusil
};

void print_de( struct de d );
int couleur_de(struct de d);
struct de lancer(struct de d);
void lancer2(struct de* d);
void selection_de(struct de* d);



#endif  // __DE_H
