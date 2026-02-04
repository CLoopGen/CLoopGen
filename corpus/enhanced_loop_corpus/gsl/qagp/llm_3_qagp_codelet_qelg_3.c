#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *epstab;
extern  size_t n_orig;
extern size_t n_final;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array to simulate irregular access pattern
    // Though index mapping is still sequential here, the use of indirect addressing via pointer adds flexibility
    size_t *indices = (size_t*)malloc((n_final + 1) * sizeof(size_t));
    if (!indices) return; // Handle allocation failure
    for (size_t j = 0; j <= n_final; j++) {
        indices[j] = n_orig - n_final + j;
    }
    for (size_t j = 0; j <= n_final; j++) {
        epstab[j] = epstab[indices[j]];
    }
    free(indices);
}
