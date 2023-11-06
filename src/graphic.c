#include "graphic.h"
#include "process.h"

void graphic_decouper_photo(char* path, Plateau* p) {
    MLV_Image* image = MLV_load_image(path);
    for(int i = 0; i < NB_COL; ++i) {
        for(int j = 0; j < NB_LIG; j++) {
            MLV_draw_partial_image();
        }
    }
}