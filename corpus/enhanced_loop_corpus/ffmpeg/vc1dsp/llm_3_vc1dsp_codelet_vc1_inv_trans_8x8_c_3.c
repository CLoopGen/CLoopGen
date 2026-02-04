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
    int idx[8]; // Indirect access via index array
    for (int j = 0; j < 8; j++) {
        idx[j] = (i * 17 + j * 13) & 63; // Pseudo-random stride using modulo-like indexing
    }
    t1 = 12 * (src[idx[0]] + src[idx[0] + 32]) + 64;
    t2 = 12 * (src[idx[0]] - src[idx[0] + 32]) + 64;
    t3 = 16 * src[idx[2]] + 6 * src[idx[6]];
    t4 = 6 * src[idx[2]] - 16 * src[idx[6]];
    t5 = t1 + t3;
    t6 = t2 + t4;
    t7 = t2 - t4;
    t8 = t1 - t3;
    t1 = 16 * src[idx[1]] + 15 * src[idx[3]] + 9 * src[idx[5]] + 4 * src[idx[7]];
    t2 = 15 * src[idx[1]] - 4 * src[idx[3]] - 16 * src[idx[5]] - 9 * src[idx[7]];
    t3 = 9 * src[idx[1]] - 16 * src[idx[3]] + 4 * src[idx[5]] + 15 * src[idx[7]];
    t4 = 4 * src[idx[1]] - 9 * src[idx[3]] + 15 * src[idx[5]] - 16 * src[idx[7]];
    dst[idx[0]] = (t5 + t1) >> 7;
    dst[idx[1]] = (t6 + t2) >> 7;
    dst[idx[2]] = (t7 + t3) >> 7;
    dst[idx[3]] = (t8 + t4) >> 7;
    dst[idx[4]] = (t8 - t4 + 1) >> 7;
    dst[idx[5]] = (t7 - t3 + 1) >> 7;
    dst[idx[6]] = (t6 - t2 + 1) >> 7;
    dst[idx[7]] = (t5 - t1 + 1) >> 7;
}
}
