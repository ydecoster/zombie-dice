#ifndef SPRITE_H
#define SPRITE_H

#include <SDL.h>

/*
 * quelques constantes : 
 */
#define W_WIDTH   640
#define W_HEIGHT  480

#define COLOR_RED   0
#define COLOR_GREEN 1
#define COLOR_BLUE  2
#define COLOR_NB    3

/*
 * Structure for a Sprite: 
 */
struct sprite_str {
  int x, y, width, height;
};

/*
 * Definition of a new type link to the Dice struct
 */
typedef struct sprite_str sprite;

/*
 * sprite initialisation:
 */
sprite new_sprite( int x, int y, int width, int height );

/*
 * sprite drawing:
 */
void draw( SDL_Renderer * rend, sprite * s, int color );

/*
 * sprite movement:
 */
void move( sprite * s, int x, int y );


#endif