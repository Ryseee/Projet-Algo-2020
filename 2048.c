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
	
    // Execution du Programme
    
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
                            if ((((((X >= 200)&&(X <= 600))&&((Y >= 418)&&(Y<= 518))))||((((X>= 200)&&(X <= 600))&&((Y >= 268)&&(Y<= 368)))))||((((X >= 200)&&(X <= 600))&&((Y >= 568)&&(Y<= 668)))))
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
                            else
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
                            
                            

                            continue;
                }
                case SDL_MOUSEBUTTONDOWN : 
                    if (((event.button.x >= 200)&&(event.button.x <= 600))&&((event.button.y >= 568)&&(event.button.y <= 668)))
                    {
                        program_launched = SDL_FALSE; break;
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
