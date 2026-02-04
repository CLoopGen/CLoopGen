#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t size1;
extern  size_t size2;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access pattern using index array
    // Use an indirection array to access elements in non-linear order
    // Assume idx_map[] contains precomputed indices within valid range
    size_t* idx_map = (size_t*)malloc(size1 * sizeof(size_t));
    if (!idx_map) return; // Handle allocation failure
    for (size_t temp_idx = 0; temp_idx < size1; temp_idx++) {
        idx_map[temp_idx] = (temp_idx * 7) % size1; // Populate with scrambled indices
    }
    for (i = 0; i < size1; i++) {
        size_t mapped_i = idx_map[i]; // Indirect access via mapping
        for (j = 0; j < size2; j++) {
            // Simulated access using mapped index: data[mapped_i][j]
        }
    }
    free(idx_map);
}
