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
extern int t5;
extern int t6;
extern int t7;
extern int t8;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8; i++) {
    if (flags[i]) {
        int32_t s0 = src[0], s8 = src[8], s16 = src[16], s24 = src[24];
        int32_t s32 = src[32], s40 = src[40], s48 = src[48], s56 = src[56];

        t0 = s24 + (((s8 * 4 - s24 + 4) >> 3));
        t5 = s8 + (((-s8 - s24 * 4 + 4) >> 3));
        t4 = t0;

        t0 = s0 - t5;
        t1 = s0 + t5;
        t5 = t0;

        t0 = s32 - s40;
        t2 = s32 + s40;
        t6 = t0;

        t0 = s56 - s48;
        t7 = s56 + s48;
        t3 = t0;

        t0 = t4 - s16;
        t4 = t4 + s16;
        t8 = t0;

        t0 = t1 - t2;
        t1 = t1 + t2;
        t2 = t0;

        t0 = (((t4 + t3 * 2 + 2) >> 2) + t4);
        t3 = (((t4 * 2 - t3 + 2) >> 2) - t3);
        t4 = t0;

        t0 = t5 - t6;
        t5 = t5 + t6;
        t6 = t0;

        t0 = (((t8 + t7 * 2 + 2) >> 2) + t8);
        t7 = (((t8 * 2 - t7 + 2) >> 2) - t7);
        t8 = t0;

        t0 = t1 - t4;
        t1 = t1 + t4;
        t4 = t0;

        t0 = t2 - t3;
        t2 = t2 + t3;
        t3 = t0;

        t0 = t5 - t8;
        t5 = t5 + t8;
        t8 = t0;

        t0 = t6 - t7;
        t6 = t6 + t7;
        t7 = t0;

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
