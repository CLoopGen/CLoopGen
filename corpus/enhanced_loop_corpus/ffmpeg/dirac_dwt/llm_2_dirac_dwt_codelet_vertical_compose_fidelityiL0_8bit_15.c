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
    // Variant 1: Strided Memory Access (stride of 2)
    // This variant accesses every second element in each array, processing half the width
    int stride = 2;
    int limit = width / stride;
    for (i = 0; i < limit; i++) {
        int idx = i * stride;
        dst[idx] = ((unsigned int)dst[idx] - ((int)(-8 * (b0[idx] + (unsigned int)b7[idx]) + 21 * (b1[idx] + (unsigned int)b6[idx]) - 46 * (b2[idx] + (unsigned int)b5[idx]) + 161 * (b3[idx] + (unsigned int)b4[idx]) + 128) >> 8));
    }
}
