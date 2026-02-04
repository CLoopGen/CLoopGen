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
    if (b0[i] >= 0 && b7[i] >= 0) {
        dst[i] = ((unsigned int)dst[i] - ((int)(-8 * (b0[i] + (unsigned int)b7[i]) + 21 * (b1[i] + (unsigned int)b6[i]) - 46 * (b2[i] + (unsigned int)b5[i]) + 161 * (b3[i] + (unsigned int)b4[i]) + 128) >> 8));
    } else {
        dst[i] = 0;
    }
}
}
