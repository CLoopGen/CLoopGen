#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t M;
extern  size_t N;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access pattern with indirect indexing
    size_t stride = 4; // Simulate strided access, e.g., every 4th element
    size_t max_idx = M * N;
    for (i = 0; i < max_idx; i += stride) {
        for (j = 0; j < stride && (i + j) < max_idx; j++) {
            // Access with offset j within each stride block
        }
    }
}
