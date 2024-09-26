/**
 * \file constantes.h
 * \brief Header contenant les constantes pré-processeur nécessaires au fonctionnement du jeu.
 * \author Marcelin Maxime/ Tysoun Phillip /Signorino-Gelo Matteo
 * \version 1.0.
 * \date 12 octobre 2021
 */


#ifndef CONSTANTES_H
#define CONSTANTES_H


//----------CONSTANTES PRE-PROCESSEUR-----------//

//---------------------------------------------------------//
/**
  * \brief Valeur permettant d'afficher des informations supplémentaires lors de l'éxecution du programme. (par Défaut à 0).
  */
#define DEV_MODE 0

//---------------------------------------------------------//
/**
  * \brief Valeur permettant de jouer ou non la musique. (défaut à 1)
  */
#define PLAY_MUSIC 1

//---------------------------------------------------------//
/**
  * \brief Valeur permettant de jouer ou non les sons. (défaut à 1)
  */
#define PLAY_SOUNDS 0

//---------------------------------------------------------//
/**
  * \brief Valeur permettant de régler le volume. (défaut à 20)
  */
#define VOLUME 0

//---------------------------------------------------------//
/**
  * \brief Valeur permettant de rendre le joueur invincible à tout type de dégâts (par Défaut à 0).
  */
#define GOD_MODE 0

//---------------------------------------------------------//
/**
  * \brief Valeur déterminant la hauteur de la fenêtre (par Défaut à 720).
  */
#define HEIGHT 480

//---------------------------------------------------------//
/**
  * \brief Valeur déterminant la largeur de la fenêtre (par Défaut à 1280).
  */
#define WIDTH 854

//---------------------------------------------------------//
/**
  * \brief Valeur déterminant le nombre maximum de plateformes par niveaux (par Défaut à 100).
  */
#define NB_PLATFORMS_MAX 100

//---------------------------------------------------------//
/**
  * \brief Valeur déterminant le nombre maximum de mobs par niveaux (par Défaut à 100).
  */
#define NB_MOBS_MAX 100

//---------------------------------------------------------//
/**
  * \brief Valeur déterminant la taille d'une colonne. (par Défaut à 100).
  */
#define COLUMN_SIZE 100

//---------------------------------------------------------//
/**
  * \brief Valeur déterminant la taille d'une couche. (par Défaut à 100).
  */
#define LAYER_SIZE 100

//---------------------------------------------------------//
/**
  * \brief Valeur déterminant le nombre maximum de niveaux (par Défaut à 4).
  */
#define NB_LEVEL 4

//---------------------------------------------------------//
/**
  * \brief Valeur déterminant le nombre de pixel de déplacement pour les sprites (par Défaut à 8).
  */
#define PAS_DEPLACEMENT 8

//---------------------------------------------------------//
/**
  * \brief Valeur déterminant la taille de police d'écriture du titre du jeu (par Défaut à 40).
  */
#define TITLE_FONT_SIZE 40

//---------------------------------------------------------//
/**
  * \brief Valeur permettant de définir les identifiants de l'état du jeu (Ici lorsque le jeu affiche un menu). (par Défaut 'M').
  */
#define MENU_STATE 'M'

//---------------------------------------------------------//
/**
  * \brief Valeur permettant de définir les identifiants de l'état du jeu (Ici lorsque le jeu affiche un niveau). (par Défaut 'L').
  */
#define LEVEL_STATE 'L'

//---------------------------------------------------------//
/**
  * \brief Valeur permettant de définir les identifiants de l'état du jeu (Ici lorsque le jeu affiche le menu de pause). (par Défaut 'B').
  */
#define PAUSE_STATE 'P'

//---------------------------------------------------------//
/**
  * \brief Valeur permettant de définir les identifiants de l'état du jeu (Ici lorsque le jeu affiche le menu de mort). (par Défaut 'D').
  */
#define DEATH_STATE 'D'

//---------------------------------------------------------//
/**
  * \brief Valeur permettant de définir les identifiants de la direction à laquelle le sprite fait face (ici, la droite). (par Défaut 'R').
  */
#define FACING_RIGHT 'R'

//---------------------------------------------------------//
/**
  * \brief Valeur permettant de définir les identifiants de la direction à laquelle le sprite fait face (ici, la gauche). (par Défaut 'L').
  */
#define FACING_LEFT 'L'

//---------------------------------------------------------//
/**
  * \brief Valeur permettant de définir le nombre de frames pour les plate-formes (par Défaut à 5).
  */
#define NB_PLATFORMS_FRAMES 5

//---------------------------------------------------------//
/**
  * \brief Valeur permettant de définir le nombre de frames pour le player lorsqu'il reste immobile. (par Défaut à 2).
  */
#define NB_FRAME_PLAYER_STANDING 2

//---------------------------------------------------------//
/**
  * \brief Valeur permettant de définir le nombre de frames pour le player lorsqu'il bouge. (par Défaut à 6).
  */
#define NB_FRAME_PLAYER_MOVING 6

//---------------------------------------------------------//
/**
  * \brief Valeur permettant de définir le nombre de frames pour le player lorsqu'il saute. (par Défaut à 5).
  */
#define NB_FRAME_PLAYER_JUMPING 5

//---------------------------------------------------------//
/**
  * \brief Valeur permettant de définir le nombre de frames pour le player lorsqu'il attaque . (par Défaut à 6).
  */
#define NB_FRAME_PLAYER_ATTACKING 6

//---------------------------------------------------------//
/**
  * \brief Valeur permettant de définir le nombre de frames disponibles pour le background (Ici lorsque le jeu affiche un niveau). (par Défaut à 4).
  */
#define NB_FRAME_BACKGROUND 4

//---------------------------------------------------------//
/**
  * \brief Valeur permettant de définir le nombre de frames pour le mob croco lorsqu'il bouge. (par Défaut à 3).
  */
#define NB_FRAME_CROCO_MOVING 3

//---------------------------------------------------------//
/**
  * \brief Valeur permettant de définir le nombre de frames pour le mob dino lorsqu'il bouge. (par Défaut à 4).
  */
#define NB_FRAME_DINO_MOVING 4

//---------------------------------------------------------//
/**
  * \brief Valeur permettant de définir le nombre de frames pour le mob dino lorsqu'il meurt. (par Défaut à 1).
  */
#define NB_FRAME_DINO_DEAD 1

//---------------------------------------------------------//
/**
  * \brief Valeur permettant de définir la vitesse d'attraction du sprite vers le sol (Par Défaut à 4).
  */
#define GRAVITY 4

//---------------------------------------------------------//
/**
  * \brief Valeur permettant de définir la hauteur du sol (Par Défaut à 596).
  */
#define EARTH_LEVEL 596

//---------------------------------------------------------//
/**
  * \brief Valeur permettant de définir le temps séparant 2 frames lors d'une animation. (Par Défaut à 100)
  */
#define ANIMATION_TIMERATE 100

//---------------------------------------------------------//
/**
  * \brief Valeur permettant de définir le nombre de colonne maximal par niveau (Par défaut à 100).
  */
#define MAX_LEVEL_SIZE 100

//---------------------------------------------------------//
/**
  * \brief Valeur permettant de définir le nombre de maximal de charactères pour le nom d'un fichie.level (sans compter l'extension) (Par défaut à 100).
  */
#define MAX_LEVEL_NAME_SIZE 100


#endif
