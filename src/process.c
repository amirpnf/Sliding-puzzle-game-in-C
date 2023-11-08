#include "process.h"
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <MLV/MLV_all.h>

void process_init(Plateau* p, Carre* c){
    c->col = 0;
    c->lig = 0;
    int i, j;
    for(i = 0; i < NB_LIG; i++) {
        for(j = 0; j < NB_COL; j++) {
            ((p->bloc)[i][j]).lig = i;
            ((p->bloc)[i][j]).col = j;
        }
    }
}

int process_est_valide(int col, int lig, Carre black) {
    if(col >= NB_COL || col < 0 || lig >= NB_LIG || lig < 0) {
        return 0;
    }
    if(abs(black.col - col) + abs(black.lig - lig) == 1 ) {
        return 1;
    }
    return 0;
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

void process_move_particle(Plateau* p, Carre* black, MLV_Keyboard_button key) {
    Carre tmp;
    switch(key) {
        case MLV_KEYBOARD_UP :
            tmp = p->bloc[black->lig][black->col];
            p->bloc[black->lig][black->col] = p->bloc[black->lig][black->col-1];
            p->bloc[black->lig][black->col-1] = tmp;
            black->lig -= 1;
            return;    
    }
}