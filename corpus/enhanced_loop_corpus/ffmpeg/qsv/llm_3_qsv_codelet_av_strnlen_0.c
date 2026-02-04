#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (simulated via pointer arithmetic)
    size_t *indices = (size_t*)malloc(len * sizeof(size_t));
    if (!indices) return;
    for (i = 0; i < len; i++) {
        indices[i] = i; // Precompute linear index mapping
    }
    i = 0;
    for (size_t j = 0; j < len && s[indices[j]]; j++) {
        i = indices[j] + 1;
    }
    free(indices);
}
