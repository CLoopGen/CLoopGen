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
for (i = 0; i < 4; i++) {
    t1 = 8 * (src[0] + src[32]) + 64;
    t2 = 8 * (src[0] - src[32]) + 64;
    t3 = 12 * src[16] + 8 * src[48];
    t4 = 8 * src[16] - 12 * src[48];
    t5 = (t1 + t3) >> 1;
    t6 = (t2 + t4) >> 1;
    t7 = (t2 - t4) >> 1;
    t8 = (t1 - t3) >> 1;

    t1 = 12 * src[8] + 12 * src[24];
    t2 = 12 * src[8] - 12 * src[24];
    t3 = 12 * src[40] + 12 * src[56];
    t4 = 12 * src[40] - 12 * src[56];

    dst[0] = (t5 + t1) >> 6;
    dst[8] = (t6 + t2) >> 6;
    dst[16] = (t7 + t3) >> 6;
    dst[24] = (t8 + t4) >> 6;
    dst[32] = (t8 - t4 + 1) >> 6;
    dst[40] = (t7 - t3 + 1) >> 6;
    dst[48] = (t6 - t2 + 1) >> 6;
    dst[56] = (t5 - t1 + 1) >> 6;

    src += 2;
    dst += 2;
}
}
