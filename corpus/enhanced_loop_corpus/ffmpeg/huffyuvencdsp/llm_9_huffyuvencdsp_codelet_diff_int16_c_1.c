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
    for (i = 0; i + 1 < w; i += 2) {
        uint16_t diff0 = src1[i + 0] - src2[i + 0];
        uint16_t diff1 = src1[i + 1] - src2[i + 1];
        dst[i + 0] = (diff0 + (diff0 >> 1)) & mask;
        dst[i + 1] = (diff1 + (diff1 >> 1)) & mask;
    }
}
