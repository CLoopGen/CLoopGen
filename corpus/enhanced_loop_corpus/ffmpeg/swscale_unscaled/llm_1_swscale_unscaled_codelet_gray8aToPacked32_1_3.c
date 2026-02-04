#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern uint8_t *dst;
extern int num_pixels;
extern  uint8_t *palette;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int outer_i;
    int inner_i;
    int block_size = 4;
    for (outer_i = 0; outer_i < (num_pixels + block_size - 1) / block_size; outer_i++) {
        for (inner_i = 0; inner_i < block_size; inner_i++) {
            i = outer_i * block_size + inner_i;
            if (i < num_pixels) {
                ((uint32_t *)dst)[i] = ((const uint32_t *)palette)[src[i << 1]] | src[(i << 1) + 1];
            }
        }
    }
}
