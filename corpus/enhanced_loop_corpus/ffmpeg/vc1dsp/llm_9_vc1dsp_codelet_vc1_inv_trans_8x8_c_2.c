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
for (i = 0; i < 16; i += 2) {
    t1 = 12 * (src[0] + src[32]) + 4;
    t2 = 12 * (src[0] - src[32]) + 4;
    t3 = 16 * src[16] + 6 * src[48] + 1;
    t4 = 6 * src[16] - 16 * src[48] - 1;
    t5 = t1 + t3;
    t6 = t2 + t4;
    t7 = t2 - t4;
    t8 = t1 - t3;
    t1 = 16 * src[8] + 15 * src[24] + 9 * src[40] + 4 * src[56];
    t2 = 15 * src[8] - 4 * src[24] - 16 * src[40] - 9 * src[56];
    t3 = 9 * src[8] - 16 * src[24] + 4 * src[40] + 15 * src[56];
    t4 = 4 * src[8] - 9 * src[24] + 15 * src[40] - 16 * src[56];
    dst[0] = (t5 + t1 + 4) >> 3;
    dst[1] = (t6 + t2 + 4) >> 3;
    dst[2] = (t7 + t3 + 4) >> 3;
    dst[3] = (t8 + t4 + 4) >> 3;
    dst[4] = (t8 - t4 + 4) >> 3;
    dst[5] = (t7 - t3 + 4) >> 3;
    dst[6] = (t6 - t2 + 4) >> 3;
    dst[7] = (t5 - t1 + 4) >> 3;

    t1 = 12 * (src[1] + src[33]) + 4;
    t2 = 12 * (src[1] - src[33]) + 4;
    t3 = 16 * src[17] + 6 * src[49];
    t4 = 6 * src[17] - 16 * src[49];
    t5 = t1 + t3;
    t6 = t2 + t4;
    t7 = t2 - t4;
    t8 = t1 - t3;
    t1 = 16 * src[9] + 15 * src[25] + 9 * src[41] + 4 * src[57];
    t2 = 15 * src[9] - 4 * src[25] - 16 * src[41] - 9 * src[57];
    t3 = 9 * src[9] - 16 * src[25] + 4 * src[41] + 15 * src[57];
    t4 = 4 * src[9] - 9 * src[25] + 15 * src[41] - 16 * src[57];
    dst[8] = (t5 + t1 + 4) >> 3;
    dst[9] = (t6 + t2 + 4) >> 3;
    dst[10] = (t7 + t3 + 4) >> 3;
    dst[11] = (t8 + t4 + 4) >> 3;
    dst[12] = (t8 - t4 + 4) >> 3;
    dst[13] = (t7 - t3 + 4) >> 3;
    dst[14] = (t6 - t2 + 4) >> 3;
    dst[15] = (t5 - t1 + 4) >> 3;

    src += 2;
    dst += 16;
}

}
