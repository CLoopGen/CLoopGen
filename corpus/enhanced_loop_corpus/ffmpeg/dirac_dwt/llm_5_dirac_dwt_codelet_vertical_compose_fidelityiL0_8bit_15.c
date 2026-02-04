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
    unsigned int sum_b3_b4 = b3[i] + (unsigned int)b4[i];
    unsigned int combined = -8 * (b0[i] + (unsigned int)b7[i]) + 21 * (b1[i] + (unsigned int)b6[i]) - 46 * (b2[i] + (unsigned int)b5[i]) + 161 * sum_b3_b4 + 128;
    if (sum_b3_b4 > 64) {
        dst[i] = ((unsigned int)dst[i] - ((int)(combined >> 8)));
    }
}
}
