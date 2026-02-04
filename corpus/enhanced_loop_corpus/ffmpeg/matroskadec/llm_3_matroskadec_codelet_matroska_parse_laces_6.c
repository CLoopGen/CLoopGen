#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int size;
extern uint32_t lace_size[256];
extern int *laces;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via index remapping
    // Use an auxiliary array to define a non-linear access order to lace_size.
    // Simulate indirect access using modulo-based permutation to avoid extra storage.
    // This creates a scattered write pattern, potentially stressing address calculation.
    int *index_map = laces; // reuse laces as base for indexing (assumed valid)
    for (n = 0; n < *laces; n++) {
        int mapped_index = (n * 7 + 3) % *laces; // simple permutation: affine mapping
        lace_size[mapped_index] = size / *laces;
    }
}
