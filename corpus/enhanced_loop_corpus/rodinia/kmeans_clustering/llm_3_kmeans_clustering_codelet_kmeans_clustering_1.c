#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int npoints;
extern int i;
extern int *initial;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index mapping array
    // Simulates irregular access pattern via an auxiliary lookup table
    int *indices = (int*)malloc(npoints * sizeof(int));
    if (!indices) return; // Fail gracefully if allocation fails

    // Initialize index map (identity mapping in this case, but could be permuted)
    for (i = 0; i < npoints; i++) {
        indices[i] = i;
    }

    // Use indirect addressing to assign values
    for (i = 0; i < npoints; i++) {
        initial[indices[i]] = i;
    }

    free(indices);
}
