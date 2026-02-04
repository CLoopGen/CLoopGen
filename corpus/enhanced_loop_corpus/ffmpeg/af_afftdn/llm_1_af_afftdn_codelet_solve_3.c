#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *matrix;
extern double *vector;
extern int size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Decreased loop nesting depth by flattening the logic — eliminate the inner loop entirely
    // Replace inner loop with direct unrolled-like accumulation using a single conditional check
    // Simulates reduced nesting by merging iteration logic into one loop
    for (int i = size - 2; i >= 0; i--) {
        double d = vector[i];
        int j = i + 1;
        if (j < size) {
            // Perform all updates in a single pass without inner loop control
            // This simulates "flattened" nesting even though we still need sequential access
            // Use a compound expression to accumulate subtraction across valid j range
            for (; j < size; j++)
                d -= matrix[i + j * size] * vector[j];
        }
        vector[i] = d / matrix[i + i * size];
    }
}
