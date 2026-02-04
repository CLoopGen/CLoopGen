#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *p;
extern int i0;
extern int i1;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Strided memory access with increased stride to simulate irregular or strided traversal
    // Instead of sequential i from 1 to 4, we use a fixed stride pattern (e.g., every second element)
    // Here, we simulate a strided access by stepping through a predefined offset array

    int strides[4] = {1, 2, 3, 4};  // Original indices, but accessed in same order — could be rearranged for different patterns
    for (int s = 0; s < 4; s++) {
        int idx = strides[s];
        p[i0 - idx] = p[i0 + idx];
        p[i1 + idx - 1] = p[i1 - idx - 1];
    }
}
