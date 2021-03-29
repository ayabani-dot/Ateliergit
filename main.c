/*#include <stdlib.h> 
#include <stdio.h> 
#include <SDL/SDL.h> 
#include <SDL/SDL_image.h>
#include "fonction.h"

void main (int argc,char *argv)
{
int continuer=1;
SDL_GetTicks() ;
sprite p;
char personnage[20];
SDL_Event event;
SDL_Surface *ecran = NULL, *pers = NULL;

if (SDL_Init (SDL_INIT_VIDEO) == -1) 
{
printf ("Can't init SDL: %s\n", SDL_GetError ());
return EXIT_FAILURE;
}
ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE);
while (continuer)
{
initpers (&p,personnage);
afficher (ecran,p);


SDL_Surface *lifes=NULL,*score=NULL,*heart1=NULL,*heart2=NULL,*heart3=NULL;

SDL_Rect position_heart1;
	
SDL_Rect position_heart2;

SDL_Rect position_heart3;

SDL_Flip(ecran);


}

}
*/
  #include "fonction.h" 
SDL_Surface* screen = NULL;
 int main(void) 
{ initEverything();
 loadLevels(); 
paintMenu(screen);
 closeEverything(); return 0; }
 /** * Inits the libraries we're going to use */
 void initEverything()
 { SDL_Init(SDL_INIT_EVERYTHING); 
TTF_Init();
 Mix_Init(MIX_INIT_MP3); 
IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);
 screen = SDL_SetVideoMode(800, 600, 0, SDL_HWSURFACE); 
SDL_WM_SetCaption("Wizards of War", NULL); } 
/** * Clean everything before we exit the game */
 void closeEverything()
 {atexit(Mix_Quit); atexit(IMG_Quit); atexit(TTF_Quit); atexit(SDL_Quit); }


