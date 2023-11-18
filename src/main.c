#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "process.h"
#include "graphic.h"
#include <MLV/MLV_all.h>

int main(int argc, char* argv[]) {
    Tray* tray = (Tray*)malloc(sizeof(Tray));
    Unit black;
    create_game(tray, &black);
    init_tray(tray);
    MLV_create_window("", "", 512, 512);
    MLV_Keyboard_button key;
    MLV_Image* image = MLV_load_image("image.jpg");
    shuffle_tray(tray, 200, &black);
    refresh_screen(image, tray, black);
    do {
        MLV_wait_keyboard(&key, NULL, NULL);
        if(key == MLV_KEYBOARD_SPACE) {
            exit(0);
        }
        move_units(tray, key, &black);
        if(victory(*tray, black)) {
            MLV_draw_text_on_image(200, 200, "YOU WIN !", MLV_COLOR_ALICE_BLUE, image);
            refresh_screen(image, tray, black);
            printf("HEYYYY!");
            break;
        }
        refresh_screen(image, tray, black);
    } while (key != MLV_KEYBOARD_SPACE);
    MLV_wait_seconds(10);
    MLV_free_window();
    free(tray);
    return 0;
}