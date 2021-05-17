//
// Created by hugoc on 27/04/2021.
//

#ifndef PROJET_1_BOAT_H
#define PROJET_1_BOAT_H

typedef struct{
    char position[10][10];
    int taille;
    char orientation;
} Boat;

void bateaux (char tableau[10][10]);

#endif //PROJET_1_BOAT_H
