#include <stdio.h>
#include <stdlib.h> //Pour importer randint
#include <time.h>
#include "jeu.h"


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

	//Initialisation des randoms
	srand((int)time(NULL));


	//Jouer
	//Joueur reel
	if(IA==0){
		pts = jouer2(0, 3);
	}
	// 1 pour IA1
	else if(IA==1){
		pts = jouer2(1, 3);
	}
	else if(IA==2){
		pts = jouer2(2, 3);
	}
	else{
		printf("ce numero d'IA n'existe pas...");
		return 0;
	}
	printf("points : %d\n", pts);
}
