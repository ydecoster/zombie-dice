#ifndef __INTERFACE_H
#define __INTERFACE_H


#include <stdio.h>  // STandard Input Output functions


int interface(int nb_des, int couleur[nb_des], int symbole[nb_des]);
void createF(int k, int nb_des);
void createE(int k, int nb_des);
void createC(int k, int nb_des);
int create_sdl();
void destroy_sdl();
void tick_sdl(int ms);


#endif  // __INTERFACE_H
