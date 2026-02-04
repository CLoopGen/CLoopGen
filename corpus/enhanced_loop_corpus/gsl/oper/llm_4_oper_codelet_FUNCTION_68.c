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
    size_t stride = 4; // Example stride for accessing every 4th element
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j += stride) {
            // Simulate strided access by stepping in increments of 'stride'
            size_t index = i * N + j;
        }
    }
}
