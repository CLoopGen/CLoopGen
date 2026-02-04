#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *flags;
extern int i;
extern int shift;
extern int sp1;
extern int sp2;
extern  int32_t *src;
extern int32_t *dst;
extern int t0;
extern int t1;
extern int t2;
extern int t3;
extern int t4;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8; i++) {
    if (flags[i % 4]) {
        shift = !(i & 1);
        sp1 = src[0] * (1 << shift);
        sp2 = src[8] * (1 << shift);
        {
            t0 = ((sp1) + (sp2)) >> 1;
            t4 = ((sp1) - (sp2)) >> 1;
            t1 = t4;
            t4 = ((t0) - (src[16])) >> 1;
            t2 = ((t0) + (src[16])) >> 1;
            t3 = t4;
            dst[0] = t2;
            dst[8] = t3;
            t4 = ((t1) - (src[24])) >> 1;
            t2 = ((t1) + (src[24])) >> 1;
            t3 = t4;
            dst[16] = t2;
            dst[24] = t3;
        }
    } else {
        dst[0] = dst[8] = dst[16] = dst[24] = 0;
    }
    src += 2;
    dst += 2;
}
}
