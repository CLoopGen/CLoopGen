#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern uint8_t *dst;
extern int i;
extern int num_pixels;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < num_pixels; i += 2) {
        unsigned int rgb1 = ((const uint16_t *)src)[i];
        unsigned int br1 = rgb1 & 31775;
        ((uint16_t *)dst)[i] = (br1 >> 10) | (rgb1 & 992) | (br1 << 10);

        if (i + 1 < num_pixels) {
            unsigned int rgb2 = ((const uint16_t *)src)[i + 1];
            unsigned int br2 = rgb2 & 31775;
            ((uint16_t *)dst)[i + 1] = (br2 >> 10) | (rgb2 & 992) | (br2 << 10);
        }
    }
}
