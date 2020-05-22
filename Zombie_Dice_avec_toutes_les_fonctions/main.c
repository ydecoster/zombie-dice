#include <stdio.h>
#include <stdlib.h> //Pour importer randint
#include <time.h>
#include "jeu.h"


//Creation de la variable globale stock
int Stock[2]; // indice : 0->vert, 1->jaune, 2->rouge

int main(int nb_arg, char * arg[]){
	//On regarde si on a le bon nombre d'arguments
	if(nb_arg != 2){
		printf("Attention :  Zombie <int>\n<int> -----> 0 : Joueur humain      Autre : Ordi\n");
		return 0;
	}
	//Creation de pts qui retournera le nombre de pts
	int pts;

	//Transforme le deuxieme argument en entier
	int IA = strtol(arg[1], NULL, 10);
	//printf("%i='%d'\n",1, IA);

	//Initialisation du Stock
	Stock[0] = 6;
	Stock[1] = 4;
	Stock[2] = 3;

	//Initialisation des randoms
	srand((int)time(NULL));


	//Jouer
	//Joueur reel
	if(IA==0){
		pts = jouer2(0, 3);
	}
	// 1 pour IA1
	else if(IA==1){
		pts = jouer(1);
	}
	else if(IA==2){
		pts = jouer(2);
	}
	else{
		printf("ce numero d'IA n'existe pas...");
		return 0;
	}
	printf("points : %d\n", pts);
}
