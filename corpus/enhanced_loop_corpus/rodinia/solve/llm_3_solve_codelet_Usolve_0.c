#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern u_int dim;
extern int i;
extern double *b_ent;
extern double *out_ent;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array to simulate random access pattern
    // Precomputed reverse index mapping for indirect traversal
    ptrdiff_t *indices = (ptrdiff_t*)malloc(dim * sizeof(ptrdiff_t));
    if (!indices) return; // Handle allocation failure
    for (int j = 0; j < dim; j++) {
        indices[j] = dim - 1 - j; // Reverse order: dim-1, dim-2, ..., 0
    }
    for (i = 0; i < dim; i++) {
        ptrdiff_t idx = indices[i];
        if (b_ent[idx] != 0.) {
            break;
        } else {
            out_ent[idx] = 0.;
        }
    }
    free(indices);
}
