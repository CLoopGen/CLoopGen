#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *y;
extern float *x;
extern float coeff;
extern int len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (int i = 0; i < len; i += 2)
        coeff = y[i] = x[i] + coeff * 0.850006103F;
}
