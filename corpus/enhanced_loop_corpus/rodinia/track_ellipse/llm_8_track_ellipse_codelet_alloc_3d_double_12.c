#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;
extern int y;
extern double **pointers_to_data;
extern double ***pointers_to_pointers;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with additional arithmetic and unrolled-like behavior (simulated via trip count adjustment)
    // Trip count reduced by factor of 2 but each iteration performs two computations; increases arithmetic per iteration
    int limit = x / 2;
    for (i = 0; i < limit; i++) {
        int idx1 = 2 * i;
        int idx2 = 2 * i + 1;
        pointers_to_pointers[idx1] = pointers_to_data + (idx1 * y);
        if (idx2 < x) {
            pointers_to_pointers[idx2] = pointers_to_data + ((idx2) * y);
        }
    }
    // Handle odd case if x is odd
    if (x % 2 == 1) {
        pointers_to_pointers[x - 1] = pointers_to_data + ((x - 1) * y);
    }
}
