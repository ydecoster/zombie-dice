#include <stdio.h>
#include <stdlib.h> //Pour importer randint
#include <time.h>
#include "de.h"

//pour afficher un de : sa couleur et son résultat (une fois lance)
void print_de( struct de d ){
	//On commence par regarder la couleur du de
	switch(d.code_value){
		case 0:
				printf("De vert\t");
            break;
        case 1:
				printf("De jaune\t");
            break;
		case 2:
				printf("De rouge\t");
			break;
		default:
		printf("default");
	}
	//On regarde son resultat
	switch(d.resultat){
		case 1:
				printf("etat : cerveau\n");

            break;
        case 2:
				printf("etat : empreintes\n");
            break;
		case 3:
				printf("etat : fusil\n");
			break;
		default:
		printf("default");
	}
}

/*
//choisir la bonne couleur pour un indentifiant de de choisi. Fonction devenue obselette
int couleur_de(struct de d){
	if(d.numero_de <=6){
		return 0; //vert
	}
	else if(d.numero_de>=11){
		return 2; //rouge
	}
	else {
		return 1; //jaune
	}
}
*/


//Lancer un de sans utiliser de pointeur
struct de lancer(struct de d){
	int numero_face = rand() %6 + 1;
	if(d.code_value==0){ //si le de est vert
		if(numero_face<=3){ //cerveaux
			d.resultat = 1;
		}
		else if(numero_face==6){ //shotgun
			d.resultat = 3;
		}
		else { //empreintes
			d.resultat = 2;
		}
	}
	if(d.code_value==1){ //si le de est jaune
		if(numero_face<=2){ //cerveaux
			d.resultat = 1;
		}
		else if(numero_face>=5){ //shotgun
			d.resultat = 3;
		}
		else { //empreintes
			d.resultat = 2;
		}
	}
	if(d.code_value==2){ //si le de est rouge
		if(numero_face==1){ //cerveaux
			d.resultat = 1;
		}
		else if(numero_face>=4){ //shotgun
			d.resultat = 3;
		}
		else { //empreintes
			d.resultat = 2;
		}
	}
	return d;
}


//Lancer un de version pointeur
void lancer2(struct de* d){
	int numero_face = rand() %6 + 1;
	if(d->code_value==0){ //si le de est vert
		if(numero_face<=3){ //cerveaux
			d->resultat = 1;
		}
		else if(numero_face==6){ //shotgun
			d->resultat = 3;
		}
		else { //empreintes
			d->resultat = 2;
		}
	}
	if(d->code_value==1){ //si le de est jaune
		if(numero_face<=2){ //cerveaux
			d->resultat = 1;
		}
		else if(numero_face>=5){ //shotgun
			d->resultat = 3;
		}
		else { //empreintes
			d->resultat = 2;
		}
	}
	if(d->code_value==2){ //si le de est rouge
		if(numero_face==1){ //cerveaux
			d->resultat = 1;
		}
		else if(numero_face>=4){ //shotgun
			d->resultat = 3;
		}
		else { //empreintes
			d->resultat = 2;
		}
	}
}

//Selectionner un de dans le stock
void selection_de(struct de* d){
	//On regarde quelle indice de dé on tire
	int indice = rand() %(Stock[0]+Stock[1]+Stock[2]) + 1;
	//On regarde à quelle indice la couleur correspond
	if(indice <= Stock[0]){
		d->code_value = 0;
		Stock[0] -= 1;
	}
	else if(indice <= Stock[0]+Stock[1]){
		d->code_value = 1;
		Stock[1] -= 1;
	}
	else {
		d->code_value = 2;
		Stock[2] -= 1;
	}
	d->resultat = 100000; //Pour le fun !
}


//Selectionner un de dans le stock
void selection_des(struct de* d, int Sto[3]){
	enum couleur_de{de_vert, de_jaune, de_rouge};
	enum couleur_de v,j,r;
	v = de_vert;
	j = de_jaune;
	r = de_rouge;
	//On regarde quelle indice de dé on tire
	int indice = rand() %(Sto[v]+Sto[j]+Sto[r]) + 1;
	//On regarde à quelle indice la couleur correspond
	if(indice <= Sto[v]){
		d->code_value = 0;
	}
	else if(indice <= Sto[v]+Sto[j]){
		d->code_value = 1;
	}
	else {
		d->code_value = 2;
	}
	d->resultat = 100000; //Pour le fun !
}
