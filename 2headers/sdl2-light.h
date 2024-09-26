/**
 * \file sdl2-light.h
 * \brief Header du module correspondant à une sur-couche de SDL2 pour simplifier son utilisation pour le projet
 * \author Marcelin Maxime/ Tysoun Phillip /Signorino-Gelo Matteo
 * \version 0.2
 * \date 25 nov 2021
*/


#ifndef __SDL2_LIGHT__H__
#define __SDL2_LIGHT__H__

#include <SDL2/SDL.h>


//------------------------------------------INITIALISATION-------------------------------------------------------//

 /**
  * \brief Fonction permettant d'initialiser SDL (fenêtre et renderer).
  * \param window Pointeur vers la fenêtre.
  * \param renderer Le renderer.
  * \param width Largeur de la fenêtre.
  * \param height Hauteur de la fenêtre.
  * \return Entier indiquant le résultat de l'opération (-1 : Echec ; 0 : Réussite).
  */

int init_sdl(SDL_Window **window, SDL_Renderer **renderer, int width, int height);


//------------------------------------------CHARGEMENT DES TEXTURES-------------------------------------------------------//

/**
 * \brief Fonction permettant de charger les textures d'un sprite BMP.
 * \param path Chemin d'accès au fichier du Sprite.
 * \param renderer Le renderer.
 * \return Texture initialisée.
 */
SDL_Texture *load_imageBMP(const char path[], SDL_Renderer *renderer);

//------------------------------------------APPLICATION DES TEXTURES-------------------------------------------------------//

/**
 * \brief Fonction permettant d'appliquer les textures des Spritess au renderer.
 * \param texture La texture à initialiser.
 * \param renderer Le renderer.
 * \param x Abscisse du centre du Sprite.
 * \param y Ordonnée du centre du Sprite.
 */
void apply_texture(SDL_Texture *texture,SDL_Renderer *renderer,int x, int y);

//------------------------------------------NETTOYAGE-------------------------------------------------------//

/**
 * \brief Fonction permettant de nettoyer SDL.
 * \param renderer Le renderer.
 * \param window La fenêtre.
 */
void clean_sdl(SDL_Renderer *renderer,SDL_Window *window);

/**
 * \brief Fonction permettant de nettoyer la texture donnée en paramètre.
 * \param texture La texture à nettoyer.
 */
void clean_texture(SDL_Texture *texture);

/**
 * \brief Fonction permettant de nettoyer le renderer donné en paramètre.
 * \param renderer Le renderer à nettoyer.
 */
void clear_renderer(SDL_Renderer *renderer);

//------------------------------------------UTILITY-------------------------------------------------------//

/**
 * \brief Fonction permettant de mettre à jour le renderer en appliquant les textures.
 * \param renderer Le renderer.
 */
void update_screen(SDL_Renderer *renderer);

/**
 * \brief La fonction met le programme en pause pendant un laps de temps
 * \param time ce laps de temps en milliseconde
*/

void pause(int time);

#endif
