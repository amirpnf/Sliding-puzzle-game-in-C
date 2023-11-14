#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "process.h"
#include "graphic.h"
#include <MLV/MLV_all.h>

int main(int argc, char* argv[]) {
    Plateau p;
    Carre black;
    MLV_Keyboard_button key;
    black.col = 1;
    black.lig = 1;
    init(&p);
    MLV_create_window("", "", 512, 512);
    MLV_Image* image = MLV_load_image("image.png");
    show_photo(image, p, black);
    while(1) {
        MLV_wait_keyboard(&key, NULL, NULL);
        play(&p, key, &black);
        fprintf(stderr, "%d --%d \n", p.bloc[black.lig][black.col].col, p.bloc[black.lig][black.col].lig);
        fprintf(stderr, "%d -- %d \n", black.col, black.lig);
        show_photo(image, p, black);
    }
    MLV_wait_seconds(20);
    MLV_free_window();
}