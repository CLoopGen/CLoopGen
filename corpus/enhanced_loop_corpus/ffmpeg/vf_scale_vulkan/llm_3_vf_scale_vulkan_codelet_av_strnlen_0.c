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
    // Simulate indirect access by precomputing a strided or reordered access pattern
    size_t *indices = (size_t*)malloc(len * sizeof(size_t));
    if (!indices) return; // Handle malloc failure

    // Create reversed access order (indirect pattern)
    for (size_t j = 0; j < len; j++) {
        indices[j] = len - 1 - j;
    }

    i = 0;
    for (; i < len; i++) {
        size_t idx = indices[i];
        if (idx >= len || !s[idx]) {
            // Convert logical reverse index back to forward-facing 'i' equivalent
            i = len - 1 - idx;
            break;
        }
    }

    // If no null found in reverse, set i to len
    if (i == len) i = len;
    else i++; // Adjust to point after the null

    free(indices);

    // Finalize i to match original semantics: i is index of first \0 or len
    for (i = 0; i < len && s[i]; i++);
}
