#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern int i;
extern int16_t *b0;
extern int16_t *b1;
extern int16_t *b2;
extern int16_t *b3;
extern int16_t *b4;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    // This variant processes every second element in the arrays, reducing data dependency and potentially improving cache behavior
    for (i = 0; i < width; i += 2) {
        b2[i] = (int)(((unsigned int)(b2[i]) - ((int)(9U * b1[i] + 9U * b3[i] - b4[i] - b0[i] + 16) >> 5)));
        if (i + 1 < width) {
            b2[i + 1] = (int)(((unsigned int)(b2[i + 1]) - ((int)(9U * b1[i + 1] + 9U * b3[i + 1] - b4[i + 1] - b0[i + 1] + 16) >> 5)));
        }
    }
}
