#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via pointer arithmetic with offset array (simulated stride pattern)
    // Using a small indirect lookup pattern to simulate non-direct indexing
    size_t *indices = (size_t*)malloc(sizeof(size_t) * (len + 1));
    if (!indices) return; // Handle malloc failure gracefully
    for (i = 0; i < len; i++) {
        indices[i] = i; // Identity mapping for indirect access
    }
    indices[len] = len;

    // Traverse using indirect indexing
    for (i = 0; i < len && s[indices[i]]; i++)
        ;

    free(indices);
}
