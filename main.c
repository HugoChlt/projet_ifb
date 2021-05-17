#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "grid.h"
#include "boat.h"
#include "autres_fonctions.h"
#include "inventory.h"

int main() {
    char plateau[10][10]={0};
    char tab[10][10]={0};
    char lettre_partie = '\0';
    char difficulte = '\0';
    srand(time(0));

    difficulte = partie(difficulte, lettre_partie);

    grille_initiale(plateau);

    printf("\n\n");

    printf("L'adversaire possede 5 bateaux : un de taille 5, un de taille 4, 2 de taille 3 et un de taille 2.\n");

    bateaux(plateau);

    grille(plateau);

    Inventory e = nb_munitions(difficulte);

    tirs(plateau, e, tab);

}
