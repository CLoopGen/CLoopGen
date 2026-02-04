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
        unsigned int temp_sum = (unsigned int)b3[i] + (unsigned int)b4[i];
        int weighted = -2 * (b0[i] + b7[i]) + 10 * (b1[i] + b6[i]) - 25 * (b2[i] + b5[i]) + 81 * temp_sum;
        if (weighted >= 0) {
            dst[i] = ((unsigned int)dst[i] + ((weighted + 128) >> 8));
        }
    }
}
