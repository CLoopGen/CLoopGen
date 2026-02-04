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
    size_t stride = 4; // Example stride for scattered access
    size_t idx;
    for (i = 1; i < M; i++) {
        size_t limit = (i < N) ? i : N;
        for (idx = 0; idx * stride < limit; idx++) {
            // Access at non-unit stride: potential use in matrix bands or filtered processing
            // Effective index would be idx * stride, skipping elements
        }
    }
}
