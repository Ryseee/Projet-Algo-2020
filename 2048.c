#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

#define WindowWidth 800
#define WindowHeight 800
#define CaseWidth 162
#define CaseHeight 162
#define CaseWidth8 84
#define CaseHeight8 84
#define N 4
#define M 8
// gcc 2048.c -o 2048 $(sdl2-config --cflags --libs) -lSDL_ttf  // COMMANDE DE COMPILATION
// ./2048                                             // COMMANDE D'EXECUTION


void SDL_ExitWithError (const char *message)
{
	SDL_Log("ERREUR : %s > %s\n", message, SDL_GetError());
	SDL_Quit();
	exit(EXIT_FAILURE);
}

void InitialiserGrille8(int Grille[M][M])
{
    int i;
    int j;
    for(i=0; i<M; i++)
    {
        for(j=0; j<M; j++)
        {
            Grille[i][j]=0;
        }
    }
    i = rand()%8;
    j = rand()%8;
    Grille[i][j]=2;
    i = rand()%8;
    j = rand()%8;
    Grille[i][j]=2;
}
void AjouterRandom8(int Grille[M][M])
{
    int i;
    int j;
    int i_init;
    int j_init;
    int premier=1;
    int bon = 0;
    int c2ou4 = 0;
    i = rand()%8;
    j = rand()%8;
    i_init = i;
    j_init = j;

    while(bon==0)
    {
        if (((i_init == i)&&(j_init == j))&&(premier == 0))
        {
            break;
        }
        else
        {
            if(Grille[i][j]==0)
            {
                bon=1;
                c2ou4= rand()%2;
                if(c2ou4==0)
                {
                    Grille[i][j]=2;
                }
                if(c2ou4==1)
                {
                    Grille[i][j]=4;
                }
            }
            else
            {
                if (j!=7)
                {
                    j += 1;
                }
                else if (j == 7)
                {
                    if (i!= 7)
                    {
                        i +=1;
                        j=0;
                    }
                    else
                    {
                        i=0;
                        j=0;
                    }
                    
                }

            }
            premier = 0;
        }
    }
}
void DeplacerDroite8(int Grille[M][M])
{
    int i;
    int j;
    for(i=0; i<M; i++)
    {
        for(j=0; j<M; j++)
        {
            if (j<7)
            {    
                if (Grille[i][j]==Grille[i][j+1])
                {
                    Grille[i][j+1] = 2*Grille[i][j];
                    Grille[i][j] = 0;
                }
                else if(Grille[i][j+1]==0)
                {
                    Grille[i][j+1]=Grille[i][j];
                    Grille[i][j]=0;
                }
            }
        }
    }
}
void DeplacerGauche8(int Grille[M][M])
{
    int i;
    int j;
    for(i=0; i<M; i++)
    {
        for(j=0; j<M; j++)
        {
            if (6-j>=0)   
            { 
                if (Grille[i][7-j]==Grille[i][6-j])
                {
                    Grille[i][6-j]+=Grille[i][7-j];
                    Grille[i][7-j] = 0;
                }
                else if(Grille[i][6-j]==0)
                {
                    Grille[i][6-j]=Grille[i][7-j];
                    Grille[i][7-j]=0;
                }
            }
        }
    }
}
void DeplacerBas8(int Grille[M][M])
{
    int i;
    int j;
    for(i=0; i<M; i++)
    {
        for(j=0; j<M; j++)
        {
            if (i < 7   )
            {
                if (Grille[i][j]==Grille[i+1][j])
                {
                    Grille[i+1][j]+=Grille[i][j];
                    Grille[i][j] = 0;
                }
                else if(Grille[i+1][j]==0)
                {
                    Grille[i+1][j]=Grille[i][j];
                    Grille[i][j]=0;
                }
            }
        }
    }
}
void DeplacerHaut8(int Grille[M][M])
{
    int i;
    int j;
    for(i=0; i<M; i++)
    {
        for(j=0; j<M; j++)
        {
            if (6-i >= 0)
            {
                if (Grille[7-i][j]==Grille[6-i][j])
                {
                    Grille[6-i][j]+=Grille[7-i][j];
                    Grille[7-i][j] = 0;
                }
                else if(Grille[6-i][j]==0)
                {
                    Grille[6-i][j]=Grille[7-i][j];
                    Grille[7-i][j]=0;
                }
            }
        }
    }
}
int ConditionFIN8(int Grille[M][M])
{
    int i;
    int j;
    int condition =1;
    int FIN=0;

    for (i=0; i<M; i++)
    {
        for (j=0; j<M; j++)
        {
            if (((Grille[i][j]!=Grille[i+1][j])&&(Grille[i][j]!=Grille[i-1][j]))&&((Grille[i][j]!=Grille[i][j+1])&&(Grille[i][j]!=Grille[i][j+1])))
            {
                if (Grille[i][j]!=0)
                {
                    condition += 1;
                }
            }
            if (Grille[i][j]==2048)
            {
                printf("Victoire !!!\n");
                FIN = 2;
            }
        }
    }
    if (condition == 64)
    {
        FIN = 1;
    }

    return FIN;
}
void affichageJeu8(int Grille[M][M], int skin_2048, SDL_Renderer *renderer)
{
    int i;
    int j;
    SDL_Rect Case;


    int r;
    int g; 
    int b; 
    int a = 255; 
    for (i=0; i<M; i++)
    {
        for (j=0; j<M; j++)
        {
            
            if (skin_2048 == 0)
            {
                switch (Grille[i][j])
                {
                    default : r = 255; g = 255; b = 255;break;
                    case 2 : r = 255; g = 255; b = 0; break;
                    case 4 : r = 0; g = 255; b = 0; break;
                    case 8 : r = 0; g = 100; b = 0; break;
                    case 16 : r = 0; g = 100; b = 255; break;
                    case 32 : r = 0; g = 0; b = 255; break;
                    case 64 : r = 100; g = 0; b = 255; break;
                    case 128 : r = 255; g = 0; b = 100; break;
                    case 256 : r = 255; g = 0; b = 0; break;
                    case 512 : r = 255; g = 100 ; b = 0; break;
                    case 1024 : r = 125; g = 125; b = 125; break;
                    case 2048 : r = 0; g = 0; b = 0; break;
                }
                
            }
            else 
            {
                switch (Grille[i][j])
                {
                    default : r = 0; g = 0; b = 0;break;
                    case 2 : r = 255; g = 255; b = 0; break;
                    case 4 : r = 0; g = 255; b = 0; break;
                    case 8 : r = 0; g = 100; b = 0; break;
                    case 16 : r = 0; g = 100; b = 255; break;
                    case 32 : r = 0; g = 0; b = 255; break;
                    case 64 : r = 100; g = 0; b = 255; break;
                    case 128 : r = 255; g = 0; b = 100; break;
                    case 256 : r = 255; g = 0; b = 0; break;
                    case 512 : r = 255; g = 100 ; b = 0; break;
                    case 1024 : r = 125; g = 125; b = 125; break;
                    case 2048 : r = 255; g = 255; b = 255; break;
                }
            }
            Case.w = CaseWidth8;
            Case.h = CaseHeight8;
            Case.x = 14 + (CaseWidth8+15)*j;
            Case.y = 14 + (CaseHeight8+15)*i;
        
            
            SDL_SetRenderDrawColor(renderer, r, g, b, a);
            SDL_RenderFillRect(renderer, &Case);
        }
    }
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
    int i_init;
    int j_init;
    int premier=1;
    int bon = 0;
    int c2ou4 = 0;
    i = rand()%4;
    j = rand()%4;
    i_init = i;
    j_init = j;

    while(bon==0)
    {
        if (((i_init == i)&&(j_init == j))&&(premier == 0))
        {
            break;
        }
        else
        {
            if(Grille[i][j]==0)
            {
                bon=1;
                c2ou4= rand()%2;
                if(c2ou4==0)
                {
                    Grille[i][j]=2;
                }
                if(c2ou4==1)
                {
                    Grille[i][j]=4;
                }
            }
            else
            {
                if (j!=3)
                {
                    j += 1;
                }
                else if (j == 3)
                {
                    if (i!= 3)
                    {
                        i +=1;
                        j=0;
                    }
                    else
                    {
                        i=0;
                        j=0;
                    }
                    
                }

            }
            premier = 0;
        }
    }
}

void DeplacerDroite(int Grille[N][N])
{
    int i;
    int j;
    for(i=0; i<N; i++)
    {
        for(j=0; j<N; j++)
        {
            if(j<3)
            {
                if (Grille[i][j]==Grille[i][j+1])
                {
                    Grille[i][j+1] = 2*Grille[i][j];
                    Grille[i][j] = 0;
                }
                else if(Grille[i][j+1]==0)
                {
                    Grille[i][j+1]=Grille[i][j];
                    Grille[i][j]=0;
                }
            }
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
            if (2-j>=0)
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
            }
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
            if (i  < 3)
            {
                if (Grille[i][j]==Grille[i+1][j])
                {
                    Grille[i+1][j]+=Grille[i][j];
                    Grille[i][j] = 0;
                }
                else if(Grille[i+1][j]==0)
                {
                    Grille[i+1][j]=Grille[i][j];
                    Grille[i][j]=0;
                }
            }
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
            if (2-i >= 0)
            {
                if (Grille[3-i][j]==Grille[2-i][j])
                {
                    Grille[2-i][j]+=Grille[3-i][j];
                    Grille[3-i][j] = 0;
                }
                else if(Grille[2-i][j]==0)
                {
                    Grille[2-i][j]=Grille[3-i][j];
                    Grille[3-i][j]=0;
                }
            }
        }
    }
}

int ConditionFIN(int Grille[N][N])
{
    int i;
    int j;
    int condition =1;
    int FIN=0;

    for (i=0; i<N; i++)
    {
        for (j=0; j<N; j++)
        {
            if (((Grille[i][j]!=Grille[i+1][j])&&(Grille[i][j]!=Grille[i-1][j]))&&((Grille[i][j]!=Grille[i][j+1])&&(Grille[i][j]!=Grille[i][j+1])))
            {
                if (Grille[i][j]!=0)
                {
                    condition += 1;
                }
            }
            if (Grille[i][j]==2048)
            {
                printf("Victoire !!!\n");
                FIN = 2;
            }
        }
    }
    if (condition == 16)
    {
        FIN = 1;
    }

    return FIN;
}

void affichageJeu(int Grille[N][N], int skin_2048, SDL_Renderer *renderer)
{
    int i;
    int j;
    SDL_Rect Case;


    int r;
    int g; 
    int b; 
    int a = 255; 
    for (i=0; i<N; i++)
    {
        for (j=0; j<N; j++)
        {
            
            if (skin_2048 == 0)
            {
                switch (Grille[i][j])
                {
                    default : r = 255; g = 255; b = 255;break;
                    case 2 : r = 255; g = 255; b = 0; break;
                    case 4 : r = 0; g = 255; b = 0; break;
                    case 8 : r = 0; g = 100; b = 0; break;
                    case 16 : r = 0; g = 100; b = 255; break;
                    case 32 : r = 0; g = 0; b = 255; break;
                    case 64 : r = 100; g = 0; b = 255; break;
                    case 128 : r = 255; g = 0; b = 100; break;
                    case 256 : r = 255; g = 0; b = 0; break;
                    case 512 : r = 255; g = 100 ; b = 0; break;
                    case 1024 : r = 125; g = 125; b = 125; break;
                    case 2048 : r = 0; g = 0; b = 0; break;
                }
                
            }
            else 
            {
                switch (Grille[i][j])
                {
                    default : r = 0; g = 0; b = 0;break;
                    case 2 : r = 255; g = 255; b = 0; break;
                    case 4 : r = 0; g = 255; b = 0; break;
                    case 8 : r = 0; g = 100; b = 0; break;
                    case 16 : r = 0; g = 100; b = 255; break;
                    case 32 : r = 0; g = 0; b = 255; break;
                    case 64 : r = 100; g = 0; b = 255; break;
                    case 128 : r = 255; g = 0; b = 100; break;
                    case 256 : r = 255; g = 0; b = 0; break;
                    case 512 : r = 255; g = 100 ; b = 0; break;
                    case 1024 : r = 125; g = 125; b = 125; break;
                    case 2048 : r = 255; g = 255; b = 255; break;
                }
            }
            Case.w = CaseWidth;
            Case.h = CaseHeight;
            Case.x = 30 + (CaseWidth+30)*j;
            Case.y = 30 + (CaseHeight+30)*i;
        
            
            SDL_SetRenderDrawColor(renderer, r, g, b, a);
            SDL_RenderFillRect(renderer, &Case);
        }
    }
}

int main(int argc, char **argv)
{
    int Grille[N][N];
    InitialiserGrille(Grille);
    int GrilleJ2[N][N];
    InitialiserGrille(GrilleJ2);
    int Grille8[M][M];
    InitialiserGrille8(Grille8);
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
    int joueur = 1;            
    int continuer = 0;
    int i;
    int j; 
    int var;
    int varx = 0;
    int vary = 0;
    int FIN=0;
    int chgmnt_8x8=0;
    int tour = 0;
    
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
                            case SDLK_d :
                                if (affichage_menu == 2)
                                {
                                    if ((joueur == 1)||((joueur == 2)&&(tour == 0)))
                                    {
                                        if (chgmnt_8x8 == 0)
                                        {
                                            DeplacerDroite(Grille);
                                            AjouterRandom(Grille);
                                            affichageJeu(Grille, skin_2048, renderer);
                                            FIN = ConditionFIN(Grille);
                                            tour = 1;
                                            if (FIN == 2)
                                            {
                                                printf("VICTOIRE !\n");
                                                image = SDL_LoadBMP("img/Victoire.bmp");
                                                texture = SDL_CreateTextureFromSurface(renderer, image);
                                                SDL_FreeSurface(image);
                                                SDL_QueryTexture(texture, NULL, NULL, &BG.w, &BG.h);
                                                SDL_RenderCopy(renderer, texture, NULL, &BG);
                                                SDL_RenderPresent(renderer);
                                                SDL_Delay(1500);
                                                program_launched = SDL_FALSE;
                                                break;
                                            }
                                            else if (FIN == 1)
                                            {
                                                printf("Defaite \n");
                                                program_launched = SDL_FALSE;
                                                image = SDL_LoadBMP("img/defaite.bmp");
                                                texture = SDL_CreateTextureFromSurface(renderer, image);
                                                SDL_FreeSurface(image);
                                                SDL_QueryTexture(texture, NULL, NULL, &BG.w, &BG.h);
                                                SDL_RenderCopy(renderer, texture, NULL, &BG);
                                                SDL_RenderPresent(renderer);
                                                SDL_Delay(1500);
                                                program_launched = SDL_FALSE;
                                                break;
                                            }
                                            else
                                            {
                                                continue;
                                            }
                                        }
                                        else if (chgmnt_8x8 == 1)
                                        {
                                            DeplacerDroite8(Grille8);
                                            AjouterRandom8(Grille8);
                                            affichageJeu8(Grille8, skin_2048, renderer);
                                            FIN = ConditionFIN8(Grille8);
                                            if (FIN == 2)
                                            {
                                                printf("VICTOIRE !\n");
                                                image = SDL_LoadBMP("img/Victoire.bmp");
                                                texture = SDL_CreateTextureFromSurface(renderer, image);
                                                SDL_FreeSurface(image);
                                                SDL_QueryTexture(texture, NULL, NULL, &BG.w, &BG.h);
                                                SDL_RenderCopy(renderer, texture, NULL, &BG);
                                                SDL_RenderPresent(renderer);
                                                SDL_Delay(1500);
                                                program_launched = SDL_FALSE;
                                                break;
                                            }
                                            else if (FIN == 1)
                                            {
                                                printf("Defaite \n");
                                                program_launched = SDL_FALSE;
                                                image = SDL_LoadBMP("img/defaite.bmp");
                                                texture = SDL_CreateTextureFromSurface(renderer, image);
                                                SDL_FreeSurface(image);
                                                SDL_QueryTexture(texture, NULL, NULL, &BG.w, &BG.h);
                                                SDL_RenderCopy(renderer, texture, NULL, &BG);
                                                SDL_RenderPresent(renderer);
                                                SDL_Delay(1500);
                                                program_launched = SDL_FALSE;
                                                break;
                                            }
                                            else
                                            {
                                                continue;
                                            }
                                        }
                                    }
                                    else
                                    {
                                        continue;
                                    }
                                }
                            case SDLK_q :
                                if (affichage_menu == 2)    
                                {
                                    if ((joueur == 1)||((joueur == 2)&&(tour == 0)))
                                    {
                                        if (chgmnt_8x8 == 0)
                                        {
                                            DeplacerGauche(Grille);
                                            AjouterRandom(Grille);
                                            affichageJeu(Grille, skin_2048, renderer);
                                            FIN = ConditionFIN(Grille);
                                            tour = 1;
                                            if (FIN == 2)
                                            {
                                                printf("VICTOIRE !\n");
                                                image = SDL_LoadBMP("img/Victoire.bmp");
                                                texture = SDL_CreateTextureFromSurface(renderer, image);
                                                SDL_FreeSurface(image);
                                                SDL_QueryTexture(texture, NULL, NULL, &BG.w, &BG.h);
                                                SDL_RenderCopy(renderer, texture, NULL, &BG);
                                                SDL_RenderPresent(renderer);
                                                SDL_Delay(1500);
                                                program_launched = SDL_FALSE;
                                                break;
                                            }
                                            else if (FIN == 1)
                                            {
                                                printf("Defaite \n");
                                                image = SDL_LoadBMP("img/defaite.bmp");
                                                texture = SDL_CreateTextureFromSurface(renderer, image);
                                                SDL_FreeSurface(image);
                                                SDL_QueryTexture(texture, NULL, NULL, &BG.w, &BG.h);
                                                SDL_RenderCopy(renderer, texture, NULL, &BG);
                                                SDL_RenderPresent(renderer);
                                                SDL_Delay(1500);
                                                program_launched = SDL_FALSE;
                                                break;
                                            }
                                            else
                                            {
                                                continue;
                                            }
                                        }
                                        else if (chgmnt_8x8 == 1)
                                        {
                                            DeplacerGauche8(Grille8);
                                            AjouterRandom8(Grille8);
                                            affichageJeu8(Grille8, skin_2048, renderer);
                                            FIN = ConditionFIN8(Grille8);
                                            if (FIN == 2)
                                            {
                                                printf("VICTOIRE !\n");
                                                image = SDL_LoadBMP("img/Victoire.bmp");
                                                texture = SDL_CreateTextureFromSurface(renderer, image);
                                                SDL_FreeSurface(image);
                                                SDL_QueryTexture(texture, NULL, NULL, &BG.w, &BG.h);
                                                SDL_RenderCopy(renderer, texture, NULL, &BG);
                                                SDL_RenderPresent(renderer);
                                                SDL_Delay(1500);
                                                program_launched = SDL_FALSE;
                                                break;
                                            }
                                            else if (FIN == 1)
                                            {
                                                printf("Defaite \n");
                                                image = SDL_LoadBMP("img/defaite.bmp");
                                                texture = SDL_CreateTextureFromSurface(renderer, image);
                                                SDL_FreeSurface(image);
                                                SDL_QueryTexture(texture, NULL, NULL, &BG.w, &BG.h);
                                                SDL_RenderCopy(renderer, texture, NULL, &BG);
                                                SDL_RenderPresent(renderer);
                                                SDL_Delay(1500);
                                                program_launched = SDL_FALSE;
                                                break;
                                            }
                                            else
                                            {
                                                continue;
                                            }
                                        }
                                    }
                                    else
                                    {
                                        continue;
                                    }
                                    
                                }
                            
                            case SDLK_z :
                                if (affichage_menu == 2)
                                {
                                    if ((joueur==1)||((joueur==2)&&(tour == 0)))
                                    {
                                        if (chgmnt_8x8 == 0)
                                        {
                                            DeplacerHaut(Grille);
                                            AjouterRandom(Grille);
                                            affichageJeu(Grille, skin_2048, renderer);
                                            FIN = ConditionFIN(Grille);
                                            tour = 1;
                                            if (FIN == 2)
                                            {
                                                printf("VICTOIRE !\n");
                                                image = SDL_LoadBMP("img/Victoire.bmp");
                                                texture = SDL_CreateTextureFromSurface(renderer, image);
                                                SDL_FreeSurface(image);
                                                SDL_QueryTexture(texture, NULL, NULL, &BG.w, &BG.h);
                                                SDL_RenderCopy(renderer, texture, NULL, &BG);
                                                SDL_RenderPresent(renderer);
                                                SDL_Delay(1500);
                                                program_launched = SDL_FALSE;
                                                break;
                                            }
                                            else if (FIN == 1)
                                            {
                                                printf("Defaite \n");
                                                image = SDL_LoadBMP("img/defaite.bmp");
                                                texture = SDL_CreateTextureFromSurface(renderer, image);
                                                SDL_FreeSurface(image);
                                                SDL_QueryTexture(texture, NULL, NULL, &BG.w, &BG.h);
                                                SDL_RenderCopy(renderer, texture, NULL, &BG);
                                                SDL_RenderPresent(renderer);
                                                SDL_Delay(1500);
                                                program_launched = SDL_FALSE;
                                                break;
                                            }
                                            else
                                            {
                                                continue;
                                            }
                                        }
                                        else if (chgmnt_8x8 == 1)
                                        {
                                            DeplacerHaut8(Grille8);
                                            AjouterRandom8(Grille8);
                                            affichageJeu8(Grille8, skin_2048, renderer);
                                            FIN = ConditionFIN8(Grille8);
                                            if (FIN == 2)
                                            {
                                                printf("VICTOIRE !\n");
                                                image = SDL_LoadBMP("img/Victoire.bmp");
                                                texture = SDL_CreateTextureFromSurface(renderer, image);
                                                SDL_FreeSurface(image);
                                                SDL_QueryTexture(texture, NULL, NULL, &BG.w, &BG.h);
                                                SDL_RenderCopy(renderer, texture, NULL, &BG);
                                                SDL_RenderPresent(renderer);
                                                SDL_Delay(1500);
                                                program_launched = SDL_FALSE;
                                                break;
                                            }
                                            else if (FIN == 1)
                                            {
                                                printf("Defaite \n");
                                                image = SDL_LoadBMP("img/defaite.bmp");
                                                texture = SDL_CreateTextureFromSurface(renderer, image);
                                                SDL_FreeSurface(image);
                                                SDL_QueryTexture(texture, NULL, NULL, &BG.w, &BG.h);
                                                SDL_RenderCopy(renderer, texture, NULL, &BG);
                                                SDL_RenderPresent(renderer);
                                                SDL_Delay(1500);
                                                program_launched = SDL_FALSE;
                                                break;
                                            }
                                            else
                                            {
                                                continue;
                                            }
                                        }
                                    }
                                }    
                            
                            case SDLK_s :
                                if (affichage_menu == 2)
                                {
                                    if ((joueur==1)||((joueur==2)&&(tour==0)))
                                    {
                                        if (chgmnt_8x8 == 0)
                                        {
                                            DeplacerBas(Grille);
                                            AjouterRandom(Grille);
                                            affichageJeu(Grille, skin_2048, renderer);
                                            FIN = ConditionFIN(Grille);
                                            tour = 1;
                                            if (FIN == 2)
                                            {
                                                printf("VICTOIRE !\n");
                                                image = SDL_LoadBMP("img/Victoire.bmp");
                                                texture = SDL_CreateTextureFromSurface(renderer, image);
                                                SDL_FreeSurface(image);
                                                SDL_QueryTexture(texture, NULL, NULL, &BG.w, &BG.h);
                                                SDL_RenderCopy(renderer, texture, NULL, &BG);
                                                SDL_RenderPresent(renderer);
                                                SDL_Delay(1500);
                                                program_launched = SDL_FALSE;
                                                break;
                                            }
                                            else if (FIN == 1)
                                            {
                                                printf("Defaite \n");
                                                image = SDL_LoadBMP("img/defaite.bmp");
                                                texture = SDL_CreateTextureFromSurface(renderer, image);
                                                SDL_FreeSurface(image);
                                                SDL_QueryTexture(texture, NULL, NULL, &BG.w, &BG.h);
                                                SDL_RenderCopy(renderer, texture, NULL, &BG);
                                                SDL_RenderPresent(renderer);
                                                SDL_Delay(1500);
                                                program_launched = SDL_FALSE;
                                                break;
                                            }
                                            else
                                            {
                                                continue;
                                            }
                                        }
                                        else if (chgmnt_8x8 == 1)
                                        {
                                            DeplacerBas8(Grille8);
                                            AjouterRandom8(Grille8);
                                            affichageJeu8(Grille8, skin_2048, renderer);
                                            FIN = ConditionFIN8(Grille8);
                                            if (FIN == 2)
                                            {
                                                printf("VICTOIRE !\n");
                                                image = SDL_LoadBMP("img/Victoire.bmp");
                                                texture = SDL_CreateTextureFromSurface(renderer, image);
                                                SDL_FreeSurface(image);
                                                SDL_QueryTexture(texture, NULL, NULL, &BG.w, &BG.h);
                                                SDL_RenderCopy(renderer, texture, NULL, &BG);
                                                SDL_RenderPresent(renderer);
                                                SDL_Delay(1500);
                                                program_launched = SDL_FALSE;
                                                break;
                                            }
                                            else if (FIN == 1)
                                            {
                                                printf("Defaite \n");
                                                image = SDL_LoadBMP("img/defaite.bmp");
                                                texture = SDL_CreateTextureFromSurface(renderer, image);
                                                SDL_FreeSurface(image);
                                                SDL_QueryTexture(texture, NULL, NULL, &BG.w, &BG.h);
                                                SDL_RenderCopy(renderer, texture, NULL, &BG);
                                                SDL_RenderPresent(renderer);
                                                SDL_Delay(1500);
                                                program_launched = SDL_FALSE;
                                                break;
                                            }
                                            else
                                            {
                                                continue;
                                            }
                                        }
                                    }
                                }    
                            
                            
                            /* Cas 2 Joueurs */
                            case SDLK_m :
                                if ((affichage_menu == 2)&&((joueur==2)&&(tour==1)))
                                {
                                    DeplacerDroite(GrilleJ2);
                                    
                                    tour = 0;
                                    AjouterRandom(GrilleJ2);
                                    for (i=0; i<N; i++)
                                    {
                                        for (j=0; j<N; j++)
                                        {
                                            printf("|  %d  " , GrilleJ2[i][j]);
                                        }
                                        printf("|\n");
                                    }
                                    printf("\n");
                                    FIN = ConditionFIN(GrilleJ2);
                                    if (FIN == 2)
                                    {
                                        printf("VICTOIRE !\n");
                                        image = SDL_LoadBMP("img/Victoire.bmp");
                                        texture = SDL_CreateTextureFromSurface(renderer, image);
                                        SDL_FreeSurface(image);
                                        SDL_QueryTexture(texture, NULL, NULL, &BG.w, &BG.h);
                                        SDL_RenderCopy(renderer, texture, NULL, &BG);
                                        SDL_RenderPresent(renderer);
                                        SDL_Delay(1500);
                                        program_launched = SDL_FALSE;
                                        break;
                                    }
                                    else if (FIN == 1)
                                    {
                                        printf("Defaite \n");
                                        program_launched = SDL_FALSE;
                                        image = SDL_LoadBMP("img/defaite.bmp");
                                        texture = SDL_CreateTextureFromSurface(renderer, image);
                                        SDL_FreeSurface(image);
                                        SDL_QueryTexture(texture, NULL, NULL, &BG.w, &BG.h);
                                        SDL_RenderCopy(renderer, texture, NULL, &BG);
                                        SDL_RenderPresent(renderer);
                                        SDL_Delay(1500);
                                        program_launched = SDL_FALSE;
                                        break;
                                    }
                                    else
                                    {
                                        continue;
                                    }
                                    
                                } 
                            
                            case SDLK_k :
                                if ((affichage_menu == 2)&&((joueur==2)&&(tour==1)))    
                                {
                                    DeplacerGauche(GrilleJ2);
                                    AjouterRandom(GrilleJ2);
                                    tour = 0;
                                    for (i=0; i<N; i++)
                                    {
                                        for (j=0; j<N; j++)
                                        {
                                            printf("|  %d  " , GrilleJ2[i][j]);
                                        }
                                        printf("|\n");
                                    }
                                    printf("\n");
                                    FIN = ConditionFIN(GrilleJ2);
                                    if (FIN == 2)
                                    {
                                        printf("VICTOIRE !\n");
                                        image = SDL_LoadBMP("img/Victoire.bmp");
                                        texture = SDL_CreateTextureFromSurface(renderer, image);
                                        SDL_FreeSurface(image);
                                        SDL_QueryTexture(texture, NULL, NULL, &BG.w, &BG.h);
                                        SDL_RenderCopy(renderer, texture, NULL, &BG);
                                        SDL_RenderPresent(renderer);
                                        SDL_Delay(1500);
                                        program_launched = SDL_FALSE;
                                        break;
                                    }
                                    else if (FIN == 1)
                                    {
                                        printf("Defaite \n");
                                        image = SDL_LoadBMP("img/defaite.bmp");
                                        texture = SDL_CreateTextureFromSurface(renderer, image);
                                        SDL_FreeSurface(image);
                                        SDL_QueryTexture(texture, NULL, NULL, &BG.w, &BG.h);
                                        SDL_RenderCopy(renderer, texture, NULL, &BG);
                                        SDL_RenderPresent(renderer);
                                        SDL_Delay(1500);
                                        program_launched = SDL_FALSE;
                                        break;
                                    }
                                    else
                                    {
                                        continue;
                                    }
                                    
                                }
                            
                            case SDLK_o :
                                if ((affichage_menu == 2)&&((joueur==2)&&(tour==1)))
                                {
                                    DeplacerHaut(GrilleJ2);
                                    AjouterRandom(GrilleJ2);
                                    tour = 0;
                                    for (i=0; i<N; i++)
                                    {
                                        for (j=0; j<N; j++)
                                        {
                                            printf("|  %d  " , GrilleJ2[i][j]);
                                        }
                                        printf("|\n");
                                    }
                                    printf("\n");
                                    FIN = ConditionFIN(GrilleJ2);
                                    if (FIN == 2)
                                    {
                                        printf("VICTOIRE !\n");
                                        image = SDL_LoadBMP("img/Victoire.bmp");
                                        texture = SDL_CreateTextureFromSurface(renderer, image);
                                        SDL_FreeSurface(image);
                                        SDL_QueryTexture(texture, NULL, NULL, &BG.w, &BG.h);
                                        SDL_RenderCopy(renderer, texture, NULL, &BG);
                                        SDL_RenderPresent(renderer);
                                        SDL_Delay(1500);
                                        program_launched = SDL_FALSE;
                                        break;
                                    }
                                    else if (FIN == 1)
                                    {
                                        printf("Defaite \n");
                                        image = SDL_LoadBMP("img/defaite.bmp");
                                        texture = SDL_CreateTextureFromSurface(renderer, image);
                                        SDL_FreeSurface(image);
                                        SDL_QueryTexture(texture, NULL, NULL, &BG.w, &BG.h);
                                        SDL_RenderCopy(renderer, texture, NULL, &BG);
                                        SDL_RenderPresent(renderer);
                                        SDL_Delay(1500);
                                        program_launched = SDL_FALSE;
                                        break;
                                    }
                                    else
                                    {
                                        continue;
                                    }
                                }    
                            
                            case SDLK_l :
                                if ((affichage_menu == 2)&&((joueur==2)&&(tour == 1)))
                                {
                                    DeplacerBas(GrilleJ2);
                                    AjouterRandom(GrilleJ2);
                                    tour = 0;
                                    for (i=0; i<N; i++)
                                    {
                                        for (j=0; j<N; j++)
                                        {
                                            printf("|  %d  " , GrilleJ2[i][j]);
                                        }
                                        printf("|\n");
                                    }
                                    printf("\n");
                                    FIN = ConditionFIN(GrilleJ2);
                                    if (FIN == 2)
                                    {
                                        printf("VICTOIRE !\n");
                                        image = SDL_LoadBMP("img/Victoire.bmp");
                                        texture = SDL_CreateTextureFromSurface(renderer, image);
                                        SDL_FreeSurface(image);
                                        SDL_QueryTexture(texture, NULL, NULL, &BG.w, &BG.h);
                                        SDL_RenderCopy(renderer, texture, NULL, &BG);
                                        SDL_RenderPresent(renderer);
                                        SDL_Delay(1500);
                                        program_launched = SDL_FALSE;
                                        break;
                                    }
                                    else if (FIN == 1)
                                    {
                                        printf("Defaite \n");
                                        image = SDL_LoadBMP("img/defaite.bmp");
                                        texture = SDL_CreateTextureFromSurface(renderer, image);
                                        SDL_FreeSurface(image);
                                        SDL_QueryTexture(texture, NULL, NULL, &BG.w, &BG.h);
                                        SDL_RenderCopy(renderer, texture, NULL, &BG);
                                        SDL_RenderPresent(renderer);
                                        SDL_Delay(1500);
                                        program_launched = SDL_FALSE;
                                        break;
                                    }
                                    else
                                    {
                                        continue;
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
                            else if (affichage_menu == 2)
                            {
                                continue;
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
                        if (chgmnt_8x8 == 0)
                        {
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
                        else if (chgmnt_8x8 == 1)
                        {
                            if (skin_2048 == 0)
                            {
                                image = SDL_LoadBMP("img/grid8.bmp");
                            }
                            if (skin_2048 == 1)
                            {
                                image = SDL_LoadBMP("img/grid8black.bmp");
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
                    }
                    
                    /* Cas où l'utilisateur clic sur 4x4 dans SETTINGS */
                    else if ((((event.button.x >= 450)&&(event.button.x <= 550))&&((event.button.y >= 202)&&(event.button.y <= 302)))&&(affichage_menu == 1)) 
                    {
                        affichage_menu = 1;
                        if (settings == 0)
                        {
                            image = SDL_LoadBMP("img/000.bmp");
                            settings = 0;
                            chgmnt_8x8 = 0;
                        }
                        else if (settings == 1)
                        {
                            image = SDL_LoadBMP("img/000.bmp");
                            settings = 0;
                            chgmnt_8x8 = 0;
                        }
                        else if (settings == 2)
                        {
                            image = SDL_LoadBMP("img/001.bmp");
                            settings = 2;
                            chgmnt_8x8 = 0;
                        }
                        else if (settings == 3)
                        {
                            image = SDL_LoadBMP("img/010.bmp");
                            settings = 3;
                            chgmnt_8x8 = 0;
                        }
                        else if (settings == 4)
                        {
                            image = SDL_LoadBMP("img/011.bmp");
                            settings = 4;
                            chgmnt_8x8 = 0;
                        }
                        else if (settings == 5)
                        {
                            image = SDL_LoadBMP("img/001.bmp");
                            settings = 2;
                            chgmnt_8x8 = 0;
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
                            joueur = 1;
                            chgmnt_8x8 = 1;
                        }                        
                        else if (settings == 1)
                        {
                            image = SDL_LoadBMP("img/100.bmp");
                            settings = 1;
                            joueur = 1;
                            chgmnt_8x8 = 1;
                        }

                        else if (settings == 2)
                        {
                            image = SDL_LoadBMP("img/101.bmp");
                            settings = 5;
                            joueur = 1;
                            chgmnt_8x8 = 1;
                        }
                        else if (settings == 3)
                        {
                            image = SDL_LoadBMP("img/100.bmp");
                            settings = 1;
                            chgmnt_8x8 = 1;
                        }
                        else if (settings == 4)
                        {
                            image = SDL_LoadBMP("img/101.bmp");
                            settings = 5;
                            joueur = 1;
                            chgmnt_8x8 = 1;
                        }
                        else if (settings == 5)
                        {
                            image = SDL_LoadBMP("img/101.bmp");
                            settings = 5;
                            joueur = 1;
                            chgmnt_8x8 = 1;
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
                            joueur = 1;
                        } 
                        else if (settings == 1)
                        {
                            image = SDL_LoadBMP("img/100.bmp");
                            settings = 1;
                            joueur = 1;
                        }                       
                        else if (settings == 2)
                        {
                            image = SDL_LoadBMP("img/001.bmp");
                            settings = 2;
                            joueur = 1;
                        }
                        else if (settings == 3)
                        {
                            image = SDL_LoadBMP("img/000.bmp");
                            settings = 0;
                            joueur = 1;
                        }
                        else if (settings == 4)
                        {
                            image = SDL_LoadBMP("img/001.bmp");
                            settings = 2;
                            joueur = 1;
                        }
                        else if (settings == 5)
                        {
                            image = SDL_LoadBMP("img/101.bmp");
                            settings = 5;
                            joueur = 1;
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
                            joueur = 2;
                        }
                        else if (settings == 1)
                        {
                            image = SDL_LoadBMP("img/100.bmp");
                            settings = 1;
                            joueur = 2;
                        }                        
                        else if (settings == 2)
                        {
                            image = SDL_LoadBMP("img/011.bmp");
                            settings = 4;
                            joueur = 2;
                        }
                        else if (settings == 3)
                        {
                            image = SDL_LoadBMP("img/010.bmp");
                            settings = 3;
                            joueur = 2;
                        }
                        else if (settings == 4)
                        {
                            image = SDL_LoadBMP("img/011.bmp");
                            settings = 4;
                            joueur = 2;
                        }
                        else if (settings == 5)
                        {
                            image = SDL_LoadBMP("img/101.bmp");
                            settings = 5;
                            joueur = 2;
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
    	    if (affichage_menu == 2)
            {
                if (chgmnt_8x8 == 0)
                {
                    affichageJeu(Grille, skin_2048, renderer);
                    SDL_RenderPresent(renderer);
                    if (joueur == 2)
                    {

                        for (i=0; i<N; i++)
                        {
                            for (j=0; j<N; j++)
                            {
                                printf("|  %d  " , GrilleJ2[i][j]);
                            }
                                printf("|\n");
                        }
                    }
                }
                else if (chgmnt_8x8 == 1)
                {
                    affichageJeu8(Grille8, skin_2048, renderer);
                    SDL_RenderPresent(renderer);
                }
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