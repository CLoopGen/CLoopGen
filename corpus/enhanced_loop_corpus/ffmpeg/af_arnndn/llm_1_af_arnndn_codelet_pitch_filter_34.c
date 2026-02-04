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
    // Variant 2: Reduced loop nesting depth — although original is flat, we simulate a "flattened" version
    // by unrolling the loop in groups of 4 with conditional checks to maintain correctness.
    // This reduces effective iterations by a factor of 4, thus decreasing control flow depth impact.
    int n = (120 << 2) + 1;
    int i = 0;

    // Process four elements per iteration where possible
    for (; i <= n - 4; i += 4) {
        X[i+0].re *= normf[i+0]; X[i+0].im *= normf[i+0];
        X[i+1].re *= normf[i+1]; X[i+1].im *= normf[i+1];
        X[i+2].re *= normf[i+2]; X[i+2].im *= normf[i+2];
        X[i+3].re *= normf[i+3]; X[i+3].im *= normf[i+3];
    }

    // Handle remaining elements (cleanup loop)
    for (; i < n; i++) {
        X[i].re *= normf[i];
        X[i].im *= normf[i];
    }
}
