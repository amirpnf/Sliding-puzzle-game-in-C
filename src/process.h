#ifndef __PROCESS__
#define __PROCESS__

#include <MLV/MLV_all.h>
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


void init(Plateau* p);

void swap(Carre* a, Carre* b);

void play(Plateau* p, MLV_Keyboard_button key, Carre* black);

bool est_valide(Carre cible, MLV_Keyboard_button key);

#endif