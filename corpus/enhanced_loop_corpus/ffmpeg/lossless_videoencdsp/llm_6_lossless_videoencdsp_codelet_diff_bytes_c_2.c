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
        uint8_t temp0 = src1[i + 0] - src2[i + 0];
        uint8_t temp1 = src1[i + 1] - src2[i + 1];
        uint8_t temp2 = src1[i + 2] - src2[i + 2];
        uint8_t temp3 = src1[i + 3] - src2[i + 3];
        dst[i + 0] = temp0;
        dst[i + 1] = temp1;
        dst[i + 2] = temp2;
        dst[i + 3] = temp3;
        uint8_t temp4 = src1[i + 4] - src2[i + 4];
        uint8_t temp5 = src1[i + 5] - src2[i + 5];
        uint8_t temp6 = src1[i + 6] - src2[i + 6];
        uint8_t temp7 = src1[i + 7] - src2[i + 7];
        dst[i + 4] = temp4;
        dst[i + 5] = temp5;
        dst[i + 6] = temp6;
        dst[i + 7] = temp7;
    }
}
