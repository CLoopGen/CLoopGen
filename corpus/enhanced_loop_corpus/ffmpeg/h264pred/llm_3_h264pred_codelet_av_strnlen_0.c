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
    if (!indices) return;
    
    size_t j;
    // Build indirect access pattern: even indices, then odd
    for (j = 0; j < len; j++) {
        indices[j] = (j % 2 == 0) ? (j / 2) : (len / 2 + (j - 1) / 2);
    }

    i = 0;
    for (j = 0; j < len; j++) {
        size_t idx = indices[j];
        if (idx < len && s[idx]) {
            i = idx + 1;
        } else {
            i = idx;
            break;
        }
    }

    free(indices);
}
