#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t src_size1;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via index array
    // Use an auxiliary index array to access elements in non-sequential order
    // Simulate indirect access pattern using a precomputed permutation (conceptual)
    size_t *indices = (size_t*)malloc(src_size1 * sizeof(size_t));
    if (!indices) return; // Handle allocation failure

    // Initialize indices in reverse order for indirect backward access
    for (size_t temp_i = 0; temp_i < src_size1; temp_i++) {
        indices[temp_i] = src_size1 - 1 - temp_i;
    }

    for (i = 0; i < src_size1; i++) {
        size_t idx = indices[i]; // Indirect access index
        __asm__ volatile("" : : "r"(idx) : "memory"); // Simulate memory access via idx
    }

    free(indices);
}
