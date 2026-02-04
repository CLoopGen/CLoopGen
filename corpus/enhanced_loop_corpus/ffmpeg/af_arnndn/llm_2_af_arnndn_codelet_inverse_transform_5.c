#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct AVComplexFloat {
    float re;
    float im;
} AVComplexFloat;

extern float *out;
extern AVComplexFloat y[960];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size of 2, processing even indices first, then odd
    int n = 2 * (120 << 2);
    for (int stride = 0; stride < 2; stride++) {
        for (int i = stride; i < n; i += 2) {
            out[i] = y[i].re / n;
        }
    }
}
