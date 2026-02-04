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
        float factor = normf[i];
        if (factor == 0.0f) {
            X[i].re = 0.0f;
            X[i].im = 0.0f;
        } else {
            X[i].re *= factor;
            X[i].im *= factor;
        }
    }
}
