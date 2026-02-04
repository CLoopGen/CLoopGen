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
    int outer_loop = (num_pixels + 1) >> 1;
    for (i = 0; i < outer_loop; i++) {
        int idx1 = i << 1;
        int idx2 = idx1 + 1;
        if (idx1 < num_pixels) {
            ((uint32_t *)dst)[idx1] = ((const uint32_t *)palette)[src[idx1 << 1]] | (src[(idx1 << 1) + 1] << 24);
        }
        if (idx2 < num_pixels) {
            ((uint32_t *)dst)[idx2] = ((const uint32_t *)palette)[src[idx2 << 1]] | (src[(idx2 << 1) + 1] << 24);
        }
    }
}
