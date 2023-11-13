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

void process_move_particle(Plateau* p, Carre* black, MLV_Keyboard_button key) {
    //Carre tmp = p->bloc[black->lig][black->col];
    int tmp_x, tmp_y;
    switch(key) {
        case MLV_KEYBOARD_UP :
            if(black->lig > 0) {
                //tmp_x = quelque chose 1
                //tmp_y = quelque chose 1
                //quelque chose 1 = quelque chose 2
                //quelque chose 1 = quelque chose 2
                //quelque chose 2 = tmp_x
                //quelque chose 2 = tmp_x

                p->bloc[black->lig][black->col].lig = p->bloc[black->lig][black->col-1].lig;
                p->bloc[black->lig][black->col].col = p->bloc[black->lig][black->col-1].col;
                p->bloc[black->lig][black->col-1].lig = tmp.lig;
                p->bloc[black->lig][black->col-1].col = tmp.col;
                black->col--;
                return;
            }
        case MLV_KEYBOARD_DOWN :
            if(black->lig < NB_LIG - 1) {
                p->bloc[black->lig][black->col].lig = p->bloc[black->lig][black->col+1].lig;
                p->bloc[black->lig][black->col].col = p->bloc[black->lig][black->col+1].col;
                p->bloc[black->lig][black->col+1].lig = tmp.lig;
                p->bloc[black->lig][black->col+1].col = tmp.col;
                black->col += 1;
                return;
            }    
        case MLV_KEYBOARD_LEFT :
            if(black->col > 0) {
                p->bloc[black->lig][black->col].lig = p->bloc[black->lig-1][black->col].lig;
                p->bloc[black->lig][black->col].col = p->bloc[black->lig-1][black->col].col;
                p->bloc[black->lig-1][black->col].lig = tmp.lig;
                p->bloc[black->lig-1][black->col].col = tmp.col;
                black->lig -= 1;
                return;
            }    
        case MLV_KEYBOARD_RIGHT :
            if(black->col < NB_COL - 1) {
                p->bloc[black->lig][black->col].lig = p->bloc[black->lig+1][black->col].lig;
                fprintf(stderr, "%d, %d \n", black->col, black->lig);
                p->bloc[black->lig][black->col].col = p->bloc[black->lig+1][black->col].col;
                p->bloc[black->lig+1][black->col].lig = tmp.lig;
                p->bloc[black->lig+1][black->col].col = tmp.col;
                black->lig += 1;
                return;       
            }    
        default:
            return;      
    }
}