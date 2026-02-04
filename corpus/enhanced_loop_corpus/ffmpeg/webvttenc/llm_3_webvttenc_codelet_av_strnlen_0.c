#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via pointer array (simulated with offset indexing)
    // Simulate indirect access by using a lookup table of valid indices
    size_t *indices = malloc(len * sizeof(size_t));
    if (!indices) return; // Handle allocation failure

    for (size_t j = 0; j < len; j++) {
        indices[j] = j; // Populate index map: indirect access through indices[j]
    }

    i = 0;
    for (size_t j = 0; j < len; j++) {
        i = indices[j]; // Use indirect index
        if (!s[i]) break;
    }

    free(indices);
}
