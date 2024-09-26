/**
 * \file gestionSon.h
 * \brief Header contenant les modifieurs et définitions du gestionnaire de son.
 * \author Marcelin Maxime/ Tysoun Phillip /Signorino-Gelo Matteo
 * \version 1.0.
 * \date 27 décembre 2021
 */


#include "SDL2/SDL_mixer.h"

#include "struct_ressources.h"

//---------------------------------------------------------//

/**
 *\brief La fonction initialise les données du renderer et de la fenêtre.
 *\param frequency Paramètre de la fréquence.
 *\param format Paramètre du format audio.
 *\param channels Paramètre des canaux de stockage des sons.
 *\param chunksize Paramètre du nombre de bits pour le sons.
*/
int initAudio(int frequency, Uint16 format, int channels, int chunksize);

//---------------------------------------------------------//
/**
  *\brief La fonction permettant de jouer la musique du menu.
  *\param ressources Structure des ressources.
*/
void playMenuMusic(ressources_p ressources);

//---------------------------------------------------------//
/**
  *\brief La fonction permettant de jouer la musique du boss.
  *\param ressources Structure des ressources.
*/
void playBossMusic(ressources_p ressources);

//---------------------------------------------------------//
/**
  *\brief La fonction permettant de jouer la musique du level.
  *\param ressources Structure des ressources.
*/
void playLevelMusic(ressources_p ressources);

//---------------------------------------------------------//
/**
  *\brief La fonction permettant de jouer le son de la mort du joueur.
  *\param ressources Structure des ressources.
*/
void playSoundDeath(ressources_p ressources);

//---------------------------------------------------------//
/**
  *\brief La fonction permettant de jouer le son quand le joueur se fait toucher.
  *\param ressources Structure des ressources.
*/
void playSoundGetHit(ressources_p ressources);

//---------------------------------------------------------//
/**
  *\brief La fonction permettant de jouer le son quand le joueur touche un ennemi.
  *\param ressources Structure des ressources.
*/
void playSoundHit(ressources_p ressources);

//---------------------------------------------------------//
/**
  *\brief La fonction permettant de jouer le son quand le joueur marche.
  *\param ressources Structure des ressources.
*/
void playSoundWalk(ressources_p ressources);

//---------------------------------------------------------//
/**
  *\brief La fonction permettant de jouer le son quand le joueur frappe dans le vide.
  *\param ressources Structure des ressources.
*/
void playSoundSwing(ressources_p ressources);

//---------------------------------------------------------//
/**
  *\brief La fonction permettant de jouer le son quand le joueur saute.
  *\param ressources Structure des ressources.
*/
void playSoundJump(ressources_p ressources);

//---------------------------------------------------------//
/**
  *\brief La fonction permettant de jouer le son quand le curseur séléctionne un menu.
  *\param ressources Structure des ressources.
*/
void playSoundLabel(ressources_p ressources);

//---------------------------------------------------------//
/**
  *\brief La fonction permettant de jouer le son quand le curseur passe sur le menu.
  *\param ressources Structure des ressources.
*/
void playSoundClick(ressources_p ressources);

//---------------------------------------------------------//
/**
*\brief La fonction permet de stopper la musique.
*/
void stopMusic();

//---------------------------------------------------------//
/**
  *\brief La fonction permettant de gerer le jeu de musique.
  *\param ressources Structure des ressources.
  *\param world Structure du monde.
*/
void musics(world_p world, ressources_p ressources);

//---------------------------------------------------------//
/**
*\brief La fonction permet de load les soundseffects et musiques.
*\param ressources Structure de ressources.
*/
void loadSounds(ressources_p ressources);
//---------------------------------------------------------//
/**
*\brief La fonction qui ferme l'audio
*/

void closeAudio(ressources_p ressources);
