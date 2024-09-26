#include <stdlib.h>
#include <stdio.h>

#include "struct_sprite.h"


void testSetCoords(sprite_p sprite){
  int x,y,w,h;

}


void testSetHp(sprite_p sprite){
  int hp;

}




void tests(){
  printf("Initialisation du Sprite...");
  sprite_t sprite;
  printf("Done !\n");

  testSetCoords(&sprite);
  testSetHp(&sprite);

}

int main(){
  printf("##-----BIENVENUE DANS L'ARCHITECTURE DE TEST DE LA STRUCTURE SPRITE ! -----##\n\n");
  printf("Début des tests ...\n");

  tests();

  printf("Tous les tests ont étés effectués avec succès !\n\n");
  printf("##-----FERMETURE DE L'ARCHITECTURE DE TEST DE LA STRUCTURE SPRITE ! -----##\n\n");
}
