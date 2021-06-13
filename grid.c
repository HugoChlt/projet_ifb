//
// Created by hugoc on 27/04/2021.
//


#include "grid.h"

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

/**
 * Permet d'afficher la grille vierge au lancement du jeu
 * @param tableau
 */
void grille_initiale (char tableau[10][10]) {
    int i, j;

    for (i=0;i<10;i++){
        for (j=0;j<10;j++){
            tableau[i][j]='_';
        }
    }
    printf("\n");
    printf("     0   1   2   3   4   5   6   7   8   9\n");
    for (i=0; i<10;i=i+1){
        printf("   -----------------------------------------");
        printf("\n");
        printf("%d  ", i);
        for (j=0;j<10; j=j+1){
            printf("| %c ", tableau[i][j]);
        }
        printf("|");
        printf("\n");
    }

    printf("   -----------------------------------------");
}

/**
 * Permet d'afficher la grille tout au long du jeu, notamment lors du placement des bateaux
 * @param tableau
 */
void grille (char tableau[10][10]){
    int i, j;
    printf("\n");
    printf("     0   1   2   3   4   5   6   7   8   9\n");
    for (i=0; i<10;i=i+1){
        printf("   -----------------------------------------");
        printf("\n");
        printf("%d  ", i);
        for (j=0;j<10; j=j+1){
            printf("| %c ", tableau[i][j]);
        }
        printf("|");
        printf("\n");
    }

    printf("   -----------------------------------------");
}

/**
 * Permet d'initialiser les grilles au lancement du jeu avec le caractère '_'
 * @param tableau
 */
void affectation(char tableau[10][10]){
    int i, j;
    for (i=0;i<10;i++){
        for(j=0;j<10;j++){
            tableau[i][j] = '_';
        }
    }
}