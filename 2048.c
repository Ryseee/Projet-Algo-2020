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

int* AjouterCase (int Grille[N][N])
{
    int j;
    int i;
    int k;
    int pose = 0;
    while (pose==0)
    {
        i = rand()%4;
        j = rand()%4;
        if(Grille[i][j]==0)
        {
            pose=1;
            k = rand()%2;
            if(k==1)
            {
                Grille[i][j]=2;
            }
            if(k==0)
            {
                Grille[i][j]=4;
            }
        }
    }
    return Grille;
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
    while (program_launched)
    {
    	SDL_Event event;

    	while (SDL_PollEvent(&event))
    	{
    		switch(event.type)
    		{
    			case SDL_KEYDOWN : switch(event.key.keysym.sym)
    					    {
                            case SDLK_ESCAPE : printf("Vous avez quitté le programme\n"); program_launched = SDL_FALSE; break;
                            case SDLK_RIGHT :
                                if (affichage_menu == 2)
                                {
                                    printf("Vous avez appuyer sur la flèche droite \n");
                                    DeplacerDroite(Grille);
                                    if (skin_2048 == 0)
                                    {
                                        /* Case 1 */
                                        if (Grille[0][0]==0)
                                        {
                                            continue;
                                        }
                                        else if (Grille[0][0]==2)
                                        {
                                            case1 = SDL_LoadBMP("img/2.bmp");  
                                            if (case1 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case1 = SDL_CreateTextureFromSurface(renderer, case1);
                                            SDL_FreeSurface(case1);
                                            
                                            if (texture_case1 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 162;
                                            BG.h = 162;
                                            BG.x = 30;
                                            BG.y = 30;
                                            
                                            if (SDL_QueryTexture(texture_case1, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case1, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        else if (Grille[0][0]==4)
                                        {
                                            case1 = SDL_LoadBMP("img/4.bmp");  
                                            if (case1 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case1 = SDL_CreateTextureFromSurface(renderer, case1);
                                            SDL_FreeSurface(case1);
                                            
                                            if (texture_case1 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 162;
                                            BG.h = 162;
                                            BG.x = 30;
                                            BG.y = 30;
                                            
                                            if (SDL_QueryTexture(texture_case1, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case1, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        else if (Grille[0][0]==8)
                                        {
                                            case1 = SDL_LoadBMP("img/8.bmp");  
                                            if (case1 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case1 = SDL_CreateTextureFromSurface(renderer, case1);
                                            SDL_FreeSurface(case1);
                                            
                                            if (texture_case1 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 162;
                                            BG.h = 162;
                                            BG.x = 30;
                                            BG.y = 30;
                                            
                                            if (SDL_QueryTexture(texture_case1, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case1, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        else if (Grille[0][0]==16)
                                        {
                                            case1 = SDL_LoadBMP("img/16.bmp");  
                                            if (case1 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case1 = SDL_CreateTextureFromSurface(renderer, case1);
                                            SDL_FreeSurface(case1);
                                            
                                            if (texture_case1 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 162;
                                            BG.h = 162;
                                            BG.x = 30;
                                            BG.y = 30;
                                            
                                            if (SDL_QueryTexture(texture_case1, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case1, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        else if (Grille[0][0]==32)
                                        {
                                            case1 = SDL_LoadBMP("img/32.bmp");  
                                            if (case1 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case1 = SDL_CreateTextureFromSurface(renderer, case1);
                                            SDL_FreeSurface(case1);
                                            
                                            if (texture_case1 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 162;
                                            BG.h = 162;
                                            BG.x = 30;
                                            BG.y = 30;
                                            
                                            if (SDL_QueryTexture(texture_case1, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case1, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        else if (Grille[0][0]==64)
                                        {
                                            case1 = SDL_LoadBMP("img/64.bmp");  
                                            if (case1 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case1 = SDL_CreateTextureFromSurface(renderer, case1);
                                            SDL_FreeSurface(case1);
                                            
                                            if (texture_case1 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 162;
                                            BG.h = 162;
                                            BG.x = 30;
                                            BG.y = 30;
                                            
                                            if (SDL_QueryTexture(texture_case1, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case1, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        else if (Grille[0][0]==128)
                                        {
                                            case1 = SDL_LoadBMP("img/128.bmp");  
                                            if (case1 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case1 = SDL_CreateTextureFromSurface(renderer, case1);
                                            SDL_FreeSurface(case1);
                                            
                                            if (texture_case1 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 162;
                                            BG.h = 162;
                                            BG.x = 30;
                                            BG.y = 30;
                                            
                                            if (SDL_QueryTexture(texture_case1, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case1, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        else if (Grille[0][0]==256)
                                        {
                                            case1 = SDL_LoadBMP("img/256.bmp");  
                                            if (case1 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case1 = SDL_CreateTextureFromSurface(renderer, case1);
                                            SDL_FreeSurface(case1);
                                            
                                            if (texture_case1 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 162;
                                            BG.h = 162;
                                            BG.x = 30;
                                            BG.y = 30;
                                            
                                            if (SDL_QueryTexture(texture_case1, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case1, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        else if (Grille[0][0]==512)
                                        {
                                            case1 = SDL_LoadBMP("img/512.bmp");  
                                            if (case1 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case1 = SDL_CreateTextureFromSurface(renderer, case1);
                                            SDL_FreeSurface(case1);
                                            
                                            if (texture_case1 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 162;
                                            BG.h = 162;
                                            BG.x = 30;
                                            BG.y = 30;
                                            
                                            if (SDL_QueryTexture(texture_case1, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case1, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        else if (Grille[0][0]==1024)
                                        {
                                            case1 = SDL_LoadBMP("img/1024.bmp");  
                                            if (case1 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case1 = SDL_CreateTextureFromSurface(renderer, case1);
                                            SDL_FreeSurface(case1);
                                            
                                            if (texture_case1 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 162;
                                            BG.h = 162;
                                            BG.x = 30;
                                            BG.y = 30;
                                            
                                            if (SDL_QueryTexture(texture_case1, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case1, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        else if (Grille[0][0]==2048)
                                        {
                                            case1 = SDL_LoadBMP("img/2048.bmp");  
                                            if (case1 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case1 = SDL_CreateTextureFromSurface(renderer, case1);
                                            SDL_FreeSurface(case1);
                                            
                                            if (texture_case1 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 162;
                                            BG.h = 162;
                                            BG.x = 30;
                                            BG.y = 30;
                                            
                                            if (SDL_QueryTexture(texture_case1, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case1, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        
                                        /* Case 2 */
                                        if (Grille[0][1]==0)
                                        {
                                            continue;
                                        }
                                        else if (Grille[0][1]==2)
                                        {
                                            case2 = SDL_LoadBMP("img/2.bmp");  
                                            if (case2 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case2 = SDL_CreateTextureFromSurface(renderer, case2);
                                            SDL_FreeSurface(case2);
                                            
                                            if (texture_case2 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 384;
                                            BG.h = 162;
                                            BG.x = 222;
                                            BG.y = 30;
                                            
                                            if (SDL_QueryTexture(texture_case2, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case2, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        else if (Grille[0][1]==4)
                                        {
                                            case2 = SDL_LoadBMP("img/4.bmp");  
                                            if (case2 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case2 = SDL_CreateTextureFromSurface(renderer, case2);
                                            SDL_FreeSurface(case2);
                                            
                                            if (texture_case2 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 384;
                                            BG.h = 162;
                                            BG.x = 222;
                                            BG.y = 30;
                                            
                                            if (SDL_QueryTexture(texture_case2, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case2, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        else if (Grille[0][1]==8)
                                        {
                                            case2 = SDL_LoadBMP("img/8.bmp");  
                                            if (case2 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case2 = SDL_CreateTextureFromSurface(renderer, case2);
                                            SDL_FreeSurface(case2);
                                            
                                            if (texture_case2 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 384;
                                            BG.h = 162;
                                            BG.x = 222;
                                            BG.y = 30;
                                            
                                            if (SDL_QueryTexture(texture_case2, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case2, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        else if (Grille[0][1]==16)
                                        {
                                            case2 = SDL_LoadBMP("img/16.bmp");  
                                            if (case2 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case2 = SDL_CreateTextureFromSurface(renderer, case2);
                                            SDL_FreeSurface(case2);
                                            
                                            if (texture_case2 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 384;
                                            BG.h = 162;
                                            BG.x = 222;
                                            BG.y = 30;
                                            
                                            if (SDL_QueryTexture(texture_case2, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case2, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        else if (Grille[0][1]==32)
                                        {
                                            case2 = SDL_LoadBMP("img/32.bmp");  
                                            if (case2 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case2 = SDL_CreateTextureFromSurface(renderer, case2);
                                            SDL_FreeSurface(case2);
                                            
                                            if (texture_case2 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 384;
                                            BG.h = 162;
                                            BG.x = 222;
                                            BG.y = 30;
                                            
                                            if (SDL_QueryTexture(texture_case2, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case2, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        else if (Grille[0][1]==64)
                                        {
                                            case2 = SDL_LoadBMP("img/64.bmp");  
                                            if (case2 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case2 = SDL_CreateTextureFromSurface(renderer, case2);
                                            SDL_FreeSurface(case2);
                                            
                                            if (texture_case2 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 384;
                                            BG.h = 162;
                                            BG.x = 222;
                                            BG.y = 30;
                                            
                                            if (SDL_QueryTexture(texture_case2, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case2, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        else if (Grille[0][1]==128)
                                        {
                                            case2 = SDL_LoadBMP("img/128.bmp");  
                                            if (case2 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case2 = SDL_CreateTextureFromSurface(renderer, case2);
                                            SDL_FreeSurface(case2);
                                            
                                            if (texture_case2 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 384;
                                            BG.h = 162;
                                            BG.x = 222;
                                            BG.y = 30;
                                            
                                            if (SDL_QueryTexture(texture_case2, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case2, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        else if (Grille[0][1]==256)
                                        {
                                            case2 = SDL_LoadBMP("img/256.bmp");  
                                            if (case2 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case2 = SDL_CreateTextureFromSurface(renderer, case2);
                                            SDL_FreeSurface(case2);
                                            
                                            if (texture_case2 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 384;
                                            BG.h = 162;
                                            BG.x = 222;
                                            BG.y = 30;
                                            
                                            if (SDL_QueryTexture(texture_case2, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case2, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        else if (Grille[0][1]==512)
                                        {
                                            case2 = SDL_LoadBMP("img/512.bmp");  
                                            if (case2 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case2 = SDL_CreateTextureFromSurface(renderer, case2);
                                            SDL_FreeSurface(case2);
                                            
                                            if (texture_case2 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 384;
                                            BG.h = 162;
                                            BG.x = 222;
                                            BG.y = 30;
                                            
                                            if (SDL_QueryTexture(texture_case2, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case2, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        else if (Grille[0][1]==1024)
                                        {
                                            case2 = SDL_LoadBMP("img/1024.bmp");  
                                            if (case2 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case2 = SDL_CreateTextureFromSurface(renderer, case2);
                                            SDL_FreeSurface(case2);
                                            
                                            if (texture_case2 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 384;
                                            BG.h = 162;
                                            BG.x = 222;
                                            BG.y = 30;
                                            
                                            if (SDL_QueryTexture(texture_case2, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case2, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        else if (Grille[0][1]==2048)
                                        {
                                            case2 = SDL_LoadBMP("img/2048.bmp");  
                                            if (case2 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case2 = SDL_CreateTextureFromSurface(renderer, case2);
                                            SDL_FreeSurface(case2);
                                            
                                            if (texture_case2 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 384;
                                            BG.h = 162;
                                            BG.x = 222;
                                            BG.y = 30;
                                            
                                            if (SDL_QueryTexture(texture_case2, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case2, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        
                                        /* Case 3 */
                                        if (Grille[0][2]==0)
                                        {
                                            continue;
                                        }
                                        else if (Grille[0][2]==2)
                                        {
                                            case3 = SDL_LoadBMP("img/2.bmp");  
                                            if (case3 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case3 = SDL_CreateTextureFromSurface(renderer, case3);
                                            SDL_FreeSurface(case3);
                                            
                                            if (texture_case3 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 162;
                                            BG.h = 162;
                                            BG.x = 416;
                                            BG.y = 30;
                                            
                                            if (SDL_QueryTexture(texture_case3, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case3, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        else if (Grille[0][2]==4)
                                        {
                                            case3 = SDL_LoadBMP("img/4.bmp");  
                                            if (case3 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case3 = SDL_CreateTextureFromSurface(renderer, case3);
                                            SDL_FreeSurface(case3);
                                            
                                            if (texture_case3 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 162;
                                            BG.h = 162;
                                            BG.x = 416;
                                            BG.y = 30;
                                            
                                            if (SDL_QueryTexture(texture_case3, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case3, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        else if (Grille[0][2]==8)
                                        {
                                            case3 = SDL_LoadBMP("img/8.bmp");  
                                            if (case3 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case3 = SDL_CreateTextureFromSurface(renderer, case3);
                                            SDL_FreeSurface(case3);
                                            
                                            if (texture_case3 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 162;
                                            BG.h = 162;
                                            BG.x = 416;
                                            BG.y = 30;
                                            
                                            if (SDL_QueryTexture(texture_case3, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case3, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        else if (Grille[0][2]==16)
                                        {
                                            case3 = SDL_LoadBMP("img/16.bmp");  
                                            if (case3 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case3 = SDL_CreateTextureFromSurface(renderer, case3);
                                            SDL_FreeSurface(case3);
                                            
                                            if (texture_case3 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 162;
                                            BG.h = 162;
                                            BG.x = 416;
                                            BG.y = 30;
                                            
                                            if (SDL_QueryTexture(texture_case3, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case3, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        else if (Grille[0][2]==32)
                                        {
                                            case3 = SDL_LoadBMP("img/32.bmp");  
                                            if (case3 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case3 = SDL_CreateTextureFromSurface(renderer, case3);
                                            SDL_FreeSurface(case3);
                                            
                                            if (texture_case3 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 162;
                                            BG.h = 162;
                                            BG.x = 416;
                                            BG.y = 30;
                                            
                                            if (SDL_QueryTexture(texture_case3, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case3, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        else if (Grille[0][2]==64)
                                        {
                                            case3 = SDL_LoadBMP("img/64.bmp");  
                                            if (case3 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case3 = SDL_CreateTextureFromSurface(renderer, case3);
                                            SDL_FreeSurface(case3);
                                            
                                            if (texture_case3 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 162;
                                            BG.h = 162;
                                            BG.x = 416;
                                            BG.y = 30;
                                            
                                            if (SDL_QueryTexture(texture_case3, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case3, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        else if (Grille[0][2]==128)
                                        {
                                            case3 = SDL_LoadBMP("img/128.bmp");  
                                            if (case3 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case3 = SDL_CreateTextureFromSurface(renderer, case3);
                                            SDL_FreeSurface(case3);
                                            
                                            if (texture_case3 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 162;
                                            BG.h = 162;
                                            BG.x = 416;
                                            BG.y = 30;
                                            
                                            if (SDL_QueryTexture(texture_case3, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case3, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        else if (Grille[0][2]==256)
                                        {
                                            case3 = SDL_LoadBMP("img/256.bmp");  
                                            if (case3 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case3 = SDL_CreateTextureFromSurface(renderer, case3);
                                            SDL_FreeSurface(case3);
                                            
                                            if (texture_case3 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 162;
                                            BG.h = 162;
                                            BG.x = 416;
                                            BG.y = 30;
                                            
                                            if (SDL_QueryTexture(texture_case3, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case3, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        else if (Grille[0][2]==512)
                                        {
                                            case3 = SDL_LoadBMP("img/512.bmp");  
                                            if (case3 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case3 = SDL_CreateTextureFromSurface(renderer, case3);
                                            SDL_FreeSurface(case3);
                                            
                                            if (texture_case3 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 162;
                                            BG.h = 162;
                                            BG.x = 416;
                                            BG.y = 30;
                                            
                                            if (SDL_QueryTexture(texture_case3, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case3, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        else if (Grille[0][2]==1024)
                                        {
                                            case3 = SDL_LoadBMP("img/1024.bmp");  
                                            if (case3 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case3 = SDL_CreateTextureFromSurface(renderer, case3);
                                            SDL_FreeSurface(case3);
                                            
                                            if (texture_case3 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 162;
                                            BG.h = 162;
                                            BG.x = 416;
                                            BG.y = 30;
                                            
                                            if (SDL_QueryTexture(texture_case3, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case3, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        else if (Grille[0][2]==2048)
                                        {
                                            case3 = SDL_LoadBMP("img/2048.bmp");  
                                            if (case3 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case3 = SDL_CreateTextureFromSurface(renderer, case3);
                                            SDL_FreeSurface(case3);
                                            
                                            if (texture_case3 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 162;
                                            BG.h = 162;
                                            BG.x = 416;
                                            BG.y = 30;
                                            
                                            if (SDL_QueryTexture(texture_case3, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case3, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                    
                                        /* Case 4 */
                                        if (Grille[0][3]==0)
                                        {
                                            continue;
                                        }
                                        else if (Grille[0][3]==2)
                                        {
                                            case4 = SDL_LoadBMP("img/2.bmp");  
                                            if (case4 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case4 = SDL_CreateTextureFromSurface(renderer, case4);
                                            SDL_FreeSurface(case4);
                                            
                                            if (texture_case4 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 162;
                                            BG.h = 162;
                                            BG.x = 608;
                                            BG.y = 30;
                                            
                                            if (SDL_QueryTexture(texture_case4, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case4, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        else if (Grille[0][3]==4)
                                        {
                                            case4 = SDL_LoadBMP("img/4.bmp");  
                                            if (case4 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case4 = SDL_CreateTextureFromSurface(renderer, case4);
                                            SDL_FreeSurface(case4);
                                            
                                            if (texture_case4 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 162;
                                            BG.h = 162;
                                            BG.x = 608;
                                            BG.y = 30;
                                            
                                            if (SDL_QueryTexture(texture_case4, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case4, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        else if (Grille[0][3]==8)
                                        {
                                            case4 = SDL_LoadBMP("img/8.bmp");  
                                            if (case4 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case4 = SDL_CreateTextureFromSurface(renderer, case4);
                                            SDL_FreeSurface(case4);
                                            
                                            if (texture_case4 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 162;
                                            BG.h = 162;
                                            BG.x = 608;
                                            BG.y = 30;
                                            
                                            if (SDL_QueryTexture(texture_case4, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case4, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        else if (Grille[0][3]==16)
                                        {
                                            case4 = SDL_LoadBMP("img/16.bmp");  
                                            if (case4 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case4 = SDL_CreateTextureFromSurface(renderer, case4);
                                            SDL_FreeSurface(case4);
                                            
                                            if (texture_case4 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 162;
                                            BG.h = 162;
                                            BG.x = 608;
                                            BG.y = 30;
                                            
                                            if (SDL_QueryTexture(texture_case4, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case4, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        else if (Grille[0][3]==32)
                                        {
                                            case4 = SDL_LoadBMP("img/32.bmp");  
                                            if (case4 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case4 = SDL_CreateTextureFromSurface(renderer, case4);
                                            SDL_FreeSurface(case4);
                                            
                                            if (texture_case4 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 162;
                                            BG.h = 162;
                                            BG.x = 608;
                                            BG.y = 30;
                                            
                                            if (SDL_QueryTexture(texture_case4, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case4, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        else if (Grille[0][3]==64)
                                        {
                                            case4 = SDL_LoadBMP("img/64.bmp");  
                                            if (case4 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case4 = SDL_CreateTextureFromSurface(renderer, case4);
                                            SDL_FreeSurface(case4);
                                            
                                            if (texture_case4 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 162;
                                            BG.h = 162;
                                            BG.x = 608;
                                            BG.y = 30;
                                            
                                            if (SDL_QueryTexture(texture_case4, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case4, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        else if (Grille[0][3]==128)
                                        {
                                            case4 = SDL_LoadBMP("img/128.bmp");  
                                            if (case4 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case4 = SDL_CreateTextureFromSurface(renderer, case4);
                                            SDL_FreeSurface(case4);
                                            
                                            if (texture_case4 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 162;
                                            BG.h = 162;
                                            BG.x = 608;
                                            BG.y = 30;
                                            
                                            if (SDL_QueryTexture(texture_case4, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case4, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        else if (Grille[0][3]==256)
                                        {
                                            case4 = SDL_LoadBMP("img/256.bmp");  
                                            if (case4 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case4 = SDL_CreateTextureFromSurface(renderer, case4);
                                            SDL_FreeSurface(case4);
                                            
                                            if (texture_case4 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 162;
                                            BG.h = 162;
                                            BG.x = 608;
                                            BG.y = 30;
                                            
                                            if (SDL_QueryTexture(texture_case4, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case4, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        else if (Grille[0][3]==512)
                                        {
                                            case4 = SDL_LoadBMP("img/512.bmp");  
                                            if (case4 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case4 = SDL_CreateTextureFromSurface(renderer, case4);
                                            SDL_FreeSurface(case4);
                                            
                                            if (texture_case4 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 162;
                                            BG.h = 162;
                                            BG.x = 608;
                                            BG.y = 30;
                                            
                                            if (SDL_QueryTexture(texture_case4, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case4, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        else if (Grille[0][3]==1024)
                                        {
                                            case4 = SDL_LoadBMP("img/1024.bmp");  
                                            if (case4 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case4 = SDL_CreateTextureFromSurface(renderer, case4);
                                            SDL_FreeSurface(case4);
                                            
                                            if (texture_case4 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 162;
                                            BG.h = 162;
                                            BG.x = 608;
                                            BG.y = 30;
                                            
                                            if (SDL_QueryTexture(texture_case4, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case4, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        else if (Grille[0][3]==2048)
                                        {
                                            case4 = SDL_LoadBMP("img/2048.bmp");  
                                            if (case4 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case4 = SDL_CreateTextureFromSurface(renderer, case4);
                                            SDL_FreeSurface(case4);
                                            
                                            if (texture_case4 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 162;
                                            BG.h = 162;
                                            BG.x = 608;
                                            BG.y = 30;
                                            
                                            if (SDL_QueryTexture(texture_case4, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case4, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                    
                                        /* Case 5 */
                                        if (Grille[1][0]==0)
                                        {
                                            continue;
                                        }
                                        else if (Grille[1][0]==2)
                                        {
                                            case5 = SDL_LoadBMP("img/2.bmp");  
                                            if (case5 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case5 = SDL_CreateTextureFromSurface(renderer, case5);
                                            SDL_FreeSurface(case5);
                                            
                                            if (texture_case5 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 162;
                                            BG.h = 162;
                                            BG.x = 30;
                                            BG.y = 222;
                                            
                                            if (SDL_QueryTexture(texture_case5, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case5, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        else if (Grille[1][0]==4)
                                        {
                                            case5 = SDL_LoadBMP("img/4.bmp");  
                                            if (case5 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case5 = SDL_CreateTextureFromSurface(renderer, case5);
                                            SDL_FreeSurface(case5);
                                            
                                            if (texture_case5 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 162;
                                            BG.h = 162;
                                            BG.x = 30;
                                            BG.y = 222;
                                            
                                            if (SDL_QueryTexture(texture_case5, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case5, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        else if (Grille[1][0]==8)
                                        {
                                            case5 = SDL_LoadBMP("img/8.bmp");  
                                            if (case5 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case5 = SDL_CreateTextureFromSurface(renderer, case5);
                                            SDL_FreeSurface(case5);
                                            
                                            if (texture_case5 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 162;
                                            BG.h = 162;
                                            BG.x = 30;
                                            BG.y = 222;
                                            
                                            if (SDL_QueryTexture(texture_case5, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case5, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        else if (Grille[1][0]==16)
                                        {
                                            case5 = SDL_LoadBMP("img/16.bmp");  
                                            if (case5 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case5 = SDL_CreateTextureFromSurface(renderer, case5);
                                            SDL_FreeSurface(case5);
                                            
                                            if (texture_case5 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 162;
                                            BG.h = 162;
                                            BG.x = 30;
                                            BG.y = 222;
                                            
                                            if (SDL_QueryTexture(texture_case5, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case5, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        else if (Grille[1][0]==32)
                                        {
                                            case5 = SDL_LoadBMP("img/32.bmp");  
                                            if (case5 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case5 = SDL_CreateTextureFromSurface(renderer, case5);
                                            SDL_FreeSurface(case5);
                                            
                                            if (texture_case5 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 162;
                                            BG.h = 162;
                                            BG.x = 30;
                                            BG.y = 222;
                                            
                                            if (SDL_QueryTexture(texture_case5, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case5, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        else if (Grille[1][0]==64)
                                        {
                                            case5 = SDL_LoadBMP("img/64.bmp");  
                                            if (case5 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case5 = SDL_CreateTextureFromSurface(renderer, case5);
                                            SDL_FreeSurface(case5);
                                            
                                            if (texture_case5 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 162;
                                            BG.h = 162;
                                            BG.x = 30;
                                            BG.y = 222;
                                            
                                            if (SDL_QueryTexture(texture_case5, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case5, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        else if (Grille[1][0]==128)
                                        {
                                            case5 = SDL_LoadBMP("img/128.bmp");  
                                            if (case5 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case5 = SDL_CreateTextureFromSurface(renderer, case5);
                                            SDL_FreeSurface(case5);
                                            
                                            if (texture_case5 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 162;
                                            BG.h = 162;
                                            BG.x = 30;
                                            BG.y = 222;
                                            
                                            if (SDL_QueryTexture(texture_case5, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case5, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        else if (Grille[1][0]==256)
                                        {
                                            case5 = SDL_LoadBMP("img/256.bmp");  
                                            if (case5 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case5 = SDL_CreateTextureFromSurface(renderer, case5);
                                            SDL_FreeSurface(case5);
                                            
                                            if (texture_case5 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 162;
                                            BG.h = 162;
                                            BG.x = 30;
                                            BG.y = 222;
                                            
                                            if (SDL_QueryTexture(texture_case5, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case5, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        else if (Grille[1][0]==512)
                                        {
                                            case5 = SDL_LoadBMP("img/512.bmp");  
                                            if (case5 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case5 = SDL_CreateTextureFromSurface(renderer, case5);
                                            SDL_FreeSurface(case5);
                                            
                                            if (texture_case5 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 162;
                                            BG.h = 162;
                                            BG.x = 30;
                                            BG.y = 222;
                                            
                                            if (SDL_QueryTexture(texture_case5, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case5, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        else if (Grille[1][0]==1024)
                                        {
                                            case5 = SDL_LoadBMP("img/1024.bmp");  
                                            if (case5 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case5 = SDL_CreateTextureFromSurface(renderer, case5);
                                            SDL_FreeSurface(case5);
                                            
                                            if (texture_case5 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 162;
                                            BG.h = 162;
                                            BG.x = 30;
                                            BG.y = 222;
                                            
                                            if (SDL_QueryTexture(texture_case5, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case5, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        else if (Grille[1][0]==2048)
                                        {
                                            case5 = SDL_LoadBMP("img/2048.bmp");  
                                            if (case5 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case5 = SDL_CreateTextureFromSurface(renderer, case5);
                                            SDL_FreeSurface(case5);
                                            
                                            if (texture_case5 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 162;
                                            BG.h = 162;
                                            BG.x = 30;
                                            BG.y = 222;
                                            
                                            if (SDL_QueryTexture(texture_case5, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case5, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                    
                                        /* Case 6 */
                                        if (Grille[1][1]==0)
                                        {
                                            continue;
                                        }
                                        else if (Grille[1][1]==2)
                                        {
                                            case6 = SDL_LoadBMP("img/2.bmp");  
                                            if (case6 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case6 = SDL_CreateTextureFromSurface(renderer, case6);
                                            SDL_FreeSurface(case6);
                                            
                                            if (texture_case6 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 162;
                                            BG.h = 162;
                                            BG.x = 222;
                                            BG.y = 222;
                                            
                                            if (SDL_QueryTexture(texture_case6, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case6, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        else if (Grille[1][1]==4)
                                        {
                                            case6 = SDL_LoadBMP("img/4.bmp");  
                                            if (case6 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case6 = SDL_CreateTextureFromSurface(renderer, case6);
                                            SDL_FreeSurface(case6);
                                            
                                            if (texture_case6 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 162;
                                            BG.h = 162;
                                            BG.x = 222;
                                            BG.y = 222;
                                            
                                            if (SDL_QueryTexture(texture_case6, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case6, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        else if (Grille[1][1]==8)
                                        {
                                            case6 = SDL_LoadBMP("img/8.bmp");  
                                            if (case6 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case6 = SDL_CreateTextureFromSurface(renderer, case6);
                                            SDL_FreeSurface(case6);
                                            
                                            if (texture_case6 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 162;
                                            BG.h = 162;
                                            BG.x = 222;
                                            BG.y = 222;
                                            
                                            if (SDL_QueryTexture(texture_case6, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case6, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        else if (Grille[1][1]==16)
                                        {
                                            case6 = SDL_LoadBMP("img/16.bmp");  
                                            if (case6 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case6 = SDL_CreateTextureFromSurface(renderer, case6);
                                            SDL_FreeSurface(case6);
                                            
                                            if (texture_case6 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 162;
                                            BG.h = 162;
                                            BG.x = 222;
                                            BG.y = 222;
                                            
                                            if (SDL_QueryTexture(texture_case6, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case6, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        else if (Grille[1][1]==32)
                                        {
                                            case6 = SDL_LoadBMP("img/32.bmp");  
                                            if (case6 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case6 = SDL_CreateTextureFromSurface(renderer, case6);
                                            SDL_FreeSurface(case6);
                                            
                                            if (texture_case6 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 162;
                                            BG.h = 162;
                                            BG.x = 222;
                                            BG.y = 222;
                                            
                                            if (SDL_QueryTexture(texture_case6, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case6, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        else if (Grille[1][1]==64)
                                        {
                                            case6 = SDL_LoadBMP("img/64.bmp");  
                                            if (case6 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case6 = SDL_CreateTextureFromSurface(renderer, case6);
                                            SDL_FreeSurface(case6);
                                            
                                            if (texture_case6 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 162;
                                            BG.h = 162;
                                            BG.x = 222;
                                            BG.y = 222;
                                            
                                            if (SDL_QueryTexture(texture_case6, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case6, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        else if (Grille[1][1]==128)
                                        {
                                            case6 = SDL_LoadBMP("img/128.bmp");  
                                            if (case6 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case6 = SDL_CreateTextureFromSurface(renderer, case6);
                                            SDL_FreeSurface(case6);
                                            
                                            if (texture_case6 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 162;
                                            BG.h = 162;
                                            BG.x = 222;
                                            BG.y = 222;
                                            
                                            if (SDL_QueryTexture(texture_case6, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case6, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        else if (Grille[1][1]==256)
                                        {
                                            case6 = SDL_LoadBMP("img/256.bmp");  
                                            if (case6 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case6 = SDL_CreateTextureFromSurface(renderer, case6);
                                            SDL_FreeSurface(case6);
                                            
                                            if (texture_case6 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 162;
                                            BG.h = 162;
                                            BG.x = 222;
                                            BG.y = 222;
                                            
                                            if (SDL_QueryTexture(texture_case6, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case6, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        else if (Grille[1][1]==512)
                                        {
                                            case6 = SDL_LoadBMP("img/512.bmp");  
                                            if (case6 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case6 = SDL_CreateTextureFromSurface(renderer, case6);
                                            SDL_FreeSurface(case6);
                                            
                                            if (texture_case6 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 162;
                                            BG.h = 162;
                                            BG.x = 222;
                                            BG.y = 222;
                                            
                                            if (SDL_QueryTexture(texture_case6, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case6, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        else if (Grille[1][1]==1024)
                                        {
                                            case6 = SDL_LoadBMP("img/1024.bmp");  
                                            if (case6 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case6 = SDL_CreateTextureFromSurface(renderer, case6);
                                            SDL_FreeSurface(case6);
                                            
                                            if (texture_case6 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 162;
                                            BG.h = 162;
                                            BG.x = 222;
                                            BG.y = 222;
                                            
                                            if (SDL_QueryTexture(texture_case6, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case6, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        else if (Grille[1][1]==2048)
                                        {
                                            case6 = SDL_LoadBMP("img/2048.bmp");  
                                            if (case6 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case6 = SDL_CreateTextureFromSurface(renderer, case6);
                                            SDL_FreeSurface(case6);
                                            
                                            if (texture_case6 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 162;
                                            BG.h = 162;
                                            BG.x = 222;
                                            BG.y = 222;
                                            
                                            if (SDL_QueryTexture(texture_case6, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case6, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                    
                                        /* Case 7 */
                                        if (Grille[1][2]==0)
                                        {
                                            continue;
                                        }
                                        else if (Grille[1][2]==2)
                                        {
                                            case7 = SDL_LoadBMP("img/2.bmp");  
                                            if (case7 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case7 = SDL_CreateTextureFromSurface(renderer, case7);
                                            SDL_FreeSurface(case7);
                                            
                                            if (texture_case7 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 162;
                                            BG.h = 162;
                                            BG.x = 416;
                                            BG.y = 222;
                                            
                                            if (SDL_QueryTexture(texture_case7, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case7, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        else if (Grille[1][2]==4)
                                        {
                                            case7 = SDL_LoadBMP("img/4.bmp");  
                                            if (case7 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case7 = SDL_CreateTextureFromSurface(renderer, case7);
                                            SDL_FreeSurface(case7);
                                            
                                            if (texture_case7 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 162;
                                            BG.h = 162;
                                            BG.x = 416;
                                            BG.y = 222;
                                            
                                            if (SDL_QueryTexture(texture_case7, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case7, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        else if (Grille[1][2]==8)
                                        {
                                            case7 = SDL_LoadBMP("img/8.bmp");  
                                            if (case7 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case7 = SDL_CreateTextureFromSurface(renderer, case7);
                                            SDL_FreeSurface(case7);
                                            
                                            if (texture_case7 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 162;
                                            BG.h = 162;
                                            BG.x = 416;
                                            BG.y = 222;
                                            
                                            if (SDL_QueryTexture(texture_case7, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case7, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        else if (Grille[1][2]==16)
                                        {
                                            case7 = SDL_LoadBMP("img/16.bmp");  
                                            if (case7 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case7 = SDL_CreateTextureFromSurface(renderer, case7);
                                            SDL_FreeSurface(case7);
                                            
                                            if (texture_case7 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 162;
                                            BG.h = 162;
                                            BG.x = 416;
                                            BG.y = 222;
                                            
                                            if (SDL_QueryTexture(texture_case7, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case7, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        else if (Grille[1][2]==32)
                                        {
                                            case7 = SDL_LoadBMP("img/32.bmp");  
                                            if (case7 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case7 = SDL_CreateTextureFromSurface(renderer, case7);
                                            SDL_FreeSurface(case7);
                                            
                                            if (texture_case7 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 162;
                                            BG.h = 162;
                                            BG.x = 416;
                                            BG.y = 222;
                                            
                                            if (SDL_QueryTexture(texture_case7, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case7, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        else if (Grille[1][2]==64)
                                        {
                                            case7 = SDL_LoadBMP("img/64.bmp");  
                                            if (case7 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case7 = SDL_CreateTextureFromSurface(renderer, case7);
                                            SDL_FreeSurface(case7);
                                            
                                            if (texture_case7 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 162;
                                            BG.h = 162;
                                            BG.x = 416;
                                            BG.y = 222;
                                            
                                            if (SDL_QueryTexture(texture_case7, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case7, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        else if (Grille[1][2]==128)
                                        {
                                            case7 = SDL_LoadBMP("img/128.bmp");  
                                            if (case7 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case7 = SDL_CreateTextureFromSurface(renderer, case7);
                                            SDL_FreeSurface(case7);
                                            
                                            if (texture_case7 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 162;
                                            BG.h = 162;
                                            BG.x = 416;
                                            BG.y = 222;
                                            
                                            if (SDL_QueryTexture(texture_case7, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case7, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        else if (Grille[1][2]==256)
                                        {
                                            case7 = SDL_LoadBMP("img/256.bmp");  
                                            if (case7 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case7 = SDL_CreateTextureFromSurface(renderer, case7);
                                            SDL_FreeSurface(case7);
                                            
                                            if (texture_case7 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 162;
                                            BG.h = 162;
                                            BG.x = 416;
                                            BG.y = 222;
                                            
                                            if (SDL_QueryTexture(texture_case7, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case7, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        else if (Grille[1][2]==512)
                                        {
                                            case7 = SDL_LoadBMP("img/512.bmp");  
                                            if (case7 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case7 = SDL_CreateTextureFromSurface(renderer, case7);
                                            SDL_FreeSurface(case7);
                                            
                                            if (texture_case7 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 162;
                                            BG.h = 162;
                                            BG.x = 416;
                                            BG.y = 222;
                                            
                                            if (SDL_QueryTexture(texture_case7, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case7, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        else if (Grille[1][2]==1024)
                                        {
                                            case7 = SDL_LoadBMP("img/1024.bmp");  
                                            if (case7 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case7 = SDL_CreateTextureFromSurface(renderer, case7);
                                            SDL_FreeSurface(case7);
                                            
                                            if (texture_case7 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 162;
                                            BG.h = 162;
                                            BG.x = 416;
                                            BG.y = 222;
                                            
                                            if (SDL_QueryTexture(texture_case7, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case7, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        else if (Grille[1][2]==2048)
                                        {
                                            case7 = SDL_LoadBMP("img/2048.bmp");  
                                            if (case7 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case7 = SDL_CreateTextureFromSurface(renderer, case7);
                                            SDL_FreeSurface(case7);
                                            
                                            if (texture_case7 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 162;
                                            BG.h = 162;
                                            BG.x = 416;
                                            BG.y = 222;
                                            
                                            if (SDL_QueryTexture(texture_case7, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case7, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                    
                                        /* Case 8 */
                                        if (Grille[1][3]==0)
                                        {
                                            continue;
                                        }
                                        else if (Grille[1][3]==2)
                                        {
                                            case8 = SDL_LoadBMP("img/2.bmp");  
                                            if (case8 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case8 = SDL_CreateTextureFromSurface(renderer, case8);
                                            SDL_FreeSurface(case8);
                                            
                                            if (texture_case8 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 162;
                                            BG.h = 162;
                                            BG.x = 608;
                                            BG.y = 222;
                                            
                                            if (SDL_QueryTexture(texture_case8, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case8, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        else if (Grille[1][3]==4)
                                        {
                                            case8 = SDL_LoadBMP("img/4.bmp");  
                                            if (case8 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case8 = SDL_CreateTextureFromSurface(renderer, case8);
                                            SDL_FreeSurface(case8);
                                            
                                            if (texture_case8 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 162;
                                            BG.h = 162;
                                            BG.x = 608;
                                            BG.y = 222;
                                            
                                            if (SDL_QueryTexture(texture_case8, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case8, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        else if (Grille[1][3]==8)
                                        {
                                            case8 = SDL_LoadBMP("img/8.bmp");  
                                            if (case8 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case8 = SDL_CreateTextureFromSurface(renderer, case8);
                                            SDL_FreeSurface(case8);
                                            
                                            if (texture_case8 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 162;
                                            BG.h = 162;
                                            BG.x = 608;
                                            BG.y = 222;
                                            
                                            if (SDL_QueryTexture(texture_case8, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case8, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        else if (Grille[1][3]==16)
                                        {
                                            case8 = SDL_LoadBMP("img/16.bmp");  
                                            if (case8 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case8 = SDL_CreateTextureFromSurface(renderer, case8);
                                            SDL_FreeSurface(case8);
                                            
                                            if (texture_case8 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 162;
                                            BG.h = 162;
                                            BG.x = 608;
                                            BG.y = 222;
                                            
                                            if (SDL_QueryTexture(texture_case8, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case8, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        else if (Grille[1][3]==32)
                                        {
                                            case8 = SDL_LoadBMP("img/32.bmp");  
                                            if (case8 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case8 = SDL_CreateTextureFromSurface(renderer, case8);
                                            SDL_FreeSurface(case8);
                                            
                                            if (texture_case8 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 162;
                                            BG.h = 162;
                                            BG.x = 608;
                                            BG.y = 222;
                                            
                                            if (SDL_QueryTexture(texture_case8, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case8, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        else if (Grille[1][3]==64)
                                        {
                                            case8 = SDL_LoadBMP("img/64.bmp");  
                                            if (case8 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case8 = SDL_CreateTextureFromSurface(renderer, case8);
                                            SDL_FreeSurface(case8);
                                            
                                            if (texture_case8 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 162;
                                            BG.h = 162;
                                            BG.x = 608;
                                            BG.y = 222;
                                            
                                            if (SDL_QueryTexture(texture_case8, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case8, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        else if (Grille[1][3]==128)
                                        {
                                            case8 = SDL_LoadBMP("img/128.bmp");  
                                            if (case8 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case8 = SDL_CreateTextureFromSurface(renderer, case8);
                                            SDL_FreeSurface(case8);
                                            
                                            if (texture_case8 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 162;
                                            BG.h = 162;
                                            BG.x = 608;
                                            BG.y = 222;
                                            
                                            if (SDL_QueryTexture(texture_case8, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case8, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        else if (Grille[1][3]==256)
                                        {
                                            case8 = SDL_LoadBMP("img/256.bmp");  
                                            if (case8 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case8 = SDL_CreateTextureFromSurface(renderer, case8);
                                            SDL_FreeSurface(case8);
                                            
                                            if (texture_case8 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 162;
                                            BG.h = 162;
                                            BG.x = 608;
                                            BG.y = 222;
                                            
                                            if (SDL_QueryTexture(texture_case8, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case8, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        else if (Grille[1][3]==512)
                                        {
                                            case8 = SDL_LoadBMP("img/512.bmp");  
                                            if (case8 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case8 = SDL_CreateTextureFromSurface(renderer, case8);
                                            SDL_FreeSurface(case8);
                                            
                                            if (texture_case8 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 162;
                                            BG.h = 162;
                                            BG.x = 608;
                                            BG.y = 222;
                                            
                                            if (SDL_QueryTexture(texture_case8, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case8, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        else if (Grille[1][3]==1024)
                                        {
                                            case8 = SDL_LoadBMP("img/1024.bmp");  
                                            if (case8 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case8 = SDL_CreateTextureFromSurface(renderer, case8);
                                            SDL_FreeSurface(case8);
                                            
                                            if (texture_case8 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 162;
                                            BG.h = 162;
                                            BG.x = 608;
                                            BG.y = 222;
                                            
                                            if (SDL_QueryTexture(texture_case8, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case8, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        else if (Grille[1][3]==2048)
                                        {
                                            case8 = SDL_LoadBMP("img/2048.bmp");  
                                            if (case8 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case8 = SDL_CreateTextureFromSurface(renderer, case8);
                                            SDL_FreeSurface(case8);
                                            
                                            if (texture_case8 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 162;
                                            BG.h = 162;
                                            BG.x = 608;
                                            BG.y = 222;
                                            
                                            if (SDL_QueryTexture(texture_case8, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case8, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }

                                        /* Case 9 */
                                        if (Grille[2][0]==0)
                                        {
                                            continue;
                                        }
                                        else if (Grille[2][0]==2)
                                        {
                                            case9 = SDL_LoadBMP("img/2.bmp");  
                                            if (case9 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case9 = SDL_CreateTextureFromSurface(renderer, case9);
                                            SDL_FreeSurface(case9);
                                            
                                            if (texture_case9 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 162;
                                            BG.h = 162;
                                            BG.x = 30;
                                            BG.y = 608;
                                            
                                            if (SDL_QueryTexture(texture_case9, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case9, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        else if (Grille[2][0]==4)
                                        {
                                            case9 = SDL_LoadBMP("img/4.bmp");  
                                            if (case9 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case9 = SDL_CreateTextureFromSurface(renderer, case9);
                                            SDL_FreeSurface(case9);
                                            
                                            if (texture_case9 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 162;
                                            BG.h = 162;
                                            BG.x = 608;
                                            BG.y = 608;
                                            
                                            if (SDL_QueryTexture(texture_case9, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case9, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        else if (Grille[2][0]==8)
                                        {
                                            case9 = SDL_LoadBMP("img/8.bmp");  
                                            if (case9 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case9 = SDL_CreateTextureFromSurface(renderer, case9);
                                            SDL_FreeSurface(case9);
                                            
                                            if (texture_case9 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 162;
                                            BG.h = 162;
                                            BG.x = 608;
                                            BG.y = 608;
                                            
                                            if (SDL_QueryTexture(texture_case9, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case9, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        else if (Grille[2][0]==16)
                                        {
                                            case9 = SDL_LoadBMP("img/16.bmp");  
                                            if (case9 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case9 = SDL_CreateTextureFromSurface(renderer, case9);
                                            SDL_FreeSurface(case9);
                                            
                                            if (texture_case9 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 162;
                                            BG.h = 162;
                                            BG.x = 608;
                                            BG.y = 608;
                                            
                                            if (SDL_QueryTexture(texture_case9, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case9, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        else if (Grille[2][0]==32)
                                        {
                                            case9 = SDL_LoadBMP("img/32.bmp");  
                                            if (case9 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case9 = SDL_CreateTextureFromSurface(renderer, case9);
                                            SDL_FreeSurface(case9);
                                            
                                            if (texture_case9 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 162;
                                            BG.h = 162;
                                            BG.x = 608;
                                            BG.y = 608;
                                            
                                            if (SDL_QueryTexture(texture_case9, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case9, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        else if (Grille[2][0]==64)
                                        {
                                            case9 = SDL_LoadBMP("img/64.bmp");  
                                            if (case9 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case9 = SDL_CreateTextureFromSurface(renderer, case9);
                                            SDL_FreeSurface(case9);
                                            
                                            if (texture_case9 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 162;
                                            BG.h = 162;
                                            BG.x = 608;
                                            BG.y = 608;
                                            
                                            if (SDL_QueryTexture(texture_case9, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case9, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        else if (Grille[2][0]==128)
                                        {
                                            case9 = SDL_LoadBMP("img/128.bmp");  
                                            if (case9 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case9 = SDL_CreateTextureFromSurface(renderer, case9);
                                            SDL_FreeSurface(case9);
                                            
                                            if (texture_case9 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 162;
                                            BG.h = 162;
                                            BG.x = 608;
                                            BG.y = 608;
                                            
                                            if (SDL_QueryTexture(texture_case9, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case9, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        else if (Grille[2][0]==256)
                                        {
                                            case9 = SDL_LoadBMP("img/256.bmp");  
                                            if (case9 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case9 = SDL_CreateTextureFromSurface(renderer, case9);
                                            SDL_FreeSurface(case9);
                                            
                                            if (texture_case9 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 162;
                                            BG.h = 162;
                                            BG.x = 608;
                                            BG.y = 608;
                                            
                                            if (SDL_QueryTexture(texture_case9, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case9, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        else if (Grille[2][0]==512)
                                        {
                                            case9 = SDL_LoadBMP("img/512.bmp");  
                                            if (case9 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case9 = SDL_CreateTextureFromSurface(renderer, case9);
                                            SDL_FreeSurface(case9);
                                            
                                            if (texture_case9 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 162;
                                            BG.h = 162;
                                            BG.x = 608;
                                            BG.y = 608;
                                            
                                            if (SDL_QueryTexture(texture_case9, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case9, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        else if (Grille[2][0]==1024)
                                        {
                                            case9 = SDL_LoadBMP("img/1024.bmp");  
                                            if (case9 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case9 = SDL_CreateTextureFromSurface(renderer, case9);
                                            SDL_FreeSurface(case9);
                                            
                                            if (texture_case9 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 162;
                                            BG.h = 162;
                                            BG.x = 608;
                                            BG.y = 608;
                                            
                                            if (SDL_QueryTexture(texture_case9, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case9, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        else if (Grille[2][0]==2048)
                                        {
                                            case9 = SDL_LoadBMP("img/2048.bmp");  
                                            if (case9 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case9 = SDL_CreateTextureFromSurface(renderer, case9);
                                            SDL_FreeSurface(case9);
                                            
                                            if (texture_case9 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 162;
                                            BG.h = 162;
                                            BG.x = 608;
                                            BG.y = 608;
                                            
                                            if (SDL_QueryTexture(texture_case9, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case9, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                    
                                        /* Case 10 */
                                        if (Grille[2][1]==0)
                                        {
                                            continue;
                                        }
                                        else if (Grille[2][1]==2)
                                        {
                                            case10 = SDL_LoadBMP("img/2.bmp");  
                                            if (case10 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case10 = SDL_CreateTextureFromSurface(renderer, case10);
                                            SDL_FreeSurface(case10);
                                            
                                            if (texture_case10 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 162;
                                            BG.h = 162;
                                            BG.x = 222;
                                            BG.y = 608;
                                            
                                            if (SDL_QueryTexture(texture_case10, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case10, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        else if (Grille[2][1]==4)
                                        {
                                            case10 = SDL_LoadBMP("img/4.bmp");  
                                            if (case10 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case10 = SDL_CreateTextureFromSurface(renderer, case10);
                                            SDL_FreeSurface(case10);
                                            
                                            if (texture_case10 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 162;
                                            BG.h = 162;
                                            BG.x = 608;
                                            BG.y = 608;
                                            
                                            if (SDL_QueryTexture(texture_case10, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case10, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        else if (Grille[2][1]==8)
                                        {
                                            case10 = SDL_LoadBMP("img/8.bmp");  
                                            if (case10 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case10 = SDL_CreateTextureFromSurface(renderer, case10);
                                            SDL_FreeSurface(case10);
                                            
                                            if (texture_case10 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 162;
                                            BG.h = 162;
                                            BG.x = 608;
                                            BG.y = 608;
                                            
                                            if (SDL_QueryTexture(texture_case10, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case10, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        else if (Grille[2][1]==16)
                                        {
                                            case10 = SDL_LoadBMP("img/16.bmp");  
                                            if (case10 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case10 = SDL_CreateTextureFromSurface(renderer, case10);
                                            SDL_FreeSurface(case10);
                                            
                                            if (texture_case10 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 162;
                                            BG.h = 162;
                                            BG.x = 608;
                                            BG.y = 608;
                                            
                                            if (SDL_QueryTexture(texture_case10, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case10, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        else if (Grille[2][1]==32)
                                        {
                                            case10 = SDL_LoadBMP("img/32.bmp");  
                                            if (case10 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case10 = SDL_CreateTextureFromSurface(renderer, case10);
                                            SDL_FreeSurface(case10);
                                            
                                            if (texture_case10 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 162;
                                            BG.h = 162;
                                            BG.x = 608;
                                            BG.y = 608;
                                            
                                            if (SDL_QueryTexture(texture_case10, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case10, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        else if (Grille[2][1]==64)
                                        {
                                            case10 = SDL_LoadBMP("img/64.bmp");  
                                            if (case10 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case10 = SDL_CreateTextureFromSurface(renderer, case10);
                                            SDL_FreeSurface(case10);
                                            
                                            if (texture_case10 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 162;
                                            BG.h = 162;
                                            BG.x = 608;
                                            BG.y = 608;
                                            
                                            if (SDL_QueryTexture(texture_case10, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case10, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        else if (Grille[2][1]==128)
                                        {
                                            case10 = SDL_LoadBMP("img/128.bmp");  
                                            if (case10 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case10 = SDL_CreateTextureFromSurface(renderer, case10);
                                            SDL_FreeSurface(case10);
                                            
                                            if (texture_case10 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 162;
                                            BG.h = 162;
                                            BG.x = 608;
                                            BG.y = 608;
                                            
                                            if (SDL_QueryTexture(texture_case10, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case10, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        else if (Grille[2][1]==256)
                                        {
                                            case10 = SDL_LoadBMP("img/256.bmp");  
                                            if (case10 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case10 = SDL_CreateTextureFromSurface(renderer, case10);
                                            SDL_FreeSurface(case10);
                                            
                                            if (texture_case10 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 162;
                                            BG.h = 162;
                                            BG.x = 608;
                                            BG.y = 608;
                                            
                                            if (SDL_QueryTexture(texture_case10, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case10, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        else if (Grille[2][1]==512)
                                        {
                                            case10 = SDL_LoadBMP("img/512.bmp");  
                                            if (case10 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case10 = SDL_CreateTextureFromSurface(renderer, case10);
                                            SDL_FreeSurface(case10);
                                            
                                            if (texture_case10 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 162;
                                            BG.h = 162;
                                            BG.x = 608;
                                            BG.y = 608;
                                            
                                            if (SDL_QueryTexture(texture_case10, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case10, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        else if (Grille[2][1]==1024)
                                        {
                                            case10 = SDL_LoadBMP("img/1024.bmp");  
                                            if (case10 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case10 = SDL_CreateTextureFromSurface(renderer, case10);
                                            SDL_FreeSurface(case10);
                                            
                                            if (texture_case10 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 162;
                                            BG.h = 162;
                                            BG.x = 608;
                                            BG.y = 608;
                                            
                                            if (SDL_QueryTexture(texture_case10, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case10, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                        else if (Grille[2][1]==2048)
                                        {
                                            case10 = SDL_LoadBMP("img/2048.bmp");  
                                            if (case10 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger l'image");
                                                printf("Chargement");
                                            }
                                            
                                            texture_case10 = SDL_CreateTextureFromSurface(renderer, case10);
                                            SDL_FreeSurface(case10);
                                            
                                            if (texture_case10 == NULL)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de créer la texture");
                                            }

                                            SDL_Rect BG;
                                            BG.w = 162;
                                            BG.h = 162;
                                            BG.x = 608;
                                            BG.y = 608;
                                            
                                            if (SDL_QueryTexture(texture_case10, NULL, NULL, &BG.w, &BG.h) != 0)
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible de charger la texture");
                                            }
                                            
                                            if ( SDL_RenderCopy(renderer, texture_case10, NULL, &BG) != 0 )
                                            {
                                                SDL_DestroyRenderer(renderer);
                                                SDL_DestroyWindow(window);
                                                SDL_ExitWithError("Impossible d'afficher la texture");
                                            }
                                        }
                                    }

                                    else if (skin_2048 == 1)
                                    {

                                    }
                                    continue;
                                }
                            case SDLK_LEFT :
                                if (affichage_menu == 2)
                                {
                                    printf("Vous avez appuyer sur la flèche gauche \n");
                                    continue;
                                }
                            case SDLK_UP :
                                if (affichage_menu == 2)
                                {
                                    printf("Vous avez appuyer sur la flèche haut \n");
                                    continue;
                                }
                            case SDLK_DOWN :
                                if (affichage_menu == 2)
                                {
                                    printf("Vous avez appuyer sur la flèche bas \n");
                                    continue;
                                }
    					    }
                
                case SDL_MOUSEMOTION : printf("%d / %d \n", event.motion.x, event.motion.y);
                {
                            int X = event.motion.x;
                            int Y = event.motion.y;
                            if (((((((X >= 200)&&(X <= 600))&&((Y >= 418)&&(Y<= 518))))||((((X>= 200)&&(X <= 600))&&((Y >= 268)&&(Y<= 368)))))||((((X >= 200)&&(X <= 600))&&((Y >= 568)&&(Y<= 668)))))&&(affichage_menu == 0))
                            {
                                if (((X >= 200)&&(X <= 600))&&((Y >= 268)&&(Y<= 368)))
                                {
                                    //afficher image assombrie
                                    printf("C'EST LA CASE 1\n");
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
                                    printf("C'EST LA CASE 2\n");
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
                                    printf("C'EST LA CASE 3\n");

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
                case SDL_QUIT : program_launched = SDL_FALSE; break;
    			default : break;		
    		}
    	}
    }
    
    	
    SDL_Delay(500);
    
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    
    return EXIT_SUCCESS;
}