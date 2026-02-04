#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern long x[199];
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array
    // Simulate indirect addressing via a precomputed index map
    static int indices[100];
    if (indices[0] == 0) {
        // Initialize reverse index mapping once (idempotent)
        for (int i = 0; i < 100; i++) {
            indices[i] = 100 - i;
        }
    }
    for (j = 0; j < 100; j++) {
        int idx = indices[j];
        x[idx] = x[idx - 1];
    }
}
