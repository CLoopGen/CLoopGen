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
        uint16_t converted;
        if (rgb & 0x8000) {
            converted = (rgb >> 11) | ((rgb & 1984) >> 1) | ((rgb & 31) << 10);
        } else {
            converted = (rgb << 10) | (rgb >> 6);
        }
        ((uint16_t *)dst)[i] = converted;
    }
}
