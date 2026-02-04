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
        int k = i;
        if (k < width) {
            dst[k] = ((unsigned int)dst[k] - ((int)(-8 * (b0[k] + (unsigned int)b7[k]) + 21 * (b1[k] + (unsigned int)b6[k]) - 46 * (b2[k] + (unsigned int)b5[k]) + 161 * (b3[k] + (unsigned int)b4[k]) + 128) >> 8));
        }
        k = i + 1;
        if (k < width) {
            dst[k] = ((unsigned int)dst[k] - ((int)(-8 * (b0[k] + (unsigned int)b7[k]) + 21 * (b1[k] + (unsigned int)b6[k]) - 46 * (b2[k] + (unsigned int)b5[k]) + 161 * (b3[k] + (unsigned int)b4[k]) + 128) >> 8));
        }
    }
}
