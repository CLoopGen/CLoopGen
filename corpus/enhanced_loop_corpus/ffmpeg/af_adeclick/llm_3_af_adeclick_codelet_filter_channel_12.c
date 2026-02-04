#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *is;
extern double *dst;
extern int j;
extern double *interpolated;
extern int *_usr_index;
extern int nb_errors;
extern double *enabled;

// Variable name mappings to avoid conflicts with system symbols
#define index _usr_index



void loop(){
    // Variant 2: Consecutive Memory Access Pattern via Index Reordering
    // Assume that 'index' array can be reordered to group accesses to contiguous memory locations
    // Here we simulate reordering by accessing 'interpolated' and 'enabled' consecutively,
    // while still using 'index[j]' to write into scattered 'dst' and 'is'.
    // This improves spatial locality in reading 'interpolated' and 'enabled'.

    // We reverse the loop order to demonstrate different access pattern
    for (j = nb_errors - 1; j >= 0; j--) {
        int idx = index[j];  // Load the indirect index once
        if (enabled[idx]) {
            dst[idx] = interpolated[j];
            is[idx] = 1;
        }
    }
}
