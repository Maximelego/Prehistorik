/**
 * \file struct_ressources.c
 * \brief Fichier contenant les fonctions permettant de gèrer les ressources du jeu.
 * \author Marcelin Maxime/ Tysoun Phillip /Signorino-Gelo Matteo
 * \version 1.0.
 * \date 25 novembre 2021
 */

#include <stdio.h>
#include <stdlib.h>

#include "sdl2-light.h"
#include "sdl2-ttf-light.h"

#include "constantes.h"
#include "struct_ressources.h"

//---------------------------------------------------------//
 /**
  * \brief La fonction charge les ressources du jeu.
  * \param renderer Le renderer.
  * \param ressources Structure des ressources.
  */

void loadRessources(SDL_Renderer *renderer, ressources_p ressources){
  if(DEV_MODE){printf("Appel de <loadTextures()>.\n");}

  //---------------------------------------FONT----------------------------------------------------//

  //Chargement de la police d'écriture.//
  ressources->font = load_font("Ressources/Polices/Prehistoric Caveman.ttf",TITLE_FONT_SIZE);

  //---------------------------------------BACKGROUND----------------------------------------------------//

  //Application de la texture de background.//
 	ressources->background[0] = load_imageBMP("Ressources/Background/BackgroundImage/Hills.bmp",renderer);
  ressources->background[1] = load_imageBMP("Ressources/Background/BackgroundImage/MontainsBeautiful.bmp",renderer);
  ressources->background[2] = load_imageBMP("Ressources/Background/BackgroundImage/Plains.bmp",renderer);
  ressources->background[3] = load_imageBMP("Ressources/Background/BackgroundImage/RockDesert.bmp",renderer);

  //---------------------------------------PLAYER----------------------------------------------------//

 	//Application de la texture du Joueur Immobile.//
 	ressources->playerStandingRight[0] = load_imageBMP("Ressources/Sprites/Player/StandingRight/0.bmp",renderer);
  ressources->playerStandingRight[1] = load_imageBMP("Ressources/Sprites/Player/StandingRight/1.bmp",renderer);

  ressources->playerStandingLeft[0] = load_imageBMP("Ressources/Sprites/Player/StandingLeft/0.bmp",renderer);
  ressources->playerStandingLeft[1] = load_imageBMP("Ressources/Sprites/Player/StandingLeft/1.bmp",renderer);

  //Application de la texture du Joueur En déplacement.//
  ressources->playerMovingRight[0] = load_imageBMP("Ressources/Sprites/Player/MovingRight/0.bmp",renderer);
  ressources->playerMovingRight[1] = load_imageBMP("Ressources/Sprites/Player/MovingRight/1.bmp",renderer);
  ressources->playerMovingRight[2] = load_imageBMP("Ressources/Sprites/Player/MovingRight/2.bmp",renderer);
  ressources->playerMovingRight[3] = load_imageBMP("Ressources/Sprites/Player/MovingRight/3.bmp",renderer);
  ressources->playerMovingRight[4] = load_imageBMP("Ressources/Sprites/Player/MovingRight/4.bmp",renderer);
  ressources->playerMovingRight[5] = load_imageBMP("Ressources/Sprites/Player/MovingRight/5.bmp",renderer);

  ressources->playerMovingLeft[0] = load_imageBMP("Ressources/Sprites/Player/MovingLeft/0.bmp",renderer);
  ressources->playerMovingLeft[1] = load_imageBMP("Ressources/Sprites/Player/MovingLeft/1.bmp",renderer);
  ressources->playerMovingLeft[2] = load_imageBMP("Ressources/Sprites/Player/MovingLeft/2.bmp",renderer);
  ressources->playerMovingLeft[3] = load_imageBMP("Ressources/Sprites/Player/MovingLeft/3.bmp",renderer);
  ressources->playerMovingLeft[4] = load_imageBMP("Ressources/Sprites/Player/MovingLeft/4.bmp",renderer);
  ressources->playerMovingLeft[5] = load_imageBMP("Ressources/Sprites/Player/MovingLeft/5.bmp",renderer);

  //Application de la texture du Joueur Sautant.//
  ressources->playerJumpingRight[0] = load_imageBMP("Ressources/Sprites/Player/JumpingRight/0.bmp",renderer);
  ressources->playerJumpingRight[1] = load_imageBMP("Ressources/Sprites/Player/JumpingRight/1.bmp",renderer);
  ressources->playerJumpingRight[2] = load_imageBMP("Ressources/Sprites/Player/JumpingRight/2.bmp",renderer);
  ressources->playerJumpingRight[3] = load_imageBMP("Ressources/Sprites/Player/JumpingRight/3.bmp",renderer);
  ressources->playerJumpingRight[4] = load_imageBMP("Ressources/Sprites/Player/JumpingRight/4.bmp",renderer);

  ressources->playerJumpingLeft[0] = load_imageBMP("Ressources/Sprites/Player/JumpingLeft/0.bmp",renderer);
  ressources->playerJumpingLeft[1] = load_imageBMP("Ressources/Sprites/Player/JumpingLeft/1.bmp",renderer);
  ressources->playerJumpingLeft[2] = load_imageBMP("Ressources/Sprites/Player/JumpingLeft/2.bmp",renderer);
  ressources->playerJumpingLeft[3] = load_imageBMP("Ressources/Sprites/Player/JumpingLeft/3.bmp",renderer);
  ressources->playerJumpingLeft[4] = load_imageBMP("Ressources/Sprites/Player/JumpingLeft/4.bmp",renderer);

  //Application de la texture du Joueur Attaquant.//
  ressources->playerAttackingRight[0] = load_imageBMP("Ressources/Sprites/Player/AttackingRight/0.bmp",renderer);
  ressources->playerAttackingRight[1] = load_imageBMP("Ressources/Sprites/Player/AttackingRight/1.bmp",renderer);
  ressources->playerAttackingRight[2] = load_imageBMP("Ressources/Sprites/Player/AttackingRight/2.bmp",renderer);
  ressources->playerAttackingRight[3] = load_imageBMP("Ressources/Sprites/Player/AttackingRight/3.bmp",renderer);
  ressources->playerAttackingRight[4] = load_imageBMP("Ressources/Sprites/Player/AttackingRight/4.bmp",renderer);
  ressources->playerAttackingRight[5] = load_imageBMP("Ressources/Sprites/Player/AttackingRight/5.bmp",renderer);

  ressources->playerAttackingLeft[0] = load_imageBMP("Ressources/Sprites/Player/AttackingLeft/0.bmp",renderer);
  ressources->playerAttackingLeft[1] = load_imageBMP("Ressources/Sprites/Player/AttackingLeft/1.bmp",renderer);
  ressources->playerAttackingLeft[2] = load_imageBMP("Ressources/Sprites/Player/AttackingLeft/2.bmp",renderer);
  ressources->playerAttackingLeft[3] = load_imageBMP("Ressources/Sprites/Player/AttackingLeft/3.bmp",renderer);
  ressources->playerAttackingLeft[4] = load_imageBMP("Ressources/Sprites/Player/AttackingLeft/4.bmp",renderer);
  ressources->playerAttackingLeft[5] = load_imageBMP("Ressources/Sprites/Player/AttackingLeft/5.bmp",renderer);

  //---------------------------------------PLAYER----------------------------------------------------//

  //Application de la texture du croco marchant a gauche.//
  ressources->crocoMovingLeft[0] = load_imageBMP("Ressources/Sprites/Mobs/Croco/MovingLeft/0.bmp",renderer);
  ressources->crocoMovingLeft[1] = load_imageBMP("Ressources/Sprites/Mobs/Croco/MovingLeft/1.bmp",renderer);
  ressources->crocoMovingLeft[2] = load_imageBMP("Ressources/Sprites/Mobs/Croco/MovingLeft/2.bmp",renderer);
  //Application de la texture du croco marchant a droite.//
  ressources->crocoMovingRight[0] = load_imageBMP("Ressources/Sprites/Mobs/Croco/MovingRight/0.bmp",renderer);
  ressources->crocoMovingRight[1] = load_imageBMP("Ressources/Sprites/Mobs/Croco/MovingRight/1.bmp",renderer);
  ressources->crocoMovingRight[2] = load_imageBMP("Ressources/Sprites/Mobs/Croco/MovingRight/2.bmp",renderer);

  //Application de la texture du dino marchant à gauche.//
  ressources->dinoMovingLeft[0] = load_imageBMP("Ressources/Sprites/Mobs/Dino/MovingLeft/0.bmp",renderer);
  ressources->dinoMovingLeft[1] = load_imageBMP("Ressources/Sprites/Mobs/Dino/MovingLeft/1.bmp",renderer);
  ressources->dinoMovingLeft[2] = load_imageBMP("Ressources/Sprites/Mobs/Dino/MovingLeft/2.bmp",renderer);
  ressources->dinoMovingLeft[3] = load_imageBMP("Ressources/Sprites/Mobs/Dino/MovingLeft/3.bmp",renderer);

  //Application de la texture du dino marchant à droite.//
  ressources->dinoMovingRight[0] = load_imageBMP("Ressources/Sprites/Mobs/Dino/MovingRight/0.bmp",renderer);
  ressources->dinoMovingRight[1] = load_imageBMP("Ressources/Sprites/Mobs/Dino/MovingRight/1.bmp",renderer);
  ressources->dinoMovingRight[2] = load_imageBMP("Ressources/Sprites/Mobs/Dino/MovingRight/2.bmp",renderer);
  ressources->dinoMovingRight[3] = load_imageBMP("Ressources/Sprites/Mobs/Dino/MovingRight/3.bmp",renderer);

  //Application des textures des plateformes.//
  ressources->platform[0] = load_imageBMP("Ressources/Sprites/GameElements/Platforms/Pelouse/0.bmp", renderer);
  ressources->platform[1] = load_imageBMP("Ressources/Sprites/GameElements/Platforms/Pelouse/1.bmp", renderer);
  ressources->platform[2] = load_imageBMP("Ressources/Sprites/GameElements/Platforms/Pelouse/2.bmp", renderer);
  ressources->platform[3] = load_imageBMP("Ressources/Sprites/GameElements/Platforms/Pelouse/3.bmp", renderer);
  ressources->platform[4] = load_imageBMP("Ressources/Sprites/GameElements/Platforms/Pelouse/4.bmp", renderer);


  //---------------------------------------LABELS----------------------------------------------------//

  //Application de la texture des labels Play.//
  ressources->labelPlay[0] = load_imageBMP("Ressources/Labels/Play/0.bmp",renderer);
  ressources->labelPlay[1] = load_imageBMP("Ressources/Labels/Play/1.bmp",renderer);

  //Application de la texture des labels Help.//
  ressources->labelHelp[0] = load_imageBMP("Ressources/Labels/Help/0.bmp",renderer);
  ressources->labelHelp[1] = load_imageBMP("Ressources/Labels/Help/1.bmp",renderer);

  //Application de la texture des labels Score.//
  ressources->labelScore[0] = load_imageBMP("Ressources/Labels/Score/0.bmp",renderer);
  ressources->labelScore[1] = load_imageBMP("Ressources/Labels/Score/1.bmp",renderer);

  //Application de la texture des labels Exit.//
  ressources->labelExit[0] = load_imageBMP("Ressources/Labels/Exit/0.bmp",renderer);
  ressources->labelExit[1] = load_imageBMP("Ressources/Labels/Exit/1.bmp",renderer);

  //Application de la texture des labels Back.//
  ressources->labelBack[0] = load_imageBMP("Ressources/Labels/Back/0.bmp",renderer);
  ressources->labelBack[1] = load_imageBMP("Ressources/Labels/Back/1.bmp",renderer);

  //Application de la texture des labels No.//
  ressources->labelNo[0] = load_imageBMP("Ressources/Labels/No/0.bmp",renderer);
  ressources->labelNo[1] = load_imageBMP("Ressources/Labels/No/1.bmp",renderer);

  //Application de la texture des labels Yes.//
  ressources->labelYes[0] = load_imageBMP("Ressources/Labels/Yes/0.bmp",renderer);
  ressources->labelYes[1] = load_imageBMP("Ressources/Labels/Yes/1.bmp",renderer);

  //---------------------------------------HELPSPRITES----------------------------------------------------//

  //Application de la texture de l'image de flèche.//
  ressources->arrows = load_imageBMP("Ressources/HelpSprites/0.bmp",renderer);

  //Application de la texture de l'image de barre Espace.//
  ressources->spacebar = load_imageBMP("Ressources/HelpSprites/1.bmp",renderer);


}

//---------------------------------------------------------//
 /**
  * \brief La fonction nettoie les textures du joueur.
  * \param ressources Structure des ressources.
  */

void cleanPlayerTextures(ressources_p ressources){
  if(DEV_MODE){printf("Appel de <cleanPlayerTextures()>.\n");}
  for(int i = 0; i< NB_FRAME_PLAYER_STANDING ;i++){
    clean_texture(ressources->playerStandingRight[i]);
    clean_texture(ressources->playerStandingLeft[i]);
  }
  for(int i = 0; i< NB_FRAME_PLAYER_MOVING ;i++){
    clean_texture(ressources->playerMovingRight[i]);
    clean_texture(ressources->playerMovingLeft[i]);
  }
  for(int i = 0; i< NB_FRAME_PLAYER_JUMPING ;i++){
    clean_texture(ressources->playerJumpingRight[i]);
    clean_texture(ressources->playerJumpingLeft[i]);
  }
  for(int i = 0; i< NB_FRAME_PLAYER_ATTACKING ;i++){
    clean_texture(ressources->playerAttackingRight[i]);
    clean_texture(ressources->playerAttackingLeft[i]);
  }
}

/**
  * \brief La fonction nettoie les textures du croco.
  * \param ressources Structure des ressources.
*/
void cleanCrocoTextures(ressources_p ressources){
  if(DEV_MODE){printf("Appel de <cleanCrocoTextures()>.\n");}
  for(int i = 0; i< NB_FRAME_CROCO_MOVING;i++){
    clean_texture(ressources->crocoMovingLeft[i]);
    clean_texture(ressources->crocoMovingRight[i]);
  }
}

/**
  * \brief La fonction nettoie les textures des plateformes.
  * \param ressources Structure des ressources.
*/
void cleanPlatformsTextures(ressources_p ressources){
  if(DEV_MODE){printf("Appel de <cleanCrocoTextures()>.\n");}
  for(int i = 0; i< NB_PLATFORMS_FRAMES ;i++){
    clean_texture(ressources->platform[i]);
  }
}

/**
  * \brief La fonction nettoie les textures du dino.
  * \param ressources Structure des ressources.
*/
void cleanDinoTextures(ressources_p ressources){
  if(DEV_MODE){printf("Appel de <cleanDinoTextures()>.\n");}
  for(int i = 0; i< NB_FRAME_DINO_MOVING;i++){
    clean_texture(ressources->dinoMovingLeft[i]);
    clean_texture(ressources->dinoMovingRight[i]);
  }
  for (int i =0; i< NB_FRAME_DINO_DEAD; i++) {
    clean_texture(ressources->dinoDead[i]);
  }
}


  /**
  * \brief La fonction nettoie les textures de background.
  * \param ressources Structure des ressources.
  */
void cleanBackgroundTextures(ressources_p ressources){
  if(DEV_MODE){printf("Appel de <cleanBackgroundTextures()>.\n");}
  for(int i = 0; i< NB_FRAME_BACKGROUND;i++){
    clean_texture(ressources->background[i]);
  }
}

/**
* \brief La fonction nettoie les textures de background.
* \param ressources Structure des ressources.
*/
void cleanLabelTextures(ressources_p ressources){
  if(DEV_MODE){printf("Appel de <cleanLabelTextures()>.\n");}
  for(int i = 0; i< 2;i++){
    clean_texture(ressources->labelPlay[i]);
    clean_texture(ressources->labelHelp[i]);
    clean_texture(ressources->labelScore[i]);
    clean_texture(ressources->labelExit[i]);
    clean_texture(ressources->labelBack[i]);
    clean_texture(ressources->labelNo[i]);
    clean_texture(ressources->labelYes[i]);
  }
}

/**
* \brief La fonction nettoie les textures du menu help.
* \param ressources Structure des ressources.
*/
void cleanHelpTextures(ressources_p ressources){
  if(DEV_MODE){printf("Appel de <cleanHelpTextures()>.\n");}
  clean_texture(ressources->arrows);
  clean_texture(ressources->spacebar);
}

 /**
  * \brief La fonction nettoie les textures.
  * \param ressources Structure des ressources.
  */

void cleanRessources(ressources_p ressources){
  if(DEV_MODE){printf("Appel de <cleanTextures()>.\n");}
  //Textures.//
  cleanPlayerTextures(ressources);
  cleanBackgroundTextures(ressources);
  cleanLabelTextures(ressources);
  cleanHelpTextures(ressources);
  cleanCrocoTextures(ressources);
  cleanPlatformsTextures(ressources);

  //Polices d'écriture.//
  clean_font(ressources->font);

}
