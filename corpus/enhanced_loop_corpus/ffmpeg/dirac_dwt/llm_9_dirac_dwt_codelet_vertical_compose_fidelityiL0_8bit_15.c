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
    int limit = width > 64 ? 64 : width;
    for (i = 0; i < limit; i++) {
        int16_t sum0 = b0[i] + b7[i];
        int16_t sum1 = b1[i] + b6[i];
        int16_t sum2 = b2[i] + b5[i];
        int16_t sum3 = b3[i] + b4[i];
        int temp = -10 * sum0 + 25 * sum1 - 60 * sum2 + 180 * sum3 + 128;
        dst[i] = (unsigned int)dst[i] - ((int)(temp >> 8));
    }
}
