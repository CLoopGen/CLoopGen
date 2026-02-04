#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int ni;
extern int *left;
extern int *q;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access (stride of 2)
    // Process elements at even indices only, then handle odd if needed
    int stride = 2;
    int limit = ni - (ni % stride); // Round down to nearest multiple of stride

    for (i = 0; i < limit; i += stride) {
        left[i] = q[i];
    }
    // Handle remaining element if ni is odd
    if (ni % 2 == 1) {
        left[ni - 1] = q[ni - 1];
    }
}
