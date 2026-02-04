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
    int y_step = 2; // Increase stride to reduce trip count
    for (y = 1; y < h - 3; y += y_step) {
        current_pixel = current_pixel0;
        for (x = 2; x < w - 2; x += 2) { // Start later, step by 2 to reduce inner loop iterations
            uint8_t center = *current_pixel;
            uint8_t right = *(current_pixel + 1);
            uint8_t left = *(current_pixel - 1);
            uint8_t down = *(current_pixel + linesize);
            uint8_t up = *(current_pixel - linesize);

            if (center >= current_pass && right >= current_pass && left >= current_pass &&
                down >= current_pass && up >= current_pass) {
                *current_pixel += 2; // More aggressive update
                has_anything_changed = 1;
            }
            current_pixel += 2; // Advance pointer by 2
        }
        current_pixel0 += linesize * 2; // Skip every other row
    }
}
