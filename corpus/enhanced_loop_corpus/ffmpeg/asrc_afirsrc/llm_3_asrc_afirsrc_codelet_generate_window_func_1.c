#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *lut;
extern int N;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (simulated via arithmetic instead of explicit table)
    // Simulate indirect access by reversing the order of traversal (reverse indexing)
    for (n = 0; n < N; n++) {
        int idx = N - 1 - n;  // reverse access pattern
        lut[idx] = 1. - (idx - (N - 1) / 2.) / ((N - 1) / 2.) * (idx - (N - 1) / 2.) / ((N - 1) / 2.);
    }
}
