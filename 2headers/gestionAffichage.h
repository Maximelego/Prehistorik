/**
 * \file gestionAffichage.h
 * \brief Header contenant les modifieurs et définitions du gestionnaire de jeu.
 * \author Marcelin Maxime/ Tysoun Phillip /Signorino-Gelo Matteo
 * \version 1.0.
 * \date 08 novembre 2021
 */

#ifndef GESTION_AFFICHAGE_H
#define GESTION_AFFICHAGE_H

//---------------------------------------------------------//
#include "struct_ressources.h"
#include "struct_world.h"

//---------------------------------------------------------//
 /**
  * \brief La fonction initialise les données du renderer et de la fenêtre.
  * \param window La fenêtre du jeu.
  * \param renderer Le renderer.
  * \param ressources Les ressources.
  */

void initGraphique(SDL_Window ** window, SDL_Renderer ** renderer, ressources_p ressources);


//---------------------------------------------------------//
/**
 * \brief La fonction applique la texture du fond sur le renderer lié à l'écran de jeu.
 * \param renderer Le renderer.
 * \param texture La texture liée au fond.
*/
void applyBackground(SDL_Renderer *renderer, SDL_Texture *texture);

/**
 * \brief La fonction applique la texture des plateformes dans le renderer.
 * \param renderer Le renderer.
 * \param ressources Les ressources.
 * \param world Le Monde.
*/
void applyPlatforms(SDL_Renderer *renderer, ressources_p ressources, world_p world);

//---------------------------------------------------------//
/**
 * \brief La fonction applique les textures des labels d'option du jeu lors de l'affichage du menu.
 * \param renderer Le renderer.
 * \param ressources Les ressources.
 * \param world Le monde.
*/
void applyLabels(SDL_Renderer *renderer, ressources_p ressources, world_p world);

//---------------------------------------------------------//
/**
 * \brief La fonction applique le message du menu de pause.
 * \param renderer Le renderer.
 * \param ressources Les ressources.
*/
void applyPauseMessage(SDL_Renderer *renderer, ressources_p ressources);


//---------------------------------------------------------//
/**
 * \brief La fonction applique le titre de l'écran titre.
 * \param renderer Le renderer.
 * \param ressources Les ressources.
*/
void applyMainTitle(SDL_Renderer *renderer, ressources_p ressources);

//---------------------------------------------------------//
/**
 * \brief La fonction applique les images et textes du menu Help.
 * \param renderer Le renderer.
 * \param ressources Les ressources.
*/

void applyHelpMenu(SDL_Renderer *renderer, ressources_p ressources);


//---------------------------------------------------------//
/**
 * \brief La fonction permet d'afficher les meilleurs scores.
 * \return Pointeur vers les meilleurs scores.
*/
void tableauScore(int top5[]);

//---------------------------------------------------------//
/**
 * \brief La fonction applique la texture du Player à l'écran du jeu.
 * \param renderer Le renderer.
 * \param ressources Les ressources.
 * \param sprite Les sprites.
*/
void applyPlayer(SDL_Renderer *renderer, ressources_p ressources, sprite_p sprite);

//---------------------------------------------------------//
/**
 * \brief La fonction applique la texture du mob crocodile à l'écran du jeu.
 * \param renderer Le renderer.
 * \param ressources Les ressources.
 * \param sprite Les sprites.
*/
void applyCrocoSprite(SDL_Renderer *renderer, ressources_p ressources, sprite_p sprite);

//---------------------------------------------------------//
 /**
  * \brief La fonction rafraîchit l'écran en fonction de l'état des données du monde.
  * \param renderer Le renderer lié à l'écran de jeu.
  * \param world Les données du monde.
  * \param ressources Les ressources.
  */
void refreshGraphics(SDL_Renderer *renderer, world_p world, ressources_p ressources);

//---------------------------------------------------------//
 /**
  * \brief La fonction nettoie les données graphiques.
  * \param window La fenêtre du jeu.
  * \param renderer Le renderer.
  * \param ressources Structure des ressources.
  */
void cleanGraphique(SDL_Window ** window, SDL_Renderer ** renderer, ressources_p ressources);

#endif
