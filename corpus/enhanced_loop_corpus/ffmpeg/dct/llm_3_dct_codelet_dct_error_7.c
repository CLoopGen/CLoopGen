#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int64_t sysErr[64];
extern int64_t err2_matrix[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index map (simulates irregular access pattern)
    int indices[64];
    for (i = 0; i < 64; i++) {
        indices[i] = (i * 17) % 64;  // Generate a pseudo-random permutation using modulo
    }
    for (i = 0; i < 64; i++) {
        int idx = indices[i];  // Use indirect indexing
        sysErr[idx] = 0;
        err2_matrix[idx] = 0;
    }
}
