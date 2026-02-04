#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int linesize;
extern int w;
extern int h;
extern int x;
extern int y;
extern int current_pass;
extern int has_anything_changed;
extern uint8_t *current_pixel0;
extern uint8_t *current_pixel;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 1; y < h - 1; y++) {
    current_pixel = current_pixel0;
    for (x = 1; x < w - 1; x++) {
        uint8_t center = *current_pixel;
        uint8_t right = *(current_pixel + 1);
        uint8_t left = *(current_pixel - 1);
        uint8_t down = *(current_pixel + linesize);
        uint8_t up = *(current_pixel - linesize);

        int all_ge_pass = (center >= current_pass) &
                          (right >= current_pass) &
                          (left >= current_pass) &
                          (down >= current_pass) &
                          (up >= current_pass);

        if (all_ge_pass) {
            (*current_pixel)++;
            has_anything_changed = 1;
        }
        current_pixel++;
    }
    current_pixel0 += linesize;
}
}
