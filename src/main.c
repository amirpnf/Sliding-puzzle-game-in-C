#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "process.h"
#include "graphic.h"
#include <MLV/MLV_all.h>

int main(int argc, char* argv[]) {
    srand(time(NULL));
    Plateau p;
    Carre c;
    MLV_Keyboard_button key;
    process_init(&p, &c);
    MLV_create_window("Taquin", "taquin", 513, 513);
    MLV_Image* image = MLV_load_image("image.png");
    while(1){
        graphic_show_photo(image, p, c);
        MLV_update_window();
        MLV_wait_keyboard(&key, NULL, NULL);
        process_move_particle(&p, &c, key);
    
    }
    MLV_wait_seconds(15000);
    MLV_free_window();
}