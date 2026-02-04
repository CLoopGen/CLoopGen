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
    for (i = 0; i < num_pixels * 3; i++) {
        int idx = i / 3;
        unsigned int rgb = ((const uint16_t *)src)[idx];
        uint16_t r = (rgb >> 11) & 0x1F;
        uint16_t g = (rgb >> 6) & 0x1F;
        uint16_t b = rgb & 0x1F;
        uint16_t combined = (r << 11) | (g << 6) | b;
        ((uint16_t *)dst)[idx] = (combined >> 11) | ((combined & 1984) >> 1) | ((combined & 31) << 10);
    }
}
