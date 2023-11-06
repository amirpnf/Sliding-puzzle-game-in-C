#ifndef __PROCESS__
#define __PROCESS__

#include <stdbool.h>

#define NB_LIG 4
#define NB_COL 4

typedef struct carre {
    int lig;
    int col;
} Carre;

typedef struct {
    Carre bloc[NB_COL][NB_LIG];
} Plateau;

/**
 * @brief initializes the Game terrain
 * 
 * @param p 
 */
void process_initialisationPlateau(Plateau* p);

bool process_est_valide(int x, int y, Carre black);

void process_shufflePlateau(Plateau* p);

#endif