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
    // Variant 2: Strided memory access pattern - access every K-th element in a flattened iteration
    const size_t K = 4; // Stride factor
    size_t total = M * N;
    size_t idx = 0;
    for (i = 0; i < total; i += K) {
        idx = i; // Simulate strided access, e.g., processing elements at stride K
        if (idx >= total) break;
    }
}
