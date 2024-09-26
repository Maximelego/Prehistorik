/**
 * \file struct_world.c
 * \brief Fichier contenant les getters et définitions des Structures du jeu.
 * \author Marcelin Maxime/ Tysoun Phillip /Signorino-Gelo Matteo
 * \version 1.0.
 * \date 12 octobre 2021
 */

 #include <stdio.h>
 #include <stdlib.h>

 #include "struct_sprite.h"
 #include "struct_world.h"
 #include "struct_level.h"
 #include "struct_list.h"

 #include "constantes.h"

 //------------------------------------------CHAMP GRAVITY-------------------------------------------------------//
 /**
  * \brief Fonction permettant de consulter l'état du champ world.gravity.
  * \param world Pointeur vers le monde.
  * \return int Etat du champ gravity.
  */
 int getGravity(world_p world){
   if(DEV_MODE){printf("Appel de <gravity()>.\n");}
   return(world->gravity);
 }

 /**
   * \brief Fonction permettant de modifier l'état du champ world.gravity.
   * \param world Pointeur vers le monde.
   * \param g Etat du champ gravity désiré.
  */
 void setGravity(world_p world, int g){
   if(DEV_MODE){printf("Appel de <setGravity()>.\n");}
   world->gravity = g;
 }

 //------------------------------------------CHAMP LEVELS-------------------------------------------------------//
 /**
  * \brief Fonction permettant de consulter l'état du champ world.levels.
  * \param world Pointeur vers le monde.
  * \return liste_p Etat du champ levels.
  */
 liste_p getLevels(world_p world){
   if(DEV_MODE){printf("Appel de <getLevels()>.\n");}
   return(world->levels);
 }

 /**
   * \brief Fonction permettant de modifier l'état du champ world.levels.
   * \param world Pointeur vers le monde.
   * \param levels Etat du champ levels désiré.
  */
 void setLevels(world_p world, liste_p levels){
   if(DEV_MODE){printf("Appel de <setLevels()>.\n");}
   world->levels = levels;
 }


 //------------------------------------------CHAMP EARTHLEVEL-------------------------------------------------------//
 /**
  * \brief Fonction permettant de consulter l'état du champ world.earthLevel.
  * \param world Pointeur vers le monde.
  * \return int Etat du champ earthLevel.
  */
 int getEarthLevel(world_p world){
   if(DEV_MODE){printf("Appel de <getEarthLevel()>.\n");}
   return(world->earthLevel);
 }

 /**
   * \brief Fonction permettant de modifier l'état du champ world.earthLevel.
   * \param world Pointeur vers le monde.
   * \param earthLevel Etat du champ earthLevel désiré.
  */
 void setEarthLevel(world_p world, int earthLevel){
   if(DEV_MODE){printf("Appel de <setEarthLevel()>.\n");}
   world->earthLevel = earthLevel;
 }

//------------------------------------------CHAMP GAMEOVER-------------------------------------------------------//

/**
 * \brief Fonction permettant de consulter l'état du champ world.gameover.
 * \param world Pointeur vers le monde.
 * \return int Etat du champ gameover.
 */

int isGameOver(world_p world){
  if(DEV_MODE){printf("Appel de <isGameOver()>.\n");}
  return(world->gameover);
}

/**
 * \brief Fonction permettant de modifier l'état du champ world.gameover.
 * \param world Pointeur vers le monde.
 * \param b Etat du champ gameover désiré.
 */
void setGameOver(world_p world, int b){
  if(DEV_MODE){printf("Appel de <setGameOver()>.\n");}
  world->gameover = b;
}

//------------------------------------------CHAMP PLAYER-------------------------------------------------------//

/**
 * \brief Fonction permettant de consulter l'état du champ world.player.
 * \param world Pointeur vers le monde.
 * \return sprite_t Champ world.player.
 */

sprite_p getPlayer(world_p world){
  if(DEV_MODE){printf("Appel de <getPlayer()>.\n");}
  return &world->player;
}

/**
 * \brief Fonction permettant de modifier le champ world.player.
 * \param world Pointeur vers le monde.
 * \param player Etat du champ player désiré.
 */
void setPlayer(world_p world, sprite_t player){
  if(DEV_MODE){printf("Appel de <setPlayer()>.\n");}
  world->player = player;
}


//------------------------------------------CHAMP CURRENTSTATE-------------------------------------------------------//

/**
 * \brief Fonction permettant de consulter l'état du champ world.currentState.
 * \param world Pointeur vers le monde.
 * \return char* Etat du champ gameover.
 */
char getCurrentState(world_p world){
  if(DEV_MODE){printf("Appel de <getCurrentState()>.\n");}
  return world->currentState;
}

/**
  * \brief Fonction permettant de modifier l'état du champ world.currentState.
  * \param world Pointeur vers le monde.
  * \param currentState Etat du champ currentState.
 */
void setCurrentState(world_p world, char currentState){
  if(DEV_MODE){printf("Appel de <setCurrentState()>.\n");}
  world->currentState = currentState;
}

//------------------------------------------CHAMP CURRENTLEVEL-------------------------------------------------------//

/**
 * \brief Fonction permettant de consulter l'état du champ world.currentLevel.
 * \param world Pointeur vers le monde.
 * \return char* Etat du champ gameover.
 */
char getCurrentLevel(world_p world){
  if(DEV_MODE){printf("Appel de <getCurrentLevel()>.\n");}
  return world->currentLevel;
}

/**
  * \brief Fonction permettant de modifier l'état du champ world.currentLevel.
  * \param world Pointeur vers le monde.
  * \param currentLevel Etat du champ currentLevel.
 */
void setCurrentLevel(world_p world, char currentLevel){
  if(DEV_MODE){printf("Appel de <setCurrentLevel()>.\n");}
  world->currentLevel = currentLevel;
}

//------------------------------------------CHAMP CURRENTMENU-------------------------------------------------------//

/**
 * \brief Fonction permettant de consulter l'état du champ currentMenu.
 * \param world Pointeur vers le monde.
 * \return char Etat du champ currentMenu.
 */
int getCurrentMenu(world_p world){
  if(DEV_MODE){printf("Appel de <getCurrentMenu()>.\n");}
  return world->currentMenu;
}

/**
  * \brief Fonction permettant de modifier l'état du champ world.currentMenu.
  * \param world Pointeur vers le monde.
  * \param currentMenu Etat du champ currentMenu désiré.
 */
void setCurrentMenu(world_p world, int currentMenu){
  if(DEV_MODE){printf("Appel de <setCurrentMenu()>.\n");}
  world->currentMenu = currentMenu;
}

//------------------------------------------CHAMP LABELS-------------------------------------------------------//

/**
 * \brief Fonction permettant de consulter l'état du champ currentState.
 * \param world Pointeur vers le monde.
 * \param indiceLabel Indice du label pour trouver le Sprite dans le tableau stocké.
 * \return sprite_p Sprite du label.
 */
sprite_p getLabels(world_p world, int indiceLabel){
  if(DEV_MODE){printf("Appel de <getLabel()>.\n");}
  return &world->labels[indiceLabel];
}

/**
  * \brief Fonction permettant de modifier l'état du champ world.lsabel.
  * \param world Pointeur vers le monde.
  * \param indiceLabel Indice du label pour trouver le Sprite dans le tableau stocké.
  * \param label Sprite du label.
 */
void setLabels(world_p world, int indiceLabel, sprite_p label){
  if(DEV_MODE){printf("Appel de <setLabel()>.\n");}
  world->labels[indiceLabel] = *label;
}


//------------------------------------------CHAMP FRAMES-------------------------------------------------------//

/**
 * \brief Fonction permettant de consulter l'état du champ frames.
 * \param world Pointeur vers le monde.
 * \param indiceFrame Indice de la frame pour trouver le Sprite dans le tableau stocké.
 * \return sprite_p Sprite de la frame.
 */
sprite_p getFrames(world_p world, int indiceFrame){
  if(DEV_MODE){printf("Appel de <getFrames()>.\n");}
  return &world->frames[indiceFrame];
}

/**
  * \brief Fonction permettant de modifier l'état du champ world.frames.
  * \param world Pointeur vers le monde.
  * \param indiceFrame Indice du label pour trouver le Sprite dans le tableau stocké.
  * \param frame Sprite de la frame.
 */
void setFrames(world_p world, int indiceFrame, sprite_p frame){
  if(DEV_MODE){printf("Appel de <setFrames()>.\n");}
  world->frames[indiceFrame] = *frame;
}
