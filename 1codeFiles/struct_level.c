/**
 * \file struct_level.c
 * \brief Fichier contenant les fonctions permettant de gèrer les niveaux du jeu.
 * \author Marcelin Maxime/ Tysoun Phillip /Signorino-Gelo Matteo
 * \version 1.0.
 * \date 17 décembre 2021
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sdl2-light.h"
#include "constantes.h"

#include "struct_level.h"


/**
 * \brief Fonction permettant de paramètrer un niveau.
 * \param level Pointeur vers le niveau à paramètrer.
 * \param file Pointeur vers le file à utiliser.
 * \return 0 en cas d'execution réussi, 1 en cas d'errerur de parsing.
 */
int buildLevel(level_p level, FILE* file){
  if(DEV_MODE){printf("Appel de <buildLevel()>.\n");}
  int error = 0;

  //setting Score et TimePassed
  level->score = 0;
  level->timePassed = 0;

  //setting level et levelNumber
  if (parseLevelNumber(level, file)) {
    printf("error while parsing levelNumber\n" );
    error = 1;
  }else if(parseLevelForm(level, file)) {
      printf("error while parsing levelForm\n" );
      error = 1;
  }
  return error;
}

/**
 * \brief Fonction permettant de reconnaitre le numéro du niveau du fichier.
 * \param level Pointeur vers le niveau à paramètrer.
 * \param file Le fichier à parser.
 * \return 0 en cas de fonctionnement normal et 1 en cas d'erreur
 */
int parseLevelNumber(level_p level, FILE* file){
  if (DEV_MODE) {printf("Appel de <parseLevelNumber()>.\n");}
  int error = 1;
  int i;
  if(fscanf(file,"levelNumber %i\n", &i)!=1){
    return error;   //Premet de sauver du temps de calcul.
  }else{
    level->levelNumber = i;
    error = 0;
  }
  return error;
}

/**
 * \brief Fonction permettant de reconnaitre les différents éléments et dispositions du niveau du fichier.
 * \param level Pointeur vers le niveau à paramètrer.
 * \param file Fichier à analyser.
 * \return 0 en cas de fonctionnement normal et 1 en cas d'erreur
 */
int parseLevelForm(level_p level, FILE* file){
  if(DEV_MODE){printf("Appel de <parseLevelForm()>.\n");}
  int error = 1;
  char line[50];

/*  int nbLines = 0;

  while(fgets(line, 50, file) != NULL){
    nbLines++;
  }
  if(DEV_MODE){printf("nbLines : %i\n", nbLines);}
*/

  char c;
  int i = 0;
  int nbPlatforms = 0;
  int nbMobs = 0;
  int x, y, z;
  int w, h;

//  rewind(file);
  while ((fscanf(file, "%[^\n]", line))!= EOF) {
	fgetc(file);
    switch(c){
      case 'P':
        if(nbPlatforms < NB_PLATFORMS_MAX){
          if(DEV_MODE){printf("Platform info : x : %d, y : %d, thickness : %d\n",x,y,z);}
          setCoords(&level->platforms[nbPlatforms],x*COLUMN_SIZE,y*LAYER_SIZE, z * 100, 80,-1);
          if(DEV_MODE){printf("Sprite info : "); info(&level->platforms[nbPlatforms]);}
          nbPlatforms++;
          if(DEV_MODE){printf("nbPlatforms : %d\n", nbPlatforms);}
          error = 0;
        }
        break;
      case 'M' :
        if(DEV_MODE){printf("MobInfo : x : %d, y : %d, mobType : %d\n",x,y,x);}
        if(nbMobs < NB_MOBS_MAX){
          switch(x){        //On détermine les paramètres du mobs en fonction de son type.
            case 0 :      //Croco
              w = 200;
              h = 80;
              break;
            case 1 :      //Dino
              w = 110;
              h = 80;
              break;
            case 2 :      //Scorpion.
              w = 100;
              h = 80;
              break;
            default:
              return error;
          }
          if(DEV_MODE){printf("Mob info : x : %i, y : %i, mobType : %i\n",x,y,x);}
          setCoords(&level->mobs[nbMobs],y*COLUMN_SIZE,z*LAYER_SIZE,w,h,x);
          if(DEV_MODE){printf("Sprite info : "); info(&level->mobs[nbMobs]);}
          nbMobs++;
          if(DEV_MODE){printf("nbMobs : %i\n", nbMobs);}
          error = 0;
        }
        break;
      default :
        break;
      }
    int ret = sscanf(line,"%c %d %d %d",&c,&x,&y,&z);
    i++;
  }


  level->nbPlatforms = nbPlatforms;
  level->nbMobs = nbMobs;

  return error;
}


/**
 * \brief Fonction permettant de voir les informations d'un niveau.
 * \param level Pointeur vers le niveau à observer.
 */
void getLevelInfo(level_p level){
  if(DEV_MODE){printf("Appel de <getLevelInfo()>.\n");}

  printf("\n##========Level n°%i infos : ========##\n", level->levelNumber);

  printf("//-----Platforms : ------\\ \n\n");
  for(int i = 0; i<NB_PLATFORMS_MAX; i++){
    info(&level->platforms[i]);
  }
  printf("\n");
  printf("//-----End of level : -----\\ \n\n");
  info(&level->endLevelLine);
  printf("\n");

  printf("Score : %i\n",level->score);
  printf("TimePassed : %i\n", level->timePassed);

  printf("##=================================##\n\n");

}

/**
 * \brief Fonction permettant de retouner le numéro du niveau.
 * \param level Pointeur vers le niveau à observer.
 * \return Numéro du niveau.
 */
int getLevelNumber(level_p level){
  if(DEV_MODE){printf("Appel de <getLevelNumber()>.\n");}
  return level->levelNumber;
}

/**
 * \brief Fonction permettant de copier les informations d'un niveau à un autre.
 * \param level Pointeur vers le niveau à copier.
 * \return Pointeur vers la copie du niveau.
 */
level_p copyLevel(level_p level){
  if(DEV_MODE){printf("Appel de <copyLevel()>.\n");}

  level_p copie = malloc(sizeof(level_t));    //création copie.//

  copie->levelNumber = level->levelNumber;
  copie->score = level->score;
  copie->timePassed = level->timePassed;

  for(int i = 0; i<NB_PLATFORMS_MAX; i++){
    copie->platforms[i] = copie->platforms[i];
  }
  for(int i = 0; i<NB_MOBS_MAX; i++){
    copie->mobs[i] = copie->mobs[i];
  }

  return copie;
}
