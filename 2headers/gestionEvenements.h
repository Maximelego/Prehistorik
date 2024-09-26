/**
 * \file gestionEvenements.h
 * \brief Header contenant les profils des fonctions nécessaire à la gestion des évènements.
 * \author Marcelin Maxime/ Tysoun Phillip /Signorino-Gelo Matteo
 * \version 1.0
 * \date 2 décembre 2021
 */

#ifndef GESTION_EVENEMENTS_H
#define GESTION_EVENEMENTS_H

#include "constantes.h"
#include "sdl2-light.h"
#include "struct_world.h"

//#################################-----FONCTIONS ET PROCEDURES-----#################################//
/**
 * \brief La fonction gère les évènements ayant eu lieu et qui n'ont pas encore été traités.
 * \param event Paramètre qui contient les événements
 * \param world Les données du monde.
 * \param ressources Structure des ressources
 */
void handleEvents(SDL_Event *event, world_p world, ressources_p ressources);

/**
 * \brief La fonction gère la signalisation au jeu de la fermeture.
 * \param world Les données du monde.
 */
void handleExit(world_p world);

/**
 * \brief La fonction gère les actions à prendre lors d'un menu.
 * \param world Les données du monde.
 * \param event Paramètre qui contient les événements
 * \param ressources Structure des ressources
 */
void handleMenuEvents(world_p world, SDL_Event *event, ressources_p ressources);

/**
 * \brief La fonction gère les actions à prendre lors d'un menu pause.
 * \param world Les données du monde.
 * \param event Paramètre qui contient les événements
 * \param ressources Structure des ressources
 */
void handlePauseEvents(world_p world, SDL_Event *event, ressources_p ressources);

/**
 * \brief La fonction gère les actions à prendre lors d'un niveau.
 * \param world Les données du monde.
 * \param event Paramètre qui contient les événements
 * \param ressources Structure des ressources
 */
void handleLevelEvents(world_p world, SDL_Event *event, ressources_p ressources);

/**
 * \brief La fonction gère les actions à prendre lors de non-appui sur une touche.
 * \param world Les données du monde.
 */
void handleNoneEvent(world_p world);

/**
 * \brief La fonction gère les attaques du joueur.
 * \param world Les données du monde.
 * \param ressources Structure des ressources
 */
void handleAttack(world_p world, ressources_p ressources);

/**
 * \brief La fonction gère les sauts du joueur.
 * \param world Les données du monde.
 * \param ressources Structure des ressources
 */
void handleUpMove(world_p world, ressources_p ressources);

/**
 * \brief La fonction gère les déplacements à gauche du joueur.
 * \param world Les données du monde.
 * \param ressources Structure des ressources
 */
void handleLeftMove(world_p world, ressources_p ressources);

/**
 * \brief La fonction gère les déplacements à droite du joueur.
 * \param world Les données du monde.
 * \param ressources Structure des ressources
 */
void handleRightMove(world_p world, ressources_p ressources);


#endif
