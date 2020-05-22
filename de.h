#ifndef __DE_H
#define __DE_H


#include <stdio.h>
#include <stdlib.h> //Pour importer randint
#include <time.h>


struct de{
	int code_value; //couleur. 0:vert, 1:jaune, 2:rouge
	int resultat; //resultat du de. autre:non lance, 1:cerveau, 2:empreintes, 3:fusil
};

void print_de( struct de d );
void lancer2(struct de* d);
void selection_des(struct de* d, int Sto[3]);



#endif  // __DE_H
