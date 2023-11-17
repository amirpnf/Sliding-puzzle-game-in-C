#include "graphic.h"
#include "process.h"

/*void show_photo(MLV_Image* image, Plateau p, Carre black) {
    if (!image)
    {
        fprintf(stderr,"oh no\n");
    }
    for(int i = 0; i < 4; ++i) {
        for(int j = 0; j < 4; j++) {
            MLV_draw_partial_image(image, i *128, j * 128, 128, 128, p.bloc[i][j].col * 128 + 2*i, p.bloc[i][j] * 128 + 2*j);    
        }
    }
    MLV_draw_filled_rectangle(black.lig*128 + black.lig,black.col*128 + black.col, 128, 128, MLV_COLOR_BLACK);
} */   

/*void show_photo(MLV_Image* image, Plateau p, Carre black) {
    MLV_clear_window(MLV_COLOR_BLACK);
    for(int i = 0; i < NB_LIG; i++) {
        for(int j = 0; j < NB_COL; j++) {
            MLV_draw_partial_image(image, p.bloc[i][j].x * 128, p.bloc[i][j].y * 128, 128, 128, j *128, i * 128); 
        }
    }
    MLV_draw_filled_rectangle(black.y * 128, black.x * 128, 128, 128, MLV_COLOR_BLACK);
    MLV_update_window();
}*/

void refresh_screen(MLV_Image* image, Tray* tray, Unit black) {
    MLV_clear_window(MLV_COLOR_BLACK);
    for(int i = 0; i < SIZE; ++i) {
        for(int j = 0; j < SIZE; ++j) {
            if (j == black.x && i == black.y)
            {
                continue;
            }
            
            MLV_draw_partial_image(image, tray->list[i][j].x * 128, tray->list[i][j].y * 128, 128, 128, i*128, j*128);
        }
    }
    MLV_actualise_window();
}