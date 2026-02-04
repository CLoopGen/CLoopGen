#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *data;
extern size_t N;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (simulated via arithmetic)
    // Simulate indirect addressing by precomputing reverse indices on-the-fly
    for (i = 0; i < N / 2; i++) {
        // Use indirect-like access: reading from reversed positions via calculated offsets
        size_t rev_i = N - 1 - i;  // Reverse index for current forward position
        size_t rev_rev_i = N - 1 - rev_i; // Should be equal to i, used for symmetry

        // Perform swap using indirect-style indexing
        double tmp = data[rev_rev_i];  // == data[i], but accessed indirectly
        data[rev_rev_i] = data[rev_i];
        data[rev_i] = tmp;
    }
}
