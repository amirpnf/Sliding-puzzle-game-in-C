#include "graphic.h"
#include "process.h"

void graphic_show_photo(MLV_Image* image, Plateau p, Carre black) {
    if (!image)
    {
        fprintf(stderr,"oh no\n");
    }
    for(int i = 0; i < 4; ++i) {
        for(int j = 0; j < 4; j++) {
            MLV_draw_partial_image(image, i *128, j * 128, 128, 128, p.bloc[i][j].lig * 128 + 2*i, p.bloc[i][j].col * 128 + 2*j);    
        }
    }
    MLV_draw_filled_rectangle(black.col*128, black.lig*128, 128, 128, MLV_COLOR_BLACK);
}    