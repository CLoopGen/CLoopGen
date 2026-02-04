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
    // Variant 2: Reverse consecutive memory access (access arrays from end to start)
    int n = (120 << 2) + 1;
    for (int i = n - 1; i >= 0; i--) {
        X[i].re += rf[i] * P[i].re;
        X[i].im += rf[i] * P[i].im;
    }
}
