
/**
 * \file main.c
 * \brief Fichier contenant la boucle main du jeu.
 * \author Marcelin Maxime/ Tysoun Phillip /Signorino-Gelo Matteo
 * \version 1.0.
 * \date 12 octobre 2021
 */

// Ligne de Debug à placer avant chaque fonction !.//
// if(DEV_MODE){printf("Appel de <FONCTION>.\n");}

#include <stdio.h>
#include <stdlib.h>

#include "sdl2-light.h"
#include "SDL2/SDL_mixer.h"

#include "gestionDonnees.h"
#include "gestionAffichage.h"
#include "gestionEvenements.h"
#include "gestionSon.h"

#include "struct_world.h"
#include "struct_ressources.h"

#include "constantes.h"

//---------------------------------------------------------//
//----------INIT-----------//
//---------------------------------------------------------//
/**
 * \brief La fonction appelle les différentes fonctions d'initialisation du jeu.
 * \param world Le monde.
 * \param window La fenêtre du jeu.
 * \param renderer Le renderer.
 * \param ressources Structure des ressources
 */
void init(world_p world, SDL_Window **window, SDL_Renderer **renderer, ressources_p ressources)
{
	if (DEV_MODE)
	{
		printf("Appel de <init()>.\n");
	}

	// Initialisation du monde.//
	initWorldData(world);

	// Initialisation des polices d'écriture.//
	init_ttf();
	// Initialisation SDL renderer et window.//
	initGraphique(window, renderer, ressources);

	// Initialisation de l'audio.//
	initAudio(48000, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 512); // 1920
	// load du son//
	loadSounds(ressources);
}

//---------------------------------------------------------//
//----------CLEAN-----------//
//---------------------------------------------------------//
/**
 * \brief La fonction appelle les différentes fonctions de nettoyage du jeu.
 * \param world Le monde.
 * \param renderer Le renderer.
 * \param window La fenêtre du jeu.
 * \param ressources Structure des ressources
 */
void clean(world_p world, SDL_Renderer **renderer, SDL_Window **window, ressources_p ressources) {
	if (DEV_MODE) {
		printf("Appel de <clean()>.\n");
	}

	// Nettoyage du monde.//
	cleanWorldData(world);

	// Nettoyage graphique.//
	cleanGraphique(window, renderer, ressources);

	// Fermeture et nettoyage de l'audio.//
	closeAudio(ressources);
}

//---------------------------------------------------------//
//----------MAINLOOP-----------//
//---------------------------------------------------------//
/**
 * \brief La fonction appelle les différentes fonctions nécessaires à la boucle principale du jeu.
 * \param renderer le renderer
 * \param world Le monde.
 * \param ressources Structure des ressources
 * \param event les évènements.
 */
void mainLoop(SDL_Renderer **renderer, world_p world, ressources_p ressources, SDL_Event *event)
{
	if (DEV_MODE)
	{
		printf("Appel de <mainLoop()>.\n");
	}

	while (!isGameOver(world))
	{ // Boucle principale du jeu
		updateData(world);
		refreshGraphics(*renderer, world, ressources);
		handleEvents(event, world, ressources);
		musics(world, ressources);
		pause(10);
		if (DEV_MODE)
		{
			printf("Done 1 mainLoop !\n");
		}
	}
}

//---------------------------------------------------------//
//----------MAIN-----------//
//---------------------------------------------------------//
/**
 * \brief La fonction main, base de tout le programme. Permet d'initialiser, appeler la boucle du jeu, nettoyer et fermer le programme.
 */
int main()
{

	// Inititialisation.//
	if (DEV_MODE)
	{
		printf("\n");
	}
	if (DEV_MODE)
	{
		printf("####======================================================####\n");
	}
	if (DEV_MODE)
	{
		printf("####====================INITIALISATION====================####\n");
	}
	if (DEV_MODE)
	{
		printf("####======================================================####\n");
	}
	if (DEV_MODE)
	{
		printf("\n");
	}

	world_t world;
	SDL_Event event;
	SDL_Renderer *renderer = NULL;
	SDL_Window *window = NULL;
	ressources_t ressources;

	// Init.//
	init(&world, &window, &renderer, &ressources);

	// Boucle du jeu.//
	if (DEV_MODE)
	{
		printf("\n");
	}
	if (DEV_MODE)
	{
		printf("####=====================================================####\n");
	}
	if (DEV_MODE)
	{
		printf("####====================GAME MAINLOOP====================####\n");
	}
	if (DEV_MODE)
	{
		printf("####=====================================================####\n");
	}
	if (DEV_MODE)
	{
		printf("\n");
	}

	mainLoop(&renderer, &world, &ressources, &event);

	// Nettoyage.//
	if (DEV_MODE)
	{
		printf("\n");
	}
	if (DEV_MODE)
	{
		printf("####================================================####\n");
	}
	if (DEV_MODE)
	{
		printf("####====================CLEANING====================####\n");
	}
	if (DEV_MODE)
	{
		printf("####================================================####\n");
	}
	if (DEV_MODE)
	{
		printf("\n");
	}

	clean(&world, &renderer, &window, &ressources);

	// Fermeture.//
	return EXIT_SUCCESS;
}
