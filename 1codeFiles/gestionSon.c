/**
 * \file gestionSon.c
 * \brief Module contenant les profils des fonctions nécessaire à la gestion des sons.
 * \author Marcelin Maxime/ Tysoun Phillip /Signorino-Gelo Matteo
 * \version 1.0
 * \date 27 décembre 2021
 */

 #include <stdio.h>
 #include <stdlib.h>

 #include "SDL2/SDL_mixer.h"

 #include "struct_world.h"
 #include "gestionSon.h"
 #include "constantes.h"
 #include "struct_ressources.h"

//---------------------------------------------------------//
/**
  *\brief La fonction initialise les données du renderer et de la fenêtre.
  *\param frequency Paramètre de la fréquence.
  *\param format Paramètre du format audio.
  *\param channels Paramètre des canaux de stockage des sons.
  *\param chunksize Paramètre du nombre de bits pour le sons.
*/
int initAudio(int frequency, Uint16 format, int channels, int chunksize){
  if(DEV_MODE){printf("Appel de <initAudio())>.\n");}
  Mix_AllocateChannels(10);
  if(Mix_OpenAudio(frequency, format, channels, chunksize) == -1){
    if(DEV_MODE){printf("%s\n", Mix_GetError());}
	}
}

//---------------------------------------------------------//
/**
  *\brief La fonction permettant de jouer la musique du menu.
  *\param ressources Structure des ressources.
*/
void playMenuMusic(ressources_p ressources){
  if(DEV_MODE){printf("Appel de <playMenuMusic())>.\n");}
  if(PLAY_MUSIC){
    Mix_VolumeMusic(VOLUME);

    if(ressources->menuMusic==NULL){
      if(DEV_MODE){printf("menuMusic : %s\n", Mix_GetError());}
    }
    if(Mix_PlayMusic(ressources->menuMusic, -1)==-1){
      if(DEV_MODE){printf("%s\n", Mix_GetError());}
    }
  }
}

//---------------------------------------------------------//
/**
  *\brief La fonction permettant de jouer la musique du boss.
  *\param ressources Structure des ressources.
*/
void playBossMusic(ressources_p ressources){
  if(DEV_MODE){printf("Appel de <playBossMusic())>.\n");}
  if(PLAY_MUSIC){
    Mix_VolumeMusic(VOLUME);
    if(ressources->bossMusic==NULL){
      if(DEV_MODE){printf("bossMusic : %s\n", Mix_GetError());}
    }
    if(Mix_PlayMusic(ressources->bossMusic, -1)==-1){
      if(DEV_MODE){printf("%s\n", Mix_GetError());}
    }
  }
}

//---------------------------------------------------------//
/**
  *\brief La fonction permettant de jouer la musique du level.
  *\param ressources Structure des ressources.
*/
void playLevelMusic(ressources_p ressources){
  if(DEV_MODE){printf("Appel de <playLevelMusic())>.\n");}
  if(PLAY_MUSIC){
    Mix_VolumeMusic(VOLUME);
    if(ressources->levelMusic==NULL){
      if(DEV_MODE){printf("levelMusic : %s\n", Mix_GetError());}
    }
    if(Mix_PlayMusic(ressources->levelMusic, -1)==-1){
      printf("%s", Mix_GetError());
    }
  }
}


//---------------------------------------------------------//
/**
  *\brief La fonction permettant de gerer le jeu de musique.
  *\param ressources Structure des ressources.
  *\param world Structure du monde.
*/
void musics(world_p world, ressources_p ressources){
  if(DEV_MODE){printf("Appel de <musics())>.\n");}
  switch(getCurrentState(world)){
    case MENU_STATE :
      if(Mix_PlayingMusic()!= 1){
        if(DEV_MODE){printf("Music Menu est joué\n");}
        playMenuMusic(ressources);
      }
      break;
    case LEVEL_STATE :
      if(Mix_PlayingMusic()!= 1){
        if(DEV_MODE){printf("Music Level est joué \n");}
        playLevelMusic(ressources);
      }
      break;
  }
}

//---------------------------------------------------------//
/**
  *\brief La fonction permettant de jouer le son de la mort du joueur.
  *\param ressources Structure des ressources.
*/
void playSoundDeath(ressources_p ressources){
  if(PLAY_SOUNDS){
    if(ressources->death==NULL){
      if(DEV_MODE){printf("deathSE : %s\n", Mix_GetError());}
    }
    Mix_VolumeChunk(ressources->death, 0);
    Mix_PlayChannel(1, ressources->death, 0);
  }
}

//---------------------------------------------------------//
/**
  *\brief La fonction permettant de jouer le son quand le joueur se fait toucher.
  *\param ressources Structure des ressources.
*/
void playSoundGetHit(ressources_p ressources){
  if(PLAY_SOUNDS){
    if(ressources->getHit==NULL){
      if(DEV_MODE){printf("getHitSE : %s\n", Mix_GetError());}
    }
    Mix_VolumeChunk(ressources->getHit, 30);
    Mix_PlayChannel(1, ressources->getHit, 0);
  }
}

//---------------------------------------------------------//
/**
  *\brief La fonction permettant de jouer le son quand le joueur touche un ennemi.
  *\param ressources Structure des ressources.
*/
void playSoundHit(ressources_p ressources){
  if(PLAY_SOUNDS){
    if(ressources->hit==NULL){
      if(DEV_MODE){printf("hitSE : %s\n", Mix_GetError());}
    }
    Mix_VolumeChunk(ressources->hit, 30);
    Mix_PlayChannel(1, ressources->hit, 0);
  }
}

//---------------------------------------------------------//
/**
  *\brief La fonction permettant de jouer le son quand le joueur marche.
  *\param ressources Structure des ressources.
*/
void playSoundWalk(ressources_p ressources){
  if(PLAY_SOUNDS){
      if(ressources->walk==NULL){
        if(DEV_MODE){printf("walkSE : %s\n", Mix_GetError());}
      }
      Mix_VolumeChunk(ressources->walk, 30);
      Mix_PlayChannel(1, ressources->walk,0);
  }
}

//---------------------------------------------------------//
/**
  *\brief La fonction permettant de jouer le son quand le joueur frappe dans le vide.
  *\param ressources Structure des ressources.
*/
void playSoundSwing(ressources_p ressources){
  if(PLAY_SOUNDS){
    if(ressources->swing==NULL){
      if(DEV_MODE){printf("swingSE : %s\n", Mix_GetError());}
    }
    Mix_VolumeChunk(ressources->swing, 30);
    Mix_PlayChannel(1, ressources->swing, 0);
  }
}

//---------------------------------------------------------//
/**
  *\brief La fonction permettant de jouer le son quand le joueur saute.
  *\param ressources Structure des ressources.
*/
void playSoundJump(ressources_p ressources){
  if(PLAY_SOUNDS){
    if(ressources->jump==NULL){
      if(DEV_MODE){printf("jumpSE : %s\n", Mix_GetError());}
    }
    Mix_VolumeChunk(ressources->jump, 30);
    Mix_PlayChannel(1, ressources->jump, 0);
  }
}

//---------------------------------------------------------//
/**
  *\brief La fonction permettant de jouer le son quand le curseur séléctionne un menu.
  *\param ressources Structure des ressources.
*/
void playSoundLabel(ressources_p ressources){
  if(PLAY_SOUNDS){
    if(ressources->label==NULL){
      if(DEV_MODE){printf("labelSE : %s\n", Mix_GetError());}
    }
    Mix_VolumeChunk(ressources->label, 30);
    Mix_PlayChannel(1, ressources->label, 0);

      //printf("DUH") ;
    }
  }


//---------------------------------------------------------//
/**
  *\brief La fonction permettant de jouer le son quand le curseur passe sur le menu.
  *\param ressources Structure des ressources.
*/
void playSoundClick(ressources_p ressources){
  if(PLAY_SOUNDS){
    if(ressources->click==NULL){
      //if(DEV_MODE){
      printf("clickSE : %s\n", Mix_GetError());
    }
    Mix_PlayChannel(1, ressources->click, 0);
  }
}

//---------------------------------------------------------//
/**
*\brief La fonction permet de load les soundseffects et musiques.
*\param ressources Structure de ressources.
*/
void loadSounds(ressources_p ressources){
  //MUSICS.//
  if(PLAY_MUSIC){
    ressources->menuMusic = Mix_LoadMUS("Ressources/Son/Music/menu.ogg");
    ressources->bossMusic = Mix_LoadMUS("Ressources/Son/Music/boss.ogg");
    ressources->levelMusic = Mix_LoadMUS("Ressources/Son/Music/level.ogg");
  }
  if(PLAY_SOUNDS){
    //SOUNDS.//
    ressources->click = Mix_LoadWAV("Ressources/Son/SoundEffect/click.ogg");
    ressources->death = Mix_LoadWAV("Ressources/Son/SoundEffect/getHit.ogg");
    ressources->getHit = Mix_LoadWAV("Ressources/Son/SoundEffect/getHit.ogg");
    ressources->hit = Mix_LoadWAV("Ressources/Son/SoundEffect/hit.ogg");
    ressources->walk = Mix_LoadWAV("Ressources/Son/SoundEffect/walk.ogg");
    ressources->swing = Mix_LoadWAV("Ressources/Son/SoundEffect/swing1.ogg");
    ressources->jump = Mix_LoadWAV("Ressources/Son/SoundEffect/jump.ogg");
    ressources->label = Mix_LoadWAV("Ressources/Son/SoundEffect/label.ogg");
  }
}


//---------------------------------------------------------//
/**
 *\brief La fonction qui ferme l'audio.
*/
void closeAudio(ressources_p ressources){
  if(DEV_MODE){printf("Appel de <closeAudio())>.\n");}
  if(PLAY_MUSIC){
    Mix_FreeMusic(ressources->menuMusic);
    Mix_FreeMusic(ressources->levelMusic);
    Mix_FreeMusic(ressources->bossMusic);
  }
  if(PLAY_SOUNDS){
    Mix_FreeChunk(ressources->death);
    Mix_FreeChunk(ressources->getHit);
    Mix_FreeChunk(ressources->hit);
    Mix_FreeChunk(ressources->walk);
    Mix_FreeChunk(ressources->swing);
    Mix_FreeChunk(ressources->jump);
    Mix_FreeChunk(ressources->label);
    Mix_FreeChunk(ressources->click);
  }
  Mix_CloseAudio();
}


//---------------------------------------------------------//
/**
 *\brief La fonction qui ferme l'audio.
*/
void stopMusic(){
    if(DEV_MODE){printf("Appel de <stopMusic())>.\n");}
    Mix_HaltMusic();

}
