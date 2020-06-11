#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>

#define WindowWidth 800
#define WindowHeight 800
#define N 4

// gcc 2048.c -o 2048 $(sdl2-config --cflags --libs)  // COMMANDE DE COMPILATION
// ./2048                                             // COMMANDE D'EXECUTION

void SDL_ExitWithError (const char *message)
{
	SDL_Log("ERREUR : %s > %s\n", message, SDL_GetError());
	SDL_Quit();
	exit(EXIT_FAILURE);
}
void AfficherSDL(int Grille[N][N], int skin_2048)
{

}

void InitialiserGrille(int Grille[N][N])
{
    int i;
    int j;
    for(i=0; i<N; i++)
    {
        for(j=0; j<N; j++)
        {
            Grille[i][j]=0;
        }
    }
    i = rand()%4;
    j = rand()%4;
    Grille[i][j]=2;
    i = rand()%4;
    j = rand()%4;
    Grille[i][j]=2;
}
void AjouterRandom(int Grille[N][N])
{
    int i;
    int j;
    int 
    while
}


void DeplacerDroite(int Grille[N][N])
{
    int i;
    int j;
    for(i=0; i<N; i++)
    {
        for(j=0; j<N; j++)
        {
            if (Grille[i][j]==Grille[i][j+1])
            {
                Grille[i][j+1]+=Grille[i][j];
                Grille[i][j] = 0;
            }
            else if(Grille[i][j+1]==0)
            {
                Grille[i][j+1]=Grille[i][j];
                Grille[i][j]=0;
            }
            else 
            {}
        }
    }
}

void DeplacerGauche(int Grille[N][N])
{
    int i;
    int j;
    for(i=0; i<N; i++)
    {
        for(j=0; j<N; j++)
        {
            if (Grille[i][3-j]==Grille[i][2-j])
            {
                Grille[i][2-j]+=Grille[i][3-j];
                Grille[i][3-j] = 0;
            }
            else if(Grille[i][2-j]==0)
            {
                Grille[i][2-j]=Grille[i][3-j];
                Grille[i][3-j]=0;
            }
            else 
            {}
        }
    }
}

void DeplacerBas(int Grille[N][N])
{
    int i;
    int j;
    for(i=0; i<N; i++)
    {
        for(j=0; j<N; j++)
        {
            if (Grille[j][i]==Grille[j][i+1])
            {
                Grille[j][i+1]+=Grille[j][i];
                Grille[j][i] = 0;
            }
            else if(Grille[j][i+1]==0)
            {
                Grille[j][i+1]=Grille[j][i];
                Grille[j][i]=0;
            }
            else 
            {}
        }
    }
}

void DeplacerHaut(int Grille[N][N])
{
    int i;
    int j;
    for(i=0; i<N; i++)
    {
        for(j=0; j<N; j++)
        {
            if (Grille[j][3-i]==Grille[j][2-i])
            {
                Grille[j][2-i]+=Grille[j][3-i];
                Grille[j][3-i] = 0;
            }
            else if(Grille[j][2-i]==0)
            {
                Grille[j][2-i]=Grille[j][3-i];
                Grille[j][3-i]=0;
            }
            else 
            {}
        }
    }
}

int main(int argc, char **argv)
{
    int Grille[N][N];
    InitialiserGrille(Grille);
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;


    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        SDL_ExitWithError("Initialisation SDL ");
    }
	
    // EXECUTION DU PROGRAMME 
    
    // Création de la fenêtre + rendu
    
    if (SDL_CreateWindowAndRenderer(WindowWidth, WindowHeight, 0, &window, &renderer) != 0)
    {
        SDL_ExitWithError("Creation fenetre + Rendu SDL ");
    }
    
    SDL_bool program_launched = SDL_TRUE;
    
    /* image de base */
    SDL_Surface *image = NULL;
    SDL_Texture *texture = NULL;
    /* Images des cases du Jeu */
    SDL_Surface *case0 = NULL;
    SDL_Texture *Texture_case0 = NULL;

    SDL_Surface *case1 = NULL;
    SDL_Texture *Texture_case1 = NULL;

    SDL_Surface *case2 = NULL;
    SDL_Texture *Texture_case2 = NULL;

    SDL_Surface *case3 = NULL;
    SDL_Texture *Texture_case3 = NULL;

    SDL_Surface *case4 = NULL;
    SDL_Texture *Texture_case4 = NULL;

    SDL_Surface *case5 = NULL;
    SDL_Texture *Texture_case5 = NULL;

    SDL_Surface *case6 = NULL;
    SDL_Texture *Texture_case6 = NULL;

    SDL_Surface *case7 = NULL;
    SDL_Texture *Texture_case7 = NULL;

    SDL_Surface *case8 = NULL;
    SDL_Texture *Texture_case8 = NULL;

    SDL_Surface *case9 = NULL;
    SDL_Texture *Texture_case9 = NULL;

    SDL_Surface *case10 = NULL;
    SDL_Texture *Texture_case10 = NULL;

    SDL_Surface *case11 = NULL;
    SDL_Texture *Texture_case11 = NULL;

    SDL_Surface *case12 = NULL;
    SDL_Texture *Texture_case12 = NULL;

    SDL_Surface *case13 = NULL;
    SDL_Texture *Texture_case13 = NULL;

    SDL_Surface *case14 = NULL;
    SDL_Texture *Texture_case14 = NULL;

    SDL_Surface *case15 = NULL;
    SDL_Texture *Texture_case15 = NULL;

    SDL_Surface *case16 = NULL;
    SDL_Texture *Texture_case16 = NULL;

    image = SDL_LoadBMP("img/Menu.bmp");
    
    if (image == NULL)
    {
    	SDL_DestroyRenderer(renderer);
    	SDL_DestroyWindow(window);
    	SDL_ExitWithError("Impossible de charger l'image");
    	printf("Chargement");
    }
    
    texture = SDL_CreateTextureFromSurface(renderer, image);
    SDL_FreeSurface(image);
    
    if (texture == NULL)
    {
    	SDL_DestroyRenderer(renderer);
    	SDL_DestroyWindow(window);
    	SDL_ExitWithError("Impossible de créer la texture");
    }

    SDL_Rect BG;
    
    if (SDL_QueryTexture(texture, NULL, NULL, &BG.w, &BG.h) != 0)
    {
    	SDL_DestroyRenderer(renderer);
    	SDL_DestroyWindow(window);
    	SDL_ExitWithError("Impossible de charger la texture");
    }
    
    BG.x = (WindowWidth - BG.w)/2;
    BG.y = (WindowHeight - BG.h)/2;
    
    if ( SDL_RenderCopy(renderer, texture, NULL, &BG) != 0 )
    {
    	SDL_DestroyRenderer(renderer);
    	SDL_DestroyWindow(window);
    	SDL_ExitWithError("Impossible d'afficher la texture");
    }

    /*--------------------------------------------------*/

    SDL_RenderPresent(renderer);
    int affichage_menu = 0;
    /* affichage_menu = 0 <=> Menu
       affichage_menu = 1 <=> Settings
       affichage_menu = 2 <=> Start
    */
    int settings = 0;
    /* settings 0 Menu_settings 000 4x4 1P skin 1
       settings 1 Menu_settings 100 8x8    skin 1
       settings 2 Menu_settings 001 4x4 1P skin 2
       settings 3 Menu_settings 010 4x4 2P skin 1
       settings 4 Menu_settings 011 4x4 2P skin 2
       settings 5 Menu_settings 101 8x8    skin 2
    */
    int skin_2048= 0;
    /* skin_2048 = 0 <=> skin 1
      skin_2048 = 1 <=> skin 2
    */            
    int continuer = 0;
    int i;
    int j; 
    int var;
    int varx = 0;
    int vary = 0;
    while (program_launched)
    {
    	SDL_Event event;
    	SDL_Rect BG;
        BG.h = 162;
        BG.w = 162;
        
        while (SDL_PollEvent(&event))
    	{
    		switch(event.type)
    		{
    			case SDL_KEYDOWN : switch(event.key.keysym.sym)
    					    {
                            case SDLK_ESCAPE : printf("Vous avez quitté le programme\n"); program_launched = SDL_FALSE; break;
                            case SDLK_d :
                                if (affichage_menu == 2)
                                {
                                    DeplacerDroite(Grille);
                                    for (i=0; i<N; i++)
                                    {
                                        for (j=0; j<N; j++)
                                        {
                                            printf("%d\n", Grille[i][j]);
                                        }
                                    }
                                    for (var = 0; var<16; var++)
                                    {
                                        if (var+1 == 1)
                                        {
                                            case0 = case1;
                                            Texture_case0 = Texture_case1;
                                            BG.x = 30;
                                            BG.y = 30;
                                        }
                                        if (var+1 == 2)
                                        {
                                            case0 = case2;
                                            Texture_case0 = Texture_case2;
                                            BG.x = 222;
                                            BG.y = 30;
                                        }
                                        if (var+1 == 3)
                                        {
                                            case0 = case3;
                                            Texture_case0 = Texture_case3;
                                            BG.x = 416;
                                            BG.y = 30;
                                        }
                                        if (var+1 == 4)
                                        {
                                            case0 = case4;
                                            Texture_case0 = Texture_case4;
                                            BG.x = 608;
                                            BG.y = 30;
                                        }
                                        if (var+1 == 5)
                                        {
                                            case0 = case5;
                                            Texture_case0 = Texture_case5;
                                            BG.x = 30;
                                            BG.y = 222;
                                        }
                                        if (var+1 == 6)
                                        {
                                            case0 = case6;
                                            Texture_case0 = Texture_case6;
                                            BG.x = 222;
                                            BG.y = 222;
                                        }
                                        if (var+1 == 7)
                                        {
                                            case0 = case7;
                                            Texture_case0 = Texture_case7;
                                            BG.x = 416;
                                            BG.y = 222;
                                        }
                                        if (var+1 == 8)
                                        {
                                            case0 = case8;
                                            Texture_case0 = Texture_case8;
                                            BG.x = 608;
                                            BG.y = 222;
                                        }
                                        if (var+1 == 9)
                                        {
                                            case0 = case9;
                                            Texture_case0 = Texture_case9;
                                            BG.x = 30;
                                            BG.y = 416;
                                        }
                                        if (var+1 == 10)
                                        {
                                            case0 = case10;
                                            Texture_case0 = Texture_case10;
                                            BG.x = 222;
                                            BG.y = 416;
                                        }
                                        if (var+1 == 11)
                                        {
                                            case0 = case11;
                                            Texture_case0 = Texture_case11;
                                            BG.x = 416;
                                            BG.y = 416;
                                        }
                                        if (var+1 == 12)
                                        {
                                            case0 = case12;
                                            Texture_case0 = Texture_case12;
                                            BG.x = 608;
                                            BG.y = 416;
                                        }
                                        if (var+1 == 13)
                                        {
                                            case0 = case13;
                                            Texture_case0 = Texture_case13;
                                            BG.x = 30;
                                            BG.y = 608;
                                        }
                                        if (var+1 == 14)
                                        {
                                            case0 = case14;
                                            Texture_case0 = Texture_case14;
                                            BG.x = 222;
                                            BG.y = 608;
                                        }
                                        if (var+1 == 15)
                                        {
                                            case0 = case15;
                                            Texture_case0 = Texture_case15;
                                            BG.x = 416;
                                            BG.y = 608;
                                        }
                                        if (var+1 == 16)
                                        {
                                            case0 = case16;
                                            Texture_case0 = Texture_case16;
                                            BG.x = 608;
                                            BG.y = 608;
                                        }

                                        if (varx > 3)
                                        {
                                            vary += 1;
                                            varx = 0;
                                        }   
                                        if (Grille[vary][varx]== 0)
                                        {
                                            continue;
                                        }
                                        else if (Grille[vary][varx]== 2)
                                        {
                                            case0 = SDL_LoadBMP("img/2.bmp");
                                        }
                                        else if (Grille[vary][varx] == 4)
                                        {
                                            case0 = SDL_LoadBMP("img/4.bmp");
                                        }
                                        else if (Grille[vary][varx] == 8)
                                        {
                                            case0 = SDL_LoadBMP("img/8.bmp");
                                        }
                                        else if (Grille[vary][varx]== 16)
                                        {
                                            case0= SDL_LoadBMP("img/16.bmp");
                                        }
                                        else if (Grille[vary][varx] == 32)
                                        {
                                            case0 = SDL_LoadBMP("img/32.bmp");
                                        }
                                        else if (Grille[vary][varx] == 64)
                                        {
                                            case0 = SDL_LoadBMP("img/64.bmp");
                                        }
                                        else if (Grille[vary][varx]== 128)
                                        {
                                            case0 = SDL_LoadBMP("img/128.bmp");
                                        }
                                        else if (Grille[vary][varx] == 256)
                                        {
                                            case0 = SDL_LoadBMP("img/256.bmp");
                                        }
                                        else if (Grille[vary][varx] == 512)
                                        {
                                            case0 = SDL_LoadBMP("img/512.bmp");
                                        }
                                        else if (Grille[vary][varx]== 1024)
                                        {
                                            case0 = SDL_LoadBMP("img/1024.bmp");
                                        }
                                        else if (Grille[vary][varx] == 2048)
                                        {
                                            case0 = SDL_LoadBMP("img/2048.bmp");
                                        }
                                        if (case0 == NULL)
                                        {
                                            SDL_DestroyRenderer(renderer);
                                            SDL_DestroyWindow(window);
                                            SDL_ExitWithError("Impossible de charger l'image");
                                            printf("Chargement");
                                        }
                                                
                                        Texture_case0 = SDL_CreateTextureFromSurface(renderer, case0);
                                        SDL_FreeSurface(case0);
                                                
                                        if (Texture_case0 == NULL)
                                        {
                                            SDL_DestroyRenderer(renderer);
                                            SDL_DestroyWindow(window);
                                            SDL_ExitWithError("Impossible de créer la texture");
                                        }
                                        if (SDL_QueryTexture(Texture_case0, NULL, NULL, &BG.w, &BG.h) != 0)
                                        {
                                            SDL_DestroyRenderer(renderer);
                                            SDL_DestroyWindow(window);
                                            SDL_ExitWithError("Impossible de charger la texture");
                                        }
                                        if ( SDL_RenderCopy(renderer, Texture_case0, NULL, &BG) != 0 )
                                        {
                                            SDL_DestroyRenderer(renderer);
                                            SDL_DestroyWindow(window);
                                            SDL_ExitWithError("Impossible d'afficher la texture");
                                        }
                                        varx += 1;
                                        if (var+1 == 1)
                                        {
                                            case1 = case0;
                                            Texture_case1 = Texture_case0;
                                            if (SDL_QueryTexture(Texture_case1, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            if ( SDL_RenderCopy(renderer, Texture_case1, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }

                                        }
                                        if (var+1 == 2)
                                        {
                                            case2 = case0;
                                            Texture_case2 = Texture_case0;
                                            if (SDL_QueryTexture(Texture_case2, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            if ( SDL_RenderCopy(renderer, Texture_case2, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        if (var+1 == 3)
                                        {
                                            case3 = case0;
                                            Texture_case3 = Texture_case0;
                                            if (SDL_QueryTexture(Texture_case3, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            if ( SDL_RenderCopy(renderer, Texture_case4, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        if (var+1 == 4)
                                        {
                                            case4 = case0;
                                            Texture_case4 = Texture_case0;
                                            if (SDL_QueryTexture(Texture_case4, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            if ( SDL_RenderCopy(renderer, Texture_case4, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        if (var+1 == 5)
                                        {
                                            case5 = case0;
                                            Texture_case5 = Texture_case0;
                                            if (SDL_QueryTexture(Texture_case5, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            if ( SDL_RenderCopy(renderer, Texture_case5, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        if (var+1 == 6)
                                        {
                                            case6 = case0;
                                            Texture_case6 = Texture_case0;
                                            if (SDL_QueryTexture(Texture_case6, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            if ( SDL_RenderCopy(renderer, Texture_case6, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        if (var+1 == 7)
                                        {
                                            case7 = case0;
                                            Texture_case7 = Texture_case0;
                                            if (SDL_QueryTexture(Texture_case7, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            if ( SDL_RenderCopy(renderer, Texture_case7, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        if (var+1 == 8)
                                        {
                                            case8 = case0;
                                            Texture_case8 = Texture_case0;
                                            if (SDL_QueryTexture(Texture_case8, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            if ( SDL_RenderCopy(renderer, Texture_case8, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        if (var+1 == 9)
                                        {
                                            case9 = case0;
                                            Texture_case9 = Texture_case0;
                                            if (SDL_QueryTexture(Texture_case9, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            if ( SDL_RenderCopy(renderer, Texture_case9, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        if (var+1 == 10)
                                        {
                                            case10 = case0;
                                            Texture_case10 = Texture_case0;
                                            if (SDL_QueryTexture(Texture_case10, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            if ( SDL_RenderCopy(renderer, Texture_case10, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        if (var+1 == 11)
                                        {
                                            case11 = case0;
                                            Texture_case11 = Texture_case0;
                                            if (SDL_QueryTexture(Texture_case11, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            if ( SDL_RenderCopy(renderer, Texture_case11, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        if (var+1 == 12)
                                        {
                                            case12 = case0;
                                            Texture_case12 = Texture_case0;
                                            if (SDL_QueryTexture(Texture_case12, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            if ( SDL_RenderCopy(renderer, Texture_case12, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        if (var+1 == 13)
                                        {
                                            case13 = case0;
                                            Texture_case13 = Texture_case0;
                                            if (SDL_QueryTexture(Texture_case13, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            if ( SDL_RenderCopy(renderer, Texture_case13, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        if (var+1 == 14)
                                        {
                                            case14 = case0;
                                            Texture_case14 = Texture_case0;
                                            if (SDL_QueryTexture(Texture_case14, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            if ( SDL_RenderCopy(renderer, Texture_case14, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        if (var+1 == 15)
                                        {
                                            case15 = case0;
                                            Texture_case15 = Texture_case0;
                                            if (SDL_QueryTexture(Texture_case15, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            if ( SDL_RenderCopy(renderer, Texture_case15, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        if (var+1 == 16)
                                        {
                                            case16 = case0;
                                            Texture_case16 = Texture_case0;
                                            if (SDL_QueryTexture(Texture_case16, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            if ( SDL_RenderCopy(renderer, Texture_case16, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                    }      
                                }
                            case SDLK_q :
                                if (affichage_menu == 2)
                                {
                                    DeplacerGauche(Grille);
                                    for (var = 0; var<16; var++)
                                        {
                                            if (var+1 == 1)
                                            {
                                                case0 = case1;
                                                Texture_case0 = Texture_case1;
                                                BG.x = 30;
                                                BG.y = 30;
                                            }
                                            if (var+1 == 2)
                                            {
                                                case0 = case2;
                                                Texture_case0 = Texture_case2;
                                                BG.x = 222;
                                                BG.y = 30;
                                            }
                                            if (var+1 == 3)
                                            {
                                                case0 = case3;
                                                Texture_case0 = Texture_case3;
                                                BG.x = 416;
                                                BG.y = 30;
                                            }
                                            if (var+1 == 4)
                                            {
                                                case0 = case4;
                                                Texture_case0 = Texture_case4;
                                                BG.x = 608;
                                                BG.y = 30;
                                            }
                                            if (var+1 == 5)
                                            {
                                                case0 = case5;
                                                Texture_case0 = Texture_case5;
                                                BG.x = 30;
                                                BG.y = 222;
                                            }
                                            if (var+1 == 6)
                                            {
                                                case0 = case6;
                                                Texture_case0 = Texture_case6;
                                                BG.x = 222;
                                                BG.y = 222;
                                            }
                                            if (var+1 == 7)
                                            {
                                                case0 = case7;
                                                Texture_case0 = Texture_case7;
                                                BG.x = 416;
                                                BG.y = 222;
                                            }
                                            if (var+1 == 8)
                                            {
                                                case0 = case8;
                                                Texture_case0 = Texture_case8;
                                                BG.x = 608;
                                                BG.y = 222;
                                            }
                                            if (var+1 == 9)
                                            {
                                                case0 = case9;
                                                Texture_case0 = Texture_case9;
                                                BG.x = 30;
                                                BG.y = 416;
                                            }
                                            if (var+1 == 10)
                                            {
                                                case0 = case10;
                                                Texture_case0 = Texture_case10;
                                                BG.x = 222;
                                                BG.y = 416;
                                            }
                                            if (var+1 == 11)
                                            {
                                                case0 = case11;
                                                Texture_case0 = Texture_case11;
                                                BG.x = 416;
                                                BG.y = 416;
                                            }
                                            if (var+1 == 12)
                                            {
                                                case0 = case12;
                                                Texture_case0 = Texture_case12;
                                                BG.x = 608;
                                                BG.y = 416;
                                            }
                                            if (var+1 == 13)
                                            {
                                                case0 = case13;
                                                Texture_case0 = Texture_case13;
                                                BG.x = 30;
                                                BG.y = 608;
                                            }
                                            if (var+1 == 14)
                                            {
                                                case0 = case14;
                                                Texture_case0 = Texture_case14;
                                                BG.x = 222;
                                                BG.y = 608;
                                            }
                                            if (var+1 == 15)
                                            {
                                                case0 = case15;
                                                Texture_case0 = Texture_case15;
                                                BG.x = 416;
                                                BG.y = 608;
                                            }
                                            if (var+1 == 16)
                                            {
                                                case0 = case16;
                                                Texture_case0 = Texture_case16;
                                                BG.x = 608;
                                                BG.y = 608;
                                            }

                                            if (varx > 3)
                                            {
                                                vary += 1;
                                                varx = 0;
                                            }   
                                            if (Grille[vary][varx]== 0)
                                            {
                                                continue;
                                            }
                                            else if (Grille[vary][varx]== 2)
                                            {
                                                case0 = SDL_LoadBMP("img/2.bmp");
                                            }
                                            else if (Grille[vary][varx] == 4)
                                            {
                                                case0 = SDL_LoadBMP("img/4.bmp");
                                            }
                                            else if (Grille[vary][varx] == 8)
                                            {
                                                case0 = SDL_LoadBMP("img/8.bmp");
                                            }
                                            else if (Grille[vary][varx]== 16)
                                            {
                                                case0= SDL_LoadBMP("img/16.bmp");
                                            }
                                            else if (Grille[vary][varx] == 32)
                                            {
                                                case0 = SDL_LoadBMP("img/32.bmp");
                                            }
                                            else if (Grille[vary][varx] == 64)
                                            {
                                                case0 = SDL_LoadBMP("img/64.bmp");
                                            }
                                            else if (Grille[vary][varx]== 128)
                                            {
                                                case0 = SDL_LoadBMP("img/128.bmp");
                                            }
                                            else if (Grille[vary][varx] == 256)
                                            {
                                                case0 = SDL_LoadBMP("img/256.bmp");
                                            }
                                            else if (Grille[vary][varx] == 512)
                                            {
                                                case0 = SDL_LoadBMP("img/512.bmp");
                                            }
                                            else if (Grille[vary][varx]== 1024)
                                            {
                                                case0 = SDL_LoadBMP("img/1024.bmp");
                                            }
                                            else if (Grille[vary][varx] == 2048)
                                            {
                                                case0 = SDL_LoadBMP("img/2048.bmp");
                                            }
                                            if (case0 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                                    
                                            Texture_case0 = SDL_CreateTextureFromSurface(renderer, case0);
                                            SDL_FreeSurface(case0);
                                                    
                                            if (Texture_case0 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }
                                            if (SDL_QueryTexture(Texture_case0, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            if ( SDL_RenderCopy(renderer, Texture_case0, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                            varx += 1;
                                            if (var+1 == 1)
                                            {
                                                case1 = case0;
                                                Texture_case1 = Texture_case0;
                                                if (SDL_QueryTexture(Texture_case1, NULL, NULL, &BG.w, &BG.h) != 0)
                                                {
                                                    SDL_DestroyRenderer(renderer);
                                                    SDL_DestroyWindow(window);
                                                    SDL_ExitWithError("Impossible de charger la texture");
                                                }
                                                if ( SDL_RenderCopy(renderer, Texture_case1, NULL, &BG) != 0 )
                                                {
                                                    SDL_DestroyRenderer(renderer);
                                                    SDL_DestroyWindow(window);
                                                    SDL_ExitWithError("Impossible d'afficher la texture");
                                                }

                                            }
                                            if (var+1 == 2)
                                            {
                                                case2 = case0;
                                                Texture_case2 = Texture_case0;
                                                if (SDL_QueryTexture(Texture_case2, NULL, NULL, &BG.w, &BG.h) != 0)
                                                {
                                                    SDL_DestroyRenderer(renderer);
                                                    SDL_DestroyWindow(window);
                                                    SDL_ExitWithError("Impossible de charger la texture");
                                                }
                                                if ( SDL_RenderCopy(renderer, Texture_case2, NULL, &BG) != 0 )
                                                {
                                                    SDL_DestroyRenderer(renderer);
                                                    SDL_DestroyWindow(window);
                                                    SDL_ExitWithError("Impossible d'afficher la texture");
                                                }
                                            }
                                            if (var+1 == 3)
                                            {
                                                case3 = case0;
                                                Texture_case3 = Texture_case0;
                                                if (SDL_QueryTexture(Texture_case3, NULL, NULL, &BG.w, &BG.h) != 0)
                                                {
                                                    SDL_DestroyRenderer(renderer);
                                                    SDL_DestroyWindow(window);
                                                    SDL_ExitWithError("Impossible de charger la texture");
                                                }
                                                if ( SDL_RenderCopy(renderer, Texture_case4, NULL, &BG) != 0 )
                                                {
                                                    SDL_DestroyRenderer(renderer);
                                                    SDL_DestroyWindow(window);
                                                    SDL_ExitWithError("Impossible d'afficher la texture");
                                                }
                                            }
                                            if (var+1 == 4)
                                            {
                                                case4 = case0;
                                                Texture_case4 = Texture_case0;
                                                if (SDL_QueryTexture(Texture_case4, NULL, NULL, &BG.w, &BG.h) != 0)
                                                {
                                                    SDL_DestroyRenderer(renderer);
                                                    SDL_DestroyWindow(window);
                                                    SDL_ExitWithError("Impossible de charger la texture");
                                                }
                                                if ( SDL_RenderCopy(renderer, Texture_case4, NULL, &BG) != 0 )
                                                {
                                                    SDL_DestroyRenderer(renderer);
                                                    SDL_DestroyWindow(window);
                                                    SDL_ExitWithError("Impossible d'afficher la texture");
                                                }
                                            }
                                            if (var+1 == 5)
                                            {
                                                case5 = case0;
                                                Texture_case5 = Texture_case0;
                                                if (SDL_QueryTexture(Texture_case5, NULL, NULL, &BG.w, &BG.h) != 0)
                                                {
                                                    SDL_DestroyRenderer(renderer);
                                                    SDL_DestroyWindow(window);
                                                    SDL_ExitWithError("Impossible de charger la texture");
                                                }
                                                if ( SDL_RenderCopy(renderer, Texture_case5, NULL, &BG) != 0 )
                                                {
                                                    SDL_DestroyRenderer(renderer);
                                                    SDL_DestroyWindow(window);
                                                    SDL_ExitWithError("Impossible d'afficher la texture");
                                                }
                                            }
                                            if (var+1 == 6)
                                            {
                                                case6 = case0;
                                                Texture_case6 = Texture_case0;
                                                if (SDL_QueryTexture(Texture_case6, NULL, NULL, &BG.w, &BG.h) != 0)
                                                {
                                                    SDL_DestroyRenderer(renderer);
                                                    SDL_DestroyWindow(window);
                                                    SDL_ExitWithError("Impossible de charger la texture");
                                                }
                                                if ( SDL_RenderCopy(renderer, Texture_case6, NULL, &BG) != 0 )
                                                {
                                                    SDL_DestroyRenderer(renderer);
                                                    SDL_DestroyWindow(window);
                                                    SDL_ExitWithError("Impossible d'afficher la texture");
                                                }
                                            }
                                            if (var+1 == 7)
                                            {
                                                case7 = case0;
                                                Texture_case7 = Texture_case0;
                                                if (SDL_QueryTexture(Texture_case7, NULL, NULL, &BG.w, &BG.h) != 0)
                                                {
                                                    SDL_DestroyRenderer(renderer);
                                                    SDL_DestroyWindow(window);
                                                    SDL_ExitWithError("Impossible de charger la texture");
                                                }
                                                if ( SDL_RenderCopy(renderer, Texture_case7, NULL, &BG) != 0 )
                                                {
                                                    SDL_DestroyRenderer(renderer);
                                                    SDL_DestroyWindow(window);
                                                    SDL_ExitWithError("Impossible d'afficher la texture");
                                                }
                                            }
                                            if (var+1 == 8)
                                            {
                                                case8 = case0;
                                                Texture_case8 = Texture_case0;
                                                if (SDL_QueryTexture(Texture_case8, NULL, NULL, &BG.w, &BG.h) != 0)
                                                {
                                                    SDL_DestroyRenderer(renderer);
                                                    SDL_DestroyWindow(window);
                                                    SDL_ExitWithError("Impossible de charger la texture");
                                                }
                                                if ( SDL_RenderCopy(renderer, Texture_case8, NULL, &BG) != 0 )
                                                {
                                                    SDL_DestroyRenderer(renderer);
                                                    SDL_DestroyWindow(window);
                                                    SDL_ExitWithError("Impossible d'afficher la texture");
                                                }
                                            }
                                            if (var+1 == 9)
                                            {
                                                case9 = case0;
                                                Texture_case9 = Texture_case0;
                                                if (SDL_QueryTexture(Texture_case9, NULL, NULL, &BG.w, &BG.h) != 0)
                                                {
                                                    SDL_DestroyRenderer(renderer);
                                                    SDL_DestroyWindow(window);
                                                    SDL_ExitWithError("Impossible de charger la texture");
                                                }
                                                if ( SDL_RenderCopy(renderer, Texture_case9, NULL, &BG) != 0 )
                                                {
                                                    SDL_DestroyRenderer(renderer);
                                                    SDL_DestroyWindow(window);
                                                    SDL_ExitWithError("Impossible d'afficher la texture");
                                                }
                                            }
                                            if (var+1 == 10)
                                            {
                                                case10 = case0;
                                                Texture_case10 = Texture_case0;
                                                if (SDL_QueryTexture(Texture_case10, NULL, NULL, &BG.w, &BG.h) != 0)
                                                {
                                                    SDL_DestroyRenderer(renderer);
                                                    SDL_DestroyWindow(window);
                                                    SDL_ExitWithError("Impossible de charger la texture");
                                                }
                                                if ( SDL_RenderCopy(renderer, Texture_case10, NULL, &BG) != 0 )
                                                {
                                                    SDL_DestroyRenderer(renderer);
                                                    SDL_DestroyWindow(window);
                                                    SDL_ExitWithError("Impossible d'afficher la texture");
                                                }
                                            }
                                            if (var+1 == 11)
                                            {
                                                case11 = case0;
                                                Texture_case11 = Texture_case0;
                                                if (SDL_QueryTexture(Texture_case11, NULL, NULL, &BG.w, &BG.h) != 0)
                                                {
                                                    SDL_DestroyRenderer(renderer);
                                                    SDL_DestroyWindow(window);
                                                    SDL_ExitWithError("Impossible de charger la texture");
                                                }
                                                if ( SDL_RenderCopy(renderer, Texture_case11, NULL, &BG) != 0 )
                                                {
                                                    SDL_DestroyRenderer(renderer);
                                                    SDL_DestroyWindow(window);
                                                    SDL_ExitWithError("Impossible d'afficher la texture");
                                                }
                                            }
                                            if (var+1 == 12)
                                            {
                                                case12 = case0;
                                                Texture_case12 = Texture_case0;
                                                if (SDL_QueryTexture(Texture_case12, NULL, NULL, &BG.w, &BG.h) != 0)
                                                {
                                                    SDL_DestroyRenderer(renderer);
                                                    SDL_DestroyWindow(window);
                                                    SDL_ExitWithError("Impossible de charger la texture");
                                                }
                                                if ( SDL_RenderCopy(renderer, Texture_case12, NULL, &BG) != 0 )
                                                {
                                                    SDL_DestroyRenderer(renderer);
                                                    SDL_DestroyWindow(window);
                                                    SDL_ExitWithError("Impossible d'afficher la texture");
                                                }
                                            }
                                            if (var+1 == 13)
                                            {
                                                case13 = case0;
                                                Texture_case13 = Texture_case0;
                                                if (SDL_QueryTexture(Texture_case13, NULL, NULL, &BG.w, &BG.h) != 0)
                                                {
                                                    SDL_DestroyRenderer(renderer);
                                                    SDL_DestroyWindow(window);
                                                    SDL_ExitWithError("Impossible de charger la texture");
                                                }
                                                if ( SDL_RenderCopy(renderer, Texture_case13, NULL, &BG) != 0 )
                                                {
                                                    SDL_DestroyRenderer(renderer);
                                                    SDL_DestroyWindow(window);
                                                    SDL_ExitWithError("Impossible d'afficher la texture");
                                                }
                                            }
                                            if (var+1 == 14)
                                            {
                                                case14 = case0;
                                                Texture_case14 = Texture_case0;
                                                if (SDL_QueryTexture(Texture_case14, NULL, NULL, &BG.w, &BG.h) != 0)
                                                {
                                                    SDL_DestroyRenderer(renderer);
                                                    SDL_DestroyWindow(window);
                                                    SDL_ExitWithError("Impossible de charger la texture");
                                                }
                                                if ( SDL_RenderCopy(renderer, Texture_case14, NULL, &BG) != 0 )
                                                {
                                                    SDL_DestroyRenderer(renderer);
                                                    SDL_DestroyWindow(window);
                                                    SDL_ExitWithError("Impossible d'afficher la texture");
                                                }
                                            }
                                            if (var+1 == 15)
                                            {
                                                case15 = case0;
                                                Texture_case15 = Texture_case0;
                                                if (SDL_QueryTexture(Texture_case15, NULL, NULL, &BG.w, &BG.h) != 0)
                                                {
                                                    SDL_DestroyRenderer(renderer);
                                                    SDL_DestroyWindow(window);
                                                    SDL_ExitWithError("Impossible de charger la texture");
                                                }
                                                if ( SDL_RenderCopy(renderer, Texture_case15, NULL, &BG) != 0 )
                                                {
                                                    SDL_DestroyRenderer(renderer);
                                                    SDL_DestroyWindow(window);
                                                    SDL_ExitWithError("Impossible d'afficher la texture");
                                                }
                                            }
                                            if (var+1 == 16)
                                            {
                                                case16 = case0;
                                                Texture_case16 = Texture_case0;
                                                if (SDL_QueryTexture(Texture_case16, NULL, NULL, &BG.w, &BG.h) != 0)
                                                {
                                                    SDL_DestroyRenderer(renderer);
                                                    SDL_DestroyWindow(window);
                                                    SDL_ExitWithError("Impossible de charger la texture");
                                                }
                                                if ( SDL_RenderCopy(renderer, Texture_case16, NULL, &BG) != 0 )
                                                {
                                                    SDL_DestroyRenderer(renderer);
                                                    SDL_DestroyWindow(window);
                                                    SDL_ExitWithError("Impossible d'afficher la texture");
                                                }
                                            }
                                        }   
                                }
                            case SDLK_z :
                                if (affichage_menu == 2)
                                {
                                    DeplacerHaut(Grille);
                                    for (var = 0; var<16; var++)
                                        {
                                            if (var+1 == 1)
                                            {
                                                case0 = case1;
                                                Texture_case0 = Texture_case1;
                                                BG.x = 30;
                                                BG.y = 30;
                                            }
                                            if (var+1 == 2)
                                            {
                                                case0 = case2;
                                                Texture_case0 = Texture_case2;
                                                BG.x = 222;
                                                BG.y = 30;
                                            }
                                            if (var+1 == 3)
                                            {
                                                case0 = case3;
                                                Texture_case0 = Texture_case3;
                                                BG.x = 416;
                                                BG.y = 30;
                                            }
                                            if (var+1 == 4)
                                            {
                                                case0 = case4;
                                                Texture_case0 = Texture_case4;
                                                BG.x = 608;
                                                BG.y = 30;
                                            }
                                            if (var+1 == 5)
                                            {
                                                case0 = case5;
                                                Texture_case0 = Texture_case5;
                                                BG.x = 30;
                                                BG.y = 222;
                                            }
                                            if (var+1 == 6)
                                            {
                                                case0 = case6;
                                                Texture_case0 = Texture_case6;
                                                BG.x = 222;
                                                BG.y = 222;
                                            }
                                            if (var+1 == 7)
                                            {
                                                case0 = case7;
                                                Texture_case0 = Texture_case7;
                                                BG.x = 416;
                                                BG.y = 222;
                                            }
                                            if (var+1 == 8)
                                            {
                                                case0 = case8;
                                                Texture_case0 = Texture_case8;
                                                BG.x = 608;
                                                BG.y = 222;
                                            }
                                            if (var+1 == 9)
                                            {
                                                case0 = case9;
                                                Texture_case0 = Texture_case9;
                                                BG.x = 30;
                                                BG.y = 416;
                                            }
                                            if (var+1 == 10)
                                            {
                                                case0 = case10;
                                                Texture_case0 = Texture_case10;
                                                BG.x = 222;
                                                BG.y = 416;
                                            }
                                            if (var+1 == 11)
                                            {
                                                case0 = case11;
                                                Texture_case0 = Texture_case11;
                                                BG.x = 416;
                                                BG.y = 416;
                                            }
                                            if (var+1 == 12)
                                            {
                                                case0 = case12;
                                                Texture_case0 = Texture_case12;
                                                BG.x = 608;
                                                BG.y = 416;
                                            }
                                            if (var+1 == 13)
                                            {
                                                case0 = case13;
                                                Texture_case0 = Texture_case13;
                                                BG.x = 30;
                                                BG.y = 608;
                                            }
                                            if (var+1 == 14)
                                            {
                                                case0 = case14;
                                                Texture_case0 = Texture_case14;
                                                BG.x = 222;
                                                BG.y = 608;
                                            }
                                            if (var+1 == 15)
                                            {
                                                case0 = case15;
                                                Texture_case0 = Texture_case15;
                                                BG.x = 416;
                                                BG.y = 608;
                                            }
                                            if (var+1 == 16)
                                            {
                                                case0 = case16;
                                                Texture_case0 = Texture_case16;
                                                BG.x = 608;
                                                BG.y = 608;
                                            }

                                            if (varx > 3)
                                            {
                                                vary += 1;
                                                varx = 0;
                                            }   
                                            if (Grille[vary][varx]== 0)
                                            {
                                                continue;
                                            }
                                            else if (Grille[vary][varx]== 2)
                                            {
                                                case0 = SDL_LoadBMP("img/2.bmp");
                                            }
                                            else if (Grille[vary][varx] == 4)
                                            {
                                                case0 = SDL_LoadBMP("img/4.bmp");
                                            }
                                            else if (Grille[vary][varx] == 8)
                                            {
                                                case0 = SDL_LoadBMP("img/8.bmp");
                                            }
                                            else if (Grille[vary][varx]== 16)
                                            {
                                                case0= SDL_LoadBMP("img/16.bmp");
                                            }
                                            else if (Grille[vary][varx] == 32)
                                            {
                                                case0 = SDL_LoadBMP("img/32.bmp");
                                            }
                                            else if (Grille[vary][varx] == 64)
                                            {
                                                case0 = SDL_LoadBMP("img/64.bmp");
                                            }
                                            else if (Grille[vary][varx]== 128)
                                            {
                                                case0 = SDL_LoadBMP("img/128.bmp");
                                            }
                                            else if (Grille[vary][varx] == 256)
                                            {
                                                case0 = SDL_LoadBMP("img/256.bmp");
                                            }
                                            else if (Grille[vary][varx] == 512)
                                            {
                                                case0 = SDL_LoadBMP("img/512.bmp");
                                            }
                                            else if (Grille[vary][varx]== 1024)
                                            {
                                                case0 = SDL_LoadBMP("img/1024.bmp");
                                            }
                                            else if (Grille[vary][varx] == 2048)
                                            {
                                                case0 = SDL_LoadBMP("img/2048.bmp");
                                            }
                                            if (case0 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                                    
                                            Texture_case0 = SDL_CreateTextureFromSurface(renderer, case0);
                                            SDL_FreeSurface(case0);
                                                    
                                            if (Texture_case0 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }
                                            if (SDL_QueryTexture(Texture_case0, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            if ( SDL_RenderCopy(renderer, Texture_case0, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                            varx += 1;
                                            if (var+1 == 1)
                                            {
                                                case1 = case0;
                                                Texture_case1 = Texture_case0;
                                                if (SDL_QueryTexture(Texture_case1, NULL, NULL, &BG.w, &BG.h) != 0)
                                                {
                                                    SDL_DestroyRenderer(renderer);
                                                    SDL_DestroyWindow(window);
                                                    SDL_ExitWithError("Impossible de charger la texture");
                                                }
                                                if ( SDL_RenderCopy(renderer, Texture_case1, NULL, &BG) != 0 )
                                                {
                                                    SDL_DestroyRenderer(renderer);
                                                    SDL_DestroyWindow(window);
                                                    SDL_ExitWithError("Impossible d'afficher la texture");
                                                }

                                            }
                                            if (var+1 == 2)
                                            {
                                                case2 = case0;
                                                Texture_case2 = Texture_case0;
                                                if (SDL_QueryTexture(Texture_case2, NULL, NULL, &BG.w, &BG.h) != 0)
                                                {
                                                    SDL_DestroyRenderer(renderer);
                                                    SDL_DestroyWindow(window);
                                                    SDL_ExitWithError("Impossible de charger la texture");
                                                }
                                                if ( SDL_RenderCopy(renderer, Texture_case2, NULL, &BG) != 0 )
                                                {
                                                    SDL_DestroyRenderer(renderer);
                                                    SDL_DestroyWindow(window);
                                                    SDL_ExitWithError("Impossible d'afficher la texture");
                                                }
                                            }
                                            if (var+1 == 3)
                                            {
                                                case3 = case0;
                                                Texture_case3 = Texture_case0;
                                                if (SDL_QueryTexture(Texture_case3, NULL, NULL, &BG.w, &BG.h) != 0)
                                                {
                                                    SDL_DestroyRenderer(renderer);
                                                    SDL_DestroyWindow(window);
                                                    SDL_ExitWithError("Impossible de charger la texture");
                                                }
                                                if ( SDL_RenderCopy(renderer, Texture_case4, NULL, &BG) != 0 )
                                                {
                                                    SDL_DestroyRenderer(renderer);
                                                    SDL_DestroyWindow(window);
                                                    SDL_ExitWithError("Impossible d'afficher la texture");
                                                }
                                            }
                                            if (var+1 == 4)
                                            {
                                                case4 = case0;
                                                Texture_case4 = Texture_case0;
                                                if (SDL_QueryTexture(Texture_case4, NULL, NULL, &BG.w, &BG.h) != 0)
                                                {
                                                    SDL_DestroyRenderer(renderer);
                                                    SDL_DestroyWindow(window);
                                                    SDL_ExitWithError("Impossible de charger la texture");
                                                }
                                                if ( SDL_RenderCopy(renderer, Texture_case4, NULL, &BG) != 0 )
                                                {
                                                    SDL_DestroyRenderer(renderer);
                                                    SDL_DestroyWindow(window);
                                                    SDL_ExitWithError("Impossible d'afficher la texture");
                                                }
                                            }
                                            if (var+1 == 5)
                                            {
                                                case5 = case0;
                                                Texture_case5 = Texture_case0;
                                                if (SDL_QueryTexture(Texture_case5, NULL, NULL, &BG.w, &BG.h) != 0)
                                                {
                                                    SDL_DestroyRenderer(renderer);
                                                    SDL_DestroyWindow(window);
                                                    SDL_ExitWithError("Impossible de charger la texture");
                                                }
                                                if ( SDL_RenderCopy(renderer, Texture_case5, NULL, &BG) != 0 )
                                                {
                                                    SDL_DestroyRenderer(renderer);
                                                    SDL_DestroyWindow(window);
                                                    SDL_ExitWithError("Impossible d'afficher la texture");
                                                }
                                            }
                                            if (var+1 == 6)
                                            {
                                                case6 = case0;
                                                Texture_case6 = Texture_case0;
                                                if (SDL_QueryTexture(Texture_case6, NULL, NULL, &BG.w, &BG.h) != 0)
                                                {
                                                    SDL_DestroyRenderer(renderer);
                                                    SDL_DestroyWindow(window);
                                                    SDL_ExitWithError("Impossible de charger la texture");
                                                }
                                                if ( SDL_RenderCopy(renderer, Texture_case6, NULL, &BG) != 0 )
                                                {
                                                    SDL_DestroyRenderer(renderer);
                                                    SDL_DestroyWindow(window);
                                                    SDL_ExitWithError("Impossible d'afficher la texture");
                                                }
                                            }
                                            if (var+1 == 7)
                                            {
                                                case7 = case0;
                                                Texture_case7 = Texture_case0;
                                                if (SDL_QueryTexture(Texture_case7, NULL, NULL, &BG.w, &BG.h) != 0)
                                                {
                                                    SDL_DestroyRenderer(renderer);
                                                    SDL_DestroyWindow(window);
                                                    SDL_ExitWithError("Impossible de charger la texture");
                                                }
                                                if ( SDL_RenderCopy(renderer, Texture_case7, NULL, &BG) != 0 )
                                                {
                                                    SDL_DestroyRenderer(renderer);
                                                    SDL_DestroyWindow(window);
                                                    SDL_ExitWithError("Impossible d'afficher la texture");
                                                }
                                            }
                                            if (var+1 == 8)
                                            {
                                                case8 = case0;
                                                Texture_case8 = Texture_case0;
                                                if (SDL_QueryTexture(Texture_case8, NULL, NULL, &BG.w, &BG.h) != 0)
                                                {
                                                    SDL_DestroyRenderer(renderer);
                                                    SDL_DestroyWindow(window);
                                                    SDL_ExitWithError("Impossible de charger la texture");
                                                }
                                                if ( SDL_RenderCopy(renderer, Texture_case8, NULL, &BG) != 0 )
                                                {
                                                    SDL_DestroyRenderer(renderer);
                                                    SDL_DestroyWindow(window);
                                                    SDL_ExitWithError("Impossible d'afficher la texture");
                                                }
                                            }
                                            if (var+1 == 9)
                                            {
                                                case9 = case0;
                                                Texture_case9 = Texture_case0;
                                                if (SDL_QueryTexture(Texture_case9, NULL, NULL, &BG.w, &BG.h) != 0)
                                                {
                                                    SDL_DestroyRenderer(renderer);
                                                    SDL_DestroyWindow(window);
                                                    SDL_ExitWithError("Impossible de charger la texture");
                                                }
                                                if ( SDL_RenderCopy(renderer, Texture_case9, NULL, &BG) != 0 )
                                                {
                                                    SDL_DestroyRenderer(renderer);
                                                    SDL_DestroyWindow(window);
                                                    SDL_ExitWithError("Impossible d'afficher la texture");
                                                }
                                            }
                                            if (var+1 == 10)
                                            {
                                                case10 = case0;
                                                Texture_case10 = Texture_case0;
                                                if (SDL_QueryTexture(Texture_case10, NULL, NULL, &BG.w, &BG.h) != 0)
                                                {
                                                    SDL_DestroyRenderer(renderer);
                                                    SDL_DestroyWindow(window);
                                                    SDL_ExitWithError("Impossible de charger la texture");
                                                }
                                                if ( SDL_RenderCopy(renderer, Texture_case10, NULL, &BG) != 0 )
                                                {
                                                    SDL_DestroyRenderer(renderer);
                                                    SDL_DestroyWindow(window);
                                                    SDL_ExitWithError("Impossible d'afficher la texture");
                                                }
                                            }
                                            if (var+1 == 11)
                                            {
                                                case11 = case0;
                                                Texture_case11 = Texture_case0;
                                                if (SDL_QueryTexture(Texture_case11, NULL, NULL, &BG.w, &BG.h) != 0)
                                                {
                                                    SDL_DestroyRenderer(renderer);
                                                    SDL_DestroyWindow(window);
                                                    SDL_ExitWithError("Impossible de charger la texture");
                                                }
                                                if ( SDL_RenderCopy(renderer, Texture_case11, NULL, &BG) != 0 )
                                                {
                                                    SDL_DestroyRenderer(renderer);
                                                    SDL_DestroyWindow(window);
                                                    SDL_ExitWithError("Impossible d'afficher la texture");
                                                }
                                            }
                                            if (var+1 == 12)
                                            {
                                                case12 = case0;
                                                Texture_case12 = Texture_case0;
                                                if (SDL_QueryTexture(Texture_case12, NULL, NULL, &BG.w, &BG.h) != 0)
                                                {
                                                    SDL_DestroyRenderer(renderer);
                                                    SDL_DestroyWindow(window);
                                                    SDL_ExitWithError("Impossible de charger la texture");
                                                }
                                                if ( SDL_RenderCopy(renderer, Texture_case12, NULL, &BG) != 0 )
                                                {
                                                    SDL_DestroyRenderer(renderer);
                                                    SDL_DestroyWindow(window);
                                                    SDL_ExitWithError("Impossible d'afficher la texture");
                                                }
                                            }
                                            if (var+1 == 13)
                                            {
                                                case13 = case0;
                                                Texture_case13 = Texture_case0;
                                                if (SDL_QueryTexture(Texture_case13, NULL, NULL, &BG.w, &BG.h) != 0)
                                                {
                                                    SDL_DestroyRenderer(renderer);
                                                    SDL_DestroyWindow(window);
                                                    SDL_ExitWithError("Impossible de charger la texture");
                                                }
                                                if ( SDL_RenderCopy(renderer, Texture_case13, NULL, &BG) != 0 )
                                                {
                                                    SDL_DestroyRenderer(renderer);
                                                    SDL_DestroyWindow(window);
                                                    SDL_ExitWithError("Impossible d'afficher la texture");
                                                }
                                            }
                                            if (var+1 == 14)
                                            {
                                                case14 = case0;
                                                Texture_case14 = Texture_case0;
                                                if (SDL_QueryTexture(Texture_case14, NULL, NULL, &BG.w, &BG.h) != 0)
                                                {
                                                    SDL_DestroyRenderer(renderer);
                                                    SDL_DestroyWindow(window);
                                                    SDL_ExitWithError("Impossible de charger la texture");
                                                }
                                                if ( SDL_RenderCopy(renderer, Texture_case14, NULL, &BG) != 0 )
                                                {
                                                    SDL_DestroyRenderer(renderer);
                                                    SDL_DestroyWindow(window);
                                                    SDL_ExitWithError("Impossible d'afficher la texture");
                                                }
                                            }
                                            if (var+1 == 15)
                                            {
                                                case15 = case0;
                                                Texture_case15 = Texture_case0;
                                                if (SDL_QueryTexture(Texture_case15, NULL, NULL, &BG.w, &BG.h) != 0)
                                                {
                                                    SDL_DestroyRenderer(renderer);
                                                    SDL_DestroyWindow(window);
                                                    SDL_ExitWithError("Impossible de charger la texture");
                                                }
                                                if ( SDL_RenderCopy(renderer, Texture_case15, NULL, &BG) != 0 )
                                                {
                                                    SDL_DestroyRenderer(renderer);
                                                    SDL_DestroyWindow(window);
                                                    SDL_ExitWithError("Impossible d'afficher la texture");
                                                }
                                            }
                                            if (var+1 == 16)
                                            {
                                                case16 = case0;
                                                Texture_case16 = Texture_case0;
                                                if (SDL_QueryTexture(Texture_case16, NULL, NULL, &BG.w, &BG.h) != 0)
                                                {
                                                    SDL_DestroyRenderer(renderer);
                                                    SDL_DestroyWindow(window);
                                                    SDL_ExitWithError("Impossible de charger la texture");
                                                }
                                                if ( SDL_RenderCopy(renderer, Texture_case16, NULL, &BG) != 0 )
                                                {
                                                    SDL_DestroyRenderer(renderer);
                                                    SDL_DestroyWindow(window);
                                                    SDL_ExitWithError("Impossible d'afficher la texture");
                                                }
                                            }
                                        }   
                                }    
                            case SDLK_s :
                                if (affichage_menu == 2)
                                {
                                    DeplacerBas(Grille);
                                    for (var = 0; var<16; var++)
                                        {
                                            if (var+1 == 1)
                                            {
                                                case0 = case1;
                                                Texture_case0 = Texture_case1;
                                                BG.x = 30;
                                                BG.y = 30;
                                            }
                                            if (var+1 == 2)
                                            {
                                                case0 = case2;
                                                Texture_case0 = Texture_case2;
                                                BG.x = 222;
                                                BG.y = 30;
                                            }
                                            if (var+1 == 3)
                                            {
                                                case0 = case3;
                                                Texture_case0 = Texture_case3;
                                                BG.x = 416;
                                                BG.y = 30;
                                            }
                                            if (var+1 == 4)
                                            {
                                                case0 = case4;
                                                Texture_case0 = Texture_case4;
                                                BG.x = 608;
                                                BG.y = 30;
                                            }
                                            if (var+1 == 5)
                                            {
                                                case0 = case5;
                                                Texture_case0 = Texture_case5;
                                                BG.x = 30;
                                                BG.y = 222;
                                            }
                                            if (var+1 == 6)
                                            {
                                                case0 = case6;
                                                Texture_case0 = Texture_case6;
                                                BG.x = 222;
                                                BG.y = 222;
                                            }
                                            if (var+1 == 7)
                                            {
                                                case0 = case7;
                                                Texture_case0 = Texture_case7;
                                                BG.x = 416;
                                                BG.y = 222;
                                            }
                                            if (var+1 == 8)
                                            {
                                                case0 = case8;
                                                Texture_case0 = Texture_case8;
                                                BG.x = 608;
                                                BG.y = 222;
                                            }
                                            if (var+1 == 9)
                                            {
                                                case0 = case9;
                                                Texture_case0 = Texture_case9;
                                                BG.x = 30;
                                                BG.y = 416;
                                            }
                                            if (var+1 == 10)
                                            {
                                                case0 = case10;
                                                Texture_case0 = Texture_case10;
                                                BG.x = 222;
                                                BG.y = 416;
                                            }
                                            if (var+1 == 11)
                                            {
                                                case0 = case11;
                                                Texture_case0 = Texture_case11;
                                                BG.x = 416;
                                                BG.y = 416;
                                            }
                                            if (var+1 == 12)
                                            {
                                                case0 = case12;
                                                Texture_case0 = Texture_case12;
                                                BG.x = 608;
                                                BG.y = 416;
                                            }
                                            if (var+1 == 13)
                                            {
                                                case0 = case13;
                                                Texture_case0 = Texture_case13;
                                                BG.x = 30;
                                                BG.y = 608;
                                            }
                                            if (var+1 == 14)
                                            {
                                                case0 = case14;
                                                Texture_case0 = Texture_case14;
                                                BG.x = 222;
                                                BG.y = 608;
                                            }
                                            if (var+1 == 15)
                                            {
                                                case0 = case15;
                                                Texture_case0 = Texture_case15;
                                                BG.x = 416;
                                                BG.y = 608;
                                            }
                                            if (var+1 == 16)
                                            {
                                                case0 = case16;
                                                Texture_case0 = Texture_case16;
                                                BG.x = 608;
                                                BG.y = 608;
                                            }

                                            if (varx > 3)
                                            {
                                                vary += 1;
                                                varx = 0;
                                            }   
                                            if (Grille[vary][varx]== 0)
                                            {
                                                continue;
                                            }
                                            else if (Grille[vary][varx]== 2)
                                            {
                                                case0 = SDL_LoadBMP("img/2.bmp");
                                            }
                                            else if (Grille[vary][varx] == 4)
                                            {
                                                case0 = SDL_LoadBMP("img/4.bmp");
                                            }
                                            else if (Grille[vary][varx] == 8)
                                            {
                                                case0 = SDL_LoadBMP("img/8.bmp");
                                            }
                                            else if (Grille[vary][varx]== 16)
                                            {
                                                case0= SDL_LoadBMP("img/16.bmp");
                                            }
                                            else if (Grille[vary][varx] == 32)
                                            {
                                                case0 = SDL_LoadBMP("img/32.bmp");
                                            }
                                            else if (Grille[vary][varx] == 64)
                                            {
                                                case0 = SDL_LoadBMP("img/64.bmp");
                                            }
                                            else if (Grille[vary][varx]== 128)
                                            {
                                                case0 = SDL_LoadBMP("img/128.bmp");
                                            }
                                            else if (Grille[vary][varx] == 256)
                                            {
                                                case0 = SDL_LoadBMP("img/256.bmp");
                                            }
                                            else if (Grille[vary][varx] == 512)
                                            {
                                                case0 = SDL_LoadBMP("img/512.bmp");
                                            }
                                            else if (Grille[vary][varx]== 1024)
                                            {
                                                case0 = SDL_LoadBMP("img/1024.bmp");
                                            }
                                            else if (Grille[vary][varx] == 2048)
                                            {
                                                case0 = SDL_LoadBMP("img/2048.bmp");
                                            }
                                            if (case0 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                                    
                                            Texture_case0 = SDL_CreateTextureFromSurface(renderer, case0);
                                            SDL_FreeSurface(case0);
                                                    
                                            if (Texture_case0 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }
                                            if (SDL_QueryTexture(Texture_case0, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            if ( SDL_RenderCopy(renderer, Texture_case0, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                            varx += 1;
                                            if (var+1 == 1)
                                            {
                                                case1 = case0;
                                                Texture_case1 = Texture_case0;
                                                if (SDL_QueryTexture(Texture_case1, NULL, NULL, &BG.w, &BG.h) != 0)
                                                {
                                                    SDL_DestroyRenderer(renderer);
                                                    SDL_DestroyWindow(window);
                                                    SDL_ExitWithError("Impossible de charger la texture");
                                                }
                                                if ( SDL_RenderCopy(renderer, Texture_case1, NULL, &BG) != 0 )
                                                {
                                                    SDL_DestroyRenderer(renderer);
                                                    SDL_DestroyWindow(window);
                                                    SDL_ExitWithError("Impossible d'afficher la texture");
                                                }

                                            }
                                            if (var+1 == 2)
                                            {
                                                case2 = case0;
                                                Texture_case2 = Texture_case0;
                                                if (SDL_QueryTexture(Texture_case2, NULL, NULL, &BG.w, &BG.h) != 0)
                                                {
                                                    SDL_DestroyRenderer(renderer);
                                                    SDL_DestroyWindow(window);
                                                    SDL_ExitWithError("Impossible de charger la texture");
                                                }
                                                if ( SDL_RenderCopy(renderer, Texture_case2, NULL, &BG) != 0 )
                                                {
                                                    SDL_DestroyRenderer(renderer);
                                                    SDL_DestroyWindow(window);
                                                    SDL_ExitWithError("Impossible d'afficher la texture");
                                                }
                                            }
                                            if (var+1 == 3)
                                            {
                                                case3 = case0;
                                                Texture_case3 = Texture_case0;
                                                if (SDL_QueryTexture(Texture_case3, NULL, NULL, &BG.w, &BG.h) != 0)
                                                {
                                                    SDL_DestroyRenderer(renderer);
                                                    SDL_DestroyWindow(window);
                                                    SDL_ExitWithError("Impossible de charger la texture");
                                                }
                                                if ( SDL_RenderCopy(renderer, Texture_case4, NULL, &BG) != 0 )
                                                {
                                                    SDL_DestroyRenderer(renderer);
                                                    SDL_DestroyWindow(window);
                                                    SDL_ExitWithError("Impossible d'afficher la texture");
                                                }
                                            }
                                            if (var+1 == 4)
                                            {
                                                case4 = case0;
                                                Texture_case4 = Texture_case0;
                                                if (SDL_QueryTexture(Texture_case4, NULL, NULL, &BG.w, &BG.h) != 0)
                                                {
                                                    SDL_DestroyRenderer(renderer);
                                                    SDL_DestroyWindow(window);
                                                    SDL_ExitWithError("Impossible de charger la texture");
                                                }
                                                if ( SDL_RenderCopy(renderer, Texture_case4, NULL, &BG) != 0 )
                                                {
                                                    SDL_DestroyRenderer(renderer);
                                                    SDL_DestroyWindow(window);
                                                    SDL_ExitWithError("Impossible d'afficher la texture");
                                                }
                                            }
                                            if (var+1 == 5)
                                            {
                                                case5 = case0;
                                                Texture_case5 = Texture_case0;
                                                if (SDL_QueryTexture(Texture_case5, NULL, NULL, &BG.w, &BG.h) != 0)
                                                {
                                                    SDL_DestroyRenderer(renderer);
                                                    SDL_DestroyWindow(window);
                                                    SDL_ExitWithError("Impossible de charger la texture");
                                                }
                                                if ( SDL_RenderCopy(renderer, Texture_case5, NULL, &BG) != 0 )
                                                {
                                                    SDL_DestroyRenderer(renderer);
                                                    SDL_DestroyWindow(window);
                                                    SDL_ExitWithError("Impossible d'afficher la texture");
                                                }
                                            }
                                            if (var+1 == 6)
                                            {
                                                case6 = case0;
                                                Texture_case6 = Texture_case0;
                                                if (SDL_QueryTexture(Texture_case6, NULL, NULL, &BG.w, &BG.h) != 0)
                                                {
                                                    SDL_DestroyRenderer(renderer);
                                                    SDL_DestroyWindow(window);
                                                    SDL_ExitWithError("Impossible de charger la texture");
                                                }
                                                if ( SDL_RenderCopy(renderer, Texture_case6, NULL, &BG) != 0 )
                                                {
                                                    SDL_DestroyRenderer(renderer);
                                                    SDL_DestroyWindow(window);
                                                    SDL_ExitWithError("Impossible d'afficher la texture");
                                                }
                                            }
                                            if (var+1 == 7)
                                            {
                                                case7 = case0;
                                                Texture_case7 = Texture_case0;
                                                if (SDL_QueryTexture(Texture_case7, NULL, NULL, &BG.w, &BG.h) != 0)
                                                {
                                                    SDL_DestroyRenderer(renderer);
                                                    SDL_DestroyWindow(window);
                                                    SDL_ExitWithError("Impossible de charger la texture");
                                                }
                                                if ( SDL_RenderCopy(renderer, Texture_case7, NULL, &BG) != 0 )
                                                {
                                                    SDL_DestroyRenderer(renderer);
                                                    SDL_DestroyWindow(window);
                                                    SDL_ExitWithError("Impossible d'afficher la texture");
                                                }
                                            }
                                            if (var+1 == 8)
                                            {
                                                case8 = case0;
                                                Texture_case8 = Texture_case0;
                                                if (SDL_QueryTexture(Texture_case8, NULL, NULL, &BG.w, &BG.h) != 0)
                                                {
                                                    SDL_DestroyRenderer(renderer);
                                                    SDL_DestroyWindow(window);
                                                    SDL_ExitWithError("Impossible de charger la texture");
                                                }
                                                if ( SDL_RenderCopy(renderer, Texture_case8, NULL, &BG) != 0 )
                                                {
                                                    SDL_DestroyRenderer(renderer);
                                                    SDL_DestroyWindow(window);
                                                    SDL_ExitWithError("Impossible d'afficher la texture");
                                                }
                                            }
                                            if (var+1 == 9)
                                            {
                                                case9 = case0;
                                                Texture_case9 = Texture_case0;
                                                if (SDL_QueryTexture(Texture_case9, NULL, NULL, &BG.w, &BG.h) != 0)
                                                {
                                                    SDL_DestroyRenderer(renderer);
                                                    SDL_DestroyWindow(window);
                                                    SDL_ExitWithError("Impossible de charger la texture");
                                                }
                                                if ( SDL_RenderCopy(renderer, Texture_case9, NULL, &BG) != 0 )
                                                {
                                                    SDL_DestroyRenderer(renderer);
                                                    SDL_DestroyWindow(window);
                                                    SDL_ExitWithError("Impossible d'afficher la texture");
                                                }
                                            }
                                            if (var+1 == 10)
                                            {
                                                case10 = case0;
                                                Texture_case10 = Texture_case0;
                                                if (SDL_QueryTexture(Texture_case10, NULL, NULL, &BG.w, &BG.h) != 0)
                                                {
                                                    SDL_DestroyRenderer(renderer);
                                                    SDL_DestroyWindow(window);
                                                    SDL_ExitWithError("Impossible de charger la texture");
                                                }
                                                if ( SDL_RenderCopy(renderer, Texture_case10, NULL, &BG) != 0 )
                                                {
                                                    SDL_DestroyRenderer(renderer);
                                                    SDL_DestroyWindow(window);
                                                    SDL_ExitWithError("Impossible d'afficher la texture");
                                                }
                                            }
                                            if (var+1 == 11)
                                            {
                                                case11 = case0;
                                                Texture_case11 = Texture_case0;
                                                if (SDL_QueryTexture(Texture_case11, NULL, NULL, &BG.w, &BG.h) != 0)
                                                {
                                                    SDL_DestroyRenderer(renderer);
                                                    SDL_DestroyWindow(window);
                                                    SDL_ExitWithError("Impossible de charger la texture");
                                                }
                                                if ( SDL_RenderCopy(renderer, Texture_case11, NULL, &BG) != 0 )
                                                {
                                                    SDL_DestroyRenderer(renderer);
                                                    SDL_DestroyWindow(window);
                                                    SDL_ExitWithError("Impossible d'afficher la texture");
                                                }
                                            }
                                            if (var+1 == 12)
                                            {
                                                case12 = case0;
                                                Texture_case12 = Texture_case0;
                                                if (SDL_QueryTexture(Texture_case12, NULL, NULL, &BG.w, &BG.h) != 0)
                                                {
                                                    SDL_DestroyRenderer(renderer);
                                                    SDL_DestroyWindow(window);
                                                    SDL_ExitWithError("Impossible de charger la texture");
                                                }
                                                if ( SDL_RenderCopy(renderer, Texture_case12, NULL, &BG) != 0 )
                                                {
                                                    SDL_DestroyRenderer(renderer);
                                                    SDL_DestroyWindow(window);
                                                    SDL_ExitWithError("Impossible d'afficher la texture");
                                                }
                                            }
                                            if (var+1 == 13)
                                            {
                                                case13 = case0;
                                                Texture_case13 = Texture_case0;
                                                if (SDL_QueryTexture(Texture_case13, NULL, NULL, &BG.w, &BG.h) != 0)
                                                {
                                                    SDL_DestroyRenderer(renderer);
                                                    SDL_DestroyWindow(window);
                                                    SDL_ExitWithError("Impossible de charger la texture");
                                                }
                                                if ( SDL_RenderCopy(renderer, Texture_case13, NULL, &BG) != 0 )
                                                {
                                                    SDL_DestroyRenderer(renderer);
                                                    SDL_DestroyWindow(window);
                                                    SDL_ExitWithError("Impossible d'afficher la texture");
                                                }
                                            }
                                            if (var+1 == 14)
                                            {
                                                case14 = case0;
                                                Texture_case14 = Texture_case0;
                                                if (SDL_QueryTexture(Texture_case14, NULL, NULL, &BG.w, &BG.h) != 0)
                                                {
                                                    SDL_DestroyRenderer(renderer);
                                                    SDL_DestroyWindow(window);
                                                    SDL_ExitWithError("Impossible de charger la texture");
                                                }
                                                if ( SDL_RenderCopy(renderer, Texture_case14, NULL, &BG) != 0 )
                                                {
                                                    SDL_DestroyRenderer(renderer);
                                                    SDL_DestroyWindow(window);
                                                    SDL_ExitWithError("Impossible d'afficher la texture");
                                                }
                                            }
                                            if (var+1 == 15)
                                            {
                                                case15 = case0;
                                                Texture_case15 = Texture_case0;
                                                if (SDL_QueryTexture(Texture_case15, NULL, NULL, &BG.w, &BG.h) != 0)
                                                {
                                                    SDL_DestroyRenderer(renderer);
                                                    SDL_DestroyWindow(window);
                                                    SDL_ExitWithError("Impossible de charger la texture");
                                                }
                                                if ( SDL_RenderCopy(renderer, Texture_case15, NULL, &BG) != 0 )
                                                {
                                                    SDL_DestroyRenderer(renderer);
                                                    SDL_DestroyWindow(window);
                                                    SDL_ExitWithError("Impossible d'afficher la texture");
                                                }
                                            }
                                            if (var+1 == 16)
                                            {
                                                case16 = case0;
                                                Texture_case16 = Texture_case0;
                                                if (SDL_QueryTexture(Texture_case16, NULL, NULL, &BG.w, &BG.h) != 0)
                                                {
                                                    SDL_DestroyRenderer(renderer);
                                                    SDL_DestroyWindow(window);
                                                    SDL_ExitWithError("Impossible de charger la texture");
                                                }
                                                if ( SDL_RenderCopy(renderer, Texture_case16, NULL, &BG) != 0 )
                                                {
                                                    SDL_DestroyRenderer(renderer);
                                                    SDL_DestroyWindow(window);
                                                    SDL_ExitWithError("Impossible d'afficher la texture");
                                                }
                                            }
                                        }   
                                }    
                            }
                
                case SDL_MOUSEMOTION :
                {
                            int X = event.motion.x;
                            int Y = event.motion.y;
                            if (((((((X >= 200)&&(X <= 600))&&((Y >= 418)&&(Y<= 518))))||((((X>= 200)&&(X <= 600))&&((Y >= 268)&&(Y<= 368)))))||((((X >= 200)&&(X <= 600))&&((Y >= 568)&&(Y<= 668)))))&&(affichage_menu == 0))
                            {
                                if (((X >= 200)&&(X <= 600))&&((Y >= 268)&&(Y<= 368)))
                                {
                                    //afficher image assombrie
                                    printf("C'EST LA CASE0 1\n");
                                    image = SDL_LoadBMP("img/Button1.bmp");
                                    
                                    if (image == NULL)
                                    {
                                        SDL_DestroyRenderer(renderer);
                                        SDL_DestroyWindow(window);
                                        SDL_ExitWithError("Impossible de charger l'image");
                                        printf("Chargement");
                                    }
        
                                    texture = SDL_CreateTextureFromSurface(renderer, image);
                                    SDL_FreeSurface(image);
        
                                    if (texture == NULL)
                                    {
                                        SDL_DestroyRenderer(renderer);
                                        SDL_DestroyWindow(window);
                                        SDL_ExitWithError("Impossible de créer la texture");
                                    }

                                    SDL_Rect BG;
        
                                    if (SDL_QueryTexture(texture, NULL, NULL, &BG.w, &BG.h) != 0)
                                    {
                                        SDL_DestroyRenderer(renderer);
                                        SDL_DestroyWindow(window);
                                        SDL_ExitWithError("Impossible de charger la texture");
                                    }
        
                                    BG.x = (WindowWidth - BG.w)/2;
                                    BG.y = (WindowHeight - BG.h)/2;
                                    
                                    if ( SDL_RenderCopy(renderer, texture, NULL, &BG) != 0 )
                                    {
                                        SDL_DestroyRenderer(renderer);
                                        SDL_DestroyWindow(window);
                                        SDL_ExitWithError("Impossible d'afficher la texture");
                                    }
                                    SDL_RenderPresent(renderer);
                                }

                                if (((X >= 200)&&(X <= 600))&&((Y >= 418)&&(Y<= 518)))
                                {
                                    //afficher image assombrie
                                    printf("C'EST LA CASE0 2\n");
                                    image = SDL_LoadBMP("img/Button2.bmp");

                                    if (image == NULL)
                                    {
                                        SDL_DestroyRenderer(renderer);
                                        SDL_DestroyWindow(window);
                                        SDL_ExitWithError("Impossible de charger l'image");
                                        printf("Chargement");
                                    }
        
                                    texture = SDL_CreateTextureFromSurface(renderer, image);
                                    SDL_FreeSurface(image);
        
                                    if (texture == NULL)
                                    {
                                        SDL_DestroyRenderer(renderer);
                                        SDL_DestroyWindow(window);
                                        SDL_ExitWithError("Impossible de créer la texture");
                                    }

                                    SDL_Rect BG;
        
                                    if (SDL_QueryTexture(texture, NULL, NULL, &BG.w, &BG.h) != 0)
                                    {
                                        SDL_DestroyRenderer(renderer);
                                        SDL_DestroyWindow(window);
                                        SDL_ExitWithError("Impossible de charger la texture");
                                    }
        
                                    BG.x = (WindowWidth - BG.w)/2;
                                    BG.y = (WindowHeight - BG.h)/2;
                                    
                                    if ( SDL_RenderCopy(renderer, texture, NULL, &BG) != 0 )
                                    {
                                        SDL_DestroyRenderer(renderer);
                                        SDL_DestroyWindow(window);
                                        SDL_ExitWithError("Impossible d'afficher la texture");
                                    }
                                    SDL_RenderPresent(renderer);
                                    //si il clique ça change de menu
                                }

                                if (((X >= 200)&&(X <= 600))&&((Y >= 568)&&(Y<= 668)))
                                {
                                    //afficher image assombrie
                                    printf("C'EST LA CASE0 3\n");

                                    image = SDL_LoadBMP("img/Button3.bmp");

                                    if (image == NULL)
                                    {
                                        SDL_DestroyRenderer(renderer);
                                        SDL_DestroyWindow(window);
                                        SDL_ExitWithError("Impossible de charger l'image");
                                        printf("Chargement");
                                    }
        
                                    texture = SDL_CreateTextureFromSurface(renderer, image);
                                    SDL_FreeSurface(image);
        
                                    if (texture == NULL)
                                    {
                                        SDL_DestroyRenderer(renderer);
                                        SDL_DestroyWindow(window);
                                        SDL_ExitWithError("Impossible de créer la texture");
                                    }

                                    SDL_Rect BG;
        
                                    if (SDL_QueryTexture(texture, NULL, NULL, &BG.w, &BG.h) != 0)
                                    {
                                        SDL_DestroyRenderer(renderer);
                                        SDL_DestroyWindow(window);
                                        SDL_ExitWithError("Impossible de charger la texture");
                                    }
        
                                    BG.x = (WindowWidth - BG.w)/2;
                                    BG.y = (WindowHeight - BG.h)/2;
                                    
                                    if ( SDL_RenderCopy(renderer, texture, NULL, &BG) != 0 )
                                    {
                                        SDL_DestroyRenderer(renderer);
                                        SDL_DestroyWindow(window);
                                        SDL_ExitWithError("Impossible d'afficher la texture");
                                    }
                                    SDL_RenderPresent(renderer);
                                    //si il clique ça change de menu
                                }
                            }
                            else if (affichage_menu == 0)
                            {
                                image = SDL_LoadBMP("img/Menu.bmp");

                                if (image == NULL)
                                {
                                    SDL_DestroyRenderer(renderer);
                                    SDL_DestroyWindow(window);
                                    SDL_ExitWithError("Impossible de charger l'image");
                                    printf("Chargement");
                                }
    
                                texture = SDL_CreateTextureFromSurface(renderer, image);
                                SDL_FreeSurface(image);
    
                                if (texture == NULL)
                                {
                                    SDL_DestroyRenderer(renderer);
                                    SDL_DestroyWindow(window);
                                    SDL_ExitWithError("Impossible de créer la texture");
                                }
                                SDL_Rect BG;
    
                                if (SDL_QueryTexture(texture, NULL, NULL, &BG.w, &BG.h) != 0)
                                {
                                    SDL_DestroyRenderer(renderer);
                                    SDL_DestroyWindow(window);
                                    SDL_ExitWithError("Impossible de charger la texture");
                                }
        
                                BG.x = (WindowWidth - BG.w)/2;
                                BG.y = (WindowHeight - BG.h)/2;
                                    
                                if ( SDL_RenderCopy(renderer, texture, NULL, &BG) != 0 )
                                {
                                    SDL_DestroyRenderer(renderer);
                                    SDL_DestroyWindow(window);
                                    SDL_ExitWithError("Impossible d'afficher la texture");
                                }
                                SDL_RenderPresent(renderer);
                            }
                            else if (affichage_menu == 1)
                            {
                                if (settings == 0)
                                {
                                    image = SDL_LoadBMP("img/000.bmp");
                                }
                                else if (settings == 1)
                                {
                                    image = SDL_LoadBMP("img/100.bmp");
                                }
                                else if (settings == 2)
                                {
                                    image = SDL_LoadBMP("img/001.bmp");
                                }
                                else if (settings == 3)
                                {
                                    image = SDL_LoadBMP("img/010.bmp");
                                }
                                else if (settings == 4)
                                {
                                    image = SDL_LoadBMP("img/011.bmp");
                                }
                                else if (settings == 5)
                                {
                                    image = SDL_LoadBMP("img/101.bmp");
                                }
                                if (image == NULL)
                                {
                                    SDL_DestroyRenderer(renderer);
                                    SDL_DestroyWindow(window);
                                    SDL_ExitWithError("Impossible de charger l'image");
                                    printf("Chargement");
                                }
    
                                texture = SDL_CreateTextureFromSurface(renderer, image);
                                SDL_FreeSurface(image);
    
                                if (texture == NULL)
                                {
                                    SDL_DestroyRenderer(renderer);
                                    SDL_DestroyWindow(window);
                                    SDL_ExitWithError("Impossible de créer la texture");
                                }
                                SDL_Rect BG;
    
                                if (SDL_QueryTexture(texture, NULL, NULL, &BG.w, &BG.h) != 0)
                                {
                                    SDL_DestroyRenderer(renderer);
                                    SDL_DestroyWindow(window);
                                    SDL_ExitWithError("Impossible de charger la texture");
                                }
        
                                BG.x = (WindowWidth - BG.w)/2;
                                BG.y = (WindowHeight - BG.h)/2;
                                    
                                if ( SDL_RenderCopy(renderer, texture, NULL, &BG) != 0 )
                                {
                                    SDL_DestroyRenderer(renderer);
                                    SDL_DestroyWindow(window);
                                    SDL_ExitWithError("Impossible d'afficher la texture");
                                }
                                SDL_RenderPresent(renderer);
                            }
                            continue;
                }
                case SDL_MOUSEBUTTONDOWN :
                {
                    /* Cas où l'utilisateur clic sur "QUIT" dans MENU */
                    if ((((event.button.x >= 200)&&(event.button.x <= 600))&&((event.button.y >= 568)&&(event.button.y <= 668)))&&(affichage_menu==0))
                    {
                        program_launched = SDL_FALSE; break;
                    }
                    
                    /* Cas où l'utilisateur clic sur SETTINGS dans MENU*/
                    else if ((((event.button.x >= 200)&&(event.button.x <= 600))&&((event.button.y >= 418)&&(event.button.y<= 518)))&&(affichage_menu == 0))
                    {
                        affichage_menu = 1;
                        if (settings == 0)
                        {
                            image = SDL_LoadBMP("img/000.bmp");
                        }
                        else if (settings == 1)
                        {
                            image = SDL_LoadBMP("img/100.bmp");
                        }
                        else if (settings == 2)
                        {
                            image = SDL_LoadBMP("img/001.bmp");
                        }
                        else if (settings == 3)
                        {
                            image = SDL_LoadBMP("img/010.bmp");
                        }
                        else if (settings == 4)
                        {
                            image = SDL_LoadBMP("img/011.bmp");
                        }
                        else if (settings == 5)
                        {
                            image = SDL_LoadBMP("img/101.bmp");
                        }

                        if (image == NULL)
                        {
                            SDL_DestroyRenderer(renderer);
                            SDL_DestroyWindow(window);
                            SDL_ExitWithError("Impossible de charger l'image");
                            printf("Chargement");
                        }
    
                        texture = SDL_CreateTextureFromSurface(renderer, image);
                        SDL_FreeSurface(image);
    
                        if (texture == NULL)
                        {
                            SDL_DestroyRenderer(renderer);
                            SDL_DestroyWindow(window);
                            SDL_ExitWithError("Impossible de créer la texture");
                        }
                        SDL_Rect BG;
    
                        if (SDL_QueryTexture(texture, NULL, NULL, &BG.w, &BG.h) != 0)
                        {
                            SDL_DestroyRenderer(renderer);
                            SDL_DestroyWindow(window);
                            SDL_ExitWithError("Impossible de charger la texture");
                        }
        
                        BG.x = (WindowWidth - BG.w)/2;
                        BG.y = (WindowHeight - BG.h)/2;
                                    
                        if ( SDL_RenderCopy(renderer, texture, NULL, &BG) != 0 )
                        {
                            SDL_DestroyRenderer(renderer);
                            SDL_DestroyWindow(window);
                            SDL_ExitWithError("Impossible d'afficher la texture");
                        }
                        SDL_RenderPresent(renderer);
                        continue;
                    }

                    /* Cas où l'utilisateur clic sur "START" dans MENU*/
                    else if ((((event.button.x >= 200)&&(event.button.x <= 600))&&((event.button.y >= 268)&&(event.button.y<= 368)))&&(affichage_menu==0))
                    {
                        
                        affichage_menu = 2;
                        if (skin_2048 == 0)
                        {
                            image = SDL_LoadBMP("img/grid.bmp");
                        }
                        if (skin_2048 == 1)
                        {
                            image = SDL_LoadBMP("img/gridblack.bmp");
                        }        
                        if (image == NULL)
                        {
                            SDL_DestroyRenderer(renderer);
                            SDL_DestroyWindow(window);
                            SDL_ExitWithError("Impossible de charger l'image");
                            printf("Chargement");
                        }
        
                        texture = SDL_CreateTextureFromSurface(renderer, image);
                        SDL_FreeSurface(image);
        
                        if (texture == NULL)
                        {
                            SDL_DestroyRenderer(renderer);
                            SDL_DestroyWindow(window);
                            SDL_ExitWithError("Impossible de créer la texture");
                        }

                        SDL_Rect BG;
        
                        if (SDL_QueryTexture(texture, NULL, NULL, &BG.w, &BG.h) != 0)
                        {
                            SDL_DestroyRenderer(renderer);
                            SDL_DestroyWindow(window);
                            SDL_ExitWithError("Impossible de charger la texture");
                        }
        
                        BG.x = (WindowWidth - BG.w)/2;
                        BG.y = (WindowHeight - BG.h)/2;
                                    
                        if ( SDL_RenderCopy(renderer, texture, NULL, &BG) != 0 )
                        {
                            SDL_DestroyRenderer(renderer);
                            SDL_DestroyWindow(window);
                            SDL_ExitWithError("Impossible d'afficher la texture");
                        }
                        SDL_RenderPresent(renderer);
                        int x;
                        int y;
                        int k;
                        int pose = 0;
                        while (pose==0)
                        {
                            x = rand()%4;
                            y = rand()%4;
                            if(Grille[x][y]==0)
                            {
                                pose=1;
                                k = rand()%2;
                                if(k==1)
                                {
                                    Grille[x][y]=2;
                                }
                                if(k==0)
                                {
                                    Grille[x][y]=4;
                                }
                            }
                        }
                        continue;
                    }
                    
                    /* Cas où l'utilisateur clic sur 4x4 dans SETTINGS */
                    else if ((((event.button.x >= 450)&&(event.button.x <= 550))&&((event.button.y >= 202)&&(event.button.y <= 302)))&&(affichage_menu == 1)) 
                    {
                        affichage_menu = 1;
                        if (settings == 0)
                        {
                            image = SDL_LoadBMP("img/000.bmp");
                            settings = 0;
                        }
                        else if (settings == 1)
                        {
                            image = SDL_LoadBMP("img/000.bmp");
                            settings = 0;
                        }
                        else if (settings == 2)
                        {
                            image = SDL_LoadBMP("img/001.bmp");
                            settings = 2;
                        }
                        else if (settings == 3)
                        {
                            image = SDL_LoadBMP("img/010.bmp");
                            settings = 3;
                        }
                        else if (settings == 4)
                        {
                            image = SDL_LoadBMP("img/011.bmp");
                            settings = 4;
                        }
                        else if (settings == 5)
                        {
                            image = SDL_LoadBMP("001.bmp");
                            settings = 2;
                        }
                        if (image == NULL)
                        {
                            SDL_DestroyRenderer(renderer);
                            SDL_DestroyWindow(window);
                            SDL_ExitWithError("Impossible de charger l'image");
                            printf("Chargement");
                        }
    
                        texture = SDL_CreateTextureFromSurface(renderer, image);
                        SDL_FreeSurface(image);
    
                        if (texture == NULL)
                        {
                            SDL_DestroyRenderer(renderer);
                            SDL_DestroyWindow(window);
                            SDL_ExitWithError("Impossible de créer la texture");
                        }
                        SDL_Rect BG;
    
                        if (SDL_QueryTexture(texture, NULL, NULL, &BG.w, &BG.h) != 0)
                        {
                            SDL_DestroyRenderer(renderer);
                            SDL_DestroyWindow(window);
                            SDL_ExitWithError("Impossible de charger la texture");
                        }
        
                        BG.x = (WindowWidth - BG.w)/2;
                        BG.y = (WindowHeight - BG.h)/2;
                                    
                        if ( SDL_RenderCopy(renderer, texture, NULL, &BG) != 0 )
                        {
                            SDL_DestroyRenderer(renderer);
                            SDL_DestroyWindow(window);
                            SDL_ExitWithError("Impossible d'afficher la texture");
                        }
                        SDL_RenderPresent(renderer);
                        continue;
                    }
                    
                    /* Cas où l'utilisateur clic sur 8x8 dans SETTINGS */
                    else if ((((event.button.x >= 600)&&(event.button.x <= 700))&&((event.button.y >= 202)&&(event.button.y <= 302)))&&(affichage_menu == 1))
                    {
                        affichage_menu = 1;
                        if (settings == 0)
                        {
                            image = SDL_LoadBMP("img/100.bmp");
                            settings = 1;
                        }                        
                        else if (settings == 1)
                        {
                            image = SDL_LoadBMP("img/100.bmp");
                            settings = 1;
                        }

                        else if (settings == 2)
                        {
                            image = SDL_LoadBMP("img/101.bmp");
                            settings = 5;
                        }
                        else if (settings == 3)
                        {
                            image = SDL_LoadBMP("img/100.bmp");
                            settings = 1;
                        }
                        else if (settings == 4)
                        {
                            image = SDL_LoadBMP("img/101.bmp");
                            settings = 5;
                        }
                        else if (settings == 5)
                        {
                            image = SDL_LoadBMP("img/101.bmp");
                            settings = 5;
                        }
                        if (image == NULL)
                        {
                            SDL_DestroyRenderer(renderer);
                            SDL_DestroyWindow(window);
                            SDL_ExitWithError("Impossible de charger l'image");
                            printf("Chargement");
                        }
    
                        texture = SDL_CreateTextureFromSurface(renderer, image);
                        SDL_FreeSurface(image);
    
                        if (texture == NULL)
                        {
                            SDL_DestroyRenderer(renderer);
                            SDL_DestroyWindow(window);
                            SDL_ExitWithError("Impossible de créer la texture");
                        }
                        SDL_Rect BG;
    
                        if (SDL_QueryTexture(texture, NULL, NULL, &BG.w, &BG.h) != 0)
                        {
                            SDL_DestroyRenderer(renderer);
                            SDL_DestroyWindow(window);
                            SDL_ExitWithError("Impossible de charger la texture");
                        }
        
                        BG.x = (WindowWidth - BG.w)/2;
                        BG.y = (WindowHeight - BG.h)/2;
                                    
                        if ( SDL_RenderCopy(renderer, texture, NULL, &BG) != 0 )
                        {
                            SDL_DestroyRenderer(renderer);
                            SDL_DestroyWindow(window);
                            SDL_ExitWithError("Impossible d'afficher la texture");
                        }
                        SDL_RenderPresent(renderer);
                        continue;
                    }

                    /* Cas où l'utilisateur clic sur 1P dans SETTINGS */
                    else if ((((event.button.x >= 450)&&(event.button.x <= 550))&&((event.button.y >= 402)&&(event.button.y <= 502)))&&(affichage_menu == 1))
                    {
                        affichage_menu = 1;
                        if (settings == 0)
                        {
                            image = SDL_LoadBMP("img/000.bmp");
                            settings = 0;
                        } 
                        else if (settings == 1)
                        {
                            image = SDL_LoadBMP("img/100.bmp");
                            settings = 1;
                        }                       
                        else if (settings == 2)
                        {
                            image = SDL_LoadBMP("img/001.bmp");
                            settings = 2;
                        }
                        else if (settings == 3)
                        {
                            image = SDL_LoadBMP("img/000.bmp");
                            settings = 0;
                        }
                        else if (settings == 4)
                        {
                            image = SDL_LoadBMP("img/001.bmp");
                            settings = 2;
                        }
                        else if (settings == 5)
                        {
                            image = SDL_LoadBMP("img/101.bmp");
                            settings = 5;
                        }
                        if (image == NULL)
                        {
                            SDL_DestroyRenderer(renderer);
                            SDL_DestroyWindow(window);
                            SDL_ExitWithError("Impossible de charger l'image");
                            printf("Chargement");
                        }
    
                        texture = SDL_CreateTextureFromSurface(renderer, image);
                        SDL_FreeSurface(image);
    
                        if (texture == NULL)
                        {
                            SDL_DestroyRenderer(renderer);
                            SDL_DestroyWindow(window);
                            SDL_ExitWithError("Impossible de créer la texture");
                        }
                        SDL_Rect BG;
    
                        if (SDL_QueryTexture(texture, NULL, NULL, &BG.w, &BG.h) != 0)
                        {
                            SDL_DestroyRenderer(renderer);
                            SDL_DestroyWindow(window);
                            SDL_ExitWithError("Impossible de charger la texture");
                        }
        
                        BG.x = (WindowWidth - BG.w)/2;
                        BG.y = (WindowHeight - BG.h)/2;
                                    
                        if ( SDL_RenderCopy(renderer, texture, NULL, &BG) != 0 )
                        {
                            SDL_DestroyRenderer(renderer);
                            SDL_DestroyWindow(window);
                            SDL_ExitWithError("Impossible d'afficher la texture");
                        }
                        SDL_RenderPresent(renderer);
                        continue;
                    }

                    /* Cas où l'utilisateur clic sur 2P dans SETTINGS */
                    else if ((((event.button.x >= 600)&&(event.button.x <= 700))&&((event.button.y >= 402)&&(event.button.y <= 502)))&&(affichage_menu == 1))
                    {
                        affichage_menu = 1;
                        if (settings == 0)
                        {
                            image = SDL_LoadBMP("img/010.bmp");
                            settings = 3;
                        }
                        else if (settings == 1)
                        {
                            image = SDL_LoadBMP("img/100.bmp");
                            settings = 1;
                        }                        
                        else if (settings == 2)
                        {
                            image = SDL_LoadBMP("img/011.bmp");
                            settings = 4;
                        }
                        else if (settings == 3)
                        {
                            image = SDL_LoadBMP("img/010.bmp");
                            settings = 3;
                        }
                        else if (settings == 4)
                        {
                            image = SDL_LoadBMP("img/011.bmp");
                            settings = 4;
                        }
                        else if (settings == 5)
                        {
                            image = SDL_LoadBMP("img/101.bmp");
                            settings = 5;
                        }

                        if (image == NULL)
                        {
                            SDL_DestroyRenderer(renderer);
                            SDL_DestroyWindow(window);
                            SDL_ExitWithError("Impossible de charger l'image");
                            printf("Chargement");
                        }
    
                        texture = SDL_CreateTextureFromSurface(renderer, image);
                        SDL_FreeSurface(image);
    
                        if (texture == NULL)
                        {
                            SDL_DestroyRenderer(renderer);
                            SDL_DestroyWindow(window);
                            SDL_ExitWithError("Impossible de créer la texture");
                        }
                        SDL_Rect BG;
    
                        if (SDL_QueryTexture(texture, NULL, NULL, &BG.w, &BG.h) != 0)
                        {
                            SDL_DestroyRenderer(renderer);
                            SDL_DestroyWindow(window);
                            SDL_ExitWithError("Impossible de charger la texture");
                        }
        
                        BG.x = (WindowWidth - BG.w)/2;
                        BG.y = (WindowHeight - BG.h)/2;
                                    
                        if ( SDL_RenderCopy(renderer, texture, NULL, &BG) != 0 )
                        {
                            SDL_DestroyRenderer(renderer);
                            SDL_DestroyWindow(window);
                            SDL_ExitWithError("Impossible d'afficher la texture");
                        }
                        SDL_RenderPresent(renderer);
                        continue;
                    }

                    /* Cas où l'utilisateur clic sur skin 1 dans SETTINGS */
                    else if ((((event.button.x >= 450)&&(event.button.x <= 550))&&((event.button.y >= 602)&&(event.button.y <= 702)))&&(affichage_menu == 1))
                    {
                        affichage_menu = 1;
                        if (settings == 0)
                        {
                            image = SDL_LoadBMP("img/000.bmp");
                            settings = 0;
                            skin_2048 = 0;
                        }                        
                        else if (settings == 1)
                        {
                            image = SDL_LoadBMP("img/100.bmp");
                            settings = 1;
                            skin_2048 = 0;
                        }

                        else if (settings == 2)
                        {
                            image = SDL_LoadBMP("img/000.bmp");
                            settings = 0;
                            skin_2048 = 0;
                        }
                        else if (settings == 3)
                        {
                            image = SDL_LoadBMP("img/010.bmp");
                            settings = 3;
                            skin_2048 = 0;
                        }
                        else if (settings == 4)
                        {
                            image = SDL_LoadBMP("img/010.bmp");
                            settings = 3;
                            skin_2048 = 0;
                        }
                        else if (settings == 5)
                        {
                            image = SDL_LoadBMP("img/100.bmp");
                            settings = 1;
                            skin_2048 = 0;
                        }

                        if (image == NULL)
                        {
                            SDL_DestroyRenderer(renderer);
                            SDL_DestroyWindow(window);
                            SDL_ExitWithError("Impossible de charger l'image");
                            printf("Chargement");
                        }
    
                        texture = SDL_CreateTextureFromSurface(renderer, image);
                        SDL_FreeSurface(image);
    
                        if (texture == NULL)
                        {
                            SDL_DestroyRenderer(renderer);
                            SDL_DestroyWindow(window);
                            SDL_ExitWithError("Impossible de créer la texture");
                        }
                        SDL_Rect BG;
    
                        if (SDL_QueryTexture(texture, NULL, NULL, &BG.w, &BG.h) != 0)
                        {
                            SDL_DestroyRenderer(renderer);
                            SDL_DestroyWindow(window);
                            SDL_ExitWithError("Impossible de charger la texture");
                        }
        
                        BG.x = (WindowWidth - BG.w)/2;
                        BG.y = (WindowHeight - BG.h)/2;
                                    
                        if ( SDL_RenderCopy(renderer, texture, NULL, &BG) != 0 )
                        {
                            SDL_DestroyRenderer(renderer);
                            SDL_DestroyWindow(window);
                            SDL_ExitWithError("Impossible d'afficher la texture");
                        }
                        SDL_RenderPresent(renderer);
                        continue;
                    }

                    /* Cas où l'utilisateur clic sur skin 2 dans SETTINGS */
                    else if ((((event.button.x >= 600)&&(event.button.x <= 700))&&((event.button.y >= 602)&&(event.button.y <= 702)))&&(affichage_menu == 1))
                    {
                        affichage_menu = 1;
                        if (settings == 0)
                        {
                            image = SDL_LoadBMP("img/001.bmp");
                            settings = 2;
                            skin_2048 = 1;
                        }                        
                        else if (settings == 1)
                        {
                            image = SDL_LoadBMP("img/101.bmp");
                            settings = 5;
                            skin_2048 = 1;
                        }

                        else if (settings == 2)
                        {
                            image = SDL_LoadBMP("img/001.bmp");
                            settings = 2;
                            skin_2048 = 1;
                        }
                        else if (settings == 3)
                        {
                            image = SDL_LoadBMP("img/011.bmp");
                            settings = 4;
                            skin_2048 = 1;
                        }
                        else if (settings == 4)
                        {
                            image = SDL_LoadBMP("img/011.bmp");
                            settings = 4;
                            skin_2048 = 1;
                        }
                        else if (settings == 5)
                        {
                            image = SDL_LoadBMP("img/101.bmp");
                            settings = 5;
                            skin_2048 = 1;
                        }

                        if (image == NULL)
                        {
                            SDL_DestroyRenderer(renderer);
                            SDL_DestroyWindow(window);
                            SDL_ExitWithError("Impossible de charger l'image");
                            printf("Chargement");
                        }
    
                        texture = SDL_CreateTextureFromSurface(renderer, image);
                        SDL_FreeSurface(image);
    
                        if (texture == NULL)
                        {
                            SDL_DestroyRenderer(renderer);
                            SDL_DestroyWindow(window);
                            SDL_ExitWithError("Impossible de créer la texture");
                        }
                        SDL_Rect BG;
    
                        if (SDL_QueryTexture(texture, NULL, NULL, &BG.w, &BG.h) != 0)
                        {
                            SDL_DestroyRenderer(renderer);
                            SDL_DestroyWindow(window);
                            SDL_ExitWithError("Impossible de charger la texture");
                        }
        
                        BG.x = (WindowWidth - BG.w)/2;
                        BG.y = (WindowHeight - BG.h)/2;
                                    
                        if ( SDL_RenderCopy(renderer, texture, NULL, &BG) != 0 )
                        {
                            SDL_DestroyRenderer(renderer);
                            SDL_DestroyWindow(window);
                            SDL_ExitWithError("Impossible d'afficher la texture");
                        }
                        SDL_RenderPresent(renderer);
                        continue;
                    }
                    
                    /* Cas où l'utilisateur clic sur la flèche dans SETTINGS */
                    else if ((((event.button.x >= 20)&&(event.button.x <= 100))&&((event.button.y >= 80)&&(event.button.y <= 120)))&&(affichage_menu == 1))
                    {
                        affichage_menu = 0;
                        image = SDL_LoadBMP("img/Menu.bmp");

                        if (image == NULL)
                        {
                            SDL_DestroyRenderer(renderer);
                            SDL_DestroyWindow(window);
                            SDL_ExitWithError("Impossible de charger l'image");
                            printf("Chargement");
                        }
    
                        texture = SDL_CreateTextureFromSurface(renderer, image);
                        SDL_FreeSurface(image);
    
                        if (texture == NULL)
                        {
                            SDL_DestroyRenderer(renderer);
                            SDL_DestroyWindow(window);
                            SDL_ExitWithError("Impossible de créer la texture");
                        }
                        SDL_Rect BG;
    
                        if (SDL_QueryTexture(texture, NULL, NULL, &BG.w, &BG.h) != 0)
                        {
                            SDL_DestroyRenderer(renderer);
                            SDL_DestroyWindow(window);
                            SDL_ExitWithError("Impossible de charger la texture");
                        }
        
                        BG.x = (WindowWidth - BG.w)/2;
                        BG.y = (WindowHeight - BG.h)/2;
                                    
                        if ( SDL_RenderCopy(renderer, texture, NULL, &BG) != 0 )
                        {
                            SDL_DestroyRenderer(renderer);
                            SDL_DestroyWindow(window);
                            SDL_ExitWithError("Impossible d'afficher la texture");
                        }
                        SDL_RenderPresent(renderer);
                        continue;
                    }

                    else 
                    {
                        continue;
                    }
                }
                case SDL_QUIT : {program_launched = SDL_FALSE; break;}
    			default : {break;}		
    		}
    	}
    }
    
    SDL_Delay(500);
    SDL_DestroyTexture(Texture_case1);
    SDL_DestroyTexture(Texture_case2);
    SDL_DestroyTexture(Texture_case3);
    SDL_DestroyTexture(Texture_case4);
    SDL_DestroyTexture(Texture_case5);
    SDL_DestroyTexture(Texture_case6);
    SDL_DestroyTexture(Texture_case7);
    SDL_DestroyTexture(Texture_case8);
    SDL_DestroyTexture(Texture_case9);
    SDL_DestroyTexture(Texture_case10);
    SDL_DestroyTexture(Texture_case11);
    SDL_DestroyTexture(Texture_case12);
    SDL_DestroyTexture(Texture_case13);
    SDL_DestroyTexture(Texture_case14);
    SDL_DestroyTexture(Texture_case15);
    SDL_DestroyTexture(Texture_case16);
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    
    return EXIT_SUCCESS;
}