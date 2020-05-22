#include "sprite.h"

#define CANAL_R   0 // Red
#define CANAL_G   1 // Green
#define CANAL_B   2 // Blue
#define CANAL_Y   3 // Yellow
#define CANAL_A   4 // Alfa
#define CANAL_NB 5

short color_def[COLOR_NB][CANAL_NB]={
  {180, 0, 0, 255}, // COLOR_RED
  {0, 180, 0, 255}, // COLOR_GREEN
  {0, 0, 180, 255},  // COLOR_BLUE
  {180, 180, 0, 255} //COLOR_YELLOW
};

/*
 * sprite initialisation:
 */
sprite new_sprite( int x, int y, int width, int height ){
  sprite s;
  s.x= x;
  s.y= y;
  s.width= width;
  s.height= height;

  return s;
}

/*
 * sprite drawing:
 */
void draw( SDL_Renderer * rend, sprite * s, int c){
    SDL_SetRenderDrawColor( rend,
                            color_def[c][CANAL_R],
                            color_def[c][CANAL_G],
                            color_def[c][CANAL_B],
                            color_def[c][CANAL_A]);
    SDL_Rect rect;
    rect.x= s->x;
    rect.y= s->y;
    rect.w= s->width;
    rect.h= s->height;

    SDL_RenderFillRect( rend, &rect );
}

/*
 * sprite movement:
 */
void move( sprite * s, int x, int y ){
  s->x= x - s->width/2;
  s->y= y - s->height/2;
}
