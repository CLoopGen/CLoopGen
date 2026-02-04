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
    // Variant 2: Indirect memory access via index array
    // Use an indirection array to access elements in non-sequential order
    // Simulate indirect access using precomputed indices (e.g., for gather operations)
    size_t *indices = (size_t*)malloc(size2 * sizeof(size_t));
    if (!indices) return; // Handle allocation failure

    // Initialize index mapping: reverse order for example
    for (size_t idx = 0; idx < size2; idx++) {
        indices[idx] = size2 - 1 - idx;
    }

    for (i = 0; i < size1; i++) {
        for (j = 0; j < size2; j++) {
            size_t pos = indices[j]; // Indirect access via index remapping
            // Simulated access: e.g., data[i * size2 + pos]
            // No actual array used, but access pattern is indirect
        }
    }

    free(indices);
}
