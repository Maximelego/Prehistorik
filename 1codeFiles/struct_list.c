/**
 * \file struct_list.c
 * \brief Fichier contenant les fonctions permettant de gèrer les listes.
 * \author Marcelin Maxime/ Tysoun Phillip /Signorino-Gelo Matteo
 * \version 1.0.
 * \date 31 décembre 2021
 */

#include <stdio.h>
#include <stdlib.h>

#include "constantes.h"
#include "struct_level.h"
#include "struct_list.h"

//------------------------------------------CONSEMPTY-------------------------------------------------------//
/**
  * \brief Fonction retournant une liste vide.
  * \return Pointeur vers une liste.
  */
liste_p consEmpty(){
  if(DEV_MODE){printf("Appel de <consEmpty()>.\n");}
  return NULL;
}

//------------------------------------------CONS-------------------------------------------------------//
/**
  * \brief Fonction retournant une liste construite avec le niveau donné en paramètre.
  * \param previous Pointeur vers une liste.
  * \param next Pointeur vers une liste.
  * \param level Pointeur vers un niveau.
  * \return Pointeur vers une liste.
  */
liste_p cons(liste_p previous, liste_p next, level_p level){
  if(DEV_MODE){printf("Appel de <cons()>.\n");}
  liste_p listeTemp = malloc(sizeof(liste_t));

  listeTemp->level = *level;
  listeTemp->previous = previous;
  listeTemp->next = next;

  return listeTemp;

}

//------------------------------------------ISEMPTY-------------------------------------------------------//
/**
  * \brief Fonction retournant un booléen permettant de déduire si la liste est vide.
  * \param liste Pointeur vers une liste.
  * \return Entier considéré comme un booléen.
  */

int isEmpty(liste_p liste){
  if(DEV_MODE){printf("Appel de <isEmpty()>.\n");}
  return(liste==NULL);
}


//------------------------------------------GETHEAD-------------------------------------------------------//
/**
  * \brief Fonction retournant un pointeur vers le level contenu dans la liste.
  * \param liste Pointeur vers une liste.
  * \return Pointeur vers le level contenu.
  */

level_p getHead(liste_p liste){
  if(DEV_MODE){printf("Appel de <getHead()>.\n");}
  if(isEmpty(liste)){
    printf("[ERROR] - Tried to get Head on an Empty list !\n");
    return NULL;
  }
  return(&liste->level);
}

//------------------------------------------GETNEXT-------------------------------------------------------//
/**
  * \brief Fonction retournant un pointeur vers la liste suivante.
  * \param liste Pointeur vers une liste.
  * \return Pointeur vers la liste suivante.
  */

liste_p getNext(liste_p liste){
  if(DEV_MODE){printf("Appel de <getNext()>.\n");}
  if(isEmpty(liste)){
    printf("[ERROR] - Tried to get Next on an Empty list !\n");
    return NULL;
  }
  return(liste->next);
}

//------------------------------------------GETPREVIOUS-------------------------------------------------------//
/**
  * \brief Fonction retournant un pointeur vers la liste précédente.
  * \param liste Pointeur vers une liste.
  * \return Pointeur vers la liste suivante.
  */

liste_p getPrevious(liste_p liste){
  if(DEV_MODE){printf("Appel de <getPrevious()>\n");}
  if(isEmpty(liste)){
    printf("[ERROR] - Tried to get Previous on an Empty list !\n");
    return NULL;
  }
  return (liste->previous);
}

//------------------------------------------SETHEAD-------------------------------------------------------//
/**
  * \brief Fonction modifiant la tête de la liste.
  * \param liste Pointeur vers une liste.
  * \param level Pointeur vers un niveau.
  */

void setHead(liste_p liste, level_p level){
  if(DEV_MODE){printf("Appel de <setHead()>.\n");}
  liste->level = *level;
}

//------------------------------------------SETNEXT-------------------------------------------------------//
/**
  * \brief Fonction modifiant la liste pointée par next().
  * \param liste Pointeur vers une liste.
  * \param next Pointeur vers une liste.
  */
void setNext(liste_p liste, liste_p next){
  if(DEV_MODE){printf("Appel de <setNext()>.\n");}
  liste->next = next;
}

//------------------------------------------SETPREVIOUS-------------------------------------------------------//
/**
  * \brief Fonction modifiant la liste pointée par getPrevious().
  * \param liste Pointeur vers une liste.
  * \param previous Pointeur vers une liste.
  */

void setPrevious(liste_p liste, liste_p previous){
  if(DEV_MODE){printf("Appel de <setPrevious()>\n");}
  liste->previous = previous;
}

//------------------------------------------INSERTLEVEL-------------------------------------------------------//
/**
  * \brief Fonction permettant de correctement insèrer un niveau dans la liste des niveaux.
  * \param liste Pointeur vers une liste.
  * \param level Pointeur vers un level.
  * \return 0 si l'insertion a réussi, 1 sinon.
  */

int insertLevel(liste_p* liste, level_t level){
  if(DEV_MODE){printf("Appel de <insertLevel()>.\n");}
  level_p levelTemp = copyLevel(&level);
  if(isEmpty(*liste)){
    *liste = cons(consEmpty(), consEmpty(), levelTemp);
    return 0;
  }else{
    if(getLevelNumber(&level)==getLevelNumber(getHead(*liste))){      //Dans le cas où le niveau se trouve déjà dans la liste.
      return 1;
    }else{
      if(getLevelNumber(&level)<getLevelNumber(getHead(*liste))){     //Dans le cas où le numéro est inférieur à celui de la liste actuelle.
        if(!isEmpty(getPrevious(*liste))){
          if(getLevelNumber(&level)>getLevelNumber(getHead(getPrevious(*liste)))){  //Dans le cas où levelNumber est compris entre celui de previous et de next.
            liste_p listeTemp = cons(getPrevious(*liste), *liste, levelTemp);
            setNext(getPrevious(*liste),listeTemp);
            setPrevious(*liste, listeTemp);
            return 0;
          }else{
            liste_p previous = getPrevious(*liste);
            return(insertLevel(&previous, level));            //Dans le cas où levelNumber est inférieur à levelNumber de Previous.
          }
        }else{                                                //Si le previous est NULL.
          setPrevious(*liste, cons(consEmpty(), *liste, levelTemp));
          return 0;
        }
      }else{
        if(!isEmpty(getNext(*liste))){
          //Dans le cas où le numéro est supérieur à celui de la liste actuelle.
          liste_p listeTemp = getNext(*liste);
          return insertLevel(&listeTemp, level);
        }else{
          liste_p listeTemp = cons(*liste, consEmpty(), levelTemp);
          setNext(*liste,listeTemp);
          return 0;
        }
      }
    }
  }
}

//------------------------------------------FREELIST-------------------------------------------------------//
/**
  * \brief Fonction permettant de libèrer la mémoire allouée à la liste.
  * \param liste Pointeur vers une liste.
  */

void freeList(liste_p liste){
  if(DEV_MODE){printf("Appel de <freeList()>.\n");}
  if(!isEmpty(liste)){
    freeList(getNext(liste));
    free(liste);
  }else{
    free(liste);
  }
}
