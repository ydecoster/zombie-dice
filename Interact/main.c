#include <stdio.h>  // STandard Input Output functions
#include <SDL.h>

#include "sprite.h"

/* Globals variables */
SDL_Window * win;
SDL_Renderer * rend;

/* SDL managment */
int create_sdl();
void destroy_sdl();
void tick_sdl();


/* Le main : */
int main(int nb_arg, char * arg[] ){
    if(nb_arg != 2){
      printf("Attention :  interact <int>\n<int> -----> Nombre de des\n");
      return 0;
    }

    //Transforme le deuxieme argument en entier
    int nb_des = strtol(arg[1], NULL, 10);

    //Definit la taille du rectangle de couleur representant le de
    sprite red= new_sprite( 50, 50, 50, 50 );

    // Initialize SDL
    if ( !create_sdl() )
      return 1;

    // set a black background
    tick_sdl(100);

		//On va afficher tous les des qu'on a tire
		for(int k=0; k<nb_des; k++){

			// move and draw a rectangle
			move( &red, (k+1)*W_WIDTH/(nb_des+1), W_HEIGHT/2); //On utilise k+1 pour faire un espacement egal entre chaque des
			draw( rend, &red, COLOR_RED);
      createE(k, nb_des);
		}

    tick_sdl(4000);

    destroy_sdl();

    // End ok
    return 0;
  }

  //Creation lettre F
  void createF(int k, int nb_des){
    sprite I = new_sprite( 10, 40, 10, 40 );
    move( &I, (k+1)*W_WIDTH/(nb_des+1) - 12 , W_HEIGHT/2); //On utilise k+1 pour faire un espacement egal entre chaque des
    draw( rend, &I, COLOR_BLUE);
    sprite Fbar = new_sprite( 35, 5, 35, 5 );
    move( &Fbar, (k+1)*W_WIDTH/(nb_des+1), W_HEIGHT/2 - 18); //On utilise k+1 pour faire un espacement egal entre chaque des
    draw( rend, &Fbar, COLOR_BLUE);
    sprite Fbar2 = new_sprite( 30, 5, 30, 5 );
    move( &Fbar2, (k+1)*W_WIDTH/(nb_des+1), W_HEIGHT/2 - 2); //On utilise k+1 pour faire un espacement egal entre chaque des
    draw( rend, &Fbar2, COLOR_BLUE);
  }

  //Creation lettre E
  void createE(int k, int nb_des){
    sprite I = new_sprite( 10, 40, 10, 40 );
    move( &I, (k+1)*W_WIDTH/(nb_des+1) - 12 , W_HEIGHT/2); //On utilise k+1 pour faire un espacement egal entre chaque des
    draw( rend, &I, COLOR_BLUE);
    sprite Fbar = new_sprite( 35, 5, 35, 5 );
    move( &Fbar, (k+1)*W_WIDTH/(nb_des+1), W_HEIGHT/2 - 18); //On utilise k+1 pour faire un espacement egal entre chaque des
    draw( rend, &Fbar, COLOR_BLUE);
    move( &Fbar, (k+1)*W_WIDTH/(nb_des+1), W_HEIGHT/2); //On utilise k+1 pour faire un espacement egal entre chaque des
    draw( rend, &Fbar, COLOR_BLUE);
    move( &Fbar, (k+1)*W_WIDTH/(nb_des+1), W_HEIGHT/2 + 18); //On utilise k+1 pour faire un espacement egal entre chaque des
    draw( rend, &Fbar, COLOR_BLUE);
  }

  //Creation lettre C
  void createC(int k, int nb_des){
    sprite I = new_sprite( 10, 40, 10, 40 );
    move( &I, (k+1)*W_WIDTH/(nb_des+1) - 12 , W_HEIGHT/2); //On utilise k+1 pour faire un espacement egal entre chaque des
    draw( rend, &I, COLOR_BLUE);
    sprite Fbar = new_sprite( 35, 5, 35, 5 );
    move( &Fbar, (k+1)*W_WIDTH/(nb_des+1), W_HEIGHT/2 - 18); //On utilise k+1 pour faire un espacement egal entre chaque des
    draw( rend, &Fbar, COLOR_BLUE);
    move( &Fbar, (k+1)*W_WIDTH/(nb_des+1), W_HEIGHT/2 + 18); //On utilise k+1 pour faire un espacement egal entre chaque des
    draw( rend, &Fbar, COLOR_BLUE);
  }


  //Creation de la fênetre noire : celle ou les des vont apparaitre
  int create_sdl(){
      // Initialize SDL
      if (SDL_Init(SDL_INIT_VIDEO) != 0){
          printf( "SDL_Init Error: %s\n", SDL_GetError() );
          return 0;
      }

      // Create a window
      win = SDL_CreateWindow("Lances des des", 100, 100, W_WIDTH, W_HEIGHT, SDL_WINDOW_SHOWN);
      if (win == NULL){
          printf( "SDL_CreateWindow Error: %s\n", SDL_GetError() );
          SDL_Quit();
          return 0;
      }

      // Create a SDL_Renderer associate to the window (structure allowing drawing)
      rend = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
      if (rend == NULL){
          printf( "SDL_CreateRenderer Error: %s\n", SDL_GetError() );
          SDL_DestroyWindow(win);
          SDL_Quit();
          return 0;
      }

      return 1;
  }

  //Suppression de la fenetre noire de nos des
  void destroy_sdl(){
      // Properly terminate the programme (free SDL ressources)
      SDL_DestroyWindow(win);
      SDL_Quit();
  }


  //Une fonction qui permet de remettre l'affichage de la fênetre noire à la configuration initiale, a savoir rien dedans
  void tick_sdl(int ms){
    // actualize the window with the drawn render.
    SDL_RenderPresent(rend);

    // wait 3 seconds.
    SDL_Delay(ms);

    // set a black background
    SDL_SetRenderDrawColor( rend, 0, 0, 0, 255);
    SDL_RenderClear(rend);      /* Clear the entire screen to our selected color. */
  }
