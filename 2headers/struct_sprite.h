/**
 * \file struct_sprite.h
 * \brief Header contenant les profils des fonctions et la définitions des sprites.
 * \author Marcelin Maxime/ Tysoun Phillip /Signorino-Gelo Matteo
 * \version 1.0.
 * \date 25 octobre 2021
 */

#ifndef STRUCT_SPRITE_H
#define STRUCT_SPRITE_H

//------------------------------------------FLAGS-------------------------------------------------------//
/**
 * \brief Représentation mémoire pour contenir les information des différents Sprites pour les animations
 */
typedef struct flags_s{
	int isHighlighted;		/*!< Champ permettant de mettre en surbrillance le sprite. */

	int isStanding;				/*!< Champ permettant de jouer l'animation du sprite immobile. */
	int isMoving;					/*!< Champ permettant de jouer l'animation du sprite en mouvement. */
	int isJumping;				/*!< Champ permettant de jouer l'animation du sprite qui saute. */
	int isAttacking;			/*!< Champ permettant de jouer l'animation du sprite qui attaque. */
  int isHurt;						/*!< Champ permettant de jouer l'animation du sprite qui se blesse. */
  int isDead;						/*!< Champ permettant de jouer l'animation du sprite qui meurt. */
	int isVisible;	      /*!< Champ permettant de jouer l'animation du sprite visible. */

  int currentFrame;			/*!< Champ premettant de déterminer quel est l'indice de la frame à afficher. */
	int timer;						/*!< Champ permettant de déterminer quand changer la frame. */

	char facing;					/*!< Champ permettant de déterminer l'orientation du sprite. */

}flags_t, *flags_p; 		/*!< Pointeur vers les Flags. */


//------------------------------------------SPRITE-------------------------------------------------------//
/**
 * \brief Représentation du sprite du jeu.
 */
typedef struct sprite_s{
	int x;         /*!< Abscisse du Sprite. */
  int y;         /*!< Ordonnée du Sprite. */
  int w;         /*!< Largeur du Sprite. */
  int h;         /*!< Hauteur du Sprite. */
	int mobType;	 /*!< Type du Mob. */

	int vy;					/*!< Vitesse Verticale du Sprite. */
  int vx;					/*!< Vitesse Horizontale du Sprite. */

	flags_t flags;	/*!< Indicateurs d'animation du Sprite. */

}sprite_t, *sprite_p; /*!< Pointeur vers le Sprite. */


//------------------------------------------COORDS-------------------------------------------------------//

/**
 * \brief Fonction permettant de consulter les informations du sprite.
 * \param sprite Pointeur vers le sprite.
 */

void info(sprite_p sprite);

/**
 * \brief Fonction permettant de modifier la position du Sprite.
 * \param sprite Pointeur vers le sprite.
 * \param x Abscisse du Sprite.
 * \param y Ordonnée du Sprite.
 * \param w Largeur du Sprite.
 * \param h Hauteur du Sprite.
 * \param mobType Type du mob.
 */

void setCoords(sprite_p sprite,int x, int y, int w, int h, int mobType);

//------------------------------------------CHAMP VY-------------------------------------------------------//

/**
 * \brief Fonction permettant de modifier la vitesse verticale du sprite.
 * \param sprite Pointeur vers le sprite.
 * \param vy Vitesse verticale désirée.
 */

void setVY(sprite_p sprite,int vy);

/**
 * \brief Fonction permettant de retourner la vitesse verticale du sprite.
 * \param sprite Pointeur vers le sprite.
 * \return La vitesse verticale du sprite.
 */
int getVY(sprite_p sprite);

//------------------------------------------CHAMP VX-------------------------------------------------------//

/**
 * \brief Fonction permettant de modifier la vitesse horizontale du sprite.
 * \param sprite Pointeur vers le sprite.
 * \param vx Vitesse horizontale désirée.
 */
void setVX(sprite_p sprite, int vx);

/**
 * \brief Fonction permettant de retourner la vitesse horizontale du sprite.
 * \param sprite Pointeur vers le sprite.
 * \return La vitesse horizontale du sprite.
 */
int getVX(sprite_p sprite);

//------------------------------------------FLAGS-------------------------------------------------------//
/**
 * \brief Fonction permettant de modifier le champ isHighlighted.
 * \param sprite Pointeur vers le sprite.
 * \param isHighlighted champ modifié.
 */
void setIsHighlighted(sprite_p sprite,int isHighlighted);

/**
 * \brief Fonction permettant de retourner le champ isHighlighted.
 * \param sprite Pointeur vers le sprite.
 * \return Etat du champ isHighlighted.
 */
int getIsHighlighted(sprite_p sprite);

/**
 * \brief Fonction permettant de modifier le champ isStanding.
 * \param sprite Pointeur vers le sprite.
 * \param isStanding Etat du champ isStanding désiré.
 */
void setIsStanding(sprite_p sprite,int isStanding);

/**
 * \brief Fonction permettant de retourner le champ isStanding.
 * \param sprite Pointeur vers le sprite.
 * \return Etat du champ isStanding.
 */
int getIsStanding(sprite_p sprite);

/**
 * \brief Fonction permettant de modifier le champ isMoving.
 * \param sprite Pointeur vers le sprite.
 * \param isMoving Etat du champ isMoving désiré.
 */
void setIsMoving(sprite_p sprite,int isMoving);

/**
 * \brief Fonction permettant de retourner le champisMoving.
 * \param sprite Pointeur vers le sprite.
 * \return Etat du champ isMoving.
 */
int getIsMoving(sprite_p sprite);

/**
 * \brief Fonction permettant de modifier le champ isJumping.
 * \param sprite Pointeur vers le sprite.
 * \param isJumping Etat du champ isJumping désiré.
 */
void setIsJumping(sprite_p sprite,int isJumping);

/**
 * \brief Fonction permettant de retourner le champ isJumping.
 * \param sprite Pointeur vers le sprite.
 * \return Etat du champ isJumping.
 */
int getIsJumping(sprite_p sprite);

/**
 * \brief Fonction permettant de modifier le champ isAttacking.
 * \param sprite Pointeur vers le sprite.
 * \param isAttacking Etat du champ isAttacking désiré.
 */
void setIsAttacking(sprite_p sprite,int isAttacking);

/**
 * \brief Fonction permettant de retourner le champ isAttacking.
 * \param sprite Pointeur vers le sprite.
 * \return Etat du champ isAttacking.
 */
int getIsAttacking(sprite_p sprite);

/**
 * \brief Fonction permettant de modifier le champ currentFrame.
 * \param sprite Pointeur vers le sprite.
 * \param currentFrame Etat du champ currentFrame désiré.
 */
void setCurrentFrame(sprite_p sprite, int currentFrame);

/**
 * \brief Fonction permettant de retourner le champ currentFrame.
 * \param sprite Pointeur vers le sprite.
 * \return Etat du champ currentFrame.
 */
int getCurrentFrame(sprite_p sprite);

/**
 * \brief Fonction permettant de modifier le champ timer.
 * \param sprite Pointeur vers le sprite.
 * \param timer Etat du champ timer désiré.
 */
void setTimer(sprite_p sprite,int isAttacking);

/**
 * \brief Fonction permettant de retourner le champ timer.
 * \param sprite Pointeur vers le sprite.
 * \return Etat du champ timer.
 */
int getTimer(sprite_p sprite);

/**
 * \brief Fonction permettant de modifier le champ facing.
 * \param sprite Pointeur vers le sprite.
 * \param facing Etat du champ facing désiré.
 */
void setFacing(sprite_p sprite, char facing);

/**
 * \brief Fonction permettant de retourner le champ facing.
 * \param sprite Pointeur vers le sprite.
 * \return Etat du champ timer.
 */
char getFacing(sprite_p sprite);

/**
 * \brief Fonction permettant de modifier le champ isHurt.
 * \param sprite Pointeur vers le sprite.
 * \param isHurt Etat du champ isHurt désiré.
 */
void setIsHurt(sprite_p sprite,int isHurt);

/**
 * \brief Fonction permettant de retourner le champ isHurt.
 * \param sprite Pointeur vers le sprite.
 * \return Etat du champ isHurt.
 */
int getIsHurt(sprite_p sprite);

/**
 * \brief Fonction permettant de modifier le champ isDead.
 * \param sprite Pointeur vers le sprite.
 * \param isDead Etat du champ isDead désiré.
 */
void setDead(sprite_p sprite,int isDead);

/**
 * \brief Fonction permettant de retourner le champ isDead.
 * \param sprite Pointeur vers le sprite.
 * \return Etat du champ isDead.
 */
int getDead(sprite_p sprite);

/**
 * \brief Fonction permettant de modifier le champ isVisible.
 * \param sprite Pointeur vers le sprite.
 * \param isVisible Etat du champ isVisible désiré.
 */
void setIsVisible(sprite_p sprite,int isDead);

/**
 * \brief Fonction permettant de retourner le champ isVisible.
 * \param sprite Pointeur vers le sprite.
 * \return Etat du champ isVisible.
 */
int getIsVisible(sprite_p sprite);

#endif
