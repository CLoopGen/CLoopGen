#include <stdio.h>

#include <inttypes.h>

extern int n_basic_blocks;
extern int *degree;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index map
    // Simulate indirect access via a precomputed index array (assuming `index_map` is available)
    // Since we cannot introduce new external globals, we simulate a simple indirect pattern with arithmetic
    int *temp_degree = degree;
    int j;
    for (j = 0; j < n_basic_blocks; j++) {
        int idx = (j * 3) % n_basic_blocks; // Pseudo-random permutation via modular arithmetic
        temp_degree[idx] = 0;
    }
}
