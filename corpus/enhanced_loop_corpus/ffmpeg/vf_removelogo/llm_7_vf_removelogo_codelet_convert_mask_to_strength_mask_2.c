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
        current_pixel = current_pixel0 + 1;
        uint8_t prev_updated = 0;
        for (x = 1; x < w - 1; x++) {
            uint8_t neighbors[5] = {
                *(current_pixel - 1),      // left
                *(current_pixel + 1),      // right
                *(current_pixel - linesize), // up
                *(current_pixel + linesize), // down
                *current_pixel             // center
            };

            uint8_t all_pass = 1;
            for (int i = 0; i < 5; i++) {
                if (neighbors[i] < current_pass) {
                    all_pass = 0;
                    break;
                }
            }

            if (all_pass) {
                *current_pixel += 1;
                prev_updated = 1;
                has_anything_changed |= prev_updated;
            } else {
                prev_updated = 0;
            }
            current_pixel++;
        }
        current_pixel0 += linesize;
    }
}
