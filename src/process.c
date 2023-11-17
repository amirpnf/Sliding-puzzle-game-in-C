#include "process.h"
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <MLV/MLV_all.h>

void init_tray(Tray* tray){
    int i, j;
    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            ((tray->list)[i][j]).x = i;
            ((tray->list)[i][j]).y = j;
        }
    }
}

void swap_units(Unit* first, Unit* second) {
    Unit tmp = *first;
    *first = *second;
    *second = tmp;
}

bool is_valid_move(int empty_x, int empty_y, int x, int y) {
    // Check if the specified position is adjacent to the empty space
    if ((abs(x - empty_x) == 1 && y == empty_y) || (x == empty_x && abs(y - empty_y) == 1)) {
        // Check if the move is within the boundaries of the tray
        if (x >= 0 && x < SIZE && y >= 0 && y < SIZE) {
            return true; // Valid move
        } else {
            return false; // Move beyond tray boundaries
        }
    } else {
        return false; // Invalid move
    }
}

void move_units(Tray* tray, MLV_Keyboard_button key, Unit* black) {
    switch (key) {
        case MLV_KEYBOARD_RIGHT:
            if (is_valid_move(black->x, black->y, black->x, black->y - 1))
            {
                swap_units(&(tray->list[black->y][black->x]), &(tray->list[black->y - 1][black->x]));
                black->y --;
            }
            break;
        case MLV_KEYBOARD_LEFT:
            if(is_valid_move(black->x, black->y, black->x, black->y + 1)) {
                swap_units(&(tray->list[black->y][black->x]), &(tray->list[black->y + 1][black->x]));
                black->y ++;
            }
            break;
        case MLV_KEYBOARD_DOWN:
            if(is_valid_move(black->x, black->y, black->x - 1, black->y)) {
                swap_units(&(tray->list[black->y][black->x]), &(tray->list[black->y][black->x - 1]));
                black->x --;
            }
            break;
        case MLV_KEYBOARD_UP:
            if(is_valid_move(black->x, black->y, black->x + 1, black->y)) {
                swap_units(&(tray->list[black->y][black->x]), &(tray->list[black->y][black->x + 1]));
                black->x ++;
            }
            break;
        default:
            break;
    }
}


void print_tray(Tray tray) {
    int i, j;
    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            printf("%d -- %d | ", tray.list[i][j].x, tray.list[i][j].y);
        }
        printf("\n");
    }
}


void shuffle_tray(Tray *tray, int num_moves, Unit *black) {
    srand(time(NULL));
    int array[] = {MLV_KEYBOARD_UP, MLV_KEYBOARD_DOWN, MLV_KEYBOARD_LEFT, MLV_KEYBOARD_RIGHT};
    MLV_Keyboard_button key;
    for(int i = 0; i < num_moves; ++i) {
        key = array[rand() % 4];
        move_units(tray, key, black);
    } 
}
