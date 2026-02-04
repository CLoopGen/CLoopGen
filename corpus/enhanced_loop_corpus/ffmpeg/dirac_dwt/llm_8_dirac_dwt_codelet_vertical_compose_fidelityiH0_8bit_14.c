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
int j;
for (i = 0; i < width; i += 2) {
    for (j = 0; j < 2 && (i + j) < width; j++) {
        int idx = i + j;
        dst[idx] = ((unsigned int)dst[idx] + ((int)(-1 * (b0[idx] + (unsigned int)b7[idx]) + 8 * (b1[idx] + (unsigned int)b6[idx]) - 20 * (b2[idx] + (unsigned int)b5[idx]) + 70 * (b3[idx] + (unsigned int)b4[idx]) + 128) >> 8));
    }
}
}
