//
// Created by hugoc on 27/04/2021.
//

#include "autres_fonctions.h"

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include "inventory.h"

/**
 * la fonction partie permet d'afficher le menu de départ du jeu
 * @param a est la lettre de la partie souhaitee
 * @return la lettre de la partie souhaitee
 */
char partie (char a, char b) {

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
            return b;
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
                    printf("On verra après\n");
                case 'B' :
                    printf("On verra après\n");
                case 'A' :
                    printf("On verra après\n");
            }
            return a;
        default : return 0;
    }
}

void continuer(char a){
    do{
        printf("Voulez-vous continuer votre partie (C) ou la sauvegarder et quitter la partie (S) ?\n");
        gets(&a);
        a = toupper(a);
    } while (a != 'C' && a != 'S');
    if(a == 'S'){
        printf("On verra après\n");
    } else {

    }
}

int recommencer(char tableau[10][10]){
    int i;
    int j;
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            if(tableau[i][j] != '-' && tableau[i][j] != 'X' && tableau[i][j] != 'O'){
                return 1;
            }
        }
    }
    return 0;
}