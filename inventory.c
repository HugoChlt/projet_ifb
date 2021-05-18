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

void tirs(char tableau[10][10], Inventory e, char tab[10][10]) {
    char a = '\0'; //type munition
    char b = '\0'; // continuez ou sauvegarder
    char maniere = '\0';
    int co_x, co_y;
    int i, j;
    int oui;
    grille_initiale(tab);
    do {
        grille(tab);
        fflush(stdin);
        printf("\n%d missiles d'artilleries, %d missiles tactiques, %d bombes, %d missiles simples.\n\n",
               e.missile_artillerie, e.missile_tactique, e.bombe, e.missile);
        fflush(stdin);
        printf("Quel munition souhaitez-vous utiliser ? (A) ou (T) ou (B) ou (M)\n");
        gets(&a);
        while (a != 'A' && a != 'T' && a != 'B' && a != 'M') {
            printf("Quel munition souhaitez-vous utiliser ? (A) ou (T) ou (B) ou (M)\n");
            gets(&a);
        }
        switch (a) {
            case 'A' :
                e.missile_artillerie -= 1;
                printf("Ou souhaitez vous larguez le missile d'artillerie ?\n");
                scanf("%d%d", &co_y, &co_x);
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
                            printf("Un bateau a ete touche, en %d%d\n", co_y, i);
                            tableau[co_y][i] = 'X';
                            tab[co_y][i] = 'X';
                        } else {
                            tableau[co_y][i] = 'O';
                            tab[co_y][i] = 'O';
                        }
                    }
                } else {
                    for (i = 0; i < 10; i++) {
                        if (tableau[i][co_x] != '_' && tableau[i][co_x] != 'O' && tableau[i][co_x] != 'X') {
                            printf("Un bateau a ete touche, en %d%d\n", i, co_x);
                            tableau[i][co_x] = 'X';
                            tab[i][co_x] = 'X';
                        } else {
                            tableau[i][co_x] = 'O';
                            tab[i][co_x] = 'O';
                        }
                    }
                }
                grille(tableau);
                grille(tab);
                break;
            case 'T' :
                e.missile_tactique -= 1;
                printf("Ou souhaitez vous larguez le missile tactique ?\n");
                scanf("%d%d", &co_y, &co_x);
                if(tableau[co_y][co_x] == '2'){
                    printf("Un bateau a ete touche, en %d%d", co_y, co_x);
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
                }
                grille(tableau);
                grille(tab);
                    break;
            case 'B' :
                e.bombe -= 1;
                printf("Ou souhaitez vous larguez la bombe ?\n");
                scanf("%d%d", &co_y, &co_x);
                if(tableau[co_y][co_x] != '_' && tableau[co_y][co_x] != 'O' && tableau[co_y][co_x] != 'X'){
                    printf("Un bateau a ete touche, en %d%d", co_y, co_x);
                    tableau[co_y][co_x] = 'X';
                    tab[co_y][co_x] = 'X';
                } else {
                    tableau[co_y][co_x] = 'O';
                    tab[co_y][co_x] = 'O';
                }
                if(tableau[co_y-1][co_x] != '_' && tableau[co_y-1][co_x] != 'O' && tableau[co_y-1][co_x] != 'X'){
                    printf("Un bateau a ete touche, en %d%d", co_y-1, co_x);
                    tableau[co_y-1][co_x] = 'X';
                    tab[co_y-1][co_x] = 'X';
                } else {
                    tableau[co_y-1][co_x] = 'O';
                    tab[co_y-1][co_x] = 'O';
                }
                if(tableau[co_y-1][co_x+1] != '_' && tableau[co_y-1][co_x+1] != 'O' && tableau[co_y-1][co_x+1] != 'X'){
                    printf("Un bateau a ete touche, en %d%d", co_y-1, co_x+1);
                    tableau[co_y-1][co_x+1] = 'X';
                    tab[co_y-1][co_x+1] = 'X';
                } else {
                    tableau[co_y-1][co_x+1] = 'O';
                    tab[co_y-1][co_x+1] = 'O';
                }
                if(tableau[co_y][co_x+1] != '_' && tableau[co_y][co_x+1] != 'O' && tableau[co_y][co_x+1] != 'X'){
                    printf("Un bateau a ete touche, en %d%d", co_y, co_x+1);
                    tableau[co_y][co_x+1] = 'X';
                    tab[co_y][co_x+1] = 'X';
                } else {
                    tableau[co_y][co_x+1] = 'O';
                    tab[co_y][co_x+1] = 'O';
                }
                if(tableau[co_y+1][co_x+1] != '_' && tableau[co_y+1][co_x+1] != 'O' && tableau[co_y+1][co_x+1] != 'X'){
                    printf("Un bateau a ete touche, en %d%d", co_y+1, co_x+1);
                    tableau[co_y+1][co_x+1] = 'X';
                    tab[co_y+1][co_x+1] = 'X';
                } else {
                    tableau[co_y+1][co_x+1] = 'O';
                    tab[co_y+1][co_x+1] = 'O';
                }
                if(tableau[co_y+1][co_x] != '_' && tableau[co_y+1][co_x] != 'O' && tableau[co_y+1][co_x] != 'X'){
                    printf("Un bateau a ete touche, en %d%d", co_y+1, co_x);
                    tableau[co_y+1][co_x] = 'X';
                    tab[co_y+1][co_x] = 'X';
                } else {
                    tableau[co_y+1][co_x] = 'O';
                    tab[co_y+1][co_x] = 'O';
                }
                if(tableau[co_y+1][co_x-1] != '_' && tableau[co_y+1][co_x-1] != 'O' && tableau[co_y+1][co_x-1] != 'X'){
                    printf("Un bateau a ete touche, en %d%d", co_y+1, co_x-1);
                    tableau[co_y+1][co_x-1] = 'X';
                    tab[co_y+1][co_x-1] = 'X';
                } else {
                    tableau[co_y+1][co_x-1] = 'O';
                    tab[co_y+1][co_x-1] = 'O';
                }
                if(tableau[co_y][co_x-1] != '_' && tableau[co_y][co_x-1] != 'O' && tableau[co_y][co_x-1] != 'X'){
                    printf("Un bateau a ete touche, en %d%d", co_y, co_x-1);
                    tableau[co_y][co_x-1] = 'X';
                    tab[co_y][co_x-1] = 'X';
                } else {
                    tableau[co_y][co_x-1] = 'O';
                    tab[co_y][co_x-1] = 'O';
                }
                if(tableau[co_y-1][co_x-1] != '_' && tableau[co_y-1][co_x-1] != 'O' && tableau[co_y-1][co_x-1] != 'X'){
                    printf("Un bateau a ete touche, en %d%d", co_y-1, co_x-1);
                    tableau[co_y-1][co_x-1] = 'X';
                    tab[co_y-1][co_x-1] = 'X';
                } else {
                    tableau[co_y-1][co_x-1] = 'O';
                    tab[co_y-1][co_x-1] = 'O';
                }
                grille(tableau);
                grille(tab);
                break;
            case 'M' :
                e.missile -= 1;
                printf("Ou souhaitez vous larguez le missile ?\n");
                scanf("%d%d", &co_y, &co_x);
                if(tableau[co_y][co_x] != '_' && tableau[co_y][co_x] != 'O' && tableau[co_y][co_x] != 'X'){
                    printf("Un bateau a ete touche, en %d%d", co_y, co_x);
                    tableau[co_y][co_x] = 'X';
                    tab[co_y][co_x] = 'X';
                } else {
                    tableau[co_y][co_x] = 'O';
                    tab[co_y][co_x] = 'O';
                }
                grille(tableau);
                grille(tab);
                break;
            default : return 0;
                }

        oui = recommencer(tableau);

        fflush(stdin);
        printf("\nVoulez-vous continuez (C) ou sauvegarder votre partie et quitter (S) ?\n");
        gets(&b);
        while (b != 'C' && b != 'S'){
            printf("\nVoulez-vous continuez (C) ou sauvegarder votre partie et quitter (S) ?\n");
            gets(&b);
        }
    } while (b == 'C' && oui ==  1 && e.missile_artillerie > 0 || e.missile_tactique > 0 || e.bombe > 0 || e.missile > 0);
    if (e.missile_artillerie == 0 && e.missile_tactique == 0 && e.bombe == 0 && e.missile == 0){
        printf("Vous avez perdu !\n");
    } else if (oui == 0){
        printf("Vous avez gagné! \n");
    } else if (b == 'S'){
        FILE* fichier_sauvegarde = fopen("../sauvegarde.txt", "r");
        if(fichier_sauvegarde == NULL) {
            printf("Ouverture impossible du fichier\n");
            return -1;  // On quitte le programme
        }
        fprintf(fichier_sauvegarde, "%d  ", e.missile_artillerie);
        fprintf(fichier_sauvegarde, "%d  ", e.missile_tactique);
        fprintf(fichier_sauvegarde, "%d  ", e.missile);
        fprintf(fichier_sauvegarde, "%d\n\n", e.bombe);
        for(i=0;i<=10;i++){
            for(j=0;j<=10;j++){
                fprintf(fichier_sauvegarde, "%c  ", tableau[i][j]);
            }
            fprintf(fichier_sauvegarde, "\n");
        }
    }
}