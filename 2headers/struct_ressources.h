#ifndef STRUCT_RESSOURCES_H
#define STRUCT_RESSOURCES_H

/**
 * \file struct_ressources.h
 * \brief Header contenant les définitions des fonctions permettant de gèrer les ressources du jeu ainsi que le type ressources_t.
 * \author Marcelin Maxime/ Tysoun Phillip /Signorino-Gelo Matteo
 * \version 1.0.
 * \date 25 novembre 2021
 */

#include "sdl2-light.h"
#include "sdl2-ttf-light.h"
#include "SDL2/SDL_mixer.h"

#include "constantes.h"


//------------------------------------------RESSOURCES-------------------------------------------------------//
/**
 * \brief Représentation des ressources du jeu.
 */
typedef struct ressources_s{
  //Polices d'écriture.//
  TTF_Font* font;                                             /*!< Police d'écriture dans la fenêtre. */

  //Background.//
  SDL_Texture* background[NB_FRAME_BACKGROUND]; 			        /*!< Textures liées à l'image du fond de l'écran. */

  //Player.//
  SDL_Texture* playerStandingRight[NB_FRAME_PLAYER_STANDING]; 		  /*!< Textures liées à l'image du Joueur immobile. */
  SDL_Texture* playerMovingRight[NB_FRAME_PLAYER_MOVING]; 	   	    /*!< Textures liées à l'image du Joueur mobile. */
  SDL_Texture* playerJumpingRight[NB_FRAME_PLAYER_JUMPING]; 		    /*!< Textures liées à l'image du Joueur sautant. */
  SDL_Texture* playerAttackingRight[NB_FRAME_PLAYER_ATTACKING]; 		/*!< Textures liées à l'image du Joueur attaquant. */

  SDL_Texture* playerStandingLeft[NB_FRAME_PLAYER_STANDING]; 		    /*!< Textures liées à l'image du Joueur immobile. */
  SDL_Texture* playerMovingLeft[NB_FRAME_PLAYER_MOVING]; 	   	      /*!< Textures liées à l'image du Joueur mobile. */
  SDL_Texture* playerJumpingLeft[NB_FRAME_PLAYER_JUMPING]; 		      /*!< Textures liées à l'image du Joueur sautant. */
  SDL_Texture* playerAttackingLeft[NB_FRAME_PLAYER_ATTACKING]; 		  /*!< Textures liées à l'image du Joueur attaquant. */

  //Croco Mob.//
  SDL_Texture* crocoMovingLeft[NB_FRAME_CROCO_MOVING];              /*!< Textures liées à l'image du mob croco marchant. */
  SDL_Texture* crocoMovingRight[NB_FRAME_CROCO_MOVING];             /*!< Textures liées à l'image du mob croco marchant. */

  //Dino Mob.//
  SDL_Texture* dinoMovingLeft[NB_FRAME_DINO_MOVING];              /*!< Textures liées à l'image du mob dino marchant. */
  SDL_Texture* dinoMovingRight[NB_FRAME_DINO_MOVING];             /*!< Textures liées à l'image du mob dino marchant. */
  SDL_Texture* dinoDead[NB_FRAME_DINO_DEAD];                      /*!< Textures liées à l'image du mob dino meurt. */

  //Plateformes.//
  SDL_Texture* platform[NB_PLATFORMS_FRAMES];                     /*!< Textures des plateformes.*/

  //Labels.//
  SDL_Texture* labelPlay[2];      /*!< Texture liée au bouton Play. */
  SDL_Texture* labelHelp[2];      /*!< Texture liée au bouton Help. */
  SDL_Texture* labelScore[2];     /*!< Texture liée au bouton Score. */
  SDL_Texture* labelExit[2];      /*!< Texture liée au bouton Exit. */
  SDL_Texture* labelBack[2];      /*!< Texture liée au bouton Back. */
  SDL_Texture* labelNo[2];        /*!< Texture liée au bouton No. */
  SDL_Texture* labelYes[2];       /*!< Texture liée au bouton Yes. */

  //Help Menu.//
  SDL_Texture* arrows;            /*!< Texture de l'image de flèches pour le menu "Help" */
  SDL_Texture* spacebar;          /*!< Texture de l'image de barre espace pour le menu "Help" */

  //Musique.//
  Mix_Music* menuMusic;           /*!< Musique du menu. */
  Mix_Music* bossMusic;           /*!< Musique du boss.*/
  Mix_Music* levelMusic;          /*!< Musique des niveau.*/

  //Son.//
  Mix_Chunk* death;               /*!< Son de la mort du joueur.*/
  Mix_Chunk* walk;                /*!< Son de la marche du joueur.*/
  Mix_Chunk* swing;               /*!< Son de l'attaque du joueur.*/
  Mix_Chunk* label;               /*!< Son du hovering d'un label dans les menus.*/
  Mix_Chunk* click;               /*!< Son de la selection d'un label dans les menus.*/
  Mix_Chunk* hit;                 /*!< Son de la reception d'un coup sur un mob.*/
  Mix_Chunk* getHit;              /*!< Son du portage d'un coup du Player sur un mob.*/
  Mix_Chunk* jump;                /*!< Son du saut du joueur.*/

} ressources_t , *ressources_p; /*!< Pointeur vers les ressources. */



//---------------------------------------------------------//
 /**
  * \brief La fonction charge les ressources du jeu.
  * \param renderer Le renderer.
  * \param ressources Structure des ressources.
  */
void loadRessources(SDL_Renderer *renderer, ressources_p ressources);

//---------------------------------------------------------//
/**
 * \brief La fonction nettoie les textures du joueur.
 * \param ressources Structure des ressources.
 */
void cleanPlayerTexture(ressources_p ressources);

//---------------------------------------------------------//
 /**
 * \brief La fonction nettoie les textures de background.
 * \param ressources Structure des ressources.
 */
void cleanBackgroundTextures(ressources_p ressources);

//---------------------------------------------------------//
/**
* \brief La fonction nettoie les textures de background.
* \param ressources Structure des ressources.
*/
void cleanLabelTextures(ressources_p ressources);

//---------------------------------------------------------//
/**
 * \brief La fonction nettoie les textures.
 * \param ressources Structure des ressources.
 */
void cleanRessources(ressources_p ressources);



#endif
