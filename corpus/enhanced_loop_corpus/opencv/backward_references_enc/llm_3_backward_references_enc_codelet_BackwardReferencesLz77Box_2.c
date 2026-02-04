#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int window_offsets[32];
extern int window_offsets_size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via an index remapping table
    int index_map[32];
    for (int j = 0; j < 32; ++j) {
        index_map[j] = (17 * j + 31) % 32;  // Simple linear congruential permutation
    }
    
    for (i = 0; i < 32; ++i) {
        int mapped_index = index_map[i];
        if (window_offsets[mapped_index] == 0)
            continue;
        window_offsets[window_offsets_size++] = window_offsets[mapped_index];
    }
}
