#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct AVComplexFloat {
    float re;
    float im;
} AVComplexFloat;

extern AVComplexFloat *X;
extern  AVComplexFloat *P;
extern float rf[481];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    int n = (120 << 2) + 1;
    for (int i = 0; i < n; i += 2) {
        X[i].re += rf[i] * P[i].re;
        X[i].im += rf[i] * P[i].im;
        // Handle remaining element if n is odd
        if (i + 1 < n) {
            X[i+1].re += rf[i+1] * P[i+1].re;
            X[i+1].im += rf[i+1] * P[i+1].im;
        }
    }
}
