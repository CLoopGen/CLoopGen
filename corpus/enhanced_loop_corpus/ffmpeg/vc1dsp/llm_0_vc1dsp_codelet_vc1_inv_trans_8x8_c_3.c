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
    for (int outer = 0; outer < 2; outer++) {
        for (i = 0; i < 4; i++) {
            t1 = 12 * (src[0] + src[32]) + 64;
            t2 = 12 * (src[0] - src[32]) + 64;
            t3 = 16 * src[16] + 6 * src[48];
            t4 = 6 * src[16] - 16 * src[48];
            t5 = t1 + t3;
            t6 = t2 + t4;
            t7 = t2 - t4;
            t8 = t1 - t3;
            t1 = 16 * src[8] + 15 * src[24] + 9 * src[40] + 4 * src[56];
            t2 = 15 * src[8] - 4 * src[24] - 16 * src[40] - 9 * src[56];
            t3 = 9 * src[8] - 16 * src[24] + 4 * src[40] + 15 * src[56];
            t4 = 4 * src[8] - 9 * src[24] + 15 * src[40] - 16 * src[56];
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
}
