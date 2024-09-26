/**
 * \file gestionDonnees.c
 * \brief Fichier contenant les modifieurs et définitions du gestionnaire de jeu.
 * \author Marcelin Maxime/ Tysoun Phillip /Signorino-Gelo Matteo
 * \version 1.0.
 * \date 20 octobre 2021
 */

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

#include "gestionDonnees.h"
#include "gestionSon.h"

#include "struct_world.h"
#include "struct_sprite.h"
#include "constantes.h"



//----------------------INIT-----------------------------//
 /**
  * \brief La fonction initialise les données du monde.
  * \param world Le monde.
  */
void initWorldData(world_p world){
	if(DEV_MODE){printf("Appel de <initWorldData()>.\n");}

	//Champs de jeu.//
	setGameOver(world,0);									//Gameover.//
	setCurrentState(world, MENU_STATE);		//CurrentState.//
	setGravity(world, GRAVITY);						//Gravity.//
	setEarthLevel(world, EARTH_LEVEL);		//Earth Level.//

	//Initialisation du Sprite du joueur.
	initSpritePlayer(world);

	//Initialisation des niveaux.
	initLevels(world);

	//Initialisation des différents menus du jeu.
	initMenu(world);
}

/**
 * \brief La fonction initialise les niveaux du jeu.
 * \param world Le monde.
 */
void initLevels(world_p world){
	if(DEV_MODE){printf("Appel de <initLevels()>.\n");}

	liste_p levels = consEmpty();					//Initializing liste Structure.//
	level_t level;

	FILE* file;
	char fileName[MAX_LEVEL_NAME_SIZE + 6];
	char filePath[MAX_LEVEL_NAME_SIZE + 29] = "Ressources/Levels/";

	int fileCount = 0;
	struct dirent* entry;

	//Opening folder.//
	DIR* folder = opendir(filePath);

	if(DEV_MODE){printf("\n\n##====FILES PRESENT IN Level DIR : ====##\n");}

	while ((entry = readdir(folder)) != NULL){			//While there is still a file in the folder.//
		if(entry->d_type == DT_REG){				//If this file is a regular file.//

			fileCount++;
			strcpy(fileName, entry->d_name);
			if(DEV_MODE){printf("\n\nfileName : %s\n\n", fileName);}


			strcat(filePath,fileName);
			file = fopen(filePath, "r");   //Opening the level file.//

			if(file==NULL){
				printf("Error while opening %s file !\n", filePath);
				return;
			}

		  if(buildLevel(&level, file)){
				printf("Error while building the level according to %s file.\n", fileName);		//Building the level disposition and parameters.//
			}else{
				if(insertLevel(&levels,level)){																								//Storing the level in the list structure.//
					printf("Error while inserting the level in the list ! Maybe check levelNumber ? (File : %s)\n", fileName);
				}
			}

			//Resetting the filePath.//
			strcpy(filePath,"Ressources/Levels/");
		}
	}
	if(DEV_MODE){printf("\nThere are %i files in the Levels directory. \n", fileCount);}
	if(DEV_MODE){printf("##======================================##\n\n");}

	if(fileCount <= 0){
		printf("Error while opening level directory ! There are no levelBuilder types of file !\n");
		return;
	}
	while(!isEmpty(getPrevious(levels))){
		levels = getPrevious(levels);
	}
	if(DEV_MODE){
		printf("Liste des niveaux créés : ");
		while(!isEmpty(levels)){
			printf("%i ", getLevelNumber(getHead(levels)));
			levels = getNext(levels);
		}
		printf("\n");
	}

	//Closing folder.//
	closedir(folder);

	//Setting Levels.//
	setLevels(world, levels);
	setCurrentLevel(world, 1);
}



/**
 * \brief La fonction initialise les menus du jeu.
 * \param world Le monde.
 */
void initMenu(world_p world){
	if(DEV_MODE){printf("Appel de <initMenu()>.\n");}
	//Current Menu.//
	setCurrentMenu(world, 0);

	//Label 1, Bouton "Play".//
	setCoords(getLabels(world, 0), WIDTH/2, HEIGHT/2 -100, 250, 106,-1);
	setIsHighlighted(getLabels(world, 0), 0);

	//Label 2, Bouton "Help".//
	setCoords(getLabels(world, 1),WIDTH/2, HEIGHT/2, 250, 106,-1);
	setIsHighlighted(getLabels(world, 1), 0);

	//Label 3, Bouton "Score".//
	setCoords(getLabels(world, 2),WIDTH/2, HEIGHT/2  +100, 250, 106,-1);
	setIsHighlighted(getLabels(world, 2), 0);

	//Label 4 Bouton "Exit".//
	setCoords(getLabels(world, 3),WIDTH/2, HEIGHT/2 +200, 250, 106,-1);
	setIsHighlighted(getLabels(world, 3), 0);

	//Label 5 Bouton "Back".//
	setCoords(getLabels(world, 4),WIDTH-150, HEIGHT -100 , 250, 106,-1);
	setIsHighlighted(getLabels(world, 4), 0);

	//Label 6 Bouton "YES".//
	setCoords(getLabels(world, 5),WIDTH/2 - 150, HEIGHT/2, 250, 106,-1);
	setIsHighlighted(getLabels(world, 5), 0);

	//Label 7 Bouton "NO".//
	setCoords(getLabels(world, 6),WIDTH/2 + 150, HEIGHT/2, 250, 106,-1);
	setIsHighlighted(getLabels(world, 6), 0);
}


/**
 * \brief La fonction initialise les données du joueur.
 * \param world Le monde.
 */
void initSpritePlayer(world_p world){
	if(DEV_MODE){printf("Appel de <initSpritePlayer()>.\n");}
	//Coords and HP.//
	setCoords(getPlayer(world),50,getEarthLevel(world) - 100/2, 70, 100,-1);

	//FLAGS.//
	setIsHighlighted(getPlayer(world), 0);

	setIsStanding(getPlayer(world), 1);
	setIsMoving(getPlayer(world), 0);
	setIsJumping(getPlayer(world), 0);
	setIsAttacking(getPlayer(world), 0);
	setIsHurt(getPlayer(world), 0);
	setDead(getPlayer(world), 0);

	//Animation Utilities.//
	setCurrentFrame(getPlayer(world), 0);
	setTimer(getPlayer(world), 0);

	//Facing.//
	setFacing(getPlayer(world), FACING_RIGHT);

	//Vitesses.//
	setVY(getPlayer(world),0);
	setVX(getPlayer(world),0);
}

//----------------------UPDATES-----------------------------//
/**
 * \brief La fonction mets à jour le sprite pour le soumettre à la gravité
 * \param world Le monde.
 * \param sprite Le sprite à actualiser.
 */
void gravity(world_p world, sprite_p sprite){
	if(DEV_MODE){printf("Appel de <gravity()>.\n");}
	if((sprite->y + sprite->h/2) < getEarthLevel(world)){
		setVY(sprite, getVY(sprite) + getGravity(world));
	}
	if((sprite->y + sprite->h/2) >= getEarthLevel(world)){
		sprite->y = getEarthLevel(world) - sprite->h/2;
		setVY(sprite,0);
		setIsJumping(sprite,0);
		if((!getIsMoving(sprite))&&(!getIsAttacking(sprite))){
			setIsStanding(sprite,1);
		}
	}
}

//------------------------COORDS------------------------------//
/**
 * \brief La fonction met à jour la hauteur du sprite en fonction de sa vitesse en y.
 * \param sprite Le joueur.
 * \param world Le monde.
 */
void updateY(world_p world, sprite_p sprite){
	if(DEV_MODE){printf("Appel de <updateY()>.\n");}
	sprite->y = sprite->y + getVY(sprite);
}

/**
 * \brief La fonction met à jour la position x du sprite en fonction de sa vitesse en x.
 * \param sprite Le joueur.
 */
void updateX(sprite_p sprite){
	if(DEV_MODE){printf("Appel de <updateX()>.\n");}
	sprite->x = sprite->x + getVX(sprite);
	if((getVX(sprite)>0)&&(!getIsMoving(sprite))){
		setVX(sprite, getVX(sprite) -1);
	}else if ((getVX(sprite) < 0)&&(!getIsMoving(sprite))){
		setVX(sprite, getVX(sprite) +1);
	}
}

//-----------------------VITESSES-------------------------------//
/**
 * \brief La fonction met à jour tous les sprite pour actualiser le déplacement horizontal.
 * \param world Le monde.
 */
void handleVX(world_p world){
	if(DEV_MODE){printf("Appel de <handleVX()>.\n");}
	//Player.//
	updateX(getPlayer(world));
}

/**
 * \brief La fonction met à jour tous les sprites pour actualiser le déplacement vertical.
 * \param world Le monde.
 */
void handleVY(world_p world){
	if(DEV_MODE){printf("Appel de <handleVX()>.\n");}
	//Player.//
	gravity(world, getPlayer(world));
	updateY(world, getPlayer(world));
}

//----------------------MENU ANIMATION---------------------------------//
/**
 * \brief La fonction met à jour les données du Sprite du joueur pour effectuer une animation dans l'écran titre.
 * \param world Le monde.
 */
void handleMenuAnimation(world_p world){
	if(DEV_MODE){printf("Appel de <handleMenuAnimation()>.\n");}
	updateX(getPlayer(world));
	moveRightSprite(world, getPlayer(world));
}

//------------------------PLAYER ANIMATION-------------------------------//
/**
 * \brief La fonction met à jour les données des différents Sprites pour effectuer les animations de déplacement, immobilisation, saut et attaque.
 * \param world Le monde.
 * \param sprite les sprites.
 */
void handlePlayerAnimation(world_p world, sprite_p sprite){
	if(DEV_MODE){printf("Appel de <handleAnimation()>.\n");}

	if(getIsStanding(sprite)){
		if((getTimer(sprite) >= ANIMATION_TIMERATE + 50)){
			setTimer(sprite, 0);
			if(getCurrentFrame(sprite)>=NB_FRAME_PLAYER_STANDING -1){
				setCurrentFrame(sprite,0);
			}else{
				setCurrentFrame(sprite,getCurrentFrame(sprite)+1);
			}
		}else{
			setTimer(sprite, getTimer(sprite)+10);
		}
	}else if(getIsMoving(sprite)){
		if((getTimer(sprite) >= ANIMATION_TIMERATE)){
			setTimer(sprite, 0);
			if(getCurrentFrame(sprite)>=NB_FRAME_PLAYER_MOVING -1){
				setCurrentFrame(sprite,0);
			}else{
				setCurrentFrame(sprite,getCurrentFrame(sprite)+1);
			}
		}else{
			setTimer(sprite, getTimer(sprite)+10);
		}
	}else if(getIsJumping(sprite)){
		if(getCurrentFrame(sprite)<= NB_FRAME_PLAYER_JUMPING){
			if(getVY(sprite)>0){
				setCurrentFrame(sprite, 0);
			}else if((getVY(sprite)<0)&&(getVY(sprite)>= -5)){
				setCurrentFrame(sprite,1);
			}else{
				setCurrentFrame(sprite,2);
			}
		}else{
			setCurrentFrame(sprite, 0);
		}
	}else if(getIsAttacking(sprite)){
		if((getTimer(sprite) >= ANIMATION_TIMERATE/2)){
			setTimer(sprite, 0);
			if(getCurrentFrame(sprite)>=NB_FRAME_PLAYER_ATTACKING -1){
				setCurrentFrame(sprite,0);
				setIsAttacking(sprite,0);
			}else{
				setCurrentFrame(sprite,getCurrentFrame(sprite)+1);
			}
		}else{
			setTimer(sprite, getTimer(sprite)+10);
		}
	}
}


//---------------------------BORDERS---------------------------//
/**
 * \brief La fonction permet d'éviter au joueur de sortir de l'écran.
 * \param world Le monde.
 */
void handleBorder(world_p world){
	if(DEV_MODE){printf("Appel de <handleBorder()>.\n");}
	sprite_p sprite = getPlayer(world);
	switch(getCurrentState(world)){

		case MENU_STATE :												//Permet de faire réapparaître le sprite à gauche de l'écran lorsqu'il sort à droite dans le menu.//
			if(sprite->x > WIDTH +1000){
				sprite->x = -1000;
			}
			break;
		case LEVEL_STATE :
			if(sprite->x > WIDTH - 200){					//Permet de garder le Sprite du joueur relativement centré dans la fenêtre.//
				sprite->x = WIDTH-200;
			}else if(sprite->x < 200){
				sprite->x = 200;
			}
			break;
	}
}

//---------------------UPDATE DATA-----------------------------//
/**
 * \brief La fonction met à jour les données du monde à chaque rafraîchissement.
 * \param world Le monde.
 */
void updateData(world_p world){
	if(DEV_MODE){printf("Appel de <initSpritePlayer()>.\n");}
	switch(getCurrentState(world)){
		case MENU_STATE :
			//Sprite Menu Animation.//
			handleMenuAnimation(world);
			handlePlayerAnimation(world, getPlayer(world));
			handleBorder(world);
			break;
		case LEVEL_STATE :
			handlePlayerAnimation(world, getPlayer(world));
			handleBorder(world);
			handleVX(world);
			handleVY(world);
			break;
		case PAUSE_STATE :
			break;
	}
}

//---------------------HITBOXES-----------------------------//

/**
 * \brief La fonction permet de savoir si une coordonnée (x,y) se situe dans la hitbox d'un sprite.
 * \param sprite Le sprite à déplacer.
 * \param x Abscisse.
 * \param y Ordonnée.
 */
int isInHitbox(sprite_p sprite, int x, int y){
	if(DEV_MODE){printf("Appel de <isInHitbox()>.\n");}
	if((x>=sprite->x - sprite->w/2)&&(x<=sprite->x + sprite->w/2)&&(y>=sprite->y - sprite->h/2 )&&(y<=sprite->y + sprite->h/2 )){
		return 1;
	}
	return 0;
}

//---------------------MOVES-----------------------------//

/**
 * \brief La fonction déplace le sprite à Droite
 * \param world Le monde.
 * \param sprite Le sprite à deplacer.
 */
void moveRightSprite(world_p world, sprite_p sprite){
	if(DEV_MODE){printf("Appel de <moveRightSprite()>.\n");}

	setVX(getPlayer(world),PAS_DEPLACEMENT);

	setIsStanding(getPlayer(world), 0);
	setIsMoving(getPlayer(world), 1);
	setFacing(getPlayer(world), FACING_RIGHT);
}

/**
 * \brief La fonction déplace le sprite à gauche
 * \param world Le monde.
 * \param sprite Le sprite à deplacer.
 */
void moveLeftSprite(world_p world, sprite_p sprite){
	if(DEV_MODE){printf("Appel de <moveLeftSprite()>.\n");}

	setVX(getPlayer(world),-PAS_DEPLACEMENT);

	setIsStanding(getPlayer(world), 0);
	setIsMoving(getPlayer(world), 1);
	setFacing(getPlayer(world), FACING_LEFT);
}



//---------------------------------------------------------//
 /**
  * \brief La fonction nettoie les données du monde.
  * \param world Le monde.
  */
void cleanWorldData(world_p world) {
	if(DEV_MODE){printf("Appel de <cleanWorldData()>.\n");}
	//Sert à nettoyer des éventuels pointeurs dans la structure world.//
	freeList(getLevels(world));

}
