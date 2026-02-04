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
        unsigned int r = (rgb & 31744) >> 10;
        unsigned int g = (rgb & 992) >> 5;
        unsigned int b = rgb & 31;
        ((uint16_t *)dst)[i] = (b << 10) | (g << 5) | r;
    }
}
