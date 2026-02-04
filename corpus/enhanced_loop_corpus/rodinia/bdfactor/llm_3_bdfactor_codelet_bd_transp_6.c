#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int j;
extern int jj;
extern int lb;
extern int ub;
extern int n1;
extern double **in_v;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (simulated via arithmetic)
    // Use an auxiliary indexing scheme that reverses the access order (reverse traversal)
    int offset;
    int upper_bound = n1 - ub + i;
    for (jj = 0; jj <= upper_bound; jj++) {
        // Map jj to a reversed index in the source
        offset = ((i - lb) > (0) ? (i - lb) : (0)) + jj;
        int src_index = n1 - 1 - offset;  // reverse indexing
        if (src_index >= 0 && src_index < n1) {
            in_v[i][jj] = in_v[i][src_index];
        }
    }
}
