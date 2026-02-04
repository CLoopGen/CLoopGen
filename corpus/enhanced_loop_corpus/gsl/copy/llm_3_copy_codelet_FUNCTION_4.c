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
    if (!indices) return;
    // Precompute indirect access indices (e.g., reverse order)
    for (size_t j = 0; j < ((M) < (N) ? (M) : (N)); j++) {
        indices[j] = ((M) < (N) ? (M) : (N)) - 1 - j;
    }
    for (i = 0; i < ((M) < (N) ? (M) : (N)); i++) {
        // Indirect memory access via index array
        // Simulates random or out-of-order traversal
        size_t pos = indices[i];
        // Access memory at position 'pos'
    }
    free(indices);
}
