#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int t1;
extern int t2;
extern int t3;
extern int t4;
extern int t5;
extern int t6;
extern int t7;
extern int t8;
extern int16_t *src;
extern int16_t *dst;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8; i++) {
    int16_t s0 = src[0], s16 = src[16], s32 = src[32], s48 = src[48];
    t1 = 12 * (s0 + s32) + 64;
    t2 = 12 * (s0 - s32) + 64;
    t3 = 16 * s16 + 6 * s48;
    t4 = 6 * s16 - 16 * s48;
    t5 = t1 + t3;
    t6 = t2 + t4;
    t7 = t2 - t4;
    t8 = t1 - t3;

    int16_t s8 = src[8], s24 = src[24], s40 = src[40], s56 = src[56];
    t1 = 16 * s8 + 15 * s24 + 9 * s40 + 4 * s56;
    t2 = 15 * s8 - 4 * s24 - 16 * s40 - 9 * s56;
    t3 = 9 * s8 - 16 * s24 + 4 * s40 + 15 * s56;
    t4 = 4 * s8 - 9 * s24 + 15 * s40 - 16 * s56;

    dst[0] = (t5 + t1) >> 7;
    dst[8] = (t6 + t2) >> 7;
    dst[16] = (t7 + t3) >> 7;
    dst[24] = (t8 + t4) >> 7;
    dst[32] = (t8 - t4 + 1) >> 7;
    dst[40] = (t7 - t3 + 1) >> 7;
    dst[48] = (t6 - t2 + 1) >> 7;
    dst[56] = (t5 - t1 + 1) >> 7;

    src++;
    dst++;
}
}
