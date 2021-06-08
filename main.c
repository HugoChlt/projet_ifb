#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#include "grid.h"
#include "boat.h"
#include "autres_fonctions.h"
#include "inventory.h"

int main() {
    char plateau[10][10]={0}; // tableau avec affichage des bateaux
    char tab[10][10]={0}; //tableau sans affichage des bateaux
    char b = '\0';
    char a = '\0';
    srand(time(0));

    printf("\nBienvenue dans le jeu de la bataille navale !\n\n");
    printf("Menu : \n");
    printf("    Demarrer une nouvelle partie (D)\n");
    printf("    Charger une partie existante (C)\n");
    printf("    Quitter (Q)\n");
    printf("Choississez la lettre de la partie souhaitee : ");
    scanf(" %c", &b);
    b = toupper(b);
    while (b != 'D' && b != 'C' && b != 'Q') {
        printf("\n");
        printf("Erreur, la commande souhaitee n'existe pas !\n");
        printf("Choississez la lettre de la partie souhaitee :");
        scanf(" %c", &b);
        b = toupper(b);
    }
    switch (b) {
        case 'Q' :
            return 0;
        case 'C' :
            printf("On verra apres\n");
            return b;
        case 'D' :
            fflush(stdin);
            printf("Choississez le niveau de difficulte :\n");
            printf("Facile (F)\n");
            printf("Moyen (M)\n");
            printf("Difficile (D)\n");
            gets(&a);
            a = toupper(a);
            while (a != 'F' && a != 'M' && a != 'D') {
                printf("Erreur, la commande souhaitee n'existe pas !\n");
                printf("Veuillez choisir un niveau de difficulte possible : F, M ou D\n");
                gets(&a);
                a = toupper(a);
            }

            printf("\n");
            printf("Choissisez un mode de jeu :\n");
            printf("    Classique (C)\n");
            printf("    Blind (B)\n");
            printf("    Active (A)\n");
            scanf(" %c", &b);
            b = toupper(b);
            while (b != 'C' && b != 'B' && b != 'A') {
                printf("\n");
                printf("Erreur, la commande souhaitee n'existe pas !\n");
                printf("Choississez la lettre du type de partie souhaitee :");
                scanf(" %c", &b);
                b = toupper(b);
            }
            switch (b) {
                case 'C' :
                    grille_initiale(plateau);

                    printf("\n\n");

                    printf("L'adversaire possede 5 bateaux : un de taille 5, un de taille 4, 2 de taille 3 et un de taille 2.\n");

                    bateaux(plateau);

                    grille(plateau);

                    Inventory e = nb_munitions(a);

                    tirs_1(plateau, e, tab);
                    break;
                case 'B' :
                    grille_initiale(plateau);

                    printf("\n\n");

                    printf("L'adversaire possede 5 bateaux : un de taille 5, un de taille 4, 2 de taille 3 et un de taille 2.\n");

                    bateaux(plateau);

                    grille(plateau);

                    Inventory d = nb_munitions(a);

                    tirs_2(plateau, d, tab);
                    break;
                case 'A' :
                    grille_initiale(plateau);

                    printf("\n\n");

                    printf("L'adversaire possede 5 bateaux : un de taille 5, un de taille 4, 2 de taille 3 et un de taille 2.\n");

                    bateaux(plateau);

                    grille(plateau);

                    Inventory f = nb_munitions(a);

                    tirs_3(plateau, f, tab);
                    break;
            }
        default : return 0;
    }

}
