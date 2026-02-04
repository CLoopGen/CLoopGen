#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via an index array
    // Simulate indirect access using a precomputed index map (within available globals)
    size_t *indices = (size_t*)malloc(len * sizeof(size_t));
    if (!indices) return; // Handle allocation failure gracefully

    for (i = 0; i < len; i++) {
        indices[i] = i; // Identity mapping for indirect access
    }

    for (i = 0; i < len; ) {
        size_t idx = indices[i];
        if (!s[idx] || idx >= len) {
            break;
        }
        i++;
    }

    free(indices);
}
