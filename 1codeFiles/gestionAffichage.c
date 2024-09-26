/**
 * \file gestionAffichage.c
 * \brief Fichier contenant les modifieurs et définitions du gestionnaire de jeu.
 * \author Marcelin Maxime/ Tysoun Phillip /Signorino-Gelo Matteo
 * \version 1.0.
 * \date 03 novembre 2021
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sdl2-light.h"

#include "struct_sprite.h"
#include "gestionAffichage.h"
#include "struct_world.h"
#include "struct_ressources.h"
#include "constantes.h"


//------------------------INIT------------------------------//
 /**
  * \brief La fonction initialise les données du renderer et de la fenêtre.
  * \param window La fenêtre du jeu.
  * \param renderer Le renderer.
  * \param ressources Les ressources.
  */
void initGraphique(SDL_Window ** window, SDL_Renderer ** renderer, ressources_p ressources){
  if(DEV_MODE){printf("Appel de <initGraphique()>.\n");}

  //SDL.//
  int error = init_sdl(window,renderer,WIDTH,HEIGHT);
  if(error == -1){
    printf("Unfortunately, there was an error while initializing the game window. Exiting ...\n");
    exit(0);
  }

  //Ressources.//
  SDL_SetRenderDrawColor(*renderer, 210, 255, 0, 255);
  loadRessources(*renderer, ressources);
}

//----------------------BACKGROUND-----------------------------//
/**
 * \brief La fonction applique la texture du fond sur le renderer lié à l'écran de jeu.
 * \param renderer Le renderer.
 * \param texture La texture liée au fond.
*/
void applyBackground(SDL_Renderer *renderer, SDL_Texture *texture){
  if(DEV_MODE){printf("Appel de <applyBackground()>.\n");}
  //Vérification de l'abscence de textures de background//
  if(texture != NULL){
    apply_texture(texture, renderer, 0, 0);
  }
}

//----------------------PLATFORMS-----------------------------//
/**
 * \brief La fonction applique la texture des plateformes dans le renderer.
 * \param renderer Le renderer.
 * \param ressources Les ressources.
 * \param world Le Monde.
*/
void applyPlatforms(SDL_Renderer *renderer, ressources_p ressources, world_p world){
  if(DEV_MODE){printf("Appel de <applyPlatforms()>.\n");}
  /*level_p level = getHead(world->levels);

  for(int i = 0; i< level->nbPlatforms ; i++){
    sprite_p platform = &level->platforms[i];

    if((platform->x + platform-> w<WIDTH)&&(platform->x - platform-> w>0)){
      if(platform->w ==100){
        apply_texture(ressources->platform[0], renderer, platform->x - platform->w/2, platform->y - platform->h/2);
      }else if(platform->w == 200){
        apply_texture(ressources->platform[1], renderer, platform->x - platform->w/2, platform->y - platform->h/2);
      }else if(platform->w == 300){
        apply_texture(ressources->platform[2], renderer, platform->x - platform->w/2, platform->y - platform->h/2);
      }else if(platform->w == 400){
        apply_texture(ressources->platform[3], renderer, platform->x - platform->w/2, platform->y - platform->h/2);
      }else if(platform->w == 500){
        apply_texture(ressources->platform[5], renderer, platform->x - platform->w/2, platform->y - platform->h/2);
      }
    }
  }
  */
}



//----------------------LABELS---------------------------//
/**
 * \brief La fonction applique les textures des labels d'option du jeu lors de l'affichage du menu.
 * \param renderer Le renderer.
 * \param ressources Les ressources.
 * \param world Le monde.
*/
void applyLabels(SDL_Renderer *renderer, ressources_p ressources, world_p world){
  if(DEV_MODE){printf("Appel de <applySprites()>.\n");}
  sprite_p sprite;
  switch(getCurrentMenu(world)){
    case 0:
      //Label 1 : "PLAY"
      sprite = getLabels(world,0);
      apply_texture(ressources->labelPlay[getIsHighlighted(sprite)], renderer, sprite->x - sprite->w/2, sprite->y - sprite->h/2);

      //Label 2: "HELP"
      sprite = getLabels(world,1);
      apply_texture(ressources->labelHelp[getIsHighlighted(sprite)], renderer, sprite->x - sprite->w/2, sprite->y - sprite->h/2);

      //Label 3: "SCORE"
      sprite = getLabels(world,2);
      apply_texture(ressources->labelScore[getIsHighlighted(sprite)], renderer, sprite->x - sprite->w/2, sprite->y - sprite->h/2);

      //Label 4: "EXIT"
      sprite = getLabels(world,3);
      apply_texture(ressources->labelExit[getIsHighlighted(sprite)], renderer, sprite->x - sprite->w/2, sprite->y - sprite->h/2);

      break;
    case 3:     //Cas où l'on doit afficher les boutons Yes et No dans un niveau.

      //Label 5: "NO"
      sprite = getLabels(world,5);
      apply_texture(ressources->labelYes[getIsHighlighted(sprite)], renderer, sprite->x - sprite->w/2, sprite->y - sprite->h/2);

      //Label 6: "YES"
      sprite = getLabels(world,6);
      apply_texture(ressources->labelNo[getIsHighlighted(sprite)], renderer, sprite->x - sprite->w/2, sprite->y - sprite->h/2);
      break;

    default :
      sprite = getLabels(world,4);
      apply_texture(ressources->labelBack[getIsHighlighted(sprite)], renderer, sprite->x - sprite->w/2, sprite->y - sprite->h/2);
      break;

  }
}

//----------------------TEXTES---------------------------//
/**
 * \brief La fonction applique le message du menu de pause.
 * \param renderer Le renderer.
 * \param ressources Les ressources.
*/
void applyPauseMessage(SDL_Renderer *renderer, ressources_p ressources){
  if(DEV_MODE){printf("Appel de <applyMainTitle()>.\n");}

  char title[28] = "Are you sure you want to";
  apply_text(renderer, WIDTH/2 - 300, 40, 600, 100, title, ressources->font);

  sprintf(title, "go back to the main title ?");
  apply_text(renderer, WIDTH/2 - 300, 170, 600, 100, title, ressources->font);

  sprintf(title, "All progress will be lost !");
  apply_text(renderer, WIDTH/2 - 300, HEIGHT/2 + 100, 600, 100, title, ressources->font);
}

//---------------------------------------------------------//
/**
 * \brief La fonction applique le message du menu de mort.
 * \param renderer Le renderer.
 * \param ressources Les ressources.
*/
void applyDeathMessage(SDL_Renderer *renderer, ressources_p ressources){
  if(DEV_MODE){printf("Appel de <applyDeathMessage()>.\n");}

  char title[28] = "*  GAME OVER  *";
  apply_text(renderer, WIDTH/2 - 300, 40, 600, 100, title, ressources->font);
}

//---------------------------------------------------------//
/**
 * \brief La fonction applique le titre de l'écran titre.
 * \param renderer Le renderer.
 * \param ressources Les ressources.
*/
void applyMainTitle(SDL_Renderer *renderer, ressources_p ressources){
  if(DEV_MODE){printf("Appel de <applyMainTitle()>.\n");}

  char title[16] = "* Prehistoric *";
  apply_text(renderer, WIDTH/2 - 350, 40, 700, 130, title, ressources->font);
}

//-----------------------HELP MENU-----------------------------//
/**
 * \brief La fonction applique les images et textes du menu Help.
 * \param renderer Le renderer.
 * \param ressources Les ressources.
*/
void applyHelpMenu(SDL_Renderer *renderer, ressources_p ressources){
  if(DEV_MODE){printf("Appel de <applyHelpMenu()>.\n");}

  //Titre.//
  char text[29] = "* CONTROLS *";
  apply_text(renderer, WIDTH/2 - 175, 40, 400, 75, text, ressources->font);


  //Schéma Flèches.//
  apply_texture(ressources->arrows, renderer, -50, 125);
  //Schéma Barre Espace.//
  apply_texture(ressources->spacebar, renderer, 20, 500);


  //Texte Description Flèches.//
  sprintf(text, "<UP> : Jump");
  apply_text(renderer, WIDTH/2 - 200, 200, 200, 60, text, ressources->font);

  sprintf(text,"<LEFT> : Go left");
  apply_text(renderer, WIDTH/2 - 200, 400, 300, 60, text, ressources->font);

  sprintf(text,"<RIGHT> : Go right");
  apply_text(renderer, WIDTH/2 - 200, 500, 300, 60, text, ressources->font);

  //Texte Description Barre Espace.//
  sprintf(text,"<SPACE> : Attack");
  apply_text(renderer, WIDTH/2 - 200, 625, 350, 60, text, ressources->font);

}


//----------------------SCORE---------------------------//
/**
 * \brief La fonction permet d'afficher les 5 meilleurs scores.
 * \param top5 Tableau contenant le Top 5 des meilleurs Scores.
*/
void tableauScore(int top5[]){
  if(DEV_MODE){printf("Appel de <tableauScore()>.\n");}

  //Opening file.
  FILE* file = fopen("Ressources/Score/score.txt", "r");
  if(file == NULL){
    printf("[ERROR] - While opening score file !\n");
    return;
  }else{
    //Counting lines.//
    if(DEV_MODE){printf("\n\n####====SCORE FILE====####\n");}

    int nbLines = 0;
    char c = fgetc(file);
    while(c != EOF){
      if(c=='\n'){
        nbLines++;
      }
      c = fgetc(file);
    }
    if(DEV_MODE){printf("Number of lines in the file : %i \n", nbLines);}
    if(nbLines == 0){
      printf("[ERROR] - While reading score file, no lines were detected, bad indentation mabe ?\n");
      return ;
    }

    //Going back to the beginning of the file.
    rewind(file);

    //Counting Score Entries.//
    int i = 0;
    int scorePoints;
    int tab[nbLines];

    while(i < nbLines){
      fscanf(file,"%i\n", &scorePoints);                            //Scanning line.
      if(DEV_MODE){printf("Line N°%i : %i\n", i+1 , scorePoints);}
      tab[i] = scorePoints;
      if(DEV_MODE){printf("Registered : %i\n\n",tab[i]);}
      i++;
    }
    if(DEV_MODE){printf("\n####==================####\n\n");}

    //Extracting the 5 Highest scores.//
    int indiceMax = 0;
    for(int i = 0; i<5; i++){
      for(int j = 0; j < nbLines; j++){
        if(tab[j]>=tab[indiceMax]){
          indiceMax = j;
        }
      }
      top5[i] = tab[indiceMax];
      if(DEV_MODE){printf("top5 : %i\n", top5[i]);}
      tab[indiceMax] = -1;
      if(DEV_MODE){printf("tab : %i\n", tab[indiceMax]);}
    }
    fclose (file);
  }
}

//---------------------------------------------------------//
/**
 * \brief La fonction applique le titre des scores.
 * \param renderer Le renderer.
 * \param ressources Les ressources.
*/
void applyScore(SDL_Renderer *renderer, ressources_p ressources){
  if(DEV_MODE){printf("Appel de <applyScore)>.\n");}

  //-----DISPLAYING TITLES-----//

  char text[30] = "[High Scores]";                                              //affichage du titre
  apply_text(renderer, WIDTH/2 - 310, 40, 600, 110, text, ressources->font);    // dimension du titre

  //-----LISTING SCORES-----//

  int top5[5];        //Initializing scores to 0.
  for(int i = 0; i<5; i++){
    top5[i] = 0;
  }

  tableauScore(top5);
  sprintf(text, "%i", top5[0]);                                                     //affichage score 1
  apply_text(renderer, WIDTH/2 - 100, 200, 200, 40, text, ressources->font);        //dimension score

  sprintf(text, "%i", top5[1]);                                                     //affichage score  2
  apply_text(renderer, WIDTH/2 - 100, 275, 200, 40, text, ressources->font);        //dimension score

  sprintf(text, "%i", top5[2]);                                                     //affichage score  3
  apply_text(renderer, WIDTH/2 - 100, 350, 200, 40, text, ressources->font);        //dimension score

  sprintf(text, "%i", top5[3]);                                                     //affichage score  4
  apply_text(renderer, WIDTH/2 - 100, 425, 200, 40, text, ressources->font);        //dimension score

  sprintf(text, "%i", top5[4]);                                                     //affichage score 5
  apply_text(renderer, WIDTH/2 - 100, 500, 200, 40, text, ressources->font);        //dimension score

}

//--------------------PLAYER ANIMATION------------------------------//
/**
 * \brief La fonction applique la texture du Player à l'écran du jeu.
 * \param renderer Le renderer.
 * \param ressources Les ressources.
 * \param sprite Les sprites.
*/
void applyPlayer(SDL_Renderer *renderer, ressources_p ressources, sprite_p sprite){
  if(DEV_MODE){printf("Appel de <applyPlayer()>.\n");}

  if(getIsAttacking(sprite)){
    if(getFacing(sprite)==FACING_RIGHT){
      apply_texture(ressources->playerAttackingRight[getCurrentFrame(sprite)], renderer, sprite->x - sprite->w/2, sprite->y - sprite->h/2);
    }else{
      apply_texture(ressources->playerAttackingLeft[getCurrentFrame(sprite)], renderer, sprite->x - sprite->w/2, sprite->y - sprite->h/2);
    }

  }else if(getIsMoving(sprite)){
    if(getFacing(sprite)==FACING_RIGHT){
      apply_texture(ressources->playerMovingRight[getCurrentFrame(sprite)], renderer, sprite->x - sprite->w/2, sprite->y - sprite->h/2);
    }else{
      apply_texture(ressources->playerMovingLeft[getCurrentFrame(sprite)], renderer, sprite->x - sprite->w/2, sprite->y - sprite->h/2);
    }
  }else if(getIsStanding(sprite)){
    if(getFacing(sprite)==FACING_RIGHT){
      apply_texture(ressources->playerStandingRight[getCurrentFrame(sprite)], renderer, sprite->x - sprite->w/2, sprite->y - sprite->h/2);
    }else{
      apply_texture(ressources->playerStandingLeft[getCurrentFrame(sprite)], renderer, sprite->x - sprite->w/2, sprite->y - sprite->h/2);
    }
  }else if(getIsJumping(sprite)){
    if(getFacing(sprite)==FACING_RIGHT){
      apply_texture(ressources->playerJumpingRight[getCurrentFrame(sprite)], renderer, sprite->x - sprite->w/2, sprite->y - sprite->h/2);
    }else{
      apply_texture(ressources->playerJumpingLeft[getCurrentFrame(sprite)], renderer, sprite->x - sprite->w/2, sprite->y - sprite->h/2);
    }
  }
}

//---------------------DISPLAYING SPRITES--------------------------//
/**
 * \brief La fonction applique la texture du fond sur le renderer lié à l'écran de jeu.
 * \param renderer Le renderer.
 * \param ressources Les ressources.
 * \param world Le monde.
*/
void applySprites(SDL_Renderer *renderer, ressources_p ressources, world_p world){
  if(DEV_MODE){printf("Appel de <applySprites()>.\n");}
  //Sprite du joueur.//
  applyPlayer(renderer, ressources, getPlayer(world));

  //Sprites des mobs.//

}

//---------------------REFRESH GRAPHICS-----------------------------//
/**
 * \brief La fonction rafraîchit l'écran en fonction de l'état des données du monde.
 * \param renderer Le renderer lié à l'écran de jeu.
 * \param world Les données du monde.
 * \param ressources Les ressources.
 */
void refreshGraphics(SDL_Renderer *renderer, world_p world, ressources_p ressources){
  if(DEV_MODE){printf("Appel de <refreshGraphics()>.\n");}

  //Nettoyage du renderer//
  clear_renderer(renderer);

  //Calcul de l'affichage.//
  switch(getCurrentState(world)){
		case MENU_STATE :
      applyBackground(renderer, ressources->background[0]);					          //Application du Background.//
      if(getCurrentMenu(world)==0){                                           //Menu Principal.//
        applyPlayer(renderer, ressources, getPlayer(world));                  //Application du Sprite du joueur pour l'animation.//
        applyMainTitle(renderer, ressources);                                 //Application du titre du jeu dans le menu.//
      }else if(getCurrentMenu(world)==1){                                     //Menu Help.//
        applyHelpMenu(renderer, ressources);
      }else if(getCurrentMenu(world)==2){                                     //Menu Score.//
        applyScore(renderer, ressources) ;

      }
      applyLabels(renderer, ressources, world);                               //Application des labels des menus.//
      break;

    case PAUSE_STATE :
      applyBackground(renderer, ressources->background[getCurrentLevel(world)%2]);		//Application du Background.//
      applySprites(renderer, ressources, world);                                      //Application des Sprites des mobs/ du joueur etc...//
      applyPauseMessage(renderer, ressources);                                        //Application du message de pause.//
      applyLabels(renderer, ressources, world);                                       //Application des labels des menus.//
      applyPlatforms(renderer, ressources, world);
      break;

		case LEVEL_STATE :
      //Application des textures dans le renderer//
      applyBackground(renderer, ressources->background[getCurrentLevel(world)%2]);	  //Application du Background.//
      applySprites(renderer, ressources, world);                                      //Application des Sprites des mobs/ du joueur etc...//
      applyPlatforms(renderer, ressources, world);
			break;
	}

  //Mise à jour l'écran//
  update_screen(renderer);
}



//-----------------------CLEAN----------------------------------//
 /**
  * \brief La fonction nettoie les données graphiques.
  * \param window La fenêtre du jeu.
  * \param renderer Le renderer.
  * \param ressources Structure des ressources.
  */
void cleanGraphique(SDL_Window ** window, SDL_Renderer ** renderer, ressources_p ressources){
  if(DEV_MODE){printf("Appel de <cleanGraphique()>.\n");}

  cleanRessources(ressources);
  clean_sdl(*renderer,*window);
}
