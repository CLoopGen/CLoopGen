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
    for (i = 0; i < width; i += 2) {
        if (i + 1 < width) {
            dst[i] = ((unsigned int)dst[i] - ((int)(-5 * (b0[i] + (unsigned int)b7[i]) + 18 * (b1[i] + (unsigned int)b6[i]) - 39 * (b2[i] + (unsigned int)b5[i]) + 140 * (b3[i] + (unsigned int)b4[i]) + 128) >> 8));
            dst[i+1] = ((unsigned int)dst[i+1] - ((int)(-5 * (b0[i+1] + (unsigned int)b7[i+1]) + 18 * (b1[i+1] + (unsigned int)b6[i+1]) - 39 * (b2[i+1] + (unsigned int)b5[i+1]) + 140 * (b3[i+1] + (unsigned int)b4[i+1]) + 128) >> 8));
        } else {
            dst[i] = ((unsigned int)dst[i] - ((int)(-5 * (b0[i] + (unsigned int)b7[i]) + 18 * (b1[i] + (unsigned int)b6[i]) - 39 * (b2[i] + (unsigned int)b5[i]) + 140 * (b3[i] + (unsigned int)b4[i]) + 128) >> 8));
        }
    }
}
