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
    // Variant 2: Consecutive forward and backward pass to increase spatial locality and write combining
    int n = 2 * (120 << 2);
    int mid = n / 2;
    
    // Forward pass on first half
    for (int i = 0; i < mid; i++) {
        out[i] = y[i].re / n;
    }
    
    // Backward pass on second half
    for (int i = n - 1; i >= mid; i--) {
        out[i] = y[i].re / n;
    }
}
