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
    char b = '\0'; //variable utilisee dans les menus
    char a = '\0'; //vairable utlisee dans les menus
    int i, j; //pour les boucles for
    int type_jeu; //permet de reprendre une sauvegarde avec le même mode de jeu
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
                    fscanf(fichier_sauvegarde,"%c  ",&plateau[i][j]); //on recupere les valeurs de la sauvegarde et on les mets dans le tableau
                }
            }
            for(i=0;i<10;i++){ //initialisation du second tableau
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
                printf("Vous jouez en mode Classique\n\n");
                tirs_1(plateau, s, tab);
            } else if(type_jeu == 2){
                printf("Vous jouez en mode Blind\n\n");
                tirs_2(plateau, s, tab);
            } else if(type_jeu == 3){
                printf("Vous jouez en mode Active\n\n");
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
                    affectation(plateau); //initialisation du tableau avec des '_'
                    affectation(tab); //initialisation du tableau avec des '_'

                    printf("\n\n");

                    printf("L'adversaire possede 5 bateaux : un de taille 5, un de taille 4, 2 de taille 3 et un de taille 2.\n");

                    bateaux(plateau); //placement des bateaux

                    Inventory e = nb_munitions(a); //definition du nombre de munition

                    tirs_1(plateau, e, tab);
                    break;
                case 'B' :
                    affectation(plateau); //initialisation du tableau avec des '_'
                    affectation(tab); //initialisation du tableau avec des '_'

                    printf("\n\n");

                    printf("L'adversaire possede 5 bateaux : un de taille 5, un de taille 4, 2 de taille 3 et un de taille 2.\n");

                    bateaux(plateau); //placement des bateaux

                    Inventory d = nb_munitions(a); //definition du nombre de munition

                    tirs_2(plateau, d, tab);
                    break;
                case 'A' :
                    affectation(plateau); //initialisation du tableau avec des '_'
                    affectation(tab); //initialisation du tableau avec des '_'

                    printf("\n\n");

                    printf("L'adversaire possede 5 bateaux : un de taille 5, un de taille 4, 2 de taille 3 et un de taille 2.\n");

                    bateaux(plateau); //placement des bateaux

                    Inventory f = nb_munitions(a); //definition du nombre de munition

                    tirs_3(plateau, f, tab);
                    break;
            }
        default : return 0;
    }

}
