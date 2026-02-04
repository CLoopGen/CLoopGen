#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src1;
extern  uint8_t *src2;
extern intptr_t w;
extern long i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i + 7 < w; i += 8) {
        intptr_t j0 = i + 0, j1 = i + 1, j2 = i + 2, j3 = i + 3;
        intptr_t j4 = i + 4, j5 = i + 5, j6 = i + 6, j7 = i + 7;
        dst[j0] = src1[j0] - src2[j0];
        dst[j1] = src1[j1] - src2[j1];
        dst[j2] = src1[j2] - src2[j2];
        dst[j3] = src1[j3] - src2[j3];
        dst[j4] = src1[j4] - src2[j4];
        dst[j5] = src1[j5] - src2[j5];
        dst[j6] = src1[j6] - src2[j6];
        dst[j7] = src1[j7] - src2[j7];
    }
}
