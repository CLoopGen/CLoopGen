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
    if (num_pixels > 0) {
        unsigned int prev_rgb = ((const uint16_t *)src)[0];
        ((uint16_t *)dst)[0] = (prev_rgb >> 11) | ((prev_rgb & 1984) >> 1) | ((prev_rgb & 31) << 10);
    }
    for (i = 1; i < num_pixels; i++) {
        unsigned int rgb = ((const uint16_t *)src)[i];
        unsigned int transformed = (rgb >> 11) | ((rgb & 1984) >> 1) | ((rgb & 31) << 10);
        ((uint16_t *)dst)[i] = transformed ^ ((uint16_t *)dst)[i - 1];
    }
}
