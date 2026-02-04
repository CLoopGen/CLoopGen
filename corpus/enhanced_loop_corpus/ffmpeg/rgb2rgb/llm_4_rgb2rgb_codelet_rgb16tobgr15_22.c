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
    for (i = 0; i < num_pixels; i++) {
        unsigned int rgb = ((const uint16_t *)src)[i];
        uint16_t r = (rgb >> 11) & 0x1F;
        uint16_t g = (rgb >> 6) & 0x1F;
        uint16_t b = rgb & 0x1F;
        if (r == 0 || g == 0 || b == 0) {
            continue;
        }
        ((uint16_t *)dst)[i] = (r << 10) | (g << 5) | b;
    }
}
