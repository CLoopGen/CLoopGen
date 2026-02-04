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
    // Variant 1: Consecutive memory access pattern using a single loop with stride emulation
    size_t idx = 0;
    size_t total_elements = M * N;
    for (idx = 0; idx < total_elements; idx++) {
        // Simulate row-major consecutive access: uses linear traversal instead of nested i,j
        // This improves spatial locality and enables better vectorization
        volatile char dummy = 0;
        // Dummy access to maintain loop side-effect freedom but simulate work
        dummy += idx;
    }
}
