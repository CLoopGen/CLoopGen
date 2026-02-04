#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t M;
extern  size_t N;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via index array
    // Create and use an index map to access elements in non-sequential order
    size_t total = M * N;
    size_t* indices = (size_t*)malloc(total * sizeof(size_t));
    if (!indices) return; // Handle allocation failure

    // Fill indices with reverse order for indirect access
    for (size_t k = 0; k < total; k++) {
        indices[k] = total - 1 - k;
    }

    // Use indirect access through the index array
    for (size_t k = 0; k < total; k++) {
        volatile size_t pos = indices[k];
        (void)pos;
    }

    free(indices);
}
