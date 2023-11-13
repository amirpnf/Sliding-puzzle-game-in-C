#ifndef __PROCESS__
#define __PROCESS__

#include <MLV/MLV_all.h>

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
void process_init(Plateau* p, Carre* c);

int process_est_valide(int lig, int col);

void process_shufflePlateau(Plateau* p);

void process_move_particle(Plateau* p, Carre* black, MLV_Keyboard_button key);

#endif