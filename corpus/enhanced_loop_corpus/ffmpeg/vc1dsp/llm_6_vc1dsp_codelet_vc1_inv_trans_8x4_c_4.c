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
    int16_t s0 = src[0], s1 = src[1], s2 = src[2], s3 = src[3];
    int16_t s4 = src[4], s5 = src[5], s6 = src[6], s7 = src[7];

    t1 = 12 * (s0 + s4) + 4;
    t2 = 12 * (s0 - s4) + 4;
    t3 = 16 * s2 + 6 * s6;
    t4 = 6 * s2 - 16 * s6;
    t5 = t1 + t3;
    t6 = t2 + t4;
    t7 = t2 - t4;
    t8 = t1 - t3;

    t1 = 16 * s1 + 15 * s3 + 9 * s5 + 4 * s7;
    t2 = 15 * s1 - 4 * s3 - 16 * s5 - 9 * s7;
    t3 = 9 * s1 - 16 * s3 + 4 * s5 + 15 * s7;
    t4 = 4 * s1 - 9 * s3 + 15 * s5 - 16 * s7;

    dst[0] = (t5 + t1) >> 3;
    dst[1] = (t6 + t2) >> 3;
    dst[2] = (t7 + t3) >> 3;
    dst[3] = (t8 + t4) >> 3;
    dst[4] = (t8 - t4) >> 3;
    dst[5] = (t7 - t3) >> 3;
    dst[6] = (t6 - t2) >> 3;
    dst[7] = (t5 - t1) >> 3;

    src += 8;
    dst += 8;
}
}
