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
    int offset = i * 4; // Strided access with step 4
    t1 = 12 * (src[offset] + src[offset + 32]) + 64;
    t2 = 12 * (src[offset] - src[offset + 32]) + 64;
    t3 = 16 * src[offset + 16] + 6 * src[offset + 48];
    t4 = 6 * src[offset + 16] - 16 * src[offset + 48];
    t5 = t1 + t3;
    t6 = t2 + t4;
    t7 = t2 - t4;
    t8 = t1 - t3;
    t1 = 16 * src[offset + 8] + 15 * src[offset + 24] + 9 * src[offset + 40] + 4 * src[offset + 56];
    t2 = 15 * src[offset + 8] - 4 * src[offset + 24] - 16 * src[offset + 40] - 9 * src[offset + 56];
    t3 = 9 * src[offset + 8] - 16 * src[offset + 24] + 4 * src[offset + 40] + 15 * src[offset + 56];
    t4 = 4 * src[offset + 8] - 9 * src[offset + 24] + 15 * src[offset + 40] - 16 * src[offset + 56];
    dst[offset] = (t5 + t1) >> 7;
    dst[offset + 8] = (t6 + t2) >> 7;
    dst[offset + 16] = (t7 + t3) >> 7;
    dst[offset + 24] = (t8 + t4) >> 7;
    dst[offset + 32] = (t8 - t4 + 1) >> 7;
    dst[offset + 40] = (t7 - t3 + 1) >> 7;
    dst[offset + 48] = (t6 - t2 + 1) >> 7;
    dst[offset + 56] = (t5 - t1 + 1) >> 7;
}
}
