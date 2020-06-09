#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>

#define WindowWidth 800
#define WindowHeight 800

// gcc 2048.c -o 2048 $(sdl2-config --cflags --libs)  // COMMANDE DE COMPILATION
// ./2048                                             // COMMANDE D'EXECUTION

void SDL_ExitWithError (const char *message)
{
	SDL_Log("ERREUR : %s > %s\n", message, SDL_GetError());
	SDL_Quit();
	exit(EXIT_FAILURE);
}

int main(int argc, char **argv)
{
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

    SDL_Surface *image = NULL;
    SDL_Texture *texture = NULL;
    
    image = SDL_LoadBMP("Menu.bmp");
    
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
                            break;
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
                                    image = SDL_LoadBMP("Button1.bmp");
                                    
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
                                    affichage_menu = 2;
                                }

                                if (((X >= 200)&&(X <= 600))&&((Y >= 418)&&(Y<= 518)))
                                {
                                    //afficher image assombrie
                                    printf("C'EST LA CASE 2\n");
                                    image = SDL_LoadBMP("Button2.bmp");

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

                                    image = SDL_LoadBMP("Button3.bmp");

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
                                image = SDL_LoadBMP("Menu.bmp");

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
                                    image = SDL_LoadBMP("000.bmp");
                                }
                                else if (settings == 1)
                                {
                                    image = SDL_LoadBMP("100.bmp");
                                }
                                else if (settings == 2)
                                {
                                    image = SDL_LoadBMP("001.bmp");
                                }
                                else if (settings == 3)
                                {
                                    image = SDL_LoadBMP("010.bmp");
                                }
                                else if (settings == 4)
                                {
                                    image = SDL_LoadBMP("011.bmp");
                                }
                                else if (settings == 5)
                                {
                                    image = SDL_LoadBMP("101.bmp");
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
                            image = SDL_LoadBMP("000.bmp");
                        }
                        else if (settings == 1)
                        {
                            image = SDL_LoadBMP("100.bmp");
                        }
                        else if (settings == 2)
                        {
                            image = SDL_LoadBMP("001.bmp");
                        }
                        else if (settings == 3)
                        {
                            image = SDL_LoadBMP("010.bmp");
                        }
                        else if (settings == 4)
                        {
                            image = SDL_LoadBMP("011.bmp");
                        }
                        else if (settings == 5)
                        {
                            image = SDL_LoadBMP("101.bmp");
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
                        continue;
                    }
                    
                    /* Cas où l'utilisateur clic sur 4x4 dans SETTINGS */
                    else if ((((event.button.x >= 450)&&(event.button.x <= 550))&&((event.button.y >= 202)&&(event.button.y <= 302)))&&(affichage_menu == 1)) 
                    {
                        affichage_menu = 1;
                        if (settings == 0)
                        {
                            image = SDL_LoadBMP("000.bmp");
                            settings = 0;
                        }
                        else if (settings == 1)
                        {
                            image = SDL_LoadBMP("000.bmp");
                            settings = 0;
                        }
                        else if (settings == 2)
                        {
                            image = SDL_LoadBMP("001.bmp");
                            settings = 2;
                        }
                        else if (settings == 3)
                        {
                            image = SDL_LoadBMP("010.bmp");
                            settings = 3;
                        }
                        else if (settings == 4)
                        {
                            image = SDL_LoadBMP("011.bmp");
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
                            image = SDL_LoadBMP("100.bmp");
                            settings = 1;
                        }                        
                        else if (settings == 1)
                        {
                            image = SDL_LoadBMP("100.bmp");
                            settings = 1;
                        }

                        else if (settings == 2)
                        {
                            image = SDL_LoadBMP("101.bmp");
                            settings = 5;
                        }
                        else if (settings == 3)
                        {
                            image = SDL_LoadBMP("100.bmp");
                            settings = 1;
                        }
                        else if (settings == 4)
                        {
                            image = SDL_LoadBMP("101.bmp");
                            settings = 5;
                        }
                        else if (settings == 5)
                        {
                            image = SDL_LoadBMP("101.bmp");
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
                            image = SDL_LoadBMP("000.bmp");
                            settings = 0;
                        } 
                        else if (settings == 1)
                        {
                            image = SDL_LoadBMP("100.bmp");
                            settings = 1;
                        }                       
                        else if (settings == 2)
                        {
                            image = SDL_LoadBMP("001.bmp");
                            settings = 2;
                        }
                        else if (settings == 3)
                        {
                            image = SDL_LoadBMP("000.bmp");
                            settings = 0;
                        }
                        else if (settings == 4)
                        {
                            image = SDL_LoadBMP("001.bmp");
                            settings = 2;
                        }
                        else if (settings == 5)
                        {
                            image = SDL_LoadBMP("101.bmp");
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
                            image = SDL_LoadBMP("010.bmp");
                            settings = 3;
                        }
                        else if (settings == 1)
                        {
                            image = SDL_LoadBMP("100.bmp");
                            settings = 1;
                        }                        
                        else if (settings == 2)
                        {
                            image = SDL_LoadBMP("011.bmp");
                            settings = 4;
                        }
                        else if (settings == 3)
                        {
                            image = SDL_LoadBMP("010.bmp");
                            settings = 3;
                        }
                        else if (settings == 4)
                        {
                            image = SDL_LoadBMP("011.bmp");
                            settings = 4;
                        }
                        else if (settings == 5)
                        {
                            image = SDL_LoadBMP("101.bmp");
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
                            image = SDL_LoadBMP("000.bmp");
                            settings = 0;
                        }                        
                        else if (settings == 1)
                        {
                            image = SDL_LoadBMP("100.bmp");
                            settings = 1;
                        }

                        else if (settings == 2)
                        {
                            image = SDL_LoadBMP("000.bmp");
                            settings = 0;
                        }
                        else if (settings == 3)
                        {
                            image = SDL_LoadBMP("010.bmp");
                            settings = 3;
                        }
                        else if (settings == 4)
                        {
                            image = SDL_LoadBMP("010.bmp");
                            settings = 3;
                        }
                        else if (settings == 5)
                        {
                            image = SDL_LoadBMP("100.bmp");
                            settings = 1;
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
                            image = SDL_LoadBMP("001.bmp");
                            settings = 2;
                        }                        
                        else if (settings == 1)
                        {
                            image = SDL_LoadBMP("101.bmp");
                            settings = 5;
                        }

                        else if (settings == 2)
                        {
                            image = SDL_LoadBMP("001.bmp");
                            settings = 2;
                        }
                        else if (settings == 3)
                        {
                            image = SDL_LoadBMP("011.bmp");
                            settings = 4;
                        }
                        else if (settings == 4)
                        {
                            image = SDL_LoadBMP("011.bmp");
                            settings = 4;
                        }
                        else if (settings == 5)
                        {
                            image = SDL_LoadBMP("101.bmp");
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
                    
                    /* Cas où l'utilisateur clic sur la flèche dans SETTINGS */
                    else if ((((event.button.x >= 20)&&(event.button.x <= 100))&&((event.button.y >= 80)&&(event.button.y <= 120)))&&(affichage_menu == 1))
                    {
                        affichage_menu = 0;
                        image = SDL_LoadBMP("Menu.bmp");

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