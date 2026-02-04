#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t MPA_INT;

extern MPA_INT *window;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Memory Access Pattern with Fixed Stride
    // Transform nested loops into a single loop with explicit stride handling
    // Simulate a more cache-unfriendly, strided traversal pattern across iterations
    
    int idx_dst, idx_src;
    int total_elements = 8 * 16;
    int stride = 16; // Artificial stride introduced for scattered access (not optimal but demonstrates pattern)
    
    for (int k = 0; k < total_elements; k++) {
        i = k / 16; // Recover original i
        j = k % 16; // Recover original j
        
        idx_dst = 512 + 128 + 16 * i + j;
        idx_src = 64 * i + 48 - j;
        
        // Apply access with artificial stride on destination (for variation in access pattern)
        // Note: Still writes to correct location, but logic could be extended for different layouts
        window[idx_dst] = window[idx_src];
    }
}
