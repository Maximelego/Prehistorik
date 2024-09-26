/**
 * \file struct_sprite.c
 * \brief Fichier contenant les modifieurs et définitions des sprites.
 * \author Marcelin Maxime/ Tysoun Phillip /Signorino-Gelo Matteo
 * \version 1.0.
 * \date 25 octobre 2021
 */


 #include <stdio.h>
 #include <stdlib.h>

 #include "struct_sprite.h"
 #include "constantes.h"


//------------------------------------------COORDS-------------------------------------------------------//

 /**
  * \brief Fonction permettant de consulter les informations du sprite.
  * \param sprite Pointeur vers le sprite.
  */

void info(sprite_p sprite){
  if(DEV_MODE){printf("Appel de <info()>.\n");}
  printf("#x = %i   ",sprite->x);
	printf("#y = %i   ",sprite->y);
	printf("#w = %i   ",sprite->w);
	printf("#h = %i   ",sprite->h);
  printf("#mobType = %i   ", sprite->mobType);
}

 /**
  * \brief Fonction permettant de modifier la position du Sprite.
  * \param sprite Pointeur vers le sprite.
  * \param x Abscisse du Sprite.
  * \param y Ordonnée du Sprite.
  * \param w Largeur du Sprite.
  * \param h Hauteur du Sprite.
  * \param mobType Type du mob.
  */

void setCoords(sprite_p sprite,int x, int y, int w, int h, int mobType){
  if(DEV_MODE){printf("Appel de <setCoords()>.\n");}
	sprite->x = x;
	sprite->y = y;
	sprite->w = w;
	sprite->h = h;
  sprite->mobType = mobType;
}


//------------------------------------------CHAMP VY-------------------------------------------------------//

/**
 * \brief Fonction permettant de modifier la vitesse verticale du sprite.
 * \param sprite Pointeur vers le sprite.
 * \param vy Vitesse verticale désirée.
 */

void setVY(sprite_p sprite, int vy){
  if(DEV_MODE){printf("Appel de <setVY()>.\n");}
	sprite->vy = vy;
}

/**
 * \brief Fonction permettant de retourner la vitesse verticale du sprite.
 * \param sprite Pointeur vers le sprite.
 * \return La vitesse verticale du sprite.
 */

int getVY(sprite_p sprite){
  if(DEV_MODE){printf("Appel de <getVY()>.\n");}
  return(sprite->vy);
}

//------------------------------------------CHAMP VX-------------------------------------------------------//

/**
 * \brief Fonction permettant de modifier la vitesse horizontale du sprite.
 * \param sprite Pointeur vers le sprite.
 * \param vx Vitesse horizontale désirée.
 */

void setVX(sprite_p sprite, int vx){
    if(DEV_MODE){printf("Appel de <setVY()>.\n");}
    sprite->vx = vx;
}

/**
 * \brief Fonction permettant de retourner la vitesse horizontale du sprite.
 * \param sprite Pointeur vers le sprite.
 * \return La vitesse horizontale du sprite.
 */

int getVX(sprite_p sprite){
    if(DEV_MODE){printf("Appel de <getVX()>.\n");}
    return(sprite->vx);
}
//------------------------------------------FLAGS-------------------------------------------------------//

 /**
  * \brief Fonction permettant de modifier le champ isHighlighted.
  * \param sprite Pointeur vers le sprite.
  * \param isHighlighted champ modifié.
  */
void setIsHighlighted(sprite_p sprite,int isHighlighted){
  if(DEV_MODE){printf("Appel de <setIsHighlighted()>.\n");}
	sprite->flags.isHighlighted = isHighlighted;
}

/**
 * \brief Fonction permettant de retourner le champ isHighlighted.
 * \param sprite Pointeur vers le sprite.
 * \return Etat du champ isHighlighted.
 */

int getIsHighlighted(sprite_p sprite){
  if(DEV_MODE){printf("Appel de <getIsHighlighted()>.\n");}
  return(sprite->flags.isHighlighted);
}

/**
 * \brief Fonction permettant de modifier le champ isStanding.
 * \param sprite Pointeur vers le sprite.
 * \param isStanding Etat du champ isStanding désiré.
 */
void setIsStanding(sprite_p sprite,int isStanding){
  if(DEV_MODE){printf("Appel de <setIsStanding()>.\n");}
	sprite->flags.isStanding = isStanding;
}

/**
 * \brief Fonction permettant de retourner le champ isStanding.
 * \param sprite Pointeur vers le sprite.
 * \return Etat du champ isStanding.
 */

int getIsStanding(sprite_p sprite){
  if(DEV_MODE){printf("Appel de <getIsStanding()>.\n");}
  return(sprite->flags.isStanding);
}


/**
 * \brief Fonction permettant de modifier le champ isMoving.
 * \param sprite Pointeur vers le sprite.
 * \param isMoving Etat du champ isMoving désiré.
 */

void setIsMoving(sprite_p sprite,int isMoving){
 if(DEV_MODE){printf("Appel de <setisMoving()>.\n");}
 sprite->flags.isMoving = isMoving;
}

/**
 * \brief Fonction permettant de retourner le champisMoving.
 * \param sprite Pointeur vers le sprite.
 * \return Etat du champ isMoving.
 */

int getIsMoving(sprite_p sprite){
  if(DEV_MODE){printf("Appel de <geisMoving()>.\n");}
  return(sprite->flags.isMoving);
}

/**
 * \brief Fonction permettant de modifier le champ isJumping.
 * \param sprite Pointeur vers le sprite.
 * \param isJumping Etat du champ isJumping désiré.
 */
void setIsJumping(sprite_p sprite,int isJumping){
 if(DEV_MODE){printf("Appel de <setisJumping()>.\n");}
 sprite->flags.isJumping = isJumping;
}

/**
 * \brief Fonction permettant de retourner le champ isJumping.
 * \param sprite Pointeur vers le sprite.
 * \return Etat du champ isJumping.
 */

int getIsJumping(sprite_p sprite){
 if(DEV_MODE){printf("Appel de <getisJumping()>.\n");}
 return(sprite->flags.isJumping);
}

/**
 * \brief Fonction permettant de modifier le champ isAttacking.
 * \param sprite Pointeur vers le sprite.
 * \param isAttacking Etat du champ isAttacking désiré.
 */
void setIsAttacking(sprite_p sprite,int isAttacking){
 if(DEV_MODE){printf("Appel de <setisJumping()>.\n");}
 sprite->flags.isAttacking = isAttacking;
}

/**
 * \brief Fonction permettant de retourner le champ isAttacking.
 * \param sprite Pointeur vers le sprite.
 * \return Etat du champ isAttacking.
 */

int getIsAttacking(sprite_p sprite){
 if(DEV_MODE){printf("Appel de <getisAttacking()>.\n");}
 return(sprite->flags.isAttacking);
}

/**
 * \brief Fonction permettant de modifier le champ currentFrame.
 * \param sprite Pointeur vers le sprite.
 * \param currentFrame Etat du champ currentFrame désiré.
 */
void setCurrentFrame(sprite_p sprite, int currentFrame){
  if(DEV_MODE){printf("Appel de <setCurrentFrame()>.\n");}
  sprite->flags.currentFrame = currentFrame;
}

/**
 * \brief Fonction permettant de retourner le champ currentFrame.
 * \param sprite Pointeur vers le sprite.
 * \return Etat du champ currentFrame.
 */
int getCurrentFrame(sprite_p sprite){
  if(DEV_MODE){printf("Appel de <getCurrentFrame()>.\n");}
  return(sprite->flags.currentFrame);
}

/**
 * \brief Fonction permettant de modifier le champ timer.
 * \param sprite Pointeur vers le sprite.
 * \param timer Etat du champ timer désiré.
 */
void setTimer(sprite_p sprite,int timer){
  if(DEV_MODE){printf("Appel de <setTimer()>.\n");}
  sprite->flags.timer = timer;
}

/**
 * \brief Fonction permettant de retourner le champ timer.
 * \param sprite Pointeur vers le sprite.
 * \return Etat du champ timer.
 */
int getTimer(sprite_p sprite){
  if(DEV_MODE){printf("Appel de <getTimer()>.\n");}
  return(sprite->flags.timer);
}

/**
 * \brief Fonction permettant de modifier le champ facing.
 * \param sprite Pointeur vers le sprite.
 * \param facing Etat du champ facing désiré.
 */
void setFacing(sprite_p sprite, char facing){
  if(DEV_MODE){printf("Appel de <setFacing()>.\n");}
  sprite->flags.facing = facing;
}

/**
 * \brief Fonction permettant de retourner le champ facing.
 * \param sprite Pointeur vers le sprite.
 * \return Etat du champ timer.
 */
char getFacing(sprite_p sprite){
  if(DEV_MODE){printf("Appel de <getFacing()>.\n");}
  return(sprite->flags.facing);
}

/**
 * \brief Fonction permettant de modifier le champ isHurt.
 * \param sprite Pointeur vers le sprite.
 * \param isHurt Etat du champ isHurt désiré.
 */
void setIsHurt(sprite_p sprite,int isHurt){
    if(DEV_MODE){printf("Appel de <setisHurt()>.\n");}
    sprite->flags.isHurt = isHurt;
}

/**
 * \brief Fonction permettant de retourner le champ isHurt.
 * \param sprite Pointeur vers le sprite.
 * \return Etat du champ isHurt.
 */
int getIsHurt(sprite_p sprite){
    if(DEV_MODE){printf("Appel de <getisHurt()>.\n");}
    return(sprite->flags.isHurt);
}

/**
 * \brief Fonction permettant de modifier le champ isDead.
 * \param sprite Pointeur vers le sprite.
 * \param isDead Etat du champ isDead désiré.
 */
void setDead(sprite_p sprite,int isDead){
    if(DEV_MODE){printf("Appel de <setIsDead()>.\n");}
    sprite->flags.isDead = isDead;
}

/**
 * \brief Fonction permettant de retourner le champ isDead.
 * \param sprite Pointeur vers le sprite.
 * \return Etat du champ isDead.
 */
int getDead(sprite_p sprite){
    if(DEV_MODE){printf("Appel de <getIsDead()>.\n");}
    return(sprite->flags.isDead);
}

/**
 * \brief Fonction permettant de modifier le champ isVisible.
 * \param sprite Pointeur vers le sprite.
 * \param isVisible Etat du champ isVisible désiré.
 */
void setIsVisible(sprite_p sprite,int isVisible){
  if(DEV_MODE){printf("Appel de <setIsVisible()>.\n");}
  sprite->flags.isVisible = isVisible;
  }

  /**
   * \brief Fonction permettant de retourner le champ isVisible.
   * \param sprite Pointeur vers le sprite.
   * \return Etat du champ isVisible.
   */
  int getIsVisible(sprite_p sprite){
    if(DEV_MODE){printf("Appel de <getIsVisible()>.\n");}
    return(sprite->flags.isVisible);
  }
