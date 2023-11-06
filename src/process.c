#include "process.h"
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

void process_initialisationPlateau(Plateau* p){
    int i, j;
    for(i = 0; i < NB_LIG; i++) {
        for(j = 0; j < NB_COL; j++) {
            ((p->bloc)[i][j]).lig = i;
            ((p->bloc)[i][j]).col = j;
        }
    }
}

bool process_est_valide(int col, int lig, Carre black) {
    if(col >= NB_COL || col < 0 || lig >= NB_LIG || lig < 0) {
        return false;
    }
    if(abs(black.col - col) + abs(black.lig - lig) == 1 ) {
        return true;
    }
    return false;
}

void process_shufflePlateau(Plateau* p) {
    int j;
    Carre temp;
    for(int i = NB_COL - 1; i > 0; i--) {
        j = rand() % (i+1);
        temp = *p->bloc[i];
        p->bloc[i]->lig = p->bloc[j]->lig;
        p->bloc[i]->col = p->bloc[j]->col;
        p->bloc[j]->lig = temp.lig;
        p->bloc[j]->col = temp.col;
    }
}
