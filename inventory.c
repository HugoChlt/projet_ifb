//
// Created by hugoc on 27/04/2021.
//

#include "inventory.h"
#include "grid.h"
#include "autres_fonctions.h"

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

/**
 * Permet de définir le nombre de munitions disponibles en fonction du niveau de difficulte sélectionne
 * @param a est la lettre de difficulte selectionnee
 * @return Inventory e
 */
Inventory nb_munitions(char a){
    Inventory e;
    if (a == 'F'){
        e.missile_artillerie = 10;
        e.missile_tactique = 10;
        e.bombe = 10;
        e.missile = 10;
    } else if (a == 'M'){
        e.missile_artillerie = 3;
        e.missile_tactique = 5;
        e.bombe = 5;
        e.missile = 10;
    } else if (a == 'D'){
        e.missile_artillerie = 1;
        e.missile_tactique = 4;
        e.bombe = 2;
        e.missile = 15;
    }
    printf("\nVous possedez au depart : %d missiles d'artilleries, %d missiles tactiques, %d bombes, %d missiles simples.\n\n", e.missile_artillerie, e.missile_tactique, e.bombe, e.missile);
    return e;
}

void tirs_1(char tableau[10][10], Inventory e, char tab[10][10]) {
    char a = '\0'; //type munition
    char b = '\0'; // continuez ou sauvegarder
    char maniere = '\0'; //horizontale ou verticale
    int co_x, co_y; //coordonnees de lancement du missile
    int i, j;
    int continuer; //nombre entre 0 et 1 permettant de savoir si l'utilisateur a gagne ou non


    do {
        grille(tab);
        fflush(stdin);
        printf("\n%d missiles d'artilleries, %d missiles tactiques, %d bombes, %d missiles simples.\n\n",
               e.missile_artillerie, e.missile_tactique, e.bombe, e.missile);
        fflush(stdin);
        printf("Quel munition souhaitez-vous utiliser ? (A) ou (T) ou (B) ou (M)\n");
        gets(&a);
        a = toupper(a);
        while (a != 'A' && a != 'T' && a != 'B' && a != 'M' && a!= '#'){
            fflush(stdin);
            printf("Veuillez entrer une munition correcte\n");
            printf("\n%d missiles d'artilleries, %d missiles tactiques, %d bombes, %d missiles simples.\n\n",
                   e.missile_artillerie, e.missile_tactique, e.bombe, e.missile);
            printf("Quel munition souhaitez-vous utiliser ? (A) ou (T) ou (B) ou (M)\n");
            gets(&a);
            a = toupper(a);
        }
        if(a == 'A' && e.missile_artillerie == 0){
            fflush(stdin);
            printf("Veuillez entrer une munition restante\n");
            printf("\n%d missiles d'artilleries, %d missiles tactiques, %d bombes, %d missiles simples.\n\n",
                   e.missile_artillerie, e.missile_tactique, e.bombe, e.missile);
            printf("Quel munition souhaitez-vous utiliser ? (A) ou (T) ou (B) ou (M)\n");
            gets(&a);
            a = toupper(a);
        } else if (a == 'T' && e.missile_tactique == 0){
            fflush(stdin);
            printf("Veuillez entrer une munition restante\n");
            printf("\n%d missiles d'artilleries, %d missiles tactiques, %d bombes, %d missiles simples.\n\n",
                   e.missile_artillerie, e.missile_tactique, e.bombe, e.missile);
            printf("Quel munition souhaitez-vous utiliser ? (A) ou (T) ou (B) ou (M)\n");
            gets(&a);
            a = toupper(a);
        } else if (a == 'B' && e.bombe == 0){
            fflush(stdin);
            printf("Veuillez entrer une munition restante\n");
            printf("\n%d missiles d'artilleries, %d missiles tactiques, %d bombes, %d missiles simples.\n\n",
                   e.missile_artillerie, e.missile_tactique, e.bombe, e.missile);
            printf("Quel munition souhaitez-vous utiliser ? (A) ou (T) ou (B) ou (M)\n");
            gets(&a);
            a = toupper(a);
        } else if (a == 'M' && e.missile == 0){
            fflush(stdin);
            printf("Veuillez entrer une munition restante\n");
            printf("\n%d missiles d'artilleries, %d missiles tactiques, %d bombes, %d missiles simples.\n\n",
                   e.missile_artillerie, e.missile_tactique, e.bombe, e.missile);
            printf("Quel munition souhaitez-vous utiliser ? (A) ou (T) ou (B) ou (M)\n");
            gets(&a);
            a = toupper(a);
        }
        switch (a) {
            case 'A' :
                e.missile_artillerie -= 1;
                printf("Ou souhaitez vous larguez le missile d'artillerie ?\n");
                scanf("%d%d", &co_y, &co_x);
                while (co_y < 0 || co_y > 9 || co_x < 0 || co_x > 9){
                    fflush(stdin);
                    printf("Erreur, coordonnees invalides\n");
                    printf("Ou souhaitez vous larguez le missile d'artillerie ?\n");
                    scanf("%d%d", &co_y, &co_x);
                }
                fflush(stdin);
                printf("De maniere horizontale (H) ou verticale (V) ?\n");
                gets(&maniere);
                while (maniere != 'H' && maniere != 'V') {
                    printf("De maniere horizontale (H) ou verticale (V) ?\n");
                    gets(&maniere);
                }
                if (maniere == 'H') {
                    for (i = 0; i < 10; i++) {
                        if (tableau[co_y][i] != '_' && tableau[co_y][i] != 'O' && tableau[co_y][i] != 'X') {
                            printf("Un bateau a ete touche, en %d-%d\n", co_y, i);
                            tableau[co_y][i] = 'X';
                            tab[co_y][i] = 'X';
                        } else if (tableau[co_y][i] == '_'){
                            tableau[co_y][i] = 'O';
                            tab[co_y][i] = 'O';
                        } else if (tableau[co_y][i] != 'X' && tableau[co_y][i] != 'O'){

                        }
                    }
                } else {
                    for (i = 0; i < 10; i++) {
                        if (tableau[i][co_x] != '_' && tableau[i][co_x] != 'O' && tableau[i][co_x] != 'X') {
                            printf("Un bateau a ete touche, en %d-%d\n", i, co_x);
                            tableau[i][co_x] = 'X';
                            tab[i][co_x] = 'X';
                        } else if (tableau[i][co_x] == '_'){
                            tableau[i][i] = 'O';
                            tab[i][co_x] = 'O';
                        } else if (tableau[i][co_x] == 'X' && tableau[i][co_x] == 'O'){

                        }
                    }
                }
                grille(tab);
                break;
            case 'T' :
                e.missile_tactique -= 1;
                printf("Ou souhaitez vous larguez le missile d'artillerie ?\n");
                scanf("%d%d", &co_y, &co_x);
                while (co_y < 0 || co_y > 9 || co_x < 0 || co_x > 9){
                    printf("Erreur, coordonnees invalides\n");
                    printf("Ou souhaitez vous larguez le missile d'artillerie ?\n");
                    scanf("%d%d", &co_y, &co_x);
                }
                if(tableau[co_y][co_x] == '2'){
                    printf("Un bateau a ete touche, en %d-%d\n", co_y, co_x);
                    tableau[co_y][co_x] = 'X';
                    tab[co_y][co_x] = 'X';
                    if(tableau[co_y-1][co_x] == '2'){
                        tableau[co_y-1][co_x] = 'X';
                        tab[co_y-1][co_x] = 'X';
                    } else if(tableau[co_y+1][co_x] == '2'){
                        tableau[co_y+1][co_x] = 'X';
                        tab[co_y+1][co_x] = 'X';
                    }else if (tableau[co_y][co_x-1] == '2'){
                        tableau[co_y][co_x-1] = 'X';
                        tab[co_y][co_x-1] = 'X';
                    }else if(tableau[co_y][co_x+1] == '2'){
                        tableau[co_y][co_x+1] = 'X';
                        tab[co_y][co_x+1] = 'X';
                    }
                    printf("Un bateau de taille 2 a ete coule\n");
                } else if (tableau[co_y][co_x] == '3') {
                    tableau[co_y][co_x] = 'X';
                    tab[co_y][co_x] = 'X';
                    if (tableau[co_y - 1][co_x] == '3') {
                        tableau[co_y - 1][co_x] = 'X';
                        tab[co_y - 1][co_x] = 'X';
                        if (tableau[co_y - 2][co_x] == '3') {
                            tableau[co_y - 2][co_x] = 'X';
                            tab[co_y - 2][co_x] = 'X';
                        } else {
                            tableau[co_y + 1][co_x] = 'X';
                            tab[co_y + 1][co_x] = 'X';
                        }
                    } else if (tableau[co_y + 1][co_x] == '3') {
                        tableau[co_y + 1][co_x] = 'X';
                        tab[co_y + 1][co_x] = 'X';
                        if (tableau[co_y + 2][co_x] == '3') {
                            tableau[co_y + 2][co_x] = 'X';
                            tab[co_y + 2][co_x] = 'X';
                        } else {
                            tableau[co_y - 1][co_x] = 'X';
                            tab[co_y - 1][co_x] = 'X';
                        }
                    } else if (tableau[co_y][co_x - 1] == '3') {
                        tableau[co_y][co_x - 1] = 'X';
                        tab[co_y][co_x - 1] = 'X';
                        if (tableau[co_y][co_x - 2] == '3') {
                            tableau[co_y][co_x - 2] = 'X';
                            tab[co_y][co_x - 2] = 'X';
                        } else {
                            tableau[co_y][co_x + 1] = 'X';
                            tab[co_y][co_x + 1] = 'X';
                        }
                    } else if (tableau[co_y][co_x + 1] == '3') {
                        tableau[co_y][co_x + 1] = 'X';
                        tab[co_y][co_x + 1] = 'X';
                        if (tableau[co_y][co_x + 2] == '3') {
                            tableau[co_y][co_x + 2] = 'X';
                            tab[co_y][co_x + 2] = 'X';
                        } else {
                            tableau[co_y][co_x - 1] = 'X';
                            tab[co_y][co_x - 1] = 'X';
                        }
                    }
                    printf("Un bateau de taille 3 a ete coule\n");
                }else if(tableau[co_y][co_x] == '4') {
                    tableau[co_y][co_x] = 'X';
                    tab[co_y][co_x] = 'X';
                    if (tableau[co_y - 1][co_x] == '4') {
                        tableau[co_y - 1][co_x] = 'X';
                        tab[co_y - 1][co_x] = 'X';
                        if (tableau[co_y - 2][co_x] == '4') {
                            tableau[co_y - 2][co_x] = 'X';
                            tab[co_y - 2][co_x] = 'X';
                            if(tableau[co_y - 3][co_x] == '4'){
                                tableau[co_y - 3][co_x] = 'X';
                                tab[co_y - 3][co_x] = 'X';
                            } else {
                                tableau[co_y + 1][co_x] = 'X';
                                tab[co_y + 1][co_x] = 'X';
                            }
                        } else {
                            tableau[co_y + 1][co_x] = 'X';
                            tableau[co_y + 2][co_x] = 'X';
                            tab[co_y + 1][co_x] = 'X';
                            tab[co_y + 2][co_x] = 'X';
                        }
                    } else if (tableau[co_y + 1][co_x] == '4') {
                        tableau[co_y + 1][co_x] = 'X';
                        tab[co_y + 1][co_x] = 'X';
                        if (tableau[co_y + 2][co_x] == '4') {
                            tableau[co_y + 2][co_x] = 'X';
                            tab[co_y + 2][co_x] = 'X';
                            if(tableau[co_y + 3][co_x] == '4'){
                                tableau[co_y + 3][co_x] = 'X';
                                tab[co_y + 3][co_x] = 'X';
                            } else {
                                tableau[co_y - 1][co_x] = 'X';
                                tab[co_y - 1][co_x] = 'X';
                            }
                        } else {
                            tableau[co_y - 1][co_x] = 'X';
                            tableau[co_y - 2][co_x] = 'X';
                            tab[co_y - 1][co_x] = 'X';
                            tab[co_y - 2][co_x] = 'X';
                        }
                    } else if (tableau[co_y][co_x - 1] == '4') {
                        tableau[co_y][co_x - 1] = 'X';
                        tab[co_y][co_x - 1] = 'X';
                        if (tableau[co_y][co_x - 2] == '4') {
                            tableau[co_y][co_x - 2] = 'X';
                            tab[co_y][co_x - 2] = 'X';
                            if(tableau[co_y][co_x - 3] == '4'){
                                tableau[co_y][co_x - 3] = 'X';
                                tab[co_y][co_x - 3] = 'X';
                            } else {
                                tableau[co_y][co_x + 1] = 'X';
                                tab[co_y][co_x + 1] = 'X';
                            }
                        } else {
                            tableau[co_y][co_x + 1] = 'X';
                            tableau[co_y][co_x + 2] = 'X';
                            tab[co_y][co_x + 1] = 'X';
                            tab[co_y][co_x + 2] = 'X';
                        }
                    } else if (tableau[co_y][co_x + 1] == '4') {
                        tableau[co_y][co_x + 1] = 'X';
                        tab[co_y][co_x + 1] = 'X';
                        if (tableau[co_y][co_x + 2] == '4') {
                            tableau[co_y][co_x + 2] = 'X';
                            tab[co_y][co_x + 2] = 'X';
                            if (tableau[co_y][co_x + 3] == '4') {
                                tableau[co_y][co_x + 3] = 'X';
                                tab[co_y][co_x + 3] = 'X';
                            } else {
                                tableau[co_y][co_x - 1] = 'X';
                                tab[co_y][co_x - 1] = 'X';
                            }
                        } else {
                            tableau[co_y][co_x - 1] = 'X';
                            tableau[co_y][co_x - 2] = 'X';
                            tab[co_y][co_x - 1] = 'X';
                            tab[co_y][co_x - 2] = 'X';
                        }
                    }
                    printf("Un bateau de taille 4 a ete coule\n");
                } else if (tableau[co_y][co_x] == '5'){
                    tableau[co_y][co_x] = 'X';
                    tab[co_y][co_x] = 'X';
                        if (tableau[co_y - 1][co_x] == '5') {
                            tableau[co_y - 1][co_x] = 'X';
                            tab[co_y - 1][co_x] = 'X';
                            if (tableau[co_y - 2][co_x] == '5') {
                                tableau[co_y - 2][co_x] = 'X';
                                tab[co_y - 2][co_x] = 'X';
                                if (tableau[co_y - 3][co_x] == '5') {
                                    tableau[co_y - 3][co_x] = 'X';
                                    tab[co_y - 3][co_x] = 'X';
                                    if (tableau[co_y - 4][co_x] == '5') {
                                        tableau[co_y - 4][co_x] = 'X';
                                        tab[co_y - 4][co_x] = 'X';
                                    } else {
                                        tableau[co_y + 1][co_x] = 'X';
                                        tab[co_y + 1][co_x] = 'X';
                                    }
                                } else {
                                    tableau[co_y + 1][co_x] = 'X';
                                    tableau[co_y + 2][co_x] = 'X';
                                    tab[co_y + 1][co_x] = 'X';
                                    tab[co_y + 2][co_x] = 'X';
                                }
                            } else {
                                tableau[co_y + 1][co_x] = 'X';
                                tableau[co_y + 2][co_x] = 'X';
                                tableau[co_y + 3][co_x] = 'X';
                                tab[co_y + 1][co_x] = 'X';
                                tab[co_y + 2][co_x] = 'X';
                                tab[co_y + 3][co_x] = 'X';
                            }
                        } else if (tableau[co_y + 1][co_x] == '5') {
                            tableau[co_y + 1][co_x] = 'X';
                            tab[co_y + 1][co_x] = 'X';
                            if (tableau[co_y + 2][co_x] == '5') {
                                tableau[co_y + 2][co_x] = 'X';
                                tab[co_y + 2][co_x] = 'X';
                                if (tableau[co_y + 3][co_x] == '5') {
                                    tableau[co_y + 3][co_x] = 'X';
                                    tab[co_y + 3][co_x] = 'X';
                                    if (tableau[co_y + 4][co_x] == '5') {
                                        tableau[co_y + 4][co_x] = 'X';
                                        tab[co_y + 4][co_x] = 'X';
                                    } else {
                                        tableau[co_y - 1][co_x] = 'X';
                                        tab[co_y - 1][co_x] = 'X';
                                    }
                                } else {
                                    tableau[co_y - 1][co_x] = 'X';
                                    tableau[co_y - 2][co_x] = 'X';
                                    tab[co_y - 1][co_x] = 'X';
                                    tab[co_y - 2][co_x] = 'X';
                                }
                            } else {
                                tableau[co_y - 1][co_x] = 'X';
                                tableau[co_y - 2][co_x] = 'X';
                                tableau[co_y - 3][co_x] = 'X';
                                tab[co_y - 1][co_x] = 'X';
                                tab[co_y - 2][co_x] = 'X';
                                tab[co_y - 3][co_x] = 'X';
                            }
                        } else if (tableau[co_y][co_x - 1] == '5') {
                            tableau[co_y][co_x - 1] = 'X';
                            tab[co_y][co_x - 1] = 'X';
                            if (tableau[co_y][co_x - 2] == '5') {
                                tableau[co_y][co_x - 2] = 'X';
                                tab[co_y][co_x - 2] = 'X';
                                if (tableau[co_y][co_x - 3] == '5') {
                                    tableau[co_y][co_x - 3] = 'X';
                                    tab[co_y][co_x - 3] = 'X';
                                    if (tableau[co_y][co_x - 4] == '5') {
                                        tableau[co_y][co_x - 4] = 'X';
                                        tab[co_y][co_x - 4] = 'X';
                                    } else {
                                        tableau[co_y][co_x + 1] = 'X';
                                        tab[co_y][co_x + 1] = 'X';
                                    }
                                } else {
                                    tableau[co_y][co_x + 1] = 'X';
                                    tableau[co_y][co_x + 2] = 'X';
                                    tab[co_y][co_x + 1] = 'X';
                                    tab[co_y][co_x + 2] = 'X';
                                }
                            } else {
                                tableau[co_y][co_x + 1] = 'X';
                                tableau[co_y][co_x + 2] = 'X';
                                tableau[co_y][co_x + 3] = 'X';
                                tab[co_y][co_x + 1] = 'X';
                                tab[co_y][co_x + 2] = 'X';
                                tab[co_y][co_x + 3] = 'X';
                            }
                        } else if (tableau[co_y][co_x + 1] == '5') {
                            tableau[co_y][co_x + 1] = 'X';
                            tab[co_y][co_x + 1] = 'X';
                            if (tableau[co_y][co_x + 2] == '5') {
                                tableau[co_y][co_x + 2] = 'X';
                                tab[co_y][co_x + 2] = 'X';
                                if (tableau[co_y][co_x + 3] == '5') {
                                    tableau[co_y][co_x + 3] = 'X';
                                    tab[co_y][co_x + 3] = 'X';
                                    if (tableau[co_y][co_x + 4] == '5') {
                                        tableau[co_y][co_x + 4] = 'X';
                                        tab[co_y][co_x + 4] = 'X';
                                    } else {
                                        tableau[co_y][co_x - 1] = 'X';
                                        tab[co_y][co_x - 1] = 'X';
                                    }
                                } else {
                                    tableau[co_y][co_x - 1] = 'X';
                                    tableau[co_y][co_x - 2] = 'X';
                                    tab[co_y][co_x - 1] = 'X';
                                    tab[co_y][co_x - 2] = 'X';
                                }
                            } else {
                                tableau[co_y][co_x - 1] = 'X';
                                tableau[co_y][co_x - 2] = 'X';
                                tableau[co_y][co_x - 3] = 'X';
                                tab[co_y][co_x - 1] = 'X';
                                tab[co_y][co_x - 2] = 'X';
                                tab[co_y][co_x - 3] = 'X';
                            }
                        }
                    printf("Un bateau de taille 5 a ete coule\n");
                } else if (tableau[co_y][co_x] == '_'){
                    tableau[co_y][co_x] = 'O';
                    tab[co_y][co_x] = 'O';
                } else if (tableau[co_y][co_x] == 'X' && tableau[co_y][co_x] == 'O'){

                }
                grille(tab);
                    break;
            case 'B' :
                e.bombe -= 1;
                printf("Ou souhaitez vous larguez le missile d'artillerie ?\n");
                scanf("%d%d", &co_y, &co_x);
                while (co_y < 0 || co_y > 9 || co_x < 0 || co_x > 9){
                    printf("Erreur, coordonnees invalides\n");
                    printf("Ou souhaitez vous larguez le missile d'artillerie ?\n");
                    scanf("%d%d", &co_y, &co_x);
                }
                if(tableau[co_y][co_x] != '_' && tableau[co_y][co_x] != 'O' && tableau[co_y][co_x] != 'X'){
                    printf("Un bateau a ete touche, en %d-%d\n", co_y, co_x);
                    tableau[co_y][co_x] = 'X';
                    tab[co_y][co_x] = 'X';
                } else if (tableau[co_y][co_x] == '_'){
                    tableau[co_y][co_x] = 'O';
                    tab[co_y][co_x] = 'O';
                } else if (tableau[co_y][co_x] == 'X' && tableau[co_y][co_x] == 'O'){

                }
                if(tableau[co_y-1][co_x] != '_' && tableau[co_y-1][co_x] != 'O' && tableau[co_y-1][co_x] != 'X'){
                    printf("Un bateau a ete touche, en %d-%d\n", co_y-1, co_x);
                    tableau[co_y-1][co_x] = 'X';
                    tab[co_y-1][co_x] = 'X';
                } else if (tableau[co_y-1][co_x] == '_'){
                    tableau[co_y-1][co_x] = 'O';
                    tab[co_y-1][co_x] = 'O';
                } else if (tableau[co_y-1][co_x] == 'X' && tableau[co_y-1][co_x] == 'O'){

                }
                if(tableau[co_y-1][co_x+1] != '_' && tableau[co_y-1][co_x+1] != 'O' && tableau[co_y-1][co_x+1] != 'X'){
                    printf("Un bateau a ete touche, en %d-%d\n", co_y-1, co_x+1);
                    tableau[co_y-1][co_x+1] = 'X';
                    tab[co_y-1][co_x+1] = 'X';
                } else if (tableau[co_y-1][co_x+1] == '_'){
                    tableau[co_y-1][co_x+1] = 'O';
                    tab[co_y-1][co_x+1] = 'O';
                } else if (tableau[co_y-1][co_x+1] == 'X' && tableau[co_y-1][co_x+1] == 'O'){

                }
                if(tableau[co_y][co_x+1] != '_' && tableau[co_y][co_x+1] != 'O' && tableau[co_y][co_x+1] != 'X'){
                    printf("Un bateau a ete touche, en %d-%d\n", co_y, co_x+1);
                    tableau[co_y][co_x+1] = 'X';
                    tab[co_y][co_x+1] = 'X';
                } else if (tableau[co_y][co_x+1] == '_'){
                    tableau[co_y][co_x+1] = 'O';
                    tab[co_y][co_x+1] = 'O';
                } else if (tableau[co_y][co_x+1] == 'X' && tableau[co_y][co_x+1] == 'O'){

                }
                if(tableau[co_y+1][co_x+1] != '_' && tableau[co_y+1][co_x+1] != 'O' && tableau[co_y+1][co_x+1] != 'X'){
                    printf("Un bateau a ete touche, en %d-%d\n", co_y+1, co_x+1);
                    tableau[co_y+1][co_x+1] = 'X';
                    tab[co_y+1][co_x+1] = 'X';
                } else if (tableau[co_y+1][co_x+1] == '_'){
                    tableau[co_y+1][co_x+1] = 'O';
                    tab[co_y+1][co_x+1] = 'O';
                } else if (tableau[co_y+1][co_x+1] == 'X' && tableau[co_y+1][co_x+1] == 'O'){

                }
                if(tableau[co_y+1][co_x] != '_' && tableau[co_y+1][co_x] != 'O' && tableau[co_y+1][co_x] != 'X'){
                    printf("Un bateau a ete touche, en %d-%d\n", co_y+1, co_x);
                    tableau[co_y+1][co_x] = 'X';
                    tab[co_y+1][co_x] = 'X';
                } else if (tableau[co_y+1][co_x] == '_'){
                    tableau[co_y+1][co_x] = 'O';
                    tab[co_y+1][co_x] = 'O';
                } else if (tableau[co_y+1][co_x] == 'X' && tableau[co_y+1][co_x] == 'O'){

                }
                if(tableau[co_y+1][co_x-1] != '_' && tableau[co_y+1][co_x-1] != 'O' && tableau[co_y+1][co_x-1] != 'X'){
                    printf("Un bateau a ete touche, en %d-%d\n", co_y+1, co_x-1);
                    tableau[co_y+1][co_x-1] = 'X';
                    tab[co_y+1][co_x-1] = 'X';
                } else if (tableau[co_y+1][co_x-1] == '_'){
                    tableau[co_y+1][co_x-1] = 'O';
                    tab[co_y+1][co_x-1] = 'O';
                } else if (tableau[co_y+1][co_x-1] == 'X' && tableau[co_y+1][co_x-1] == 'O'){

                }
                if(tableau[co_y][co_x-1] != '_' && tableau[co_y][co_x-1] != 'O' && tableau[co_y][co_x-1] != 'X'){
                    printf("Un bateau a ete touche, en %d-%d\n", co_y, co_x-1);
                    tableau[co_y][co_x-1] = 'X';
                    tab[co_y][co_x-1] = 'X';
                } else if (tableau[co_y][co_x-1] == '_'){
                    tableau[co_y][co_x-1] = 'O';
                    tab[co_y][co_x-1] = 'O';
                } else if (tableau[co_y][co_x-1] == 'X' && tableau[co_y][co_x-1] == 'O'){

                }
                if(tableau[co_y-1][co_x-1] != '_' && tableau[co_y-1][co_x-1] != 'O' && tableau[co_y-1][co_x-1] != 'X'){
                    printf("Un bateau a ete touche, en %d-%d\n", co_y-1, co_x-1);
                    tableau[co_y-1][co_x-1] = 'X';
                    tab[co_y-1][co_x-1] = 'X';
                } else if (tableau[co_y-1][co_x-1] == '_'){
                    tableau[co_y-1][co_x-1] = 'O';
                    tab[co_y-1][co_x-1] = 'O';
                } else if (tableau[co_y-1][co_x-1] == 'X' && tableau[co_y-1][co_x-1] == 'O'){

                }
                grille(tab);
                break;
            case 'M' :
                e.missile -= 1;
                printf("Ou souhaitez vous larguez le missile d'artillerie ?\n");
                scanf("%d%d", &co_y, &co_x);
                while (co_y < 0 || co_y > 9 || co_x < 0 || co_x > 9){
                    printf("Erreur, coordonnees invalides\n");
                    printf("Ou souhaitez vous larguez le missile d'artillerie ?\n");
                    scanf("%d%d", &co_y, &co_x);
                }
                if(tableau[co_y][co_x] != '_' && tableau[co_y][co_x] != 'O' && tableau[co_y][co_x] != 'X'){
                    printf("Un bateau a ete touche, en %d-%d\n", co_y, co_x);
                    tableau[co_y][co_x] = 'X';
                    tab[co_y][co_x] = 'X';
                } else if (tableau[co_y][co_x] == '_'){
                    tableau[co_y][co_x] = 'O';
                    tab[co_y][co_x] = 'O';
                } else if (tableau[co_y][co_x] == 'X' && tableau[co_y][co_x] == 'O'){

                }
                grille(tab);
                break;
            case '#' :
                printf("Bravo a vous, vous avez trouve le caractere secret permettant de gagner cette partie immediatement\n");
                printf("N'en parlez a personne, cela reste entre nous !\n");
                for (i=0;i<10;i++){
                    for (j=0;j<10;j++){
                        if (tableau[i][j] == '_' || tableau[i][j] == 'O'){
                            tableau[i][j] = 'O';
                            tab[i][j] = 'O';
                        } else {
                            tableau[i][j] = 'X';
                            tab[i][j] = 'X';
                        }
                    }
                }
                grille(tab);
                break;
            default : return 0;
                }

        continuer = recommencer(tableau);

        if(continuer == 0){
            printf("\nVous avez gagne !\n");
            return 0;
        } else if(continuer == 1){
            fflush(stdin);
            printf("\nVoulez-vous continuez (C) ou sauvegarder votre partie et quitter (S) ?\n");
            gets(&b);
            b = toupper(b);
            while (b != 'C' && b != 'S'){
                printf("Erreur dans la saisie\n");
                printf("\nVoulez-vous continuez (C) ou sauvegarder votre partie et quitter (S) ?\n");
                gets(&b);
                b = toupper(b);
            }
        }


    } while (b == 'C' && (e.missile_artillerie > 0 || e.missile_tactique > 0 || e.bombe > 0 || e.missile > 0));
    if (e.missile_artillerie == 0 || e.missile_tactique == 0 || e.bombe == 0 || e.missile == 0){
        printf("Vous avez perdu !\n");
    } else if (b == 'S'){
        FILE* fichier_sauvegarde = fopen("../sauvegarde.txt", "w");
        if(fichier_sauvegarde == NULL) {
            printf("Ouverture impossible du fichier\n");
            return -1;  // On quitte le programme
        }
        fprintf(fichier_sauvegarde, "type de jeu : %d\n\n", 1);
        fprintf(fichier_sauvegarde, "missiles d'artilleries : %d  ", e.missile_artillerie);
        fprintf(fichier_sauvegarde, "missiles tactiques : %d  ", e.missile_tactique);
        fprintf(fichier_sauvegarde, "missiles : %d  ", e.missile);
        fprintf(fichier_sauvegarde, "bombes : %d\n\n", e.bombe);
        for(i=0;i<10;i++){
            for(j=0;j<10;j++){
                fprintf(fichier_sauvegarde, "%c  ", tableau[i][j]);
            }
            fprintf(fichier_sauvegarde, "\n");

        }
    }
}

void tirs_2(char tableau[10][10], Inventory e, char tab[10][10]) {
    char a = '\0'; //type munition
    char b = '\0'; // continuez ou sauvegarder
    char maniere = '\0';
    int co_x, co_y;
    int i, j;
    int continuer;

    do {
        fflush(stdin);
        printf("\n%d missiles d'artilleries, %d missiles tactiques, %d bombes, %d missiles simples.\n\n",
               e.missile_artillerie, e.missile_tactique, e.bombe, e.missile);
        fflush(stdin);
        printf("Quel munition souhaitez-vous utiliser ? (A) ou (T) ou (B) ou (M)\n");
        gets(&a);
        a = toupper(a);
        while (a != 'A' && a != 'T' && a != 'B' && a != 'M'){
            fflush(stdin);
            printf("Veuillez entrer une munition correcte\n");
            printf("Quel munition souhaitez-vous utiliser ? (A) ou (T) ou (B) ou (M)\n");
            gets(&a);
            a = toupper(a);
        }
        if(a == 'A' && e.missile_artillerie == 0){
            fflush(stdin);
            printf("Veuillez entrer une munition restante\n");
            printf("\n%d missiles d'artilleries, %d missiles tactiques, %d bombes, %d missiles simples.\n\n",
                   e.missile_artillerie, e.missile_tactique, e.bombe, e.missile);
            printf("Quel munition souhaitez-vous utiliser ? (A) ou (T) ou (B) ou (M)\n");
            gets(&a);
            a = toupper(a);
        } else if (a == 'T' && e.missile_tactique == 0){
            fflush(stdin);
            printf("Veuillez entrer une munition restante\n");
            printf("\n%d missiles d'artilleries, %d missiles tactiques, %d bombes, %d missiles simples.\n\n",
                   e.missile_artillerie, e.missile_tactique, e.bombe, e.missile);
            printf("Quel munition souhaitez-vous utiliser ? (A) ou (T) ou (B) ou (M)\n");
            gets(&a);
            a = toupper(a);
        } else if (a == 'B' && e.bombe == 0){
            fflush(stdin);
            printf("Veuillez entrer une munition restante\n");
            printf("\n%d missiles d'artilleries, %d missiles tactiques, %d bombes, %d missiles simples.\n\n",
                   e.missile_artillerie, e.missile_tactique, e.bombe, e.missile);
            printf("Quel munition souhaitez-vous utiliser ? (A) ou (T) ou (B) ou (M)\n");
            gets(&a);
            a = toupper(a);
        } else if (a == 'M' && e.missile == 0){
            fflush(stdin);
            printf("Veuillez entrer une munition restante\n");
            printf("\n%d missiles d'artilleries, %d missiles tactiques, %d bombes, %d missiles simples.\n\n",
                   e.missile_artillerie, e.missile_tactique, e.bombe, e.missile);
            printf("Quel munition souhaitez-vous utiliser ? (A) ou (T) ou (B) ou (M)\n");
            gets(&a);
            a = toupper(a);
        }
        switch (a) {
            case 'A' :
                e.missile_artillerie -= 1;
                printf("Ou souhaitez vous larguez le missile d'artillerie ?\n");
                scanf("%d%d", &co_y, &co_x);
                while (co_y < 0 || co_y > 9 || co_x < 0 || co_x > 9){
                    fflush(stdin);
                    printf("Erreur, coordonnees invalides\n");
                    printf("Ou souhaitez vous larguez le missile d'artillerie ?\n");
                    scanf("%d%d", &co_y, &co_x);
                }
                fflush(stdin);
                printf("De maniere horizontale (H) ou verticale (V) ?\n");
                gets(&maniere);
                while (maniere != 'H' && maniere != 'V') {
                    printf("De maniere horizontale (H) ou verticale (V) ?\n");
                    gets(&maniere);
                }
                if (maniere == 'H') {
                    for (i = 0; i < 10; i++) {
                        if (tableau[co_y][i] != '_' && tableau[co_y][i] != 'O' && tableau[co_y][i] != 'X') {
                            printf("Un bateau a ete touche, en %d-%d\n", co_y, i);
                            tableau[co_y][i] = 'X';
                            tab[co_y][i] = 'X';
                        } else if (tableau[co_y][i] == '_'){
                            tableau[co_y][i] = 'O';
                            tab[co_y][i] = 'O';
                        } else if (tableau[co_y][i] == 'X' && tableau[co_y][i] == 'O'){

                        }
                    }
                } else {
                    for (i = 0; i < 10; i++) {
                        if (tableau[i][co_x] != '_' && tableau[i][co_x] != 'O' && tableau[i][co_x] != 'X') {
                            printf("Un bateau a ete touche, en %d-%d\n", i, co_x);
                            tableau[i][co_x] = 'X';
                            tab[i][co_x] = 'X';
                        } else if (tableau[i][co_x] == '_'){
                            tableau[i][i] = 'O';
                            tab[i][co_x] = 'O';
                        } else if (tableau[i][co_x] == 'X' && tableau[i][co_x] == 'O'){

                        }
                    }
                }

                break;
            case 'T' :
                e.missile_tactique -= 1;
                printf("Ou souhaitez vous larguez le missile d'artillerie ?\n");
                scanf("%d%d", &co_y, &co_x);
                while (co_y < 0 || co_y > 9 || co_x < 0 || co_x > 9){
                    printf("Erreur, coordonnees invalides\n");
                    printf("Ou souhaitez vous larguez le missile d'artillerie ?\n");
                    scanf("%d%d", &co_y, &co_x);
                }
                if(tableau[co_y][co_x] == '2'){
                    printf("Un bateau a ete touche, en %d-%d\n", co_y, co_x);
                    tableau[co_y][co_x] = 'X';
                    tab[co_y][co_x] = 'X';
                    if(tableau[co_y-1][co_x] == '2'){
                        tableau[co_y-1][co_x] = 'X';
                        tab[co_y-1][co_x] = 'X';
                    } else if(tableau[co_y+1][co_x] == '2'){
                        tableau[co_y+1][co_x] = 'X';
                        tab[co_y+1][co_x] = 'X';
                    }else if (tableau[co_y][co_x-1] == '2'){
                        tableau[co_y][co_x-1] = 'X';
                        tab[co_y][co_x-1] = 'X';
                    }else if(tableau[co_y][co_x+1] == '2'){
                        tableau[co_y][co_x+1] = 'X';
                        tab[co_y][co_x+1] = 'X';
                    }
                    printf("Un bateau de taille 2 a ete coule\n");
                } else if (tableau[co_y][co_x] == '3') {
                    tableau[co_y][co_x] = 'X';
                    tab[co_y][co_x] = 'X';
                    if (tableau[co_y - 1][co_x] == '3') {
                        tableau[co_y - 1][co_x] = 'X';
                        tab[co_y - 1][co_x] = 'X';
                        if (tableau[co_y - 2][co_x] == '3') {
                            tableau[co_y - 2][co_x] = 'X';
                            tab[co_y - 2][co_x] = 'X';
                        } else {
                            tableau[co_y + 1][co_x] = 'X';
                            tab[co_y + 1][co_x] = 'X';
                        }
                    } else if (tableau[co_y + 1][co_x] == '3') {
                        tableau[co_y + 1][co_x] = 'X';
                        tab[co_y + 1][co_x] = 'X';
                        if (tableau[co_y + 2][co_x] == '3') {
                            tableau[co_y + 2][co_x] = 'X';
                            tab[co_y + 2][co_x] = 'X';
                        } else {
                            tableau[co_y - 1][co_x] = 'X';
                            tab[co_y - 1][co_x] = 'X';
                        }
                    } else if (tableau[co_y][co_x - 1] == '3') {
                        tableau[co_y][co_x - 1] = 'X';
                        tab[co_y][co_x - 1] = 'X';
                        if (tableau[co_y][co_x - 2] == '3') {
                            tableau[co_y][co_x - 2] = 'X';
                            tab[co_y][co_x - 2] = 'X';
                        } else {
                            tableau[co_y][co_x + 1] = 'X';
                            tab[co_y][co_x + 1] = 'X';
                        }
                    } else if (tableau[co_y][co_x + 1] == '3') {
                        tableau[co_y][co_x + 1] = 'X';
                        tab[co_y][co_x + 1] = 'X';
                        if (tableau[co_y][co_x + 2] == '3') {
                            tableau[co_y][co_x + 2] = 'X';
                            tab[co_y][co_x + 2] = 'X';
                        } else {
                            tableau[co_y][co_x - 1] = 'X';
                            tab[co_y][co_x - 1] = 'X';
                        }
                    }
                    printf("Un bateau de taille 3 a ete coule\n");
                }else if(tableau[co_y][co_x] == '4') {
                    tableau[co_y][co_x] = 'X';
                    tab[co_y][co_x] = 'X';
                    if (tableau[co_y - 1][co_x] == '4') {
                        tableau[co_y - 1][co_x] = 'X';
                        tab[co_y - 1][co_x] = 'X';
                        if (tableau[co_y - 2][co_x] == '4') {
                            tableau[co_y - 2][co_x] = 'X';
                            tab[co_y - 2][co_x] = 'X';
                            if(tableau[co_y - 3][co_x] == '4'){
                                tableau[co_y - 3][co_x] = 'X';
                                tab[co_y - 3][co_x] = 'X';
                            } else {
                                tableau[co_y + 1][co_x] = 'X';
                                tab[co_y + 1][co_x] = 'X';
                            }
                        } else {
                            tableau[co_y + 1][co_x] = 'X';
                            tableau[co_y + 2][co_x] = 'X';
                            tab[co_y + 1][co_x] = 'X';
                            tab[co_y + 2][co_x] = 'X';
                        }
                    } else if (tableau[co_y + 1][co_x] == '4') {
                        tableau[co_y + 1][co_x] = 'X';
                        tab[co_y + 1][co_x] = 'X';
                        if (tableau[co_y + 2][co_x] == '4') {
                            tableau[co_y + 2][co_x] = 'X';
                            tab[co_y + 2][co_x] = 'X';
                            if(tableau[co_y + 3][co_x] == '4'){
                                tableau[co_y + 3][co_x] = 'X';
                                tab[co_y + 3][co_x] = 'X';
                            } else {
                                tableau[co_y - 1][co_x] = 'X';
                                tab[co_y - 1][co_x] = 'X';
                            }
                        } else {
                            tableau[co_y - 1][co_x] = 'X';
                            tableau[co_y - 2][co_x] = 'X';
                            tab[co_y - 1][co_x] = 'X';
                            tab[co_y - 2][co_x] = 'X';
                        }
                    } else if (tableau[co_y][co_x - 1] == '4') {
                        tableau[co_y][co_x - 1] = 'X';
                        tab[co_y][co_x - 1] = 'X';
                        if (tableau[co_y][co_x - 2] == '4') {
                            tableau[co_y][co_x - 2] = 'X';
                            tab[co_y][co_x - 2] = 'X';
                            if(tableau[co_y][co_x - 3] == '4'){
                                tableau[co_y][co_x - 3] = 'X';
                                tab[co_y][co_x - 3] = 'X';
                            } else {
                                tableau[co_y][co_x + 1] = 'X';
                                tab[co_y][co_x + 1] = 'X';
                            }
                        } else {
                            tableau[co_y][co_x + 1] = 'X';
                            tableau[co_y][co_x + 2] = 'X';
                            tab[co_y][co_x + 1] = 'X';
                            tab[co_y][co_x + 2] = 'X';
                        }
                    } else if (tableau[co_y][co_x + 1] == '4') {
                        tableau[co_y][co_x + 1] = 'X';
                        tab[co_y][co_x + 1] = 'X';
                        if (tableau[co_y][co_x + 2] == '4') {
                            tableau[co_y][co_x + 2] = 'X';
                            tab[co_y][co_x + 2] = 'X';
                            if (tableau[co_y][co_x + 3] == '4') {
                                tableau[co_y][co_x + 3] = 'X';
                                tab[co_y][co_x + 3] = 'X';
                            } else {
                                tableau[co_y][co_x - 1] = 'X';
                                tab[co_y][co_x - 1] = 'X';
                            }
                        } else {
                            tableau[co_y][co_x - 1] = 'X';
                            tableau[co_y][co_x - 2] = 'X';
                            tab[co_y][co_x - 1] = 'X';
                            tab[co_y][co_x - 2] = 'X';
                        }
                    }
                    printf("Un bateau de taille 4 a ete coule\n");
                } else if (tableau[co_y][co_x] == '5'){
                    tableau[co_y][co_x] = 'X';
                    tab[co_y][co_x] = 'X';
                    if (tableau[co_y - 1][co_x] == '5') {
                        tableau[co_y - 1][co_x] = 'X';
                        tab[co_y - 1][co_x] = 'X';
                        if (tableau[co_y - 2][co_x] == '5') {
                            tableau[co_y - 2][co_x] = 'X';
                            tab[co_y - 2][co_x] = 'X';
                            if (tableau[co_y - 3][co_x] == '5') {
                                tableau[co_y - 3][co_x] = 'X';
                                tab[co_y - 3][co_x] = 'X';
                                if (tableau[co_y - 4][co_x] == '5') {
                                    tableau[co_y - 4][co_x] = 'X';
                                    tab[co_y - 4][co_x] = 'X';
                                } else {
                                    tableau[co_y + 1][co_x] = 'X';
                                    tab[co_y + 1][co_x] = 'X';
                                }
                            } else {
                                tableau[co_y + 1][co_x] = 'X';
                                tableau[co_y + 2][co_x] = 'X';
                                tab[co_y + 1][co_x] = 'X';
                                tab[co_y + 2][co_x] = 'X';
                            }
                        } else {
                            tableau[co_y + 1][co_x] = 'X';
                            tableau[co_y + 2][co_x] = 'X';
                            tableau[co_y + 3][co_x] = 'X';
                            tab[co_y + 1][co_x] = 'X';
                            tab[co_y + 2][co_x] = 'X';
                            tab[co_y + 3][co_x] = 'X';
                        }
                    } else if (tableau[co_y + 1][co_x] == '5') {
                        tableau[co_y + 1][co_x] = 'X';
                        tab[co_y + 1][co_x] = 'X';
                        if (tableau[co_y + 2][co_x] == '5') {
                            tableau[co_y + 2][co_x] = 'X';
                            tab[co_y + 2][co_x] = 'X';
                            if (tableau[co_y + 3][co_x] == '5') {
                                tableau[co_y + 3][co_x] = 'X';
                                tab[co_y + 3][co_x] = 'X';
                                if (tableau[co_y + 4][co_x] == '5') {
                                    tableau[co_y + 4][co_x] = 'X';
                                    tab[co_y + 4][co_x] = 'X';
                                } else {
                                    tableau[co_y - 1][co_x] = 'X';
                                    tab[co_y - 1][co_x] = 'X';
                                }
                            } else {
                                tableau[co_y - 1][co_x] = 'X';
                                tableau[co_y - 2][co_x] = 'X';
                                tab[co_y - 1][co_x] = 'X';
                                tab[co_y - 2][co_x] = 'X';
                            }
                        } else {
                            tableau[co_y - 1][co_x] = 'X';
                            tableau[co_y - 2][co_x] = 'X';
                            tableau[co_y - 3][co_x] = 'X';
                            tab[co_y - 1][co_x] = 'X';
                            tab[co_y - 2][co_x] = 'X';
                            tab[co_y - 3][co_x] = 'X';
                        }
                    } else if (tableau[co_y][co_x - 1] == '5') {
                        tableau[co_y][co_x - 1] = 'X';
                        tab[co_y][co_x - 1] = 'X';
                        if (tableau[co_y][co_x - 2] == '5') {
                            tableau[co_y][co_x - 2] = 'X';
                            tab[co_y][co_x - 2] = 'X';
                            if (tableau[co_y][co_x - 3] == '5') {
                                tableau[co_y][co_x - 3] = 'X';
                                tab[co_y][co_x - 3] = 'X';
                                if (tableau[co_y][co_x - 4] == '5') {
                                    tableau[co_y][co_x - 4] = 'X';
                                    tab[co_y][co_x - 4] = 'X';
                                } else {
                                    tableau[co_y][co_x + 1] = 'X';
                                    tab[co_y][co_x + 1] = 'X';
                                }
                            } else {
                                tableau[co_y][co_x + 1] = 'X';
                                tableau[co_y][co_x + 2] = 'X';
                                tab[co_y][co_x + 1] = 'X';
                                tab[co_y][co_x + 2] = 'X';
                            }
                        } else {
                            tableau[co_y][co_x + 1] = 'X';
                            tableau[co_y][co_x + 2] = 'X';
                            tableau[co_y][co_x + 3] = 'X';
                            tab[co_y][co_x + 1] = 'X';
                            tab[co_y][co_x + 2] = 'X';
                            tab[co_y][co_x + 3] = 'X';
                        }
                    } else if (tableau[co_y][co_x + 1] == '5') {
                        tableau[co_y][co_x + 1] = 'X';
                        tab[co_y][co_x + 1] = 'X';
                        if (tableau[co_y][co_x + 2] == '5') {
                            tableau[co_y][co_x + 2] = 'X';
                            tab[co_y][co_x + 2] = 'X';
                            if (tableau[co_y][co_x + 3] == '5') {
                                tableau[co_y][co_x + 3] = 'X';
                                tab[co_y][co_x + 3] = 'X';
                                if (tableau[co_y][co_x + 4] == '5') {
                                    tableau[co_y][co_x + 4] = 'X';
                                    tab[co_y][co_x + 4] = 'X';
                                } else {
                                    tableau[co_y][co_x - 1] = 'X';
                                    tab[co_y][co_x - 1] = 'X';
                                }
                            } else {
                                tableau[co_y][co_x - 1] = 'X';
                                tableau[co_y][co_x - 2] = 'X';
                                tab[co_y][co_x - 1] = 'X';
                                tab[co_y][co_x - 2] = 'X';
                            }
                        } else {
                            tableau[co_y][co_x - 1] = 'X';
                            tableau[co_y][co_x - 2] = 'X';
                            tableau[co_y][co_x - 3] = 'X';
                            tab[co_y][co_x - 1] = 'X';
                            tab[co_y][co_x - 2] = 'X';
                            tab[co_y][co_x - 3] = 'X';
                        }
                    }
                    printf("Un bateau de taille 5 a ete coule\n");
                } else if (tableau[co_y][co_x] == '_'){
                    tableau[co_y][co_x] = 'O';
                    tab[co_y][co_x] = 'O';
                } else if (tableau[co_y][co_x] == 'X' && tableau[co_y][co_x] == 'O'){

                }
                break;
            case 'B' :
                e.bombe -= 1;
                printf("Ou souhaitez vous larguez le missile d'artillerie ?\n");
                scanf("%d%d", &co_y, &co_x);
                while (co_y < 0 || co_y > 9 || co_x < 0 || co_x > 9){
                    printf("Erreur, coordonnees invalides\n");
                    printf("Ou souhaitez vous larguez le missile d'artillerie ?\n");
                    scanf("%d%d", &co_y, &co_x);
                }
                if(tableau[co_y][co_x] != '_' && tableau[co_y][co_x] != 'O' && tableau[co_y][co_x] != 'X'){
                    printf("Un bateau a ete touche, en %d-%d\n", co_y, co_x);
                    tableau[co_y][co_x] = 'X';
                    tab[co_y][co_x] = 'X';
                } else if (tableau[co_y][co_x] == '_'){
                    tableau[co_y][co_x] = 'O';
                    tab[co_y][co_x] = 'O';
                } else if (tableau[co_y][co_x] == 'X' && tableau[co_y][co_x] == 'O'){

                }
                if(tableau[co_y-1][co_x] != '_' && tableau[co_y-1][co_x] != 'O' && tableau[co_y-1][co_x] != 'X'){
                    printf("Un bateau a ete touche, en %d-%d\n", co_y-1, co_x);
                    tableau[co_y-1][co_x] = 'X';
                    tab[co_y-1][co_x] = 'X';
                } else if (tableau[co_y-1][co_x] == '_'){
                    tableau[co_y-1][co_x] = 'O';
                    tab[co_y-1][co_x] = 'O';
                } else if (tableau[co_y-1][co_x] == 'X' && tableau[co_y-1][co_x] == 'O'){

                }
                if(tableau[co_y-1][co_x+1] != '_' && tableau[co_y-1][co_x+1] != 'O' && tableau[co_y-1][co_x+1] != 'X'){
                    printf("Un bateau a ete touche, en %d-%d\n", co_y-1, co_x+1);
                    tableau[co_y-1][co_x+1] = 'X';
                    tab[co_y-1][co_x+1] = 'X';
                } else if (tableau[co_y-1][co_x+1] == '_'){
                    tableau[co_y-1][co_x+1] = 'O';
                    tab[co_y-1][co_x+1] = 'O';
                } else if (tableau[co_y-1][co_x+1] == 'X' && tableau[co_y-1][co_x+1] == 'O'){

                }
                if(tableau[co_y][co_x+1] != '_' && tableau[co_y][co_x+1] != 'O' && tableau[co_y][co_x+1] != 'X'){
                    printf("Un bateau a ete touche, en %d-%d\n", co_y, co_x+1);
                    tableau[co_y][co_x+1] = 'X';
                    tab[co_y][co_x+1] = 'X';
                } else if (tableau[co_y][co_x+1] == '_'){
                    tableau[co_y][co_x+1] = 'O';
                    tab[co_y][co_x+1] = 'O';
                } else if (tableau[co_y][co_x+1] == 'X' && tableau[co_y][co_x+1] == 'O'){

                }
                if(tableau[co_y+1][co_x+1] != '_' && tableau[co_y+1][co_x+1] != 'O' && tableau[co_y+1][co_x+1] != 'X'){
                    printf("Un bateau a ete touche, en %d-%d\n", co_y+1, co_x+1);
                    tableau[co_y+1][co_x+1] = 'X';
                    tab[co_y+1][co_x+1] = 'X';
                } else if (tableau[co_y+1][co_x+1] == '_'){
                    tableau[co_y+1][co_x+1] = 'O';
                    tab[co_y+1][co_x+1] = 'O';
                } else if (tableau[co_y+1][co_x+1] == 'X' && tableau[co_y+1][co_x+1] == 'O'){

                }
                if(tableau[co_y+1][co_x] != '_' && tableau[co_y+1][co_x] != 'O' && tableau[co_y+1][co_x] != 'X'){
                    printf("Un bateau a ete touche, en %d-%d\n", co_y+1, co_x);
                    tableau[co_y+1][co_x] = 'X';
                    tab[co_y+1][co_x] = 'X';
                } else if (tableau[co_y+1][co_x] == '_'){
                    tableau[co_y+1][co_x] = 'O';
                    tab[co_y+1][co_x] = 'O';
                } else if (tableau[co_y+1][co_x] == 'X' && tableau[co_y+1][co_x] == 'O'){

                }
                if(tableau[co_y+1][co_x-1] != '_' && tableau[co_y+1][co_x-1] != 'O' && tableau[co_y+1][co_x-1] != 'X'){
                    printf("Un bateau a ete touche, en %d-%d\n", co_y+1, co_x-1);
                    tableau[co_y+1][co_x-1] = 'X';
                    tab[co_y+1][co_x-1] = 'X';
                } else if (tableau[co_y+1][co_x-1] == '_'){
                    tableau[co_y+1][co_x-1] = 'O';
                    tab[co_y+1][co_x-1] = 'O';
                } else if (tableau[co_y+1][co_x-1] == 'X' && tableau[co_y+1][co_x-1] == 'O'){

                }
                if(tableau[co_y][co_x-1] != '_' && tableau[co_y][co_x-1] != 'O' && tableau[co_y][co_x-1] != 'X'){
                    printf("Un bateau a ete touche, en %d-%d\n", co_y, co_x-1);
                    tableau[co_y][co_x-1] = 'X';
                    tab[co_y][co_x-1] = 'X';
                } else if (tableau[co_y][co_x-1] == '_'){
                    tableau[co_y][co_x-1] = 'O';
                    tab[co_y][co_x-1] = 'O';
                } else if (tableau[co_y][co_x-1] == 'X' && tableau[co_y][co_x-1] == 'O'){

                }
                if(tableau[co_y-1][co_x-1] != '_' && tableau[co_y-1][co_x-1] != 'O' && tableau[co_y-1][co_x-1] != 'X'){
                    printf("Un bateau a ete touche, en %d-%d\n", co_y-1, co_x-1);
                    tableau[co_y-1][co_x-1] = 'X';
                    tab[co_y-1][co_x-1] = 'X';
                } else if (tableau[co_y-1][co_x-1] == '_'){
                    tableau[co_y-1][co_x-1] = 'O';
                    tab[co_y-1][co_x-1] = 'O';
                } else if (tableau[co_y-1][co_x-1] == 'X' && tableau[co_y-1][co_x-1] == 'O'){

                }
                break;
            case 'M' :
                e.missile -= 1;
                printf("Ou souhaitez vous larguez le missile d'artillerie ?\n");
                scanf("%d%d", &co_y, &co_x);
                while (co_y < 0 || co_y > 9 || co_x < 0 || co_x > 9){
                    printf("Erreur, coordonnees invalides\n");
                    printf("Ou souhaitez vous larguez le missile d'artillerie ?\n");
                    scanf("%d%d", &co_y, &co_x);
                }
                if(tableau[co_y][co_x] != '_' && tableau[co_y][co_x] != 'O' && tableau[co_y][co_x] != 'X'){
                    printf("Un bateau a ete touche, en %d-%d\n", co_y, co_x);
                    tableau[co_y][co_x] = 'X';
                    tab[co_y][co_x] = 'X';
                } else if (tableau[co_y][co_x] == '_'){
                    tableau[co_y][co_x] = 'O';
                    tab[co_y][co_x] = 'O';
                } else if (tableau[co_y][co_x] == 'X' && tableau[co_y][co_x] == 'O'){

                }
                break;
            case '#' :
                printf("Bravo a vous, vous avez trouve le caractere secret permettant de gagner cette partie immediatement\n");
                printf("N'en parlez a personne, cela reste entre nous !\n");
                for (i=0;i<10;i++){
                    for (j=0;j<10;j++){
                        if (tableau[i][j] == '_' || tableau[i][j] == 'O'){
                            tableau[i][j] = 'O';
                            tab[i][j] = 'O';
                        } else {
                            tableau[i][j] = 'X';
                            tab[i][j] = 'X';
                        }
                    }
                }
                break;
            default : return 0;
        }

        continuer = recommencer(tableau);

        if(continuer == 0){
            printf("\nVous avez gagne !\n");
            return 0;
        } else if(continuer == 1){
            fflush(stdin);
            printf("\nVoulez-vous continuez (C) ou sauvegarder votre partie et quitter (S) ?\n");
            gets(&b);
            b = toupper(b);
            while (b != 'C' && b != 'S'){
                printf("Erreur dans la saisie\n");
                printf("\nVoulez-vous continuez (C) ou sauvegarder votre partie et quitter (S) ?\n");
                gets(&b);
                b = toupper(b);
            }
        }


    } while (b == 'C' && (e.missile_artillerie > 0 || e.missile_tactique > 0 || e.bombe > 0 || e.missile > 0));
    if (e.missile_artillerie == 0 || e.missile_tactique == 0 || e.bombe == 0 || e.missile == 0){
        printf("Vous avez perdu !\n");
    } else if (b == 'S'){
        FILE* fichier_sauvegarde = fopen("../sauvegarde.txt", "w");
        if(fichier_sauvegarde == NULL) {
            printf("Ouverture impossible du fichier\n");
            return -1;  // On quitte le programme
        }
        fprintf(fichier_sauvegarde, "type de jeu : %d\n\n", 2);
        fprintf(fichier_sauvegarde, "missiles d'artilleries : %d  ", e.missile_artillerie);
        fprintf(fichier_sauvegarde, "missiles tactiques : %d  ", e.missile_tactique);
        fprintf(fichier_sauvegarde, "missiles : %d  ", e.missile);
        fprintf(fichier_sauvegarde, "bombes : %d\n\n", e.bombe);
        for(i=0;i<10;i++){
            for(j=0;j<10;j++){
                fprintf(fichier_sauvegarde, "%c  ", tableau[i][j]);
            }
            fprintf(fichier_sauvegarde, "\n");

        }
    }
}

void tirs_3(char tableau[10][10], Inventory e, char tab[10][10]) {
    char a = '\0'; //type munition
    char b = '\0'; // continuez ou sauvegarder
    char maniere = '\0';
    int co_x, co_y; //coordonnées x et y
    int d;
    int i, j; //entiers pour les boucles
    int continuer; //permet de stocker un entier afin de savoir si oui ou non il reste des bateaux sur la grille
    int deplacer; // permet de savoir si l'ordinateur déplace ou non un bateau
    do {
        grille(tab);
        fflush(stdin);
        printf("\n%d missiles d'artilleries, %d missiles tactiques, %d bombes, %d missiles simples.\n\n",
               e.missile_artillerie, e.missile_tactique, e.bombe, e.missile);
        fflush(stdin);
        printf("Quel munition souhaitez-vous utiliser ? (A) ou (T) ou (B) ou (M)\n");
        gets(&a);
        a = toupper(a);
        while (a != 'A' && a != 'T' && a != 'B' && a != 'M'){
            fflush(stdin);
            printf("Veuillez entrer une munition correcte\n");
            printf("Quel munition souhaitez-vous utiliser ? (A) ou (T) ou (B) ou (M)\n");
            gets(&a);
            a = toupper(a);
        }
        if(a == 'A' && e.missile_artillerie == 0){
            fflush(stdin);
            printf("Veuillez entrer une munition restante\n");
            printf("\n%d missiles d'artilleries, %d missiles tactiques, %d bombes, %d missiles simples.\n\n",
                   e.missile_artillerie, e.missile_tactique, e.bombe, e.missile);
            printf("Quel munition souhaitez-vous utiliser ? (A) ou (T) ou (B) ou (M)\n");
            gets(&a);
            a = toupper(a);
        } else if (a == 'T' && e.missile_tactique == 0){
            fflush(stdin);
            printf("Veuillez entrer une munition restante\n");
            printf("\n%d missiles d'artilleries, %d missiles tactiques, %d bombes, %d missiles simples.\n\n",
                   e.missile_artillerie, e.missile_tactique, e.bombe, e.missile);
            printf("Quel munition souhaitez-vous utiliser ? (A) ou (T) ou (B) ou (M)\n");
            gets(&a);
            a = toupper(a);
        } else if (a == 'B' && e.bombe == 0){
            fflush(stdin);
            printf("Veuillez entrer une munition restante\n");
            printf("\n%d missiles d'artilleries, %d missiles tactiques, %d bombes, %d missiles simples.\n\n",
                   e.missile_artillerie, e.missile_tactique, e.bombe, e.missile);
            printf("Quel munition souhaitez-vous utiliser ? (A) ou (T) ou (B) ou (M)\n");
            gets(&a);
            a = toupper(a);
        } else if (a == 'M' && e.missile == 0){
            fflush(stdin);
            printf("Veuillez entrer une munition restante\n");
            printf("\n%d missiles d'artilleries, %d missiles tactiques, %d bombes, %d missiles simples.\n\n",
                   e.missile_artillerie, e.missile_tactique, e.bombe, e.missile);
            printf("Quel munition souhaitez-vous utiliser ? (A) ou (T) ou (B) ou (M)\n");
            gets(&a);
            a = toupper(a);
        }
        switch (a) {
            case 'A' :
                e.missile_artillerie -= 1;
                printf("Ou souhaitez vous larguez le missile d'artillerie ?\n");
                scanf("%d%d", &co_y, &co_x);
                while (co_y < 0 || co_y > 9 || co_x < 0 || co_x > 9){
                    fflush(stdin);
                    printf("Erreur, coordonnees invalides\n");
                    printf("Ou souhaitez vous larguez le missile d'artillerie ?\n");
                    scanf("%d%d", &co_y, &co_x);
                }
                fflush(stdin);
                printf("De maniere horizontale (H) ou verticale (V) ?\n");
                gets(&maniere);
                while (maniere != 'H' && maniere != 'V') {
                    printf("De maniere horizontale (H) ou verticale (V) ?\n");
                    gets(&maniere);
                }
                if (maniere == 'H') {
                    for (i = 0; i < 10; i++) {
                        if (tableau[co_y][i] != '_' && tableau[co_y][i] != 'O' && tableau[co_y][i] != 'X') {
                            printf("Un bateau a ete touche, en %d-%d\n", co_y, i);
                            tableau[co_y][i] = 'X';
                            tab[co_y][i] = 'X';
                        } else if (tableau[co_y][i] == '_'){
                            tableau[co_y][i] = 'O';
                            tab[co_y][i] = 'O';
                        } else if (tableau[co_y][i] == 'X' && tableau[co_y][i] == 'O'){

                        }
                    }
                } else {
                    for (i = 0; i < 10; i++) {
                        if (tableau[i][co_x] != '_' && tableau[i][co_x] != 'O' && tableau[i][co_x] != 'X') {
                            printf("Un bateau a ete touche, en %d-%d\n", i, co_x);
                            tableau[i][co_x] = 'X';
                            tab[i][co_x] = 'X';
                        } else if (tableau[i][co_x] == '_'){
                            tableau[i][i] = 'O';
                            tab[i][co_x] = 'O';
                        } else if (tableau[i][co_x] == 'X' && tableau[i][co_x] == 'O'){

                        }
                    }
                }
                grille(tab);
                break;
            case 'T' :
                e.missile_tactique -= 1;
                printf("Ou souhaitez vous larguez le missile d'artillerie ?\n");
                scanf("%d%d", &co_y, &co_x);
                while (co_y < 0 || co_y > 9 || co_x < 0 || co_x > 9){
                    printf("Erreur, coordonnees invalides\n");
                    printf("Ou souhaitez vous larguez le missile d'artillerie ?\n");
                    scanf("%d%d", &co_y, &co_x);
                }
                if(tableau[co_y][co_x] == '2'){
                    printf("Un bateau a ete touche, en %d-%d\n", co_y, co_x);
                    tableau[co_y][co_x] = 'X';
                    tab[co_y][co_x] = 'X';
                    if(tableau[co_y-1][co_x] == '2'){
                        tableau[co_y-1][co_x] = 'X';
                        tab[co_y-1][co_x] = 'X';
                    } else if(tableau[co_y+1][co_x] == '2'){
                        tableau[co_y+1][co_x] = 'X';
                        tab[co_y+1][co_x] = 'X';
                    }else if (tableau[co_y][co_x-1] == '2'){
                        tableau[co_y][co_x-1] = 'X';
                        tab[co_y][co_x-1] = 'X';
                    }else if(tableau[co_y][co_x+1] == '2'){
                        tableau[co_y][co_x+1] = 'X';
                        tab[co_y][co_x+1] = 'X';
                    }
                    printf("Un bateau de taille 2 a ete coule\n");
                } else if (tableau[co_y][co_x] == '3') {
                    tableau[co_y][co_x] = 'X';
                    tab[co_y][co_x] = 'X';
                    if (tableau[co_y - 1][co_x] == '3') {
                        tableau[co_y - 1][co_x] = 'X';
                        tab[co_y - 1][co_x] = 'X';
                        if (tableau[co_y - 2][co_x] == '3') {
                            tableau[co_y - 2][co_x] = 'X';
                            tab[co_y - 2][co_x] = 'X';
                        } else {
                            tableau[co_y + 1][co_x] = 'X';
                            tab[co_y + 1][co_x] = 'X';
                        }
                    } else if (tableau[co_y + 1][co_x] == '3') {
                        tableau[co_y + 1][co_x] = 'X';
                        tab[co_y + 1][co_x] = 'X';
                        if (tableau[co_y + 2][co_x] == '3') {
                            tableau[co_y + 2][co_x] = 'X';
                            tab[co_y + 2][co_x] = 'X';
                        } else {
                            tableau[co_y - 1][co_x] = 'X';
                            tab[co_y - 1][co_x] = 'X';
                        }
                    } else if (tableau[co_y][co_x - 1] == '3') {
                        tableau[co_y][co_x - 1] = 'X';
                        tab[co_y][co_x - 1] = 'X';
                        if (tableau[co_y][co_x - 2] == '3') {
                            tableau[co_y][co_x - 2] = 'X';
                            tab[co_y][co_x - 2] = 'X';
                        } else {
                            tableau[co_y][co_x + 1] = 'X';
                            tab[co_y][co_x + 1] = 'X';
                        }
                    } else if (tableau[co_y][co_x + 1] == '3') {
                        tableau[co_y][co_x + 1] = 'X';
                        tab[co_y][co_x + 1] = 'X';
                        if (tableau[co_y][co_x + 2] == '3') {
                            tableau[co_y][co_x + 2] = 'X';
                            tab[co_y][co_x + 2] = 'X';
                        } else {
                            tableau[co_y][co_x - 1] = 'X';
                            tab[co_y][co_x - 1] = 'X';
                        }
                    }
                    printf("Un bateau de taille 3 a ete coule\n");
                }else if(tableau[co_y][co_x] == '4') {
                    tableau[co_y][co_x] = 'X';
                    tab[co_y][co_x] = 'X';
                    if (tableau[co_y - 1][co_x] == '4') {
                        tableau[co_y - 1][co_x] = 'X';
                        tab[co_y - 1][co_x] = 'X';
                        if (tableau[co_y - 2][co_x] == '4') {
                            tableau[co_y - 2][co_x] = 'X';
                            tab[co_y - 2][co_x] = 'X';
                            if(tableau[co_y - 3][co_x] == '4'){
                                tableau[co_y - 3][co_x] = 'X';
                                tab[co_y - 3][co_x] = 'X';
                            } else {
                                tableau[co_y + 1][co_x] = 'X';
                                tab[co_y + 1][co_x] = 'X';
                            }
                        } else {
                            tableau[co_y + 1][co_x] = 'X';
                            tableau[co_y + 2][co_x] = 'X';
                            tab[co_y + 1][co_x] = 'X';
                            tab[co_y + 2][co_x] = 'X';
                        }
                    } else if (tableau[co_y + 1][co_x] == '4') {
                        tableau[co_y + 1][co_x] = 'X';
                        tab[co_y + 1][co_x] = 'X';
                        if (tableau[co_y + 2][co_x] == '4') {
                            tableau[co_y + 2][co_x] = 'X';
                            tab[co_y + 2][co_x] = 'X';
                            if(tableau[co_y + 3][co_x] == '4'){
                                tableau[co_y + 3][co_x] = 'X';
                                tab[co_y + 3][co_x] = 'X';
                            } else {
                                tableau[co_y - 1][co_x] = 'X';
                                tab[co_y - 1][co_x] = 'X';
                            }
                        } else {
                            tableau[co_y - 1][co_x] = 'X';
                            tableau[co_y - 2][co_x] = 'X';
                            tab[co_y - 1][co_x] = 'X';
                            tab[co_y - 2][co_x] = 'X';
                        }
                    } else if (tableau[co_y][co_x - 1] == '4') {
                        tableau[co_y][co_x - 1] = 'X';
                        tab[co_y][co_x - 1] = 'X';
                        if (tableau[co_y][co_x - 2] == '4') {
                            tableau[co_y][co_x - 2] = 'X';
                            tab[co_y][co_x - 2] = 'X';
                            if(tableau[co_y][co_x - 3] == '4'){
                                tableau[co_y][co_x - 3] = 'X';
                                tab[co_y][co_x - 3] = 'X';
                            } else {
                                tableau[co_y][co_x + 1] = 'X';
                                tab[co_y][co_x + 1] = 'X';
                            }
                        } else {
                            tableau[co_y][co_x + 1] = 'X';
                            tableau[co_y][co_x + 2] = 'X';
                            tab[co_y][co_x + 1] = 'X';
                            tab[co_y][co_x + 2] = 'X';
                        }
                    } else if (tableau[co_y][co_x + 1] == '4') {
                        tableau[co_y][co_x + 1] = 'X';
                        tab[co_y][co_x + 1] = 'X';
                        if (tableau[co_y][co_x + 2] == '4') {
                            tableau[co_y][co_x + 2] = 'X';
                            tab[co_y][co_x + 2] = 'X';
                            if (tableau[co_y][co_x + 3] == '4') {
                                tableau[co_y][co_x + 3] = 'X';
                                tab[co_y][co_x + 3] = 'X';
                            } else {
                                tableau[co_y][co_x - 1] = 'X';
                                tab[co_y][co_x - 1] = 'X';
                            }
                        } else {
                            tableau[co_y][co_x - 1] = 'X';
                            tableau[co_y][co_x - 2] = 'X';
                            tab[co_y][co_x - 1] = 'X';
                            tab[co_y][co_x - 2] = 'X';
                        }
                    }
                    printf("Un bateau de taille 4 a ete coule\n");
                } else if (tableau[co_y][co_x] == '5'){
                    tableau[co_y][co_x] = 'X';
                    tab[co_y][co_x] = 'X';
                    if (tableau[co_y - 1][co_x] == '5') {
                        tableau[co_y - 1][co_x] = 'X';
                        tab[co_y - 1][co_x] = 'X';
                        if (tableau[co_y - 2][co_x] == '5') {
                            tableau[co_y - 2][co_x] = 'X';
                            tab[co_y - 2][co_x] = 'X';
                            if (tableau[co_y - 3][co_x] == '5') {
                                tableau[co_y - 3][co_x] = 'X';
                                tab[co_y - 3][co_x] = 'X';
                                if (tableau[co_y - 4][co_x] == '5') {
                                    tableau[co_y - 4][co_x] = 'X';
                                    tab[co_y - 4][co_x] = 'X';
                                } else {
                                    tableau[co_y + 1][co_x] = 'X';
                                    tab[co_y + 1][co_x] = 'X';
                                }
                            } else {
                                tableau[co_y + 1][co_x] = 'X';
                                tableau[co_y + 2][co_x] = 'X';
                                tab[co_y + 1][co_x] = 'X';
                                tab[co_y + 2][co_x] = 'X';
                            }
                        } else {
                            tableau[co_y + 1][co_x] = 'X';
                            tableau[co_y + 2][co_x] = 'X';
                            tableau[co_y + 3][co_x] = 'X';
                            tab[co_y + 1][co_x] = 'X';
                            tab[co_y + 2][co_x] = 'X';
                            tab[co_y + 3][co_x] = 'X';
                        }
                    } else if (tableau[co_y + 1][co_x] == '5') {
                        tableau[co_y + 1][co_x] = 'X';
                        tab[co_y + 1][co_x] = 'X';
                        if (tableau[co_y + 2][co_x] == '5') {
                            tableau[co_y + 2][co_x] = 'X';
                            tab[co_y + 2][co_x] = 'X';
                            if (tableau[co_y + 3][co_x] == '5') {
                                tableau[co_y + 3][co_x] = 'X';
                                tab[co_y + 3][co_x] = 'X';
                                if (tableau[co_y + 4][co_x] == '5') {
                                    tableau[co_y + 4][co_x] = 'X';
                                    tab[co_y + 4][co_x] = 'X';
                                } else {
                                    tableau[co_y - 1][co_x] = 'X';
                                    tab[co_y - 1][co_x] = 'X';
                                }
                            } else {
                                tableau[co_y - 1][co_x] = 'X';
                                tableau[co_y - 2][co_x] = 'X';
                                tab[co_y - 1][co_x] = 'X';
                                tab[co_y - 2][co_x] = 'X';
                            }
                        } else {
                            tableau[co_y - 1][co_x] = 'X';
                            tableau[co_y - 2][co_x] = 'X';
                            tableau[co_y - 3][co_x] = 'X';
                            tab[co_y - 1][co_x] = 'X';
                            tab[co_y - 2][co_x] = 'X';
                            tab[co_y - 3][co_x] = 'X';
                        }
                    } else if (tableau[co_y][co_x - 1] == '5') {
                        tableau[co_y][co_x - 1] = 'X';
                        tab[co_y][co_x - 1] = 'X';
                        if (tableau[co_y][co_x - 2] == '5') {
                            tableau[co_y][co_x - 2] = 'X';
                            tab[co_y][co_x - 2] = 'X';
                            if (tableau[co_y][co_x - 3] == '5') {
                                tableau[co_y][co_x - 3] = 'X';
                                tab[co_y][co_x - 3] = 'X';
                                if (tableau[co_y][co_x - 4] == '5') {
                                    tableau[co_y][co_x - 4] = 'X';
                                    tab[co_y][co_x - 4] = 'X';
                                } else {
                                    tableau[co_y][co_x + 1] = 'X';
                                    tab[co_y][co_x + 1] = 'X';
                                }
                            } else {
                                tableau[co_y][co_x + 1] = 'X';
                                tableau[co_y][co_x + 2] = 'X';
                                tab[co_y][co_x + 1] = 'X';
                                tab[co_y][co_x + 2] = 'X';
                            }
                        } else {
                            tableau[co_y][co_x + 1] = 'X';
                            tableau[co_y][co_x + 2] = 'X';
                            tableau[co_y][co_x + 3] = 'X';
                            tab[co_y][co_x + 1] = 'X';
                            tab[co_y][co_x + 2] = 'X';
                            tab[co_y][co_x + 3] = 'X';
                        }
                    } else if (tableau[co_y][co_x + 1] == '5') {
                        tableau[co_y][co_x + 1] = 'X';
                        tab[co_y][co_x + 1] = 'X';
                        if (tableau[co_y][co_x + 2] == '5') {
                            tableau[co_y][co_x + 2] = 'X';
                            tab[co_y][co_x + 2] = 'X';
                            if (tableau[co_y][co_x + 3] == '5') {
                                tableau[co_y][co_x + 3] = 'X';
                                tab[co_y][co_x + 3] = 'X';
                                if (tableau[co_y][co_x + 4] == '5') {
                                    tableau[co_y][co_x + 4] = 'X';
                                    tab[co_y][co_x + 4] = 'X';
                                } else {
                                    tableau[co_y][co_x - 1] = 'X';
                                    tab[co_y][co_x - 1] = 'X';
                                }
                            } else {
                                tableau[co_y][co_x - 1] = 'X';
                                tableau[co_y][co_x - 2] = 'X';
                                tab[co_y][co_x - 1] = 'X';
                                tab[co_y][co_x - 2] = 'X';
                            }
                        } else {
                            tableau[co_y][co_x - 1] = 'X';
                            tableau[co_y][co_x - 2] = 'X';
                            tableau[co_y][co_x - 3] = 'X';
                            tab[co_y][co_x - 1] = 'X';
                            tab[co_y][co_x - 2] = 'X';
                            tab[co_y][co_x - 3] = 'X';
                        }
                    }
                    printf("Un bateau de taille 5 a ete coule\n");
                } else if (tableau[co_y][co_x] == '_'){
                    tableau[co_y][co_x] = 'O';
                    tab[co_y][co_x] = 'O';
                } else if (tableau[co_y][co_x] == 'X' && tableau[co_y][co_x] == 'O'){

                }
                grille(tab);
                break;
            case 'B' :
                e.bombe -= 1;
                printf("Ou souhaitez vous larguez le missile d'artillerie ?\n");
                scanf("%d%d", &co_y, &co_x);
                while (co_y < 0 || co_y > 9 || co_x < 0 || co_x > 9){
                    printf("Erreur, coordonnees invalides\n");
                    printf("Ou souhaitez vous larguez le missile d'artillerie ?\n");
                    scanf("%d%d", &co_y, &co_x);
                }
                if(tableau[co_y][co_x] != '_' && tableau[co_y][co_x] != 'O' && tableau[co_y][co_x] != 'X'){
                    printf("Un bateau a ete touche, en %d-%d\n", co_y, co_x);
                    tableau[co_y][co_x] = 'X';
                    tab[co_y][co_x] = 'X';
                } else if (tableau[co_y][co_x] == '_'){
                    tableau[co_y][co_x] = 'O';
                    tab[co_y][co_x] = 'O';
                } else if (tableau[co_y][co_x] == 'X' && tableau[co_y][co_x] == 'O'){

                }
                if(tableau[co_y-1][co_x] != '_' && tableau[co_y-1][co_x] != 'O' && tableau[co_y-1][co_x] != 'X'){
                    printf("Un bateau a ete touche, en %d-%d\n", co_y-1, co_x);
                    tableau[co_y-1][co_x] = 'X';
                    tab[co_y-1][co_x] = 'X';
                } else if (tableau[co_y-1][co_x] == '_'){
                    tableau[co_y-1][co_x] = 'O';
                    tab[co_y-1][co_x] = 'O';
                } else if (tableau[co_y-1][co_x] == 'X' && tableau[co_y-1][co_x] == 'O'){

                }
                if(tableau[co_y-1][co_x+1] != '_' && tableau[co_y-1][co_x+1] != 'O' && tableau[co_y-1][co_x+1] != 'X'){
                    printf("Un bateau a ete touche, en %d-%d\n", co_y-1, co_x+1);
                    tableau[co_y-1][co_x+1] = 'X';
                    tab[co_y-1][co_x+1] = 'X';
                } else if (tableau[co_y-1][co_x+1] == '_'){
                    tableau[co_y-1][co_x+1] = 'O';
                    tab[co_y-1][co_x+1] = 'O';
                } else if (tableau[co_y-1][co_x+1] == 'X' && tableau[co_y-1][co_x+1] == 'O'){

                }
                if(tableau[co_y][co_x+1] != '_' && tableau[co_y][co_x+1] != 'O' && tableau[co_y][co_x+1] != 'X'){
                    printf("Un bateau a ete touche, en %d-%d\n", co_y, co_x+1);
                    tableau[co_y][co_x+1] = 'X';
                    tab[co_y][co_x+1] = 'X';
                } else if (tableau[co_y][co_x+1] == '_'){
                    tableau[co_y][co_x+1] = 'O';
                    tab[co_y][co_x+1] = 'O';
                } else if (tableau[co_y][co_x+1] == 'X' && tableau[co_y][co_x+1] == 'O'){

                }
                if(tableau[co_y+1][co_x+1] != '_' && tableau[co_y+1][co_x+1] != 'O' && tableau[co_y+1][co_x+1] != 'X'){
                    printf("Un bateau a ete touche, en %d-%d\n", co_y+1, co_x+1);
                    tableau[co_y+1][co_x+1] = 'X';
                    tab[co_y+1][co_x+1] = 'X';
                } else if (tableau[co_y+1][co_x+1] == '_'){
                    tableau[co_y+1][co_x+1] = 'O';
                    tab[co_y+1][co_x+1] = 'O';
                } else if (tableau[co_y+1][co_x+1] == 'X' && tableau[co_y+1][co_x+1] == 'O'){

                }
                if(tableau[co_y+1][co_x] != '_' && tableau[co_y+1][co_x] != 'O' && tableau[co_y+1][co_x] != 'X'){
                    printf("Un bateau a ete touche, en %d-%d\n", co_y+1, co_x);
                    tableau[co_y+1][co_x] = 'X';
                    tab[co_y+1][co_x] = 'X';
                } else if (tableau[co_y+1][co_x] == '_'){
                    tableau[co_y+1][co_x] = 'O';
                    tab[co_y+1][co_x] = 'O';
                } else if (tableau[co_y+1][co_x] == 'X' && tableau[co_y+1][co_x] == 'O'){

                }
                if(tableau[co_y+1][co_x-1] != '_' && tableau[co_y+1][co_x-1] != 'O' && tableau[co_y+1][co_x-1] != 'X'){
                    printf("Un bateau a ete touche, en %d-%d\n", co_y+1, co_x-1);
                    tableau[co_y+1][co_x-1] = 'X';
                    tab[co_y+1][co_x-1] = 'X';
                } else if (tableau[co_y+1][co_x-1] == '_'){
                    tableau[co_y+1][co_x-1] = 'O';
                    tab[co_y+1][co_x-1] = 'O';
                } else if (tableau[co_y+1][co_x-1] == 'X' && tableau[co_y+1][co_x-1] == 'O'){

                }
                if(tableau[co_y][co_x-1] != '_' && tableau[co_y][co_x-1] != 'O' && tableau[co_y][co_x-1] != 'X'){
                    printf("Un bateau a ete touche, en %d-%d\n", co_y, co_x-1);
                    tableau[co_y][co_x-1] = 'X';
                    tab[co_y][co_x-1] = 'X';
                } else if (tableau[co_y][co_x-1] == '_'){
                    tableau[co_y][co_x-1] = 'O';
                    tab[co_y][co_x-1] = 'O';
                } else if (tableau[co_y][co_x-1] == 'X' && tableau[co_y][co_x-1] == 'O'){

                }
                if(tableau[co_y-1][co_x-1] != '_' && tableau[co_y-1][co_x-1] != 'O' && tableau[co_y-1][co_x-1] != 'X'){
                    printf("Un bateau a ete touche, en %d-%d\n", co_y-1, co_x-1);
                    tableau[co_y-1][co_x-1] = 'X';
                    tab[co_y-1][co_x-1] = 'X';
                } else if (tableau[co_y-1][co_x-1] == '_'){
                    tableau[co_y-1][co_x-1] = 'O';
                    tab[co_y-1][co_x-1] = 'O';
                } else if (tableau[co_y-1][co_x-1] == 'X' && tableau[co_y-1][co_x-1] == 'O'){

                }
                grille(tab);
                break;
            case 'M' :
                e.missile -= 1;
                printf("Ou souhaitez vous larguez le missile d'artillerie ?\n");
                scanf("%d%d", &co_y, &co_x);
                while (co_y < 0 || co_y > 9 || co_x < 0 || co_x > 9){
                    printf("Erreur, coordonnees invalides\n");
                    printf("Ou souhaitez vous larguez le missile d'artillerie ?\n");
                    scanf("%d%d", &co_y, &co_x);
                }
                if(tableau[co_y][co_x] != '_' && tableau[co_y][co_x] != 'O' && tableau[co_y][co_x] != 'X'){
                    printf("Un bateau a ete touche, en %d-%d\n", co_y, co_x);
                    tableau[co_y][co_x] = 'X';
                    tab[co_y][co_x] = 'X';
                } else if (tableau[co_y][co_x] == '_'){
                    tableau[co_y][co_x] = 'O';
                    tab[co_y][co_x] = 'O';
                } else if (tableau[co_y][co_x] == 'X' && tableau[co_y][co_x] == 'O'){

                }
                grille(tab);
                break;
            case '#' :
                printf("Bravo a vous, vous avez trouve le caractere secret permettant de gagner cette partie immediatement\n");
                printf("N'en parlez a personne, cela reste entre nous !\n");
                for (i=0;i<10;i++){
                    for (j=0;j<10;j++){
                        if (tableau[i][j] == '_' || tableau[i][j] == 'O'){
                            tableau[i][j] = 'O';
                            tab[i][j] = 'O';
                        } else {
                            tableau[i][j] = 'X';
                            tab[i][j] = 'X';
                        }
                    }
                }
                grille(tab);
                break;
            default : return 0;
        }

        continuer = recommencer(tableau);

        if(continuer == 0){
            printf("\nVous avez gagne! \n");
            return 0;
        }

        srand(time(0));
        deplacer = rand()% 2;
        if(deplacer == 0){
            do {
                co_y = rand() % 10;
                co_x = rand() % 10;
            } while (tableau[co_y][co_x] == '_' || tableau[co_y][co_x] == 'X' || tableau[co_y][co_x] == 'O');
            if(tableau[co_y][co_x] == '2'){
                tableau[co_y][co_x] = '_';
                if(tableau[co_y][co_x+1] == '2' || tableau[co_y][co_x+1] == 'X'){
                    tableau[co_y][co_x+1] = '_';
                } else if(tableau[co_y][co_x-1] == '2' || tableau[co_y][co_x-1] == 'X'){
                    tableau[co_y][co_x-1] = '_';
                } else if (tableau[co_y+1][co_x] == '2' || tableau[co_y+1][co_x] == 'X'){
                    tableau[co_y+1][co_x] = '_';
                } else if (tableau[co_y-1][co_x] == '2' || tableau[co_y-1][co_x] == 'X'){
                    tableau[co_y-1][co_x] = '_';
                }
                do {
                    co_y = rand() % 10;
                    co_x = rand() % 10;
                } while (co_x > 8 || tableau[co_y][co_x + 1] != '_' || co_y > 8  ||
                         tableau[co_y + 1][co_x] != '_');
                tableau[co_y][co_x] = '2';

                d = rand() % 2;

                if (d == 0) {
                    tableau[co_y][co_x + 1] = '2';
                } else if (d == 1) {
                    tableau[co_y + 1][co_x] = '2';
                }

            } else if (tableau[co_y][co_x] == '3'){
                tableau[co_y][co_x] = '_';
                if(tableau[co_y][co_x+1] == '3' || tableau[co_y][co_x+1] == 'X'){
                    tableau[co_y][co_x+1] = '_';
                    if(tableau[co_y][co_x+2] == '3' || tableau[co_y][co_x+2] == 'X'){
                        tableau[co_y][co_x+2] = '_';
                    } else {
                        tableau[co_y][co_x-1] = '_';
                    }
                } else if (tableau[co_y][co_x-1] == '3' || tableau[co_y][co_x-1] == 'X'){
                    tableau[co_y][co_x-1] = '_';
                    tableau[co_y][co_x-2] = '_';
                } else if (tableau[co_y+1][co_x] == '3' || tableau[co_y+1][co_x] == 'X') {
                    tableau[co_y+1][co_x] = '_';
                    if(tableau[co_y+2][co_x] == '3' || tableau[co_y+2][co_x] == 'X'){
                        tableau[co_y+2][co_x] = '_';
                    } else {
                        tableau[co_y-1][co_x] = '_';
                    }
                } else if (tableau[co_y-1][co_x] == '3' || tableau[co_y-1][co_x] == 'X'){
                    tableau[co_y-1][co_x] = '_';
                    tableau[co_y-2][co_x] = '_';
                }
                do {
                    co_y = rand() % 10;
                    co_x = rand() % 10;
                } while (co_x > 7 || tableau[co_y][co_x + 1] != '_' || tableau[co_y][co_x + 2] != '_' || co_y > 7  ||
                         tableau[co_y + 1][co_x] != '_' || tableau[co_y + 2][co_x] != '_');
                tableau[co_y][co_x] = '3';

                d = rand() % 2;

                if (d == 0) {
                    tableau[co_y][co_x + 1] = '3';
                    tableau[co_y][co_x + 2] = '3';
                } else if (d == 1) {
                    tableau[co_y + 1][co_x] = '3';
                    tableau[co_y + 2][co_x] = '3';
                }
            } else if(tableau[co_y][co_x] == '4'){
                tableau[co_y][co_x] = '_';
                if(tableau[co_y][co_x+1] == '4' || tableau[co_y][co_x+1] == 'X'){
                    tableau[co_y][co_x+1] = '_';
                    if(tableau[co_y][co_x+2] == '4' || tableau[co_y][co_x+2] == 'X'){
                        tableau[co_y][co_x+2] = '_';
                        if(tableau[co_y][co_x+3] == '4' || tableau[co_y][co_x+3] == 'X'){
                            tableau[co_y][co_x+3] = '_';
                        } else {
                            tableau[co_y][co_x-1] = '_';
                        }
                    } else {
                        tableau[co_y][co_x-1] = '_';
                        tableau[co_y][co_x-2] = '_';
                    }
                } else if (tableau[co_y][co_x-1] == '4' || tableau[co_y][co_x-1] == 'X'){
                    tableau[co_y][co_x-1] = '_';
                    tableau[co_y][co_x-2] = '_';
                    tableau[co_y][co_x-3] = '_';
                } else if (tableau[co_y+1][co_x] == '4' || tableau[co_y+1][co_x] == 'X') {
                    tableau[co_y+1][co_x] = '_';
                    if(tableau[co_y+2][co_x] == '4' || tableau[co_y+2][co_x] == 'X'){
                        tableau[co_y+2][co_x] = '_';
                        if(tableau[co_y+3][co_x] == '4' || tableau[co_y+3][co_x] == 'X'){
                            tableau[co_y+3][co_x] = '_';
                        } else {
                            tableau[co_y-1][co_x] = '_';
                        }
                    } else {
                        tableau[co_y-1][co_x] = '_';
                        tableau[co_y-2][co_x] = '_';
                    }
                } else if (tableau[co_y-1][co_x] == '4' || tableau[co_y-1][co_x] == 'X'){
                    tableau[co_y-1][co_x] = '_';
                    tableau[co_y-2][co_x] = '_';
                    tableau[co_y-3][co_x] = '_';
                }
                do {
                    co_y = rand() % 10;
                    co_x = rand() % 10;
                } while (co_x > 6 || tableau[co_y][co_x + 1] != '_' || tableau[co_y][co_x + 2] != '_' || tableau[co_y][co_x + 3] != '_' || co_y > 6  ||
                         tableau[co_y + 1][co_x] != '_' || tableau[co_y + 2][co_x] != '_' || tableau[co_y + 3][co_x] != '_');
                tableau[co_y][co_x] = '4';

                d = rand() % 2;

                if (d == 0) {
                    tableau[co_y][co_x + 1] = '4';
                    tableau[co_y][co_x + 2] = '4';
                    tableau[co_y][co_x + 3] = '4';
                } else if (d == 1) {
                    tableau[co_y + 1][co_x] = '4';
                    tableau[co_y + 2][co_x] = '4';
                    tableau[co_y + 3][co_x] = '4';
                }
            } else if (tableau[co_y][co_x] == '5'){
                tableau[co_y][co_x] = '_';
                if(tableau[co_y][co_x+1] == '5' || tableau[co_y][co_x+1] == 'X'){
                    tableau[co_y][co_x+1] = '_';
                    if(tableau[co_y][co_x+2] == '5' || tableau[co_y][co_x+2] == 'X'){
                        tableau[co_y][co_x+2] = '_';
                        if(tableau[co_y][co_x+3] == '5' || tableau[co_y][co_x+3] == 'X'){
                            tableau[co_y][co_x+3] = '_';
                            if(tableau[co_y][co_x+4] == '5' || tableau[co_y][co_x+4] == 'X'){
                                tableau[co_y][co_x+4] = '_';
                            } else {
                                tableau[co_y][co_x-1] = '_';
                            }
                        } else {
                            tableau[co_y][co_x-1] = '_';
                            tableau[co_y][co_x-2] = '_';
                        }
                    } else {
                        tableau[co_y][co_x-1] = '_';
                        tableau[co_y][co_x-2] = '_';
                        tableau[co_y][co_x-3] = '_';
                    }
                } else if (tableau[co_y][co_x-1] == '5' || tableau[co_y][co_x-1] == 'X'){
                    tableau[co_y][co_x-1] = '_';
                    tableau[co_y][co_x-2] = '_';
                    tableau[co_y][co_x-3] = '_';
                    tableau[co_y][co_x-4] = '_';
                } else if (tableau[co_y+1][co_x] == '5' || tableau[co_y+1][co_x] == 'X') {
                    tableau[co_y+1][co_x] = '_';
                    if(tableau[co_y+2][co_x] == '5' || tableau[co_y+2][co_x] == 'X'){
                        tableau[co_y+2][co_x] = '_';
                        if(tableau[co_y+3][co_x] == '5' || tableau[co_y+3][co_x] == 'X'){
                            tableau[co_y+3][co_x] = '_';
                            if(tableau[co_y+4][co_x] == '5' || tableau[co_y+4][co_x] == 'X'){
                                tableau[co_y+4][co_x] = '_';
                            } else {
                                tableau[co_y-1][co_x] = '_';
                            }
                        } else {
                            tableau[co_y-1][co_x] = '_';
                            tableau[co_y-2][co_x] = '_';
                        }
                    } else {
                        tableau[co_y-1][co_x] = '_';
                        tableau[co_y-2][co_x] = '_';
                        tableau[co_y-3][co_x] = '_';
                    }
                } else if (tableau[co_y-1][co_x] == '5' || tableau[co_y-1][co_x] == 'X'){
                    tableau[co_y-1][co_x] = '_';
                    tableau[co_y-2][co_x] = '_';
                    tableau[co_y-3][co_x] = '_';
                    tableau[co_y-4][co_x] = '_';
                }
                do {
                    co_y = rand() % 10;
                    co_x = rand() % 10;
                } while (co_x > 5 || co_y > 5);
                tableau[co_y][co_x] = '5';

                d = rand() % 2;

                if (d == 0) {
                    tableau[co_y][co_x + 1] = '5';
                    tableau[co_y][co_x + 2] = '5';
                    tableau[co_y][co_x + 3] = '5';
                    tableau[co_y][co_x + 4] = '5';
                } else if (d == 1) {
                    tableau[co_y + 1][co_x] = '5';
                    tableau[co_y + 2][co_x] = '5';
                    tableau[co_y + 3][co_x] = '5';
                    tableau[co_y + 4][co_x] = '5';
                }
            }
        }

        if(continuer == 1){
            fflush(stdin);
            printf("\nVoulez-vous continuez (C) ou sauvegarder votre partie et quitter (S) ?\n");
            gets(&b);
            b = toupper(b);
            while (b != 'C' && b != 'S'){
                printf("Erreur dans la saisie\n");
                printf("\nVoulez-vous continuez (C) ou sauvegarder votre partie et quitter (S) ?\n");
                gets(&b);
                b = toupper(b);
            }
        }


    } while (b == 'C' && (e.missile_artillerie > 0 || e.missile_tactique > 0 || e.bombe > 0 || e.missile > 0));
    if (e.missile_artillerie == 0 || e.missile_tactique == 0 || e.bombe == 0 || e.missile == 0){
        printf("Vous avez perdu !\n");
    } else if (b == 'S'){
        FILE* fichier_sauvegarde = fopen("../sauvegarde.txt", "w");
        if(fichier_sauvegarde == NULL) {
            printf("Ouverture impossible du fichier\n");
            return -1;  // On quitte le programme
        }
        fprintf(fichier_sauvegarde, "type de jeu : %d\n\n", 3);
        fprintf(fichier_sauvegarde, "missiles d'artilleries : %d  ", e.missile_artillerie);
        fprintf(fichier_sauvegarde, "missiles tactiques : %d  ", e.missile_tactique);
        fprintf(fichier_sauvegarde, "missiles : %d  ", e.missile);
        fprintf(fichier_sauvegarde, "bombes : %d\n\n", e.bombe);
        for(i=0;i<10;i++){
            for(j=0;j<10;j++){
                fprintf(fichier_sauvegarde, "%c  ", tableau[i][j]);
            }
            fprintf(fichier_sauvegarde, "\n");
        }
    }
}