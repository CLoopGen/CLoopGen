#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern int i;
extern int32_t *b0;
extern int32_t *b1;
extern int32_t *b2;
extern int32_t *b3;
extern int32_t *b4;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    // This accesses every second element in the arrays, processing half the width
    int w = width / 2;
    for (i = 0; i < w; i++) {
        int idx = i * 2;
        b2[idx] = (int)(((unsigned int)(b2[idx]) + ((int)(9U * b1[idx] + 9U * b3[idx] - b4[idx] - b0[idx] + 8) >> 4)));
    }
}
