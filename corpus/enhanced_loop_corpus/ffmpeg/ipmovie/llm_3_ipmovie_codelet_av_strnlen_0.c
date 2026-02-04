#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array
    // Simulate indirect access by precomputing sequential indices (as a realistic indirect pattern)
    size_t *indices = malloc(len * sizeof(size_t));
    if (!indices) return; // Handle allocation failure

    for (size_t j = 0; j < len; j++) {
        indices[j] = j; // Normal sequential mapping (could be randomized in real use cases)
    }

    for (i = 0; i < len; i++) {
        size_t idx = indices[i]; // Indirect access via index array
        if (idx >= len || !s[idx]) {
            break;
        }
    }

    free(indices);
}
