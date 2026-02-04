#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x -= 16; x >= 0; x -= 16) {
        uint32_t val0 = ((uint32_t*)src)[(x >> 2)];
        dst[x +  0] = dst[x +  1] = (val0 >>  0) & 0xFF;
        dst[x +  2] = dst[x +  3] = (val0 >>  8) & 0xFF;
        dst[x +  4] = dst[x +  5] = (val0 >> 16) & 0xFF;
        dst[x +  6] = dst[x +  7] = (val0 >> 24) & 0xFF;

        uint32_t val1 = ((uint32_t*)src)[(x >> 2) + 1];
        dst[x +  8] = dst[x +  9] = (val1 >>  0) & 0xFF;
        dst[x + 10] = dst[x + 11] = (val1 >>  8) & 0xFF;
        dst[x + 12] = dst[x + 13] = (val1 >> 16) & 0xFF;
        dst[x + 14] = dst[x + 15] = (val1 >> 24) & 0xFF;
    }
}
