#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t *dst;
extern  uint16_t *src1;
extern  uint16_t *src2;
extern unsigned int mask;
extern int w;
extern long i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i + 3 < w; i += 4) {
        uint16_t diff0 = src1[i + 0] - src2[i + 0];
        uint16_t diff1 = src1[i + 1] - src2[i + 1];
        if (diff0 > 100 || diff1 > 100) {
            dst[i + 0] = diff0 & mask;
            dst[i + 1] = diff1 & mask;
            dst[i + 2] = (src1[i + 2] - src2[i + 2]) & mask;
            dst[i + 3] = (src1[i + 3] - src2[i + 3]) & mask;
        } else {
            dst[i + 0] = mask & 0xFF;
            dst[i + 1] = mask & 0xFF;
            dst[i + 2] = mask & 0xFF;
            dst[i + 3] = mask & 0xFF;
        }
    }
}
