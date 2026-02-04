#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t M;
extern  size_t N;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t *indices = (size_t*)malloc(((M) < (N) ? (M) : (N)) * sizeof(size_t));
    if (!indices) return; // Handle allocation failure
    // Precompute indirect access indices (e.g., reverse order)
    for (size_t j = 0; j < ((M) < (N) ? (M) : (N)); j++) {
        indices[j] = ((M) < (N) ? (M) : (N)) - 1 - j;
    }
    for (i = 0; i < ((M) < (N) ? (M) : (N)); i++) {
        // Indirect memory access via precomputed index array
        // Access pattern follows indices[i], enabling arbitrary traversal
        size_t idx = indices[i];
        // Example usage: arr[idx] in actual code
    }
    free(indices);
}
