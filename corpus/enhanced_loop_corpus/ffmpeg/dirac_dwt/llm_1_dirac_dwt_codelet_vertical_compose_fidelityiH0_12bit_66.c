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
    int i1, i2;
    int chunk = (width + 3) / 4;
    for (i1 = 0; i1 < 4; i1++) {
        int start = i1 * chunk;
        int end = (start + chunk < width) ? start + chunk : width;
        for (i2 = start; i2 < end; i2++) {
            dst[i2] = ((unsigned int)dst[i2] + ((int)(-2 * (b0[i2] + (unsigned int)b7[i2]) + 10 * (b1[i2] + (unsigned int)b6[i2]) - 25 * (b2[i2] + (unsigned int)b5[i2]) + 81 * (b3[i2] + (unsigned int)b4[i2]) + 128) >> 8));
        }
    }
}
