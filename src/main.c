#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "process.h"
#include "graphic.h"
#include <MLV/MLV_all.h>

int main(int argc, char* argv[]) {
    Tray* tray = (Tray*)malloc(sizeof(Tray));
    Unit black;
    black.x = SIZE - 1;
    black.y = SIZE - 1;
    if(!tray) {
        fprintf(stderr, "Tray allocation failed\n");
        return 1;
    }
    init_tray(tray);
    MLV_create_window("", "", 512, 512);
    MLV_Keyboard_button key;
    MLV_Image* image = MLV_load_image("image.png");
    shuffle_tray(tray, 20, &black);
    refresh_screen(image, tray, black);
    do {
        //print_tray(*tray);
        printf("%d -- %d \n", tray->list[black.y][black.x].x, tray->list[black.y][black.x].y);
        MLV_wait_keyboard(&key, NULL, NULL);
        move_units(tray, key, &black);
        refresh_screen(image, tray, black);
    } while (key != MLV_KEYBOARD_q);
    MLV_wait_seconds(10);
    MLV_free_window();
    free(tray);
    return 0;
}