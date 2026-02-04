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
    // Variant 1: Strided memory access with stride of 2, processing every second element first, then the odd indices
    int n = (120 << 2) + 1;
    for (int i = 0; i < n; i += 2) {
        X[i].re *= normf[i];
        X[i].im *= normf[i];
    }
    for (int i = 1; i < n; i += 2) {
        X[i].re *= normf[i];
        X[i].im *= normf[i];
    }
}
