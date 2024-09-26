/**
 * \file sdl2-ttf-light.c
 * \brief Fichier sur-couche de SDL2-TTF pour simplifier son utilisation pour le projet
 * \author Marcelin Maxime/ Tysoun Phillip /Signorino-Gelo Matteo
 * \version 1.0
 * \date 22 décembre 2021
*/

#include "sdl2-ttf-light.h"
#include <SDL2/SDL_ttf.h>
#include "constantes.h"


//------------------------------------------INITIALISATION-------------------------------------------------------//

 /**
  * \brief Fonction permettant d'initialiser SDL-ttf
  */


void init_ttf(){
    if(DEV_MODE){printf("Appel de <init_ttf()>.\n");}
    if(TTF_Init()==-1) {
        printf("TTF_Init: %s\n", TTF_GetError());
    }
}

//------------------------------------------CHARGEMENT-------------------------------------------------------//

/**
 * \brief Fonction permettant de charger une police d'écriture.
 * \param path Chemin d'accès de la police d'écriture.
 * \param font_size Taille de la police d'écriture.
 * \return Pointeur vers la police d'écriture.
 */
TTF_Font * load_font(const char *path, int font_size){
    if(DEV_MODE){printf("Appel de <load_font()>.\n");}
    TTF_Font *font = TTF_OpenFont(path, font_size);
    if(font == NULL){
        fprintf(stderr, "Erreur pendant chargement font: %s\n", SDL_GetError());
    }
    return font;
}

//------------------------------------------APPLICATION-------------------------------------------------------//

/**
 * \brief Fonction permettant d'appliquer un texte dans le renderer.
 * \param renderer Le renderer.
 * \param x Abscisse du texte.
 * \param y Ordonnée du texte.
 * \param w Largeur du texte.
 * \param h Hauteur du texte.
 * \param text Texte à afficher.
 * \param font Pointeur vers la police d'écriture.
 */
void apply_text(SDL_Renderer *renderer,int x, int y, int w, int h, const char *text, TTF_Font *font){
  if(DEV_MODE){printf("Appel de <apply_text()>.\n");}
    SDL_Color color = { 0, 0, 0 };

    SDL_Surface* surface = TTF_RenderText_Solid(font, text, color);

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Rect dstrect2 = {x, y, w, h};

    SDL_RenderCopy(renderer, texture, NULL, &dstrect2);

    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}


//------------------------------------------NETTOYAGE-------------------------------------------------------//

/**
 * \brief Fonction nettoyant la police d'écriture donnée en paramètres.
 * \param font Police à nettoyer.
 */
void clean_font(TTF_Font * font){
    TTF_CloseFont(font);
}
