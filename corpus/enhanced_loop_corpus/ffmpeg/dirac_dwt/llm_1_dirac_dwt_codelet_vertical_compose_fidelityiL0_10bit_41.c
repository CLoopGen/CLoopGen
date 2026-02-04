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
    for (i = 0; i < width; i += 2) {
        for (int k = 0; k < 2 && (i + k) < width; k++) {
            int idx = i + k;
            dst[idx] = ((unsigned int)dst[idx] - ((int)(-8 * (b0[idx] + (unsigned int)b7[idx]) + 21 * (b1[idx] + (unsigned int)b6[idx]) - 46 * (b2[idx] + (unsigned int)b5[idx]) + 161 * (b3[idx] + (unsigned int)b4[idx]) + 128) >> 8));
        }
    }
}
