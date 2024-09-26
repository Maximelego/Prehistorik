#ifndef STRUCT_LIST_H
#define STRUCT_LIST_H

/**
 * \file struct_list.h
 * \brief Header contenant les profils fonctions permettant de gèrer les listes.
 * \author Marcelin Maxime/ Tysoun Phillip /Signorino-Gelo Matteo
 * \version 1.0.
 * \date 31 décembre 2021
 */



 #include <stdio.h>
 #include <stdlib.h>

 //------------------------------------------LIST-------------------------------------------------------//
 /**
   * \brief Représentation mémoire des niveaux du jeu.
   */

typedef struct liste_s{
  level_t level;                /*!< Niveau stocké. */
  struct liste_s *next ;        /*!< Pointeur vers la liste contenant le niveau suivant */
  struct liste_s *previous;     /*!< Pointeur vers la liste contenant le niveau précédent. */

}liste_t, *liste_p; /*!< Pointeur vers la liste */


//------------------------------------------CONSEMPTY-------------------------------------------------------//
/**
  * \brief Fonction retournant une liste vide.
  * \return Pointeur vers une liste.
  */

liste_p consEmpty();

//------------------------------------------CONS-------------------------------------------------------//
/**
  * \brief Fonction retournant une liste construite avec le niveau donné en paramètre.
  * \param previous Pointeur vers une liste.
  * \param next Pointeur vers une liste.
  * \param level Pointeur vers un niveau.
  * \return Pointeur vers une liste.
  */

liste_p cons(liste_p previous, liste_p next, level_p level);

//------------------------------------------ISEMPTY-------------------------------------------------------//
/**
  * \brief Fonction retournant un booléen permettant de déduire si la liste est vide.
  * \param liste Pointeur vers une liste.
  * \return Entier considéré comme un booléen.
  */

int isEmpty(liste_p liste);


//------------------------------------------GETHEAD-------------------------------------------------------//
/**
  * \brief Fonction retournant un pointeur vers le level contenu dans la liste.
  * \param liste Pointeur vers une liste.
  * \return Pointeur vers le level contenu.
  */

level_p getHead(liste_p liste);

//------------------------------------------GETNEXT-------------------------------------------------------//
/**
  * \brief Fonction retournant un pointeur vers la liste suivante.
  * \param liste Pointeur vers une liste.
  * \return Pointeur vers la liste suivante.
  */

liste_p getNext(liste_p liste);

//------------------------------------------GETPREVIOUS-------------------------------------------------------//
/**
  * \brief Fonction retournant un pointeur vers la liste précédente.
  * \param liste Pointeur vers une liste.
  * \return Pointeur vers la liste suivante.
  */

liste_p getPrevious(liste_p liste);

//------------------------------------------SETHEAD-------------------------------------------------------//
/**
  * \brief Fonction modifiant la tête de la liste.
  * \param liste Pointeur vers une liste.
  * \param level Pointeur vers un niveau.
  */

void setHead(liste_p liste, level_p level);

//------------------------------------------SETNEXT-------------------------------------------------------//
/**
  * \brief Fonction modifiant la liste pointée par next().
  * \param liste Pointeur vers une liste.
  * \param next Pointeur vers une liste.
  */
void setNext(liste_p liste, liste_p next);

//------------------------------------------SETPREVIOUS-------------------------------------------------------//
/**
  * \brief Fonction modifiant la liste pointée par getPrevious().
  * \param liste Pointeur vers une liste.
  * \param previous Pointeur vers une liste.
  */
void setPrevious(liste_p liste, liste_p previous);


//------------------------------------------INSERTLEVEL-------------------------------------------------------//
/**
  * \brief Fonction permettant de correctement insèrer un niveau dans la liste des niveaux.
  * \param liste Pointeur vers une liste.
  * \param level Pointeur vers un level.
  * \return 0 si l'insertion a réussi, 1 sinon.
  */

int insertLevel(liste_p* liste, level_t level);

//------------------------------------------FREELIST-------------------------------------------------------//
/**
  * \brief Fonction permettant de libèrer la mémoire allouée à la liste.
  * \param liste Pointeur vers une liste.
  */

void freeList(liste_p liste);

#endif
