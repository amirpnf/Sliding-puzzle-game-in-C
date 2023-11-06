#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "process.h"

int main(int argc, char* argv[]) {
    srand(time(NULL));
    Plateau p;
    process_initialisationPlateau(&p);
    for(int i = 0; i < NB_COL; ++i) {
        for(int j = 0; j < NB_LIG; ++j) {
            //printf("%d -- %d | ", p.bloc[i][j].lig, p.bloc[i][j].col);
        }
    }
    
    process_shufflePlateau(&p);
    
    for(int i = 0; i < NB_COL; ++i) {
        for(int j = 0; j < NB_LIG; ++j) {
            printf("%d -- %d | ", p.bloc[i][j].lig, p.bloc[i][j].col);
        }
    }
}