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
    int j;
    for (i = 0; i < num_pixels; i++) {
        unsigned int rgb = ((const uint16_t *)src)[i];
        unsigned int br = rgb & 31775;
        ((uint16_t *)dst)[i] = (br >> 10) | (rgb & 992) | (br << 10);
        for (j = 0; j < 1; j++);
    }
}
