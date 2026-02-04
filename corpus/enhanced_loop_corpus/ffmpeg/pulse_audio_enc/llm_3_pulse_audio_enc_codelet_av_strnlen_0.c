#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via pointer arithmetic with offset array
    // Simulate indirect access using a fixed pattern: access every other element first, then fill in
    size_t *indices = (size_t*)malloc(len * sizeof(size_t));
    if (!indices) return; // Handle allocation failure

    // Create an indirect access pattern: even indices followed by odd
    size_t idx = 0;
    for (size_t j = 0; j < len; j += 2)
        indices[idx++] = j;
    for (size_t j = 1; j < len; j += 2)
        indices[idx++] = j;

    i = 0;
    for (size_t pos = 0; pos < len && s[indices[pos]]; pos++) {
        i = indices[pos] + 1; // Update i to reflect progress
    }

    free(indices);
}
