#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via pointer arithmetic with intermediate index array
    // Simulate indirect access using a dynamically created index map (even indices first, then odd)
    size_t *indices = malloc(len * sizeof(size_t));
    if (!indices) return; // Handle allocation failure

    size_t idx = 0;
    // Precompute even indices
    for (size_t j = 0; j < len; j += 2)
        indices[idx++] = j;
    // Then odd indices
    for (size_t j = 1; j < len; j += 2)
        indices[idx++] = j;

    i = 0;
    for (size_t pos = 0; pos < len; pos++) {
        size_t curr = indices[pos];
        if (!s[curr]) {
            i = curr;
            break;
        }
        i = curr + 1; // Maintain forward scan semantics
    }

    free(indices);
}
