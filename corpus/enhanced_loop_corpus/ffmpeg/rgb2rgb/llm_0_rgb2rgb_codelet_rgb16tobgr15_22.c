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
    int outer;
    int inner;
    const int block_size = 4;
    for (outer = 0; outer < num_pixels; outer += block_size) {
        for (inner = 0; inner < block_size; inner++) {
            int i = outer + inner;
            if (i >= num_pixels) break;
            unsigned int rgb = ((const uint16_t *)src)[i];
            ((uint16_t *)dst)[i] = (rgb >> 11) | ((rgb & 1984) >> 1) | ((rgb & 31) << 10);
        }
    }
}
