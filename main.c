#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#include "grid.h"
#include "boat.h"
#include "autres_fonctions.h"
#include "inventory.h"

#define FILENAME "sauvegarde.txt"

int main() {
    char plateau[10][10]={0}; // tableau avec affichage des bateaux
    char tab[10][10]={0}; //tableau sans affichage des bateaux
    char b = '\0';
    char a = '\0';
    int i, j;
    int type_jeu;
    srand(time(0));
    FILE *fichier_sauvegarde;

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
            printf("");
            Inventory s;

            fichier_sauvegarde = fopen("../sauvegarde.txt", "r");
            if(fichier_sauvegarde == NULL) {
                printf("Ouverture impossible du fichier\n");
                return -1;  // On quitte le programme
            }
            while(fscanf(fichier_sauvegarde,"type de jeu : %d  missiles d'artilleries : %d  missiles tactiques : %d  missiles : %d  bombes : %d\n",&type_jeu, &s.missile_artillerie, &s.missile_tactique, &s.missile, &s.bombe) != '\0') {
                printf("\nVous possedez au depart : %d missiles d'artilleries, %d missiles tactiques, %d bombes, %d missiles simples.\n\n", s.missile_artillerie, s.missile_tactique, s.bombe, s.missile);
            }

            for(i=0;i<10;i++){
                for(j=0;j<10;j++){
                    fscanf(fichier_sauvegarde,"%c  ",&plateau[i][j]);
                }
            }
            for(i=0;i<10;i++){
                for(j=0;j<10;j++){
                    if(plateau[i][j] == '_' || plateau[i][j] == 'X' || plateau[i][j] == 'O'){
                        tab[i][j] = plateau[i][j];
                    } else {
                        tab[i][j] = '_';
                    }
                }
            }
            fclose (fichier_sauvegarde);
            if(type_jeu == 1){
                tirs_1(plateau, s, tab);
            } else if(type_jeu == 2){
                tirs_2(plateau, s, tab);
            } else if(type_jeu == 3){
                tirs_3(plateau, s, tab);
            }
            break;
        case 'D' :
            fflush(stdin);
            printf("\nChoississez le niveau de difficulte :\n");
            printf("    Facile (F)\n");
            printf("    Moyen (M)\n");
            printf("    Difficile (D)\n");
            printf("Choississez la lettre du niveau de difficulte souhaitee : ");
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
            printf("Choississez la lettre du type de partie souhaitee :");
            scanf(" %c", &b);
            b = toupper(b);
            while (b != 'C' && b != 'B' && b != 'A') {
                printf("\n");
                printf("Erreur, la commande souhaitee n'existe pas !\n");
                printf("Veuillez choisir un type de partie possible : C, B ou A\n");
                scanf(" %c", &b);
                b = toupper(b);
            }
            switch (b) {
                case 'C' :
                    affectation(plateau);
                    affectation(tab);

                    printf("\n\n");

                    printf("L'adversaire possede 5 bateaux : un de taille 5, un de taille 4, 2 de taille 3 et un de taille 2.\n");

                    bateaux(plateau);

                    Inventory e = nb_munitions(a);

                    tirs_1(plateau, e, tab);
                    break;
                case 'B' :
                    affectation(plateau);
                    affectation(tab);

                    printf("\n\n");

                    printf("L'adversaire possede 5 bateaux : un de taille 5, un de taille 4, 2 de taille 3 et un de taille 2.\n");

                    bateaux(plateau);

                    Inventory d = nb_munitions(a);

                    tirs_2(plateau, d, tab);
                    break;
                case 'A' :
                    affectation(plateau);
                    affectation(tab);

                    printf("\n\n");

                    printf("L'adversaire possede 5 bateaux : un de taille 5, un de taille 4, 2 de taille 3 et un de taille 2.\n");

                    bateaux(plateau);

                    Inventory f = nb_munitions(a);

                    tirs_3(plateau, f, tab);
                    break;
            }
        default : return 0;
    }

}
