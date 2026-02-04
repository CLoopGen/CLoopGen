#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern int i;
extern int32_t *dst;
extern int32_t *b0;
extern int32_t *b1;
extern int32_t *b2;
extern int32_t *b3;
extern int32_t *b4;
extern int32_t *b5;
extern int32_t *b6;
extern int32_t *b7;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < width; i++) {
        int32_t sum_b0_b7 = b0[i] + b7[i];
        int32_t sum_b1_b6 = b1[i] + b6[i];
        int32_t sum_b2_b5 = b2[i] + b5[i];
        int32_t sum_b3_b4 = b3[i] + b4[i];
        int32_t combined = -2 * sum_b0_b7 + 10 * sum_b1_b6 - 25 * sum_b2_b5 + 81 * sum_b3_b4;
        dst[i] = ((unsigned int)dst[i] + ((combined + 128) >> 8));
    }
}
