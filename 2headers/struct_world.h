/**
 * \file struct_world.h
 * \brief Fichier contenant les getters et définitions des Structures du jeu.
 * \author Marcelin Maxime/ Tysoun Phillip /Signorino-Gelo Matteo
 * \version 1.0.
 * \date 12 octobre 2021
 */

#ifndef STRUCT_WORLD_H
#define STRUCT_WORLD_H

#include "struct_sprite.h"
#include "struct_level.h"
#include "struct_list.h"

#include "constantes.h"


//------------------------------------------WORLD-------------------------------------------------------//
/**
 * \brief Représentation du monde du jeu.
 */
typedef struct world_s{

  //UTILITY.//
 	int gameover;       /*!< Booléen indiquant si le jeu est terminé. */
  char currentState;  /*!< Chaîne de char indiquant l'état du jeu : Menu/Jeu. */
  int gravity;        /*!< Entier indiquant la constante de gravité. */
  int earthLevel;     /*!< Entier indiquant la hauteur du sol. */

  //PLAYER.//
  sprite_t player;    /*!< sprite_t correspondant au joueur. */

  //LEVELS.//
  liste_p levels;            /*!< Liste contenant les informations sur les niveaux.*/
  int currentLevel;          /*!< Entier indiquant le niveau en cours d'exécution.*/

  //MENUS.//
  sprite_t labels[7];        /*!< Tableau de Sprites qui seront utilisées pour afficher les labels dans le choix de menu.*/
  sprite_t frames[2];        /*!< Tableu de Sprites contenant les informations des Frames. */
  int currentMenu;           /*!< Entier indiquant l'indice du menu en cours d'affichage.*/


} world_t , *world_p; /*!< Pointeur vers le monde. */

//------------------------------------------CHAMP EARTHLEVEL-------------------------------------------------------//
/**
 * \brief Fonction permettant de consulter l'état du champ world.earthLevel.
 * \param world Pointeur vers le monde.
 * \return int Etat du champ earthLevel.
 */
int getEarthLevel(world_p world);

/**
  * \brief Fonction permettant de modifier l'état du champ world.earthLevel.
  * \param world Pointeur vers le monde.
  * \param earthLevel Etat du champ earthLevel désiré.
 */
void setEarthLevel(world_p world, int earthLevel);

//------------------------------------------CHAMP LEVELS-------------------------------------------------------//
/**
 * \brief Fonction permettant de consulter l'état du champ world.levels.
 * \param world Pointeur vers le monde.
 * \return liste_p Etat du champ levels.
 */
liste_p getLevels(world_p world);

/**
  * \brief Fonction permettant de modifier l'état du champ world.levels.
  * \param world Pointeur vers le monde.
  * \param levels Etat du champ levels désiré.
 */
void setLevels(world_p world, liste_p levels);

//------------------------------------------CHAMP GRAVITY-------------------------------------------------------//
/**
 * \brief Fonction permettant de consulter l'état du champ world.gravity.
 * \param world Pointeur vers le monde.
 * \return int Etat du champ gravity.
 */
int getGravity(world_p world);

/**
  * \brief Fonction permettant de modifier l'état du champ world.gravity.
  * \param world Pointeur vers le monde.
  * \param g Etat du champ gravity désiré.
 */
void setGravity(world_p world, int g);

//------------------------------------------CHAMP GAMEOVER-------------------------------------------------------//
/**
 * \brief Fonction permettant de consulter l'état du champ world.gameover.
 * \param world Pointeur vers le monde.
 * \return int Etat du champ gameover.
 */
int isGameOver(world_p world);

/**
  * \brief Fonction permettant de modifier l'état du champ world.gameover.
  * \param world Pointeur vers le monde.
  * \param b Etat du champ gameover désiré.
 */
void setGameOver(world_p world, int b);

//------------------------------------------CHAMP PLAYER-------------------------------------------------------//
/**
 * \brief Fonction permettant de consulter l'état du champ world.player.
 * \param world Pointeur vers le monde.
 * \return sprite_t Champ world.player.
 */
sprite_p getPlayer(world_p world);

/**
 * \brief Fonction permettant de modifier le champ world.player.
 * \param world Pointeur vers le monde.
 * \param player Etat du champ player désiré.
 */
void setPlayer(world_p world, sprite_t player);

//------------------------------------------CHAMP CURRENTSTATE-------------------------------------------------------//
/**
 * \brief Fonction permettant de consulter l'état du champ world.currentState.
 * \param world Pointeur vers le monde.
 * \return char* Etat du champ gameover.
 */
char getCurrentState(world_p world);

/**
  * \brief Fonction permettant de modifier l'état du champ world.currentState.
  * \param world Pointeur vers le monde.
  * \param currentState Etat du champ currentState.
 */
void setCurrentState(world_p world, char currentState);

//------------------------------------------CHAMP CURRENTSTATE-------------------------------------------------------//
/**
 * \brief Fonction permettant de consulter l'état du champ world.currentLevel.
 * \param world Pointeur vers le monde.
 * \return char* Etat du champ gameover.
 */
char getCurrentLevel(world_p world);

/**
  * \brief Fonction permettant de modifier l'état du champ world.currentLevel.
  * \param world Pointeur vers le monde.
  * \param currentLevel Etat du champ currentLevel.
 */
void setCurrentLevel(world_p world, char currentLevel);

//------------------------------------------CHAMP LABELS-------------------------------------------------------//
/**
 * \brief Fonction permettant de consulter l'état du champ currentState.
 * \param world Pointeur vers le monde.
 * \param indiceLabel Indice du label pour trouver le Sprite dans le tableau stocké.
 * \return sprite_p Sprite du label.
 */
sprite_p getLabels(world_p world, int indiceLabel);

/**
  * \brief Fonction permettant de modifier l'état du champ world.lsabel.
  * \param world Pointeur vers le monde.
  * \param indiceLabel Indice du label pour trouver le Sprite dans le tableau stocké.
  * \param label Sprite du label.
 */
void setLabels(world_p world, int indiceLabel, sprite_p label);

//------------------------------------------CHAMP CURRENTMENU-------------------------------------------------------//
/**
 * \brief Fonction permettant de consulter l'état du champ currentMenu.
 * \param world Pointeur vers le monde.
 * \return char Etat du champ currentMenu.
 */
int getCurrentMenu(world_p world);

/**
  * \brief Fonction permettant de modifier l'état du champ world.currentMenu.
  * \param world Pointeur vers le monde.
  * \param currentMenu Etat du champ currentMenu désiré.
 */
void setCurrentMenu(world_p world, int currentMenu);

/**
 * \brief Fonction permettant de consulter l'état du champ frames.
 * \param world Pointeur vers le monde.
 * \param indiceFrame Indice de la frame pour trouver le Sprite dans le tableau stocké.
 * \return sprite_p Sprite de la frame.
 */
sprite_p getFrames(world_p world, int indiceFrame);
/**
  * \brief Fonction permettant de modifier l'état du champ world.frames.
  * \param world Pointeur vers le monde.
  * \param indiceFrame Indice du label pour trouver le Sprite dans le tableau stocké.
  * \param frame Sprite de la frame.
 */
void setFrames(world_p world, int indiceFrame, sprite_p frame);


#endif
