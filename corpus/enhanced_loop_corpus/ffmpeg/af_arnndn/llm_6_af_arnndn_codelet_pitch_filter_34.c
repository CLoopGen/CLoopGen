#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct AVComplexFloat {
    float re;
    float im;
} AVComplexFloat;

extern AVComplexFloat *X;
extern float normf[481];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float *norm = normf;
    AVComplexFloat *x_ptr = X;
    for (int i = 0; i < ((120 << 2) + 1); i++) {
        float factor = *norm++;
        (*x_ptr).re *= factor;
        (*x_ptr).im *= factor;
        x_ptr++;
    }
}
