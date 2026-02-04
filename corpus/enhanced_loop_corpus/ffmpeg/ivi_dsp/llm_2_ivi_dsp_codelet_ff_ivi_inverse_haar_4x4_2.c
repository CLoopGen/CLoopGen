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
for (i = 0; i < 4; i++) {
    if (flags[i]) {
        shift = !(i & 2);
        sp1 = src[i * 4] * (1 << shift);
        sp2 = src[i * 4 + 4] * (1 << shift);
        {
            t4 = ((sp1) - (sp2)) >> 1;
            t0 = ((sp1) + (sp2)) >> 1;
            t1 = (t4);
            ;
            t4 = ((t0) - (src[i * 4 + 8])) >> 1;
            t2 = ((t0) + (src[i * 4 + 8])) >> 1;
            t3 = (t4);
            ;
            dst[i * 4] = (t2);
            dst[i * 4 + 4] = (t3);
            t4 = ((t1) - (src[i * 4 + 12])) >> 1;
            t2 = ((t1) + (src[i * 4 + 12])) >> 1;
            t3 = (t4);
            ;
            dst[i * 4 + 8] = (t2);
            dst[i * 4 + 12] = (t3);
        }
        ;
    } else
        dst[i * 4] = dst[i * 4 + 4] = dst[i * 4 + 8] = dst[i * 4 + 12] = 0;
}
}
