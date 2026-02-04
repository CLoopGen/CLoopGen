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
    if (i % 2 == 0) {
        t1 = 12 * (src[0] + src[4]) + 4;
        t2 = 12 * (src[0] - src[4]) + 4;
        t3 = 16 * src[2] + 6 * src[6];
        t4 = 6 * src[2] - 16 * src[6];
        t5 = t1 + t3;
        t6 = t2 + t4;
        t7 = t2 - t4;
        t8 = t1 - t3;
    } else {
        t5 = 16 * src[0] + 8 * src[4];
        t6 = 8 * src[0] - 16 * src[4];
        t7 = 16 * src[4] - 8 * src[0];
        t8 = 8 * src[0] + 16 * src[4];
    }

    t1 = 16 * src[1] + 15 * src[3] + 9 * src[5] + 4 * src[7];
    t2 = 15 * src[1] - 4 * src[3] - 16 * src[5] - 9 * src[7];
    t3 = 9 * src[1] - 16 * src[3] + 4 * src[5] + 15 * src[7];
    t4 = 4 * src[1] - 9 * src[3] + 15 * src[5] - 16 * src[7];

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
