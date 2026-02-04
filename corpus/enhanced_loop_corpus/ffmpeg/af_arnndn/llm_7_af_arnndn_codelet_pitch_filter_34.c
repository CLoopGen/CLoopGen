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
    for (int i = 0; i < ((120 << 2) + 1); i++) {
        float temp_re = X[i].re * normf[i];
        float temp_im = X[i].im * normf[i];
        X[i].re = temp_re;
        X[i].im = temp_im;
    }
}
