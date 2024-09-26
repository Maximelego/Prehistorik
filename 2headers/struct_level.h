#ifndef STRUCT_LEVEL_H
#define STRUCT_LEVEL_H


/**
 * \file struct_level.h
 * \brief Header contenant les définitions des fonctions permettant de gèrer les niveaux du jeu.
 * \author Marcelin Maxime/ Tysoun Phillip /Signorino-Gelo Matteo
 * \version 1.0.
 * \date 17 décembre 2021
 */

#include "struct_sprite.h"
#include "constantes.h"
#include <stdbool.h>


//------------------------------------------LEVEL-------------------------------------------------------//
/**
  * \brief Représentation des niveaux du jeu.
  */
typedef struct level_s{
  int levelNumber;                            /*!< Entier indiquant le numéro du niveau. */

  sprite_t platforms[NB_PLATFORMS_MAX];       /*!< Tableau contenant les Sprites des Plateformes. */
  int nbPlatforms;                            /*!< Entier indiquant le nombre de plate-formes du niveau. */

  sprite_t endLevelLine;                      /*!< Sprite indiquant la fin du niveau. */

  sprite_t mobs[NB_MOBS_MAX];                 /*!< Tableau contenant les Sprites des mobs. */
  int nbMobs;                                 /*!< Entier indiquant le nombre de Mobs du niveau. */

  int score;                                  /*!< Score du joueur.*/
  int timePassed;                             /*!< Temps passé par le joueur dans le niveau. */

} level_t , *level_p; /*!< Pointeur vers le niveau. */

/**
 * \brief Fonction permettant de paramètrer un niveau.
 * \param level Pointeur vers le niveau à paramètrer.
 * \param file Pointeur vers le file à utiliser.
 * \return 0 en cas d'execution réussi, 1 en cas d'errerur de parsing.
 */
int buildLevel(level_p level, FILE* file);

/**
 * \brief Fonction permettant de reconnaitre le numéro du niveau du fichier.
 * \param level Pointeur vers le niveau à paramètrer.
* \param file Le fichier à parser.
 * \return 0 en cas de fonctionnement normal et 1 en cas d'erreur
 */
int parseLevelNumber(level_p level, FILE* file);

/**
 * \brief Fonction permettant de reconnaitre les différents éléments et dispositions du niveau du fichier.
 * \param level Pointeur vers le niveau à paramètrer.
 * \param file Fichier à analyser.
 * \return 0 en cas de fonctionnement normal et 1 en cas d'erreur
 */
int parseLevelForm(level_p level, FILE *file);

/**
 * \brief Fonction permettant de voir les informations d'un niveau.
 * \param level Pointeur vers le niveau à observer.
 */
void getLevelInfo(level_p level);

/**
 * \brief Fonction permettant de retouner le numéro du niveau.
 * \param level Pointeur vers le niveau à observer.
 * \return Numéro du niveau.
 */
int getLevelNumber(level_p level);

/**
 * \brief Fonction permettant de copier les informations d'un niveau à un autre.
 * \param level Pointeur vers le niveau à copier.
 * \return Pointeur vers la copie du niveau.
 */
level_p copyLevel(level_p level);

#endif
