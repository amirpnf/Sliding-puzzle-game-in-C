#include "process.h"
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <MLV/MLV_all.h>

void init(Plateau* p){
    int i, j;
    for(i = 0; i < NB_LIG; i++) {
        for(j = 0; j < NB_COL; j++) {
            ((p->bloc)[i][j]).lig = i;
            ((p->bloc)[i][j]).col = j;
        }
    }
}

void swap(Carre* a, Carre* b) {
    int tempLig = a->lig;
    int tempCol = a->col;

    a->lig = b->lig;
    a->col = b->col;

    b->lig = tempLig;
    b->col = tempCol;
}

bool est_valide(Carre cible, MLV_Keyboard_button key) {
    if(cible.col - 1 < 0 && key == MLV_KEYBOARD_UP) {
        return false;
    }
    if(cible.col == NB_COL - 1 && key == MLV_KEYBOARD_DOWN) {
        return false;
    }
    if(cible.lig == 0 && key == MLV_KEYBOARD_LEFT) {
        return false;
    }
    if(cible.lig == NB_LIG - 1 && key == MLV_KEYBOARD_RIGHT) {
        return false;
    }
    return true;
}

void play(Plateau* p, MLV_Keyboard_button key, Carre* black) {
    Carre tmp = *black;
    switch (key)
    {
        case MLV_KEYBOARD_UP:
            if(est_valide(*black, MLV_KEYBOARD_UP)) {
                swap(&(p->bloc[tmp.lig][tmp.col]), &(p->bloc[tmp.lig][tmp.col-1]));
                //fprintf(stderr, "%d -- %d\n", black->col, black->lig);
                black->col -= 1;
            }    
            break;

        case MLV_KEYBOARD_DOWN:
            if(est_valide(*black, MLV_KEYBOARD_DOWN)) {
                swap(&(p->bloc[tmp.lig][tmp.col]), &(p->bloc[tmp.lig][tmp.col+1]));
                //fprintf(stderr, "%d -- %d\n", black->col, black->lig);
                black->col += 1;
            }    
            break;

        case MLV_KEYBOARD_LEFT:
            if(est_valide(*black, MLV_KEYBOARD_LEFT)) {
                swap(&(p->bloc[tmp.lig][tmp.col]), &(p->bloc[tmp.lig-1][tmp.col]));
                //fprintf(stderr, "%d -- %d\n", black->col, black->lig);
                black->lig -= 1;
            }    
            break;

        case MLV_KEYBOARD_RIGHT:
            if(est_valide(*black, MLV_KEYBOARD_RIGHT)) {
                swap(&(p->bloc[tmp.lig][tmp.col]), &(p->bloc[tmp.lig+1][tmp.col]));
                //fprintf(stderr, "%d -- %d\n", black->col, black->lig);
                black->lig += 1;
            }    
            break;        

    }
}