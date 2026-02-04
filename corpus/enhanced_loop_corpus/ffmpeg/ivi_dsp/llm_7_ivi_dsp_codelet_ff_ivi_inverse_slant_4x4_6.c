#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *flags;
extern int i;
extern  int32_t *src;
extern int32_t *dst;
extern int t0;
extern int t1;
extern int t2;
extern int t3;
extern int t4;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 4; i++) {
    int32_t s0 = src[0], s4 = src[4], s8 = src[8], s12 = src[12];
    if (flags[i]) {
        t1 = s0 + s8;
        t0 = s0 - s8;
        t2 = t0;

        t0 = ((s4 + 2*s12 + 2) >> 2) + s4;
        t3 = ((2*s4 - s12 + 2) >> 2) - s12;
        t4 = t0;

        t0 = t1 - t4;
        t1 += t4;
        t4 = t0;

        t0 = t2 - t3;
        t2 += t3;
        t3 = t0;

        dst[0] = t1;
        dst[4] = t2;
        dst[8] = t3;
        dst[12] = t4;
    } else {
        dst[0] = dst[4] = dst[8] = dst[12] = 0;
    }
    src += 1;
    dst += 1;
}
}
