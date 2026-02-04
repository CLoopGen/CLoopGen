#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t dim;
extern double * z;
extern size_t ord;
extern size_t i;
extern size_t j;
extern size_t k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Use indirect memory access via index remapping using a stride multiplier
    // Introduce a virtual "reverse" indexing within each block of size dim
    // This changes access pattern to indirect: accessing elements in reversed order within dim
    for (i = 1; i < ord + 1; i++)
        for (j = ord; j > i - 1; j--) {
            size_t base_prev = (j - 1) * dim;
            size_t base_curr = j * dim;
            for (k = 0; k < dim; k++) {
                size_t rev_k = dim - 1 - k;  // reverse index mapping
                z[base_prev + rev_k] += z[base_curr + rev_k];
            }
        }
}
