//
// Created by hugoc on 27/04/2021.
//

#ifndef PROJET_1_INVENTORY_H
#define PROJET_1_INVENTORY_H

typedef struct {
    int missile_artillerie;
    int missile_tactique;
    int bombe;
    int missile;
} Inventory;

Inventory nb_munitions (char a);
void tirs(char tableau[10][10], Inventory e, char tab[10][10]);
void tirs_2(char tableau[10][10], Inventory e, char tab[10][10]);

#endif //PROJET_1_INVENTORY_H
