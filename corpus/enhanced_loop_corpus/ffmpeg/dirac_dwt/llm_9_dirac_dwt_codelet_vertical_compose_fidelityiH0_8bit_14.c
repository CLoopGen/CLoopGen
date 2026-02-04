#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern int i;
extern int16_t *dst;
extern int16_t *b0;
extern int16_t *b1;
extern int16_t *b2;
extern int16_t *b3;
extern int16_t *b4;
extern int16_t *b5;
extern int16_t *b6;
extern int16_t *b7;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < width; i++) {
    int sum_b0_b7 = b0[i] + b7[i];
    int sum_b1_b6 = b1[i] + b6[i];
    int sum_b2_b5 = b2[i] + b5[i];
    int sum_b3_b4 = b3[i] + b4[i];
    int term1 = -2 * sum_b0_b7;
    int term2 = 10 * sum_b1_b6;
    int term3 = -25 * sum_b2_b5;
    int term4 = 81 * sum_b3_b4;
    int combined = term1 + term2 + term3 + term4 + 128;
    dst[i] = (unsigned int)dst[i] + ((unsigned int)(combined >> 8));
}
}
