#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t M;
extern int *ATp;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index mapping array
    size_t *indices = (size_t*)malloc((M + 1) * sizeof(size_t));
    if (!indices) return; // Handle allocation failure
    for (j = 0; j < M + 1; ++j)
        indices[j] = j; // Identity mapping, could be randomized or reordered in practice
    for (j = 0; j < M + 1; ++j)
        ATp[indices[j]] = 0;
    free(indices);
}
