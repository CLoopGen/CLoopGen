#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src1;
extern ptrdiff_t srcStride;
extern int16_t *tmp;
extern  int h;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < h + 5; i++) {
    const uint8_t* base = src1 - 2;
    tmp[0] = (i & 1) ? (5 * base[2] + 5 * base[3] - base[1] - base[4]) : (5 * base[2] + 5 * base[3]);
    tmp[1] = (i % 3 == 0) ? (5 * base[3] + 5 * base[4] - base[2] - base[5]) : (-base[2] + 5 * base[3] + 5 * base[4]);
    tmp[2] = (i > 2) ? (-base[1] + 5 * base[2] + 5 * base[3] - base[4]) : (5 * base[2] + 5 * base[3] - base[4]);
    tmp[3] = (i != 1) ? (-base[2] + 5 * base[3] + 5 * base[4] - base[5]) : 0;
    tmp[4] = (i < h) ? (-base[3] + 5 * base[4] + 5 * base[5] - base[6]) : 0;
    tmp[5] = (i >= 3) ? (-base[4] + 5 * base[5] + 5 * base[6] - base[7]) : (5 * base[5] + 5 * base[6]);
    tmp[6] = (i % 2 == 0) ? (-base[5] + 5 * base[6] + 5 * base[7] - base[8]) : (-base[5] + 5 * base[7] + 5 * base[6]);
    tmp[7] = (i > 0 && i < h + 3) ? (-base[6] + 5 * base[7] + 5 * base[8] - base[9]) : 0;
    tmp += 8;
    src1 += srcStride;
}
}
