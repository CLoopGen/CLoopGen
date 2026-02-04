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
    for (i = 0; i < (num_pixels >> 1); i++) {
        int idx1 = i << 1;
        int idx2 = (i << 1) + 1;
        uint32_t val1 = ((const uint32_t *)palette)[src[idx1 << 1]];
        uint32_t val2 = src[(idx1 << 1) + 1];
        uint32_t val3 = ((const uint32_t *)palette)[src[idx2 << 1]];
        uint32_t val4 = src[(idx2 << 1) + 1];
        ((uint32_t *)dst)[idx1] = val1 | (val2 << 24);
        ((uint32_t *)dst)[idx2] = val3 | (val4 << 24);
    }
}
