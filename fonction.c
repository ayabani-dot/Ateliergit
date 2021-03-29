/*#include <stdio.h> 
#include <SDL/SDL.h> 
#include <SDL/SDL_image.h> 
#include "fonction.h"
#include "main.c"
void initpers (sprite * p,char personnage[])
{
p->pers = IMG_Load ("personnage");
p->position.x =0;
p->position =0;
p->position.w =p->pers->w;
p->position.h =p->pers->h;
heart1 = IMG_Load("heartt.png");
		
heart2= IMG_Load("heartt.png");
		
heart3 = IMG_Load("heartt.png");
position_heart1.x=111;
	
position_heart1.y=10;
	position_heart2.x=164;

position_heart2.y=10;
	position_heart3.x=217;

position_heart3.y=10;
	
position_score.x=460;

position_score.y=0;

position_lifes.x=130;

position_lifes.y=0;
p->acceleration=0;
p->vitesse=5; 
}

void afficher (SDL_Surface *ecran,sprite p)
{
 SDL_BlitSurface(p.pers, NULL, ecran, &(p.pers)); 

SDL_BlitSurface(heart1, NULL, ecran, &position_heart1);
SDL_BlitSurface(heart2, NULL, ecran, &position_heart2);
SDL_BlitSurface(heart3, NULL, ecran, &position_heart3);

SDL_BlitSurface(lifes, NULL, ecran, &position_lifes);

SDL_BlitSurface(score, NULL, ecran, &position_score);
}
/*void deplacer (SDL_Surface *ecran,sprite p)
{
char personnage[20];
 SDL_SetColorKey(personnage, SDL_SRCCOLORKEY,SDL_MapRGB(personnage->format,255,255,255));
int continuer =1;
SDL_EnableKeyRepeat(20,20);
while(continuer)
{
SDL_BlitSurface(p.pers, NULL, ecran, &(p.pers)); 
SDL_POLLEvent(&event);
switch(event.type)
{
case SDL_QUIT:
continuer=0;
break;
case SDL_KEYDOWN:
switch (event.key.keysysm.sym)
    {
case SDLK_UP:
p->position.y -=10;
SDL_WaitEvent(&event);
break;
case SDLK_DOWN:
p->position.y +=10;
SDL_WaitEvent(&event);
break;
case SDLK_RIGHT:
p->position.x +=10;
SDL_WaitEvent(&event);
break;
case SDLK_LEFT:
p->position.x -=10;
SDL_WaitEvent(&event);
break;

   break;


   }

}
SDL_Flip(ecran);
}

}

void RecupererVecteur(Input* in,int* vx,int* vy) 
{ int vitesse = 5;
 *vx = *vy = 0; 
if (in->key[SDLK_UP]) *vy = -vitesse; 
if (in->key[SDLK_DOWN]) *vy = vitesse; 
if (in->key[SDLK_LEFT]) *vx = -vitesse; 
if (in->key[SDLK_RIGHT]) *vx = vitesse;
 } 

int DeplaceSprite(Sprite* perso,,int vx,int vy) 
{ 
    if (EssaiDeplacement(perso,vx,vy)==1) 

        return 1; 

    return 2; 
}

int EssaiDeplacement(Sprite* perso,int vx,int vy) 
{ 
    SDL_Rect test; 
    test = perso->position; 
    test.x+=vx; 
    test.y+=vy; 
    
    return 0;

}
void Evolue(Input* in,Sprite* perso)
 { int vx,vy; RecupererVecteur(in,&vx,&vy); 
  DeplaceSprite(perso,vx,vy);
 }
void acceleration()
{

continuer =1;
while (continuer)
{
sdl_POLLevent (&event);
switch(event.type)
{
case SDL_KEYDOWN:
switch(event.key.keysy.sym)
{
case SDLK_a:
p.acceleration+=0.005;
break;
case SDLK_d:
p.acceleration-=0.01;
break ;
}
}
} 
}

*/
 #include "fonction.h" 
Hero heroList[2] = {0};
 //Spell allSpells[8] = {0};
 Hero currentHero;
 SDL_Surface* imageHero; 
SDL_Rect posHero; 
direction d;
int leftcounter,rightcounter,upcounter,downcounter; 
void loadHeros()
{ 
FILE* f = fopen("text/hero.txt","r"); 
int i ;
 for(i=0; i<2; i++) 
{ char spellListID[50];
fscanf(f,"%d|%[^|]|%d|%d|%s",&heroList[i].id,heroList[i].name,&heroList[i].maxHP,&heroList[i].maxAP,spellListID);}
 /*int spellsID[4]; 
sscanf(spellListID,"%d,%d,%d,%d",&spellsID[0],&spellsID[1],&spellsID[2],&spellsID[3]); heroList[i].spellList[0] = allSpells[spellsID[0]-1]; 
heroList[i].spellList[1] = allSpells[spellsID[1]-1];
heroList[i].spellList[2] = allSpells[spellsID[2]-1]; 
heroList[i].spellList[3] = allSpells[spellsID[3]-1]; } 
fclose(f); } Spell* loadSpells() 
{ FILE* f = fopen("text/spells.txt","r");
 int i; 
for(i=0; i<8; i++)
 { fscanf(f,"%d|%[^|]|%d|%d|%d|%d\n",&allSpells[i].id,allSpells[i].name,&allSpells[i].AP,&allSpells[i].damage,&allSpells[i].heal,&allSpells[i].critchance); } return allSpells; }*/
 void initHero(int ID)
 { currentHero = heroList[ID - 1]; 
currentHero.currentHP = currentHero.maxHP; currentHero.currentAP = currentHero.maxAP; leftcounter = rightcounter = upcounter = downcounter = 1; posHero.x = x; posHero.y = y;
 char imageHeroFile[250];
 int i;
 for(i=0;i<4;i++)
{ sprintf(imageHeroFile,"image/up%d.png",i+1); 
currentHero.upImage[i] = IMG_Load(imageHeroFile); 
sprintf(imageHeroFile,"image/right%d.png",i+1);
 currentHero.rightImage[i] = IMG_Load(imageHeroFile); sprintf(imageHeroFile,"image/left%d.png",i+1); 
currentHero.leftImage[i] = IMG_Load(imageHeroFile); sprintf(imageHeroFile,"image/down%d.png",i+1); 
currentHero.downImage[i] = IMG_Load(imageHeroFile); 
} 
sprintf(imageHeroFile,"image/battleportrait.png"); 
currentHero.battleImage = IMG_Load(imageHeroFile); 
d = down; } 
void showHero(SDL_Surface* screen)
 { 
char imageHeroFile[250];
 if(d == left) 
{ imageHero = currentHero.leftImage[leftcounter-1]; } 
else if(d == right)
 { imageHero = currentHero.rightImage[rightcounter-1]; }
 else if(d == up) { imageHero = currentHero.upImage[upcounter-1];
 } 
else if(d == down)
 { imageHero = currentHero.downImage[downcounter-1]; } SDL_BlitSurface(imageHero,NULL,screen,&posHero); 
} 
void moveHero(direction dir)
 { 
d = dir;
 if(d == left)
 { if(!collisionmap (left,x,y)) 
{ if(getMapPosX()<=0||posHero.x>400) 
{ posHero.x-=5; x-=5; 
} 
else scroll(left); 
} leftcounter++; 
if(leftcounter == 5) leftcounter = 1;
 }
 else if(d == right)
 { if(!collisionmap (right,x,y))
 { if(posHero.x<400)
 { if(posHero.x+imageHero->w+getMapPosX()<getMapW()) 
{ posHero.x+=5; x+=5; } } 
else if(getMapPosX()+800>getMapW())
 { if(posHero.x+imageHero->w+getMapPosX()<getMapW()) { posHero.x+=5; x+=5; } } else scroll(right); } rightcounter++;
 if(rightcounter == 5) rightcounter = 1; } 
else if(d == up) 
{ if(!collisionmap (up,x,y)) 
{ if(getMapPosY()<=0||posHero.y>300) { posHero.y-=5; y-=5; }
 else scroll(up); } upcounter++; if(upcounter == 5) upcounter = 1; } 
else if(d == down)
 { if(!collisionmap (down,x,y)) 
{ if(posHero.y<300)
 { if(posHero.y+imageHero->h+getMapPosY()<getMapH()) { posHero.y+=5; y+=5; } } else if(getMapPosY()+600>getMapH())
 { if(posHero.y+imageHero->h+getMapPosY()<getMapH()) { posHero.y+=5; y+=5; } } else scroll(down); } 
downcounter++; 
if(downcounter == 5) 
downcounter = 1; } 
}


