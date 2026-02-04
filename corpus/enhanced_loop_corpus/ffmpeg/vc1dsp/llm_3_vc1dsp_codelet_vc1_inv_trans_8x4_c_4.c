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
    int offset = 0;
    t1 = 12 * (src[offset + 0] + src[offset + 4]) + 4;
    t2 = 12 * (src[offset + 0] - src[offset + 4]) + 4;
    t3 = 16 * src[offset + 2] + 6 * src[offset + 6];
    t4 = 6 * src[offset + 2] - 16 * src[offset + 6];
    t5 = t1 + t3;
    t6 = t2 + t4;
    t7 = t2 - t4;
    t8 = t1 - t3;
    t1 = 16 * src[offset + 1] + 15 * src[offset + 3] + 9 * src[offset + 5] + 4 * src[offset + 7];
    t2 = 15 * src[offset + 1] - 4 * src[offset + 3] - 16 * src[offset + 5] - 9 * src[offset + 7];
    t3 = 9 * src[offset + 1] - 16 * src[offset + 3] + 4 * src[offset + 5] + 15 * src[offset + 7];
    t4 = 4 * src[offset + 1] - 9 * src[offset + 3] + 15 * src[offset + 5] - 16 * src[offset + 7];
    dst[offset + 0] = (t5 + t1) >> 3;
    dst[offset + 1] = (t6 + t2) >> 3;
    dst[offset + 2] = (t7 + t3) >> 3;
    dst[offset + 3] = (t8 + t4) >> 3;
    dst[offset + 4] = (t8 - t4) >> 3;
    dst[offset + 5] = (t7 - t3) >> 3;
    dst[offset + 6] = (t6 - t2) >> 3;
    dst[offset + 7] = (t5 - t1) >> 3;
    src += 8;
    dst += 8;
}
}
