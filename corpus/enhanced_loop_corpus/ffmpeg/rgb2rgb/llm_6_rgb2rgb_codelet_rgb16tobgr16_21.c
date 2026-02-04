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
    unsigned int prev_rgb = 0;
    for (i = 0; i < num_pixels; i++) {
        unsigned int rgb = ((const uint16_t *)src)[i];
        uint16_t transformed = (rgb >> 11) | (rgb & 2016) | (rgb << 11);
        ((uint16_t *)dst)[i] = transformed ^ prev_rgb;
        prev_rgb = transformed;
    }
}
