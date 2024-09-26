/**
 * \file sdl2-light.c
 * \brief Sur-couche de SDL2 pour simplifier son utilisation pour le projet.
 * \author Marcelin Maxime/ Tysoun Phillip /Signorino-Gelo Matteo
 * \version 0.2
 * \date 25 nov 2021
*/

#include "sdl2-light.h"

#include <stdio.h>
#include <stdlib.h>

#include "constantes.h"

//------------------------------------------INITIALISATION-------------------------------------------------------//

 /**
  * \brief Fonction permettant d'initialiser SDL (fenêtre et renderer).
  * \param window Pointeur vers la fenêtre.
  * \param renderer Le renderer.
  * \param width Largeur de la fenêtre.
  * \param height Hauteur de la fenêtre.
  * \return Entier indiquant le résultat de l'opération (-1 : Echec ; 0 : Réussite).
  */

int init_sdl(SDL_Window **window, SDL_Renderer **renderer, int width, int height){
    if(DEV_MODE){printf("Appel de <init_sdl()>.\n");}
    if(0 != SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO))
    {
        fprintf(stderr, "Erreur initialisation de la SDL : %s\n", SDL_GetError());
        return -1;
    }
    if(0 != SDL_CreateWindowAndRenderer(width, height, SDL_WINDOW_SHOWN, window, renderer))
    {
        fprintf(stderr, "Erreur lors de la creation de l'image et du renderer : %s\n", SDL_GetError());
        return -1;
    }
    return 0;
}


//------------------------------------------CHARGEMENT DES TEXTURES-------------------------------------------------------//
/**
 * \brief Fonction permettant de charger les textures d'un sprite BMP.
 * \param path Chemin d'accès au fichier du Sprite.
 * \param renderer Le renderer.
 * \return Texture initialisée.
 */

SDL_Texture *load_imageBMP(const char path[], SDL_Renderer *renderer){
    if(DEV_MODE){printf("Appel de <load_imageBMP()>.\n");}
    SDL_Surface *tmp = NULL;
    SDL_Texture *texture = NULL;
    tmp = SDL_LoadBMP(path);
    if(NULL == tmp)
    {
        fprintf(stderr, "Erreur pendant chargement image BMP: %s\n", SDL_GetError());
        return NULL;
    }
    SDL_SetColorKey(tmp, SDL_TRUE, SDL_MapRGB(tmp->format, 255, 0, 255));
    texture = SDL_CreateTextureFromSurface(renderer, tmp);
    SDL_FreeSurface(tmp);
    if(NULL == texture)
    {
        fprintf(stderr, "Erreur pendant creation de la texture liee a l'image chargee: %s\n", SDL_GetError());
        return NULL;
    }
    return texture;
}

//------------------------------------------APPLICATION DES TEXTURES-------------------------------------------------------//

/**
 * \brief Fonction permettant d'appliquer les textures des Spritess au renderer.
 * \param texture La texture à initialiser.
 * \param renderer Le renderer.
 * \param x Abscisse du centre du Sprite.
 * \param y Ordonnée du centre du Sprite.
 */

void apply_texture(SDL_Texture *texture,SDL_Renderer *renderer,int x, int y){
    if(DEV_MODE){printf("Appel de <apply_texture()>.\n");}
    SDL_Rect dst = {0, 0, 0, 0};

    SDL_QueryTexture(texture, NULL, NULL, &dst.w, &dst.h);
    dst.x = x; dst.y = y;

    SDL_RenderCopy(renderer, texture, NULL, &dst);
}

//------------------------------------------NETTOYAGE-------------------------------------------------------//

/**
 * \brief Fonction permettant de nettoyer SDL.
 * \param renderer Le renderer.
 * \param window La fenêtre.
 */

void clean_sdl(SDL_Renderer *renderer,SDL_Window *window){
    if(DEV_MODE){printf("Appel de <clean_sdl()>.\n");}
    if(NULL != renderer)
        SDL_DestroyRenderer(renderer);
    if(NULL != window)
        SDL_DestroyWindow(window);
    SDL_Quit();
}

/**
 * \brief Fonction permettant de nettoyer la texture donnée en paramètre.
 * \param texture La texture à nettoyer.
 */

void clean_texture(SDL_Texture *texture){
    if(DEV_MODE){printf("Appel de <clean_texture()>.\n");}
    if(NULL != texture){
        SDL_DestroyTexture(texture);
    }
}

/**
 * \brief Fonction permettant de nettoyer le renderer donné en paramètre.
 * \param renderer Le renderer à nettoyer.
 */

void clear_renderer(SDL_Renderer *renderer){
    if(DEV_MODE){printf("Appel de <clear_renderer()>.\n");}
    SDL_RenderClear(renderer);
}

//------------------------------------------UTILITY-------------------------------------------------------//

/**
 * \brief Fonction permettant de mettre à jour le renderer en appliquant les textures.
 * \param renderer Le renderer.
 */

void update_screen(SDL_Renderer *renderer){
    if(DEV_MODE){printf("Appel de <update_screen()>.\n");}
    SDL_RenderPresent(renderer);
}

/**
 * \brief La fonction met le programme en pause pendant un laps de temps
 * \param time ce laps de temps en milliseconde
*/

void pause(int time){
    if(DEV_MODE){printf("Appel de <pause()>.\n");}
    SDL_Delay(time);
}
