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
    // Create indirect access pattern via index array
    for (size_t temp_i = 0; temp_i < ((M) < (N) ? (M) : (N)); temp_i++) {
        indices[temp_i] = ((M) < (N) ? (M) : (N)) - 1 - temp_i; // reverse order access
    }
    for (i = 0; i < ((M) < (N) ? (M) : (N)); i++) {
        // Use indirect indexing: e.g., A[indices[i]]
        // This simulates an irregular/indirect memory access pattern
    }
    free(indices);
}
