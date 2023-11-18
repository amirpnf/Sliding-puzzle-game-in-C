#ifndef __PROCESS__
#define __PROCESS__

#include <MLV/MLV_all.h>
#include <stdbool.h>
#include <time.h>

#define SIZE 4

typedef struct {
    int x;
    int y;
} Unit;

typedef struct {
    Unit list[SIZE][SIZE];
} Tray;

void init_tray(Tray* tray);

void swap_units(Unit* first, Unit* second);

bool is_valid_move(int black_x, int black_y, int x, int y);

void move_units(Tray* tray, MLV_Keyboard_button key, Unit* black);

void print_tray(Tray tray);

void shuffle_tray(Tray *tray, int num_moves, Unit *black);

bool victory(Tray tray, Unit black);

void create_game(Tray* tray, Unit* black);
#endif