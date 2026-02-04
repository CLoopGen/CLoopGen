#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *flags;
extern int i;
extern int shift;
extern int sp1;
extern int sp2;
extern int sp3;
extern int sp4;
extern  int32_t *src;
extern int32_t *dst;
extern int t0;
extern int t1;
extern int t2;
extern int t3;
extern int t4;
extern int t5;
extern int t6;
extern int t7;
extern int t8;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8; i++) {
    if (flags[i]) {
        shift = !(i & 4);
        int idx = i * 8;
        sp1 = src[idx + 0] * (1 << shift);
        sp2 = src[idx + 1] * (1 << shift);
        sp3 = src[idx + 2] * (1 << shift);
        sp4 = src[idx + 3] * (1 << shift);
        {
            t1 = (sp1) * 2;
            t5 = (sp2) * 2;
            t0 = ((t1) - (t5)) >> 1;
            t1 = ((t1) + (t5)) >> 1;
            t5 = (t0);
            ;
            t0 = ((t1) - (sp3)) >> 1;
            t1 = ((t1) + (sp3)) >> 1;
            t3 = (t0);
            ;
            t0 = ((t5) - (sp4)) >> 1;
            t5 = ((t5) + (sp4)) >> 1;
            t7 = (t0);
            ;
            t0 = ((t1) - (src[idx + 4])) >> 1;
            t1 = ((t1) + (src[idx + 4])) >> 1;
            t2 = (t0);
            ;
            t0 = ((t3) - (src[idx + 5])) >> 1;
            t3 = ((t3) + (src[idx + 5])) >> 1;
            t4 = (t0);
            ;
            t0 = ((t5) - (src[idx + 6])) >> 1;
            t5 = ((t5) + (src[idx + 6])) >> 1;
            t6 = (t0);
            ;
            t0 = ((t7) - (src[idx + 7])) >> 1;
            t7 = ((t7) + (src[idx + 7])) >> 1;
            t8 = (t0);
            ;
            dst[idx + 0] = (t1);
            dst[idx + 1] = (t2);
            dst[idx + 2] = (t3);
            dst[idx + 3] = (t4);
            dst[idx + 4] = (t5);
            dst[idx + 5] = (t6);
            dst[idx + 6] = (t7);
            dst[idx + 7] = (t8);
        }
        ;
    } else {
        int idx = i * 8;
        dst[idx + 0] = dst[idx + 1] = dst[idx + 2] = dst[idx + 3] =
        dst[idx + 4] = dst[idx + 5] = dst[idx + 6] = dst[idx + 7] = 0;
    }
}
}
