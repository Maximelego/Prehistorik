/**
 * \file gestionEvenements.c
 * \brief Fichier contenant les définitions des fonctions nécessaire à la gestion des évènements.
 * \author Marcelin Maxime/ Tysoun Phillip /Signorino-Gelo Matteo
 * \version 1.0
 * \date 02 décembre 2021
 */

#include "constantes.h"
#include "sdl2-light.h"
#include "struct_world.h"
#include "struct_ressources.h"
#include "struct_sprite.h"

#include "gestionSon.h"
#include "gestionEvenements.h"
#include "gestionDonnees.h"

//#################################-----FONCTIONS ET PROCEDURES-----#################################//

/**
 * \brief La fonction gère les évènements ayant eu lieu et qui n'ont pas encore été traités.
 * \param event Paramètre qui contient les événements
 * \param world Les données du monde.
 * \param ressources Structure des ressources
 */
void handleEvents(SDL_Event *event, world_p world, ressources_p ressources){
    if(DEV_MODE){printf("Appel de <handleEvents()>.\n");}
    sprite_p sprite = getPlayer(world);
    /*Début*/
    Uint8 *keystates;
    while( SDL_PollEvent( event ) ) {
        //Fermeture par clic sur "X" de la fenêtre.//
        if( event->type == SDL_QUIT ) {
            //Indication de la fin du jeu.//
            //printf("APPUI SUR 'X' ! \n");
            handleExit(world);
        }
        switch(getCurrentState(world)){
          int x,y;

          case MENU_STATE :
            handleMenuEvents(world, event, ressources);
            break;

          case PAUSE_STATE :
            handlePauseEvents(world, event, ressources);
            break;

          case LEVEL_STATE :
            handleLevelEvents(world, event, ressources);
            break;
        }
      }
    /*Fin*/
}



/**
 * \brief La fonction gère les actions à prendre lors d'un menu.
 * \param world Les données du monde.
 * \param event Paramètre qui contient les événements
 * \param ressources Structure des ressources
 */
void handleMenuEvents(world_p world, SDL_Event *event, ressources_p ressources){
  if(DEV_MODE){printf("Appel de <handleMenuEvents()>.\n");}
  int x,y;

  if(event->type == SDL_KEYDOWN){
    if(event->key.keysym.sym == SDLK_ESCAPE){        //Gestion de la fermeture du jeu par appui de la touche "ECHAP".//
      //printf("APPUI SUR ECHAP ! \n");
      handleExit(world);
    }
  }

  //Hovering Menu Labels.//
  x = event->motion.x;
  y = event->motion.y;
  //printf("x = %i \n", x);
  //printf("y = %i \n", y);

  if(getCurrentMenu(world)==0){       //Menu Principal.//

    if(isInHitbox(getLabels(world, 0), x, y)){        //PLAY.//
      if(!getIsHighlighted(getLabels(world, 0))){
        setIsHighlighted(getLabels(world, 0),1);
        playSoundLabel(ressources);
      }
    }else if(getIsHighlighted(getLabels(world, 0))){
      setIsHighlighted(getLabels(world, 0),0);
    }

    if(isInHitbox(getLabels(world, 1), x, y)){        //HELP.//
      if(!getIsHighlighted(getLabels(world, 1))){
        setIsHighlighted(getLabels(world, 1),1);
        playSoundLabel(ressources);
      }
    }else if(getIsHighlighted(getLabels(world, 1))){
      setIsHighlighted(getLabels(world, 1),0);
    }

    if(isInHitbox(getLabels(world, 2), x, y)){        //SCORE.//
      if(!getIsHighlighted(getLabels(world, 2))){
        setIsHighlighted(getLabels(world, 2),1);
        playSoundLabel(ressources);
      }
    }else if(getIsHighlighted(getLabels(world, 2))){
      setIsHighlighted(getLabels(world, 2),0);
    }

    if(isInHitbox(getLabels(world, 3), x, y)){        //EXIT.//
      if(!getIsHighlighted(getLabels(world, 3))){
        setIsHighlighted(getLabels(world, 3),1);
        playSoundLabel(ressources);
      }
    }else if(getIsHighlighted(getLabels(world, 3))){
      setIsHighlighted(getLabels(world, 3),0);
    }


    if(event->type == SDL_MOUSEBUTTONDOWN){
      if((isInHitbox(getLabels(world, 0), x, y))){      //Action Bouton Play.//
        stopMusic();
        setCurrentState(world, LEVEL_STATE);
        setCurrentLevel(world, 1);
        initSpritePlayer(world);

      }
      if((isInHitbox(getLabels(world, 1), x, y))){      //Action Bouton Help.//
        setCurrentMenu(world,1);

      }
      if((isInHitbox(getLabels(world, 2), x, y))){      //Action Bouton Score.//
        setCurrentMenu(world,2);

      }
      if((isInHitbox(getLabels(world, 3), x, y))){      //Action Bouton Exit.//
        handleExit(world);

      }
    }
  }else{                                               //Menu Help et Score.//
    if(isInHitbox(getLabels(world, 4), x, y)){        //BACK.//
      if(!getIsHighlighted(getLabels(world, 4))){
        setIsHighlighted(getLabels(world, 4),1);
        playSoundLabel(ressources);
      }
    }else if(getIsHighlighted(getLabels(world, 4))){
      setIsHighlighted(getLabels(world, 4),0);
    }

    if(event->type == SDL_MOUSEBUTTONDOWN){
      if((isInHitbox(getLabels(world, 4), x, y))){      //Action Bouton Back.//

        setCurrentMenu(world,0);

      }
    }
  }
}

/**
 * \brief La fonction gère les actions à prendre lors d'un menu pause.
 * \param world Les données du monde.
 * \param event Paramètre qui contient les événements
 * \param ressources Structure des ressources
 */
void handlePauseEvents(world_p world, SDL_Event *event, ressources_p ressources){
  if(DEV_MODE){printf("Appel de <handlePauseEvents()>.\n");}

  int x,y;
  //Hovering Menu Labels.//
  x = event->motion.x;
  y = event->motion.y;
  //printf("x = %i \n", x);
  //printf("y = %i \n", y);

  if(event->type == SDL_KEYDOWN){
    if(event->key.keysym.sym == SDLK_ESCAPE){        //Gestion de la fermeture du jeu par appui de la touche "ECHAP".//
      //printf("APPUI SUR ECHAP ! \n");
      setCurrentState(world, LEVEL_STATE);
    }
  }

  if(isInHitbox(getLabels(world, 5), x, y)){        //YES.//
    if(!getIsHighlighted(getLabels(world, 5))){
      setIsHighlighted(getLabels(world, 5),1);
      playSoundLabel(ressources);
    }
  }else if(getIsHighlighted(getLabels(world, 5))){
    setIsHighlighted(getLabels(world, 5),0);
  }

  if(isInHitbox(getLabels(world, 6), x, y)){        //NO.//
    if(!getIsHighlighted(getLabels(world, 6))){
      setIsHighlighted(getLabels(world, 6),1);
      playSoundLabel(ressources);
    }
  }else if(getIsHighlighted(getLabels(world, 6))){
    setIsHighlighted(getLabels(world, 6),0);
  }

  if(event->type == SDL_MOUSEBUTTONDOWN){
    if((isInHitbox(getLabels(world, 5), x, y))){      //Action Bouton YES.//

      stopMusic();
      setCurrentState(world, MENU_STATE);
      setCurrentMenu(world, 0);
      initSpritePlayer(world);

    }
    if((isInHitbox(getLabels(world, 6), x, y))){      //Action Bouton NO.//

      setCurrentState(world, LEVEL_STATE);

    }
  }
}

/**
 * \brief La fonction gère les actions à prendre lors d'un niveau.
 * \param world Les données du monde.
 * \param event Paramètre qui contient les événements
 * \param ressources Structure des ressources
 */
void handleLevelEvents(world_p world, SDL_Event *event, ressources_p ressources){
  //Gestion des évênements de pression de touches.//
  if(event->type == SDL_KEYDOWN){
    if(event->key.keysym.sym == SDLK_ESCAPE){        //Gestion de la fermeture du jeu par appui de la touche "ECHAP".//
      setCurrentState(world, PAUSE_STATE);
      setCurrentMenu(world,3);

    }else if(event->key.keysym.sym == SDLK_UP){           //Gestion de la déplacement du player par appui de la touche "FLECHE HAUT".//
      handleUpMove(world, ressources);

    }else if(event->key.keysym.sym == SDLK_LEFT){         //Gestion de la déplacement du player par appui de la touche "FLECHE GAUCHE".//
      handleLeftMove(world, ressources);

    }else if(event->key.keysym.sym == SDLK_RIGHT){        //Gestion de la déplacement du player par appui de la touche "FLECHE DROITE".//
      handleRightMove(world, ressources);

    }else if(event->key.keysym.sym == SDLK_SPACE){        //Gestion de l'attaque du player par appui de la touche "ESPACE".//
      handleAttack(world, ressources);

    }

  }else{
    handleNoneEvent(world);
  }
}



/**
 * \brief La fonction gère les actions à prendre lors de non-appui sur une touche.
 * \param world Les données du monde.
 */
void handleNoneEvent(world_p world){
  if(DEV_MODE){printf("Appel de <handleNoneEvent()>.\n");}
  if((!getIsAttacking(getPlayer(world)))&&(!getIsJumping(getPlayer(world)))){
    setIsMoving(getPlayer(world),0);
    setIsStanding(getPlayer(world),1);
  }
}

/**
 * \brief La fonction gère la signalisation au jeu de la fermeture.
 * \param world Les données du monde.
 */
void handleExit(world_p world){
  if(DEV_MODE){printf("Appel de <handleExit()>.\n");}
  setGameOver(world, 1);
}

/**
 * \brief La fonction gère les attaques du joueur.
 * \param world Les données du monde.
 * \param ressources Structure des ressources
 */
void handleAttack(world_p world, ressources_p ressources){
  if(DEV_MODE){printf("Appel de <handleAttack()>.\n");}

  setIsAttacking(getPlayer(world),1);
  setIsMoving(getPlayer(world),0);
  setIsStanding(getPlayer(world),0);
  setIsJumping(getPlayer(world),0);

  if(getCurrentFrame(getPlayer(world)) == 0 &&(getTimer(getPlayer(world))<=30)){
    playSoundSwing(ressources);
  }
}


/**
 * \brief La fonction gère les sauts du joueur.
 * \param world Les données du monde.
 * \param ressources Structure des ressources
 */
void handleUpMove(world_p world, ressources_p ressources){
  if(DEV_MODE){printf("Appel de <handleUpMove()>.\n");}
  if(!getIsJumping(getPlayer(world))&&(getVY(getPlayer(world))==0)&&(!getIsAttacking(getPlayer(world)))){
    setIsJumping(getPlayer(world),1);
    sprite_p sprite = getPlayer(world);
    sprite->y = sprite->y -1;
    setVY(getPlayer(world), -50);
  }

  if(getCurrentFrame(getPlayer(world)) == 0 &&(getTimer(getPlayer(world))<=30)){
    playSoundJump(ressources);
  }

}


/**
 * \brief La fonction gère les déplacements à gauche du joueur.
 * \param world Les données du monde.
 * \param ressources Structure des ressources
 */
void handleLeftMove(world_p world, ressources_p ressources){
  if(DEV_MODE){printf("Appel de <handleLeftMove()>.\n");}
  if(!getIsAttacking(getPlayer(world))){
    moveLeftSprite(world, getPlayer(world));
  }
  if(getCurrentFrame(getPlayer(world)) == 0 &&(getTimer(getPlayer(world))<=30)){
    playSoundWalk(ressources);
  }
}

/**
 * \brief La fonction gère les déplacements à droite du joueur.
 * \param world Les données du monde.
 * \param ressources Structure des ressources
 */
void handleRightMove(world_p world, ressources_p ressources){
  if(DEV_MODE){printf("Appel de <handleRightMove()>.\n");}
  if(!getIsAttacking(getPlayer(world))){
    moveRightSprite(world, getPlayer(world));
  }
  if(getCurrentFrame(getPlayer(world)) == 0 &&(getTimer(getPlayer(world))<=30)){
    playSoundWalk(ressources);
  }
}
