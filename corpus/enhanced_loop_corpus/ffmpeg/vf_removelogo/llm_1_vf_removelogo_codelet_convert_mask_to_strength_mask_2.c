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
    for (x = 1; x < w - 1; x++) {
        current_pixel = current_pixel0 + x;
        if (*current_pixel >= current_pass && *(current_pixel + 1) >= current_pass && *(current_pixel - 1) >= current_pass && *(current_pixel + linesize) >= current_pass && *(current_pixel - linesize) >= current_pass) {
            (*current_pixel)++;
            has_anything_changed = 1;
        }
    }
    current_pixel0 += linesize;
}
}
