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
        if (normf[i] > 0.0f) {
            X[i].re *= normf[i];
            X[i].im *= normf[i];
        }
    }
}
