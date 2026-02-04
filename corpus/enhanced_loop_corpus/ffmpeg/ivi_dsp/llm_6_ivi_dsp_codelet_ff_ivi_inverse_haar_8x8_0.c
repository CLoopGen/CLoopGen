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
        int32_t s0 = src[0] << shift;
        int32_t s8 = src[8] << shift;
        int32_t s16 = src[16] << shift;
        int32_t s24 = src[24] << shift;
        int32_t s32 = src[32];
        int32_t s40 = src[40];
        int32_t s48 = src[48];
        int32_t s56 = src[56];

        t1 = (s0 * 2 + s8 * 2) >> 1;
        t5 = (s0 * 2 - s8 * 2) >> 1;
        t0 = (t1 - s16) >> 1;
        t1 = (t1 + s16) >> 1;
        t3 = t0;
        t0 = (t5 - s24) >> 1;
        t5 = (t5 + s24) >> 1;
        t7 = t0;
        t0 = (t1 - s32) >> 1;
        t1 = (t1 + s32) >> 1;
        t2 = t0;
        t0 = (t3 - s40) >> 1;
        t3 = (t3 + s40) >> 1;
        t4 = t0;
        t0 = (t5 - s48) >> 1;
        t5 = (t5 + s48) >> 1;
        t6 = t0;
        t0 = (t7 - s56) >> 1;
        t7 = (t7 + s56) >> 1;
        t8 = t0;

        dst[0] = t1;
        dst[8] = t2;
        dst[16] = t3;
        dst[24] = t4;
        dst[32] = t5;
        dst[40] = t6;
        dst[48] = t7;
        dst[56] = t8;
    } else {
        dst[0] = dst[8] = dst[16] = dst[24] = dst[32] = dst[40] = dst[48] = dst[56] = 0;
    }
    src++;
    dst++;
}
}
