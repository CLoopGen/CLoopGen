#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t M;
extern int *ATp;
extern int *w;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index mapping array (simulated via modulo-based permutation)
    size_t j;
    for (j = 0; j < M; ++j) {
        size_t idx = (j * 3 + 1) % M;  // Simple pseudo-random indirect indexing
        w[idx] = ATp[idx];
    }
}
