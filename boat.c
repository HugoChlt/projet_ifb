//
// Created by hugoc on 27/04/2021.
//

#include "boat.h"

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

/**
 * Permet de générer les coordonnées des bateaux de différentes tailles
 * @param tableau
 */
void bateaux (char tableau[10][10]) {
    srand(time(0));
    int a, i;
    int co_x, co_y; //coordonnees des bateaux

    do {
        co_y = rand() % 10;
        co_x = rand() % 10;
    } while (co_x > 5 || co_y > 5);
    tableau[co_y][co_x] = '5';

    a = rand() % 2;

    if (a == 0) {
        tableau[co_y][co_x + 1] = '5';
        tableau[co_y][co_x + 2] = '5';
        tableau[co_y][co_x + 3] = '5';
        tableau[co_y][co_x + 4] = '5';
    } else if (a == 1) {
        tableau[co_y + 1][co_x] = '5';
        tableau[co_y + 2][co_x] = '5';
        tableau[co_y + 3][co_x] = '5';
        tableau[co_y + 4][co_x] = '5';
    }

    do {
        co_y = rand() % 10;
        co_x = rand() % 10;
    } while (co_x > 6 || tableau[co_y][co_x + 1] != '_' || tableau[co_y][co_x + 2] != '_' || tableau[co_y][co_x + 3] != '_' || co_y > 6  ||
             tableau[co_y + 1][co_x] != '_' || tableau[co_y + 2][co_x] != '_' || tableau[co_y + 3][co_x] != '_');
    tableau[co_y][co_x] = '4';

    a = rand() % 2;

    if (a == 0) {
        tableau[co_y][co_x + 1] = '4';
        tableau[co_y][co_x + 2] = '4';
        tableau[co_y][co_x + 3] = '4';
    } else if (a == 1) {
        tableau[co_y + 1][co_x] = '4';
        tableau[co_y + 2][co_x] = '4';
        tableau[co_y + 3][co_x] = '4';
    }

    for (i = 0; i < 2; i++) {

        do {
            co_y = rand() % 10;
            co_x = rand() % 10;
        } while (co_x > 7 || tableau[co_y][co_x + 1] != '_' || tableau[co_y][co_x + 2] != '_' || co_y > 7  ||
                 tableau[co_y + 1][co_x] != '_' || tableau[co_y + 2][co_x] != '_');
        tableau[co_y][co_x] = '3';

        a = rand() % 2;

        if (a == 0) {
            tableau[co_y][co_x + 1] = '3';
            tableau[co_y][co_x + 2] = '3';
        } else if (a == 1) {
            tableau[co_y + 1][co_x] = '3';
            tableau[co_y + 2][co_x] = '3';
        }
    }

    do {
        co_y = rand() % 10;
        co_x = rand() % 10;
    } while (co_x > 8 || tableau[co_y][co_x + 1] != '_' || co_y > 8  ||
             tableau[co_y + 1][co_x] != '_');
    tableau[co_y][co_x] = '2';

    a = rand() % 2;

    if (a == 0) {
        tableau[co_y][co_x + 1] = '2';
    } else if (a == 1) {
        tableau[co_y + 1][co_x] = '2';
    }

}