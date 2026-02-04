#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern int i;
extern int16_t *b0;
extern int16_t *b1;
extern int16_t *b2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < width && i < 512; i++) {
    int32_t sum = (int32_t)(b0[i]) + (int32_t)(b2[i]);
    int32_t prod = 217 * sum;
    int32_t biased = prod + 2048;
    int32_t shifted = biased >> 12;
    b1[i] = (unsigned int)(b1[i]) + (int16_t)shifted;
}
}
