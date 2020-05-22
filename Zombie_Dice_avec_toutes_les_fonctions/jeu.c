#include <stdio.h>
#include <stdlib.h> //Pour importer randint et malloc
#include <time.h>
#include "jeu.h"


//Fonction pour qui demande au joueur s'il souhaite jouer ou Scorer
int action_joueur(){
	char choix = 'a';
	printf("Que souhaitez-vous faire ?\nVeuillez entrer l'entier correspondant\n1/Jouer\n2/Scorer\n");
	while(choix!='1' && choix!='2'){
		scanf(" %c",&choix);
		if(choix!='1' && choix!='2'){
			printf("ERREUR : Veuillez entrer un nombre correct !\n");
		}
	}
	int num_choix;
	switch(choix) {
		case '1':
			printf("Vous avez choisi de jouer\n");
			num_choix = 1;
			break;
		case '2':
			printf("Vous avez choisi de scorer\n");
			num_choix = 2;
			break;
		default:
			printf("default");
			num_choix = 0;
	}

	return num_choix;
}

//La boucle de jeu
int jouer(int IA){
// SI IA==1 alors ordi joue, sinon humain joue
//la fonction va renvoyer le nombre de points
	int nb_cerveaux = 0, nb_fusils = 0; //Compteurs du nombre de cerveaux et du nombre de fusils
	int jouer = 1; //Savoir si on joue ou si on score
	int repioche_A = 1,  repioche_B = 1, repioche_C = 1; //Est-ce qu'on a eu une empreinte ou pas ? Si oui on repioche un de dans le stock, sinon on relance le meme de

	//Tant qu'on joue, on lance les des
	while(jouer == 1){
		//Lancer les 3 des
		//Declaration des de
		struct de A, B, C;
		//Selection des 3 des
		if(repioche_A == 1){
			selection_de(&A);
		}
		if(repioche_B == 1){
			selection_de(&B);
		}
		if(repioche_C == 1){
			selection_de(&C);
		}
		//On remet les repioche en 1 avant de savoir leur resultat
		repioche_A = 1;
		repioche_B = 1;
		repioche_C = 1;

		//Lancer les 3 des
		lancer2(&A);
		lancer2(&B);
		lancer2(&C);
		//Recuperation des resultats
		if(A.resultat == 1){
			nb_cerveaux += 1;
		}
		else if(A.resultat == 3){
			nb_fusils += 1;
		}
		else{
			repioche_A = 0; //on conserve le meme de
		}
		if(B.resultat == 1){
			nb_cerveaux += 1;
		}
		else if(B.resultat == 3){
			nb_fusils += 1;
		}
		else{
			repioche_B = 0; //on conserve le meme de
		}
		if(C.resultat == 1){
			nb_cerveaux += 1;
		}
		else if(C.resultat == 3){
			nb_fusils += 1;
		}
		else{
			repioche_C = 0; //on conserve le meme de
		}

		printf("\nLes 3 des que nous avons sont :\n");
		print_de(A);
		print_de(B);
		print_de(C);
		printf("nombre de cerveaux : %d\n", nb_cerveaux);
		printf("nombre de fusils : %d\n", nb_fusils);

		//Est-ce qu'on peut choisir de rejouer ?
		if(Stock[0]+Stock[1]+Stock[2] < 3 && nb_fusils < 3){
			return nb_cerveaux;
		}
		if(nb_fusils < 3){
			if(IA==0){
				jouer = action_joueur(); //1 si rejoue; 2 si veut scorer
			}
			else if(IA==1){
				//Savoir si l'IA rejoue ou pas
				jouer = rand() %(2) + 1;
			}
			else{
				if(nb_fusils>=2){
					jouer = 0;
				}
			}
		}
		else{
			//J'ai pris plus de 3 fusils, je ne marque pas de points
			printf("Vous avez perdu !\n");
			return 0;
		}
	}

	//arrivé ici, on a nécessairement choisi de scorer, et on converti le nombre de cerveaux en nombre de points
	return nb_cerveaux;

}



//La boucle de jeu amelioree
int jouer2(int IA, int nb_de){
// SI IA==1 alors ordi joue, sinon humain joue
//la fonction va renvoyer le nombre de points
	struct Game jeu= new_game(nb_de);

	int jouer = 1; //Savoir si on joue ou si on score

	//Tant qu'on joue, on lance les des
	while(jouer == 1){
		//Lancer les des
		for(int i=0; i<nb_de; i++){
			//Selection du de
			if(jeu.main[i].resultat != 2){
				selection_des(&jeu.main[i], jeu.Stock);
				jeu.Stock[jeu.main[i].code_value] -= 1;
			}
			//Lancer le de
			lancer2(&jeu.main[i]);

			//Recuperation des resultats
			if(jeu.main[i].resultat == 1){
				jeu.nb_cerveaux += 1;
			}
			else if(jeu.main[i].resultat == 3){
				jeu.nb_fusils += 1;
			}
		}

		printf("\nLes %d des que nous avons sont :\n", nb_de);
		for(int i=0; i<nb_de; i++){
			print_de(jeu.main[i]);
		}
		printf("nombre de cerveaux : %d\n", jeu.nb_cerveaux);
		printf("nombre de fusils : %d\n", jeu.nb_fusils);

		//Est-ce qu'on peut choisir de rejouer ?
		if(jeu.Stock[0]+jeu.Stock[1]+jeu.Stock[2] < 3 && jeu.nb_fusils < 3){
			int nb_cerveaux = jeu.nb_cerveaux;
			destroy_game(jeu);
			return nb_cerveaux;
		}
		if(jeu.nb_fusils < 3){
			if(IA==0){
				jouer = action_joueur(); //1 si rejoue; 2 si veut scorer
			}
			else if(IA==1){
				//Savoir si l'IA rejoue ou pas
				jouer = rand() %(2) + 1;
			}
			else{
				if(jeu.nb_fusils>=2){
					jouer = 0;
				}
			}
		}
		else{
			//J'ai pris plus de 3 fusils, je ne marque pas de points
			return 0;
		}
	}

	//arrivé ici, on a nécessairement choisi de scorer, et on converti le nombre de cerveaux en nombre de points

	int nb_cerveaux = jeu.nb_cerveaux;
	destroy_game(jeu);
	return nb_cerveaux;
}

//Creation d'un nouveau plateau de jeu
Game new_game(int nb_de){
	Game jeu;
	jeu.nb_cerveaux = 0;
	jeu.nb_fusils = 0;

	//Initialisation du Stock
	jeu.Stock[0] = 0;//6;
	jeu.Stock[1] = 0;//4;
	jeu.Stock[2] = 1000;//3;

	//Utilisation d'une variable intermediaire. Pb: une fois qu'on sort de cette methode, la variable va etre detruite
	jeu.main= (struct de *) malloc(nb_de * sizeof(struct de));

	//Est-ce qu'on a eu une empreinte ou pas ? Si non on repioche un de dans le stock, si oui on relance le meme de
	for(int i=0; i<nb_de; i++){
		jeu.main[i].resultat = 1;
	}
	return jeu;
}

void destroy_game(Game g){
	free(g.main);
}
