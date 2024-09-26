/**
 * \file gestionDonnees.h
 * \brief header contenant les modifieurs et définitions du gestionnaire de jeu.
 * \author Marcelin Maxime/ Tysoun Phillip /Signorino-Gelo Matteo
 * \version 1.0.
 * \date 20 octobre 2021
 */


#ifndef GESTIONDONNEES_H
#define GESTIONDONNEES_H

#include "struct_world.h"


//---------------------------------------------------------//
/**
 * \brief La fonction initialise les données du monde.
 * \param world Le monde.
 */
void initWorldData(world_p world);

//---------------------------------------------------------//
/**
 * \brief La fonction initialise les niveaux du jeu.
 * \param world Le monde.
 */
void initLevels(world_p world);


//---------------------------------------------------------//
/**
 * \brief La fonction initialise les menus du jeu.
 * \param world Le monde.
 */
void initMenu(world_p world);

//---------------------------------------------------------//
/**
 * \brief La fonction initialise les données du joueur.
 * \param world Le monde.
 */
void initSpritePlayer(world_p world);

//---------------------------------------------------------//
/**
 * \brief La fonction mets à jour le sprite pour le soumettre à la gravité
 * \param world Le monde.
 * \param sprite Le sprite à actualiser.
 */
void gravity(world_p world, sprite_p sprite);

//---------------------------------------------------------//
/**
 * \brief La fonction met à jour la hauteur du sprite en fonction de sa vitesse en y.
 * \param sprite Le joueur.
 * \param world Le monde.
 */
void updateY(world_p world, sprite_p sprite);

//---------------------------------------------------------//
/**
 * \brief La fonction met à jour la position x du sprite en fonction de sa vitesse en x.
 * \param sprite Le joueur.
 */
void updateX(sprite_p sprite);

//---------------------------------------------------------//
/**
 * \brief La fonction met à jour tous les sprite pour actualiser le déplacement horizontal.
 * \param world Le monde.
 */
void handleVX(world_p world);

/**
 * \brief La fonction met à jour tous les sprites pour actualiser le déplacement vertical.
 * \param world Le monde.
 */
void handleVY(world_p world);

//---------------------------------------------------------//
/**
 * \brief La fonction met à jour les données des différents Sprites pour effectuer les animations de déplacement, immobilisation, saut et attaque.
 * \param world Le monde.
 * \param sprite les sprites.
 */
void handlePlayerAnimation(world_p world, sprite_p sprite);

//---------------------------------------------------------//
/**
 * \brief La fonction permet d'éviter au joueur de sortir de l'écran.
 * \param world Le monde.
 */
void handleBorder(world_p world);

//---------------------------------------------------------//
/**
 * \brief La fonction met à jour les données du monde à chaque rafraîchissement.
 * \param world Le monde.
 */
void updateData(world_p world);

//---------------------------------------------------------//
/**
 * \brief La fonction permet de savoir si une coordonnée (x,y) se situe dans la hitbox d'un sprite.
 * \param sprite Le sprite à déplacer.
 * \param x Abscisse.
 * \param y Ordonnée.
 */
int isInHitbox(sprite_p sprite, int x, int y);

//---------------------------------------------------------//
/**
 * \brief La fonction déplace le sprite à Droite
 * \param world Le monde.
 * \param sprite Le sprite à deplacer.
 */
void moveRightSprite(world_p world, sprite_p sprite);

//---------------------------------------------------------//
/**
 * \brief La fonction déplace le sprite à gauche
 * \param world Le monde.
 * \param sprite Le sprite à deplacer.
 */
void moveLeftSprite(world_p world, sprite_p sprite);

//---------------------------------------------------------//
 /**
  * \brief La fonction nettoie les données du monde.
  * \param world Le monde.
  */
void cleanWorldData(world_p world);

#endif
