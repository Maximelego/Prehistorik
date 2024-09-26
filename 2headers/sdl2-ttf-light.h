/**
 * \file sdl2-ttf-light.h
 * \brief en-tête du module correspondant à une sur-couche de SDL2-TTF pour simplifier son utilisation pour le projet
 * \author Marcelin Maxime/ Tysoun Phillip /Signorino-Gelo Matteo
 * \version 1.0
 * \date 22 décembre 2021
*/


#ifndef __SDL2_TTF_LIGHT__H__
#define __SDL2_TTF_LIGHT__H__

#include <SDL2/SDL_ttf.h>

//------------------------------------------INITIALISATION-------------------------------------------------------//

/**
 * \brief Fonction permettant d'initialiser SDL-ttf
 */
void init_ttf();


//------------------------------------------CHARGEMENT-------------------------------------------------------//

/**
 * \brief Fonction permettant de charger une police d'écriture.
 * \param path Chemin d'accès de la police d'écriture.
 * \param font_size Taille de la police d'écriture.
 * \return Pointeur vers la police d'écriture.
 */
TTF_Font * load_font(const char *path, int font_size);

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
void apply_text(SDL_Renderer *renderer,int x, int y, int w, int h, const char *text, TTF_Font *font);

//------------------------------------------NETTOYAGE-------------------------------------------------------//

/**
 * \brief Fonction nettoyant la police d'écriture donnée en paramètres.
 * \param font Police à nettoyer.
 */
void clean_font(TTF_Font * font);

#endif
