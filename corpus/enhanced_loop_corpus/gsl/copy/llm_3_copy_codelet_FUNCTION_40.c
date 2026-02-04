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
    for (i = 0; i < ((M) < (N) ? (M) : (N)); i++) {
        indices[i] = i; // Populate direct index map (could be randomized or reordered in practice)
    }
    for (i = 0; i < ((M) < (N) ? (M) : (N)); i++) {
        // Indirect memory access via index array 'indices'
        // Enables gather-type access patterns, useful in sparse computation
        volatile size_t idx = indices[i];
    }
    free(indices);
}
