#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t *d;
extern uint16_t *s;
extern int i;
extern int num_pixels;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (num_pixels > 0) {
    for (i = 0; i < num_pixels; i += 2) {
        unsigned int rgb1 = s[i];
        d[i] = (rgb1 << 8 | rgb1 & 240 | rgb1 >> 8) & 4095;

        if (i + 1 < num_pixels) {
            unsigned int rgb2 = s[i + 1];
            d[i + 1] = (rgb2 << 8 | rgb2 & 240 | rgb2 >> 8) & 4095;
        }
    }
}
}
