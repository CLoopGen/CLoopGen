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
for (i = 0; i < 16; i += 2) {
    int local_shift1 = flags[i] ? (!(i & 4)) : 0;
    int local_shift2 = flags[i+1] ? (!(i & 4)) : 0;
    int valid1 = flags[i];
    int valid2 = flags[i+1];

    // First element processing with reduced temp usage
    if (valid1) {
        sp1 = src[0] * (1 << local_shift1);
        sp2 = src[8] * (1 << local_shift1);
        t1 = (sp1 + sp2);
        t5 = (sp1 - sp2);
        t0 = (t1 - src[16]) >> 1;
        t1 = (t1 + src[16]) >> 1;
        dst[0] = t1;
        dst[8] = t0;
        dst[16] = (t5 - src[24]) >> 1;
        dst[24] = (t5 + src[24]) >> 1;
    } else {
        dst[0] = dst[8] = dst[16] = dst[24] = 0;
    }

    // Second element in unrolled step
    if (valid2) {
        sp3 = src[32] * (1 << local_shift2);
        sp4 = src[40] * (1 << local_shift2);
        t3 = (sp3 + sp4);
        t7 = (sp3 - sp4);
        t0 = (t3 - src[48]) >> 1;
        t3 = (t3 + src[48]) >> 1;
        dst[32] = t3;
        dst[40] = t0;
        dst[48] = (t7 - src[56]) >> 1;
        dst[56] = (t7 + src[56]) >> 1;
    } else {
        dst[32] = dst[40] = dst[48] = dst[56] = 0;
    }

    src += 2;
    dst += 2;
}
}
