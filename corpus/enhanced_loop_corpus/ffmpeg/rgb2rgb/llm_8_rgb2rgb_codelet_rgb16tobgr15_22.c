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
        ((uint16_t *)dst)[i] = (rgb1 >> 11) | ((rgb1 & 1984) >> 1) | ((rgb1 & 31) << 10);
        if (i + 1 < num_pixels) {
            unsigned int rgb2 = ((const uint16_t *)src)[i + 1];
            ((uint16_t *)dst)[i + 1] = (rgb2 >> 11) | ((rgb2 & 1984) >> 1) | ((rgb2 & 31) << 10);
        }
    }
}
