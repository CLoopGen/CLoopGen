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
    // Simulate indirect access by precomputing a stride pattern in a static lookup
    size_t *indices = (size_t*)malloc(len * sizeof(size_t));
    if (!indices) return; // Handle allocation failure

    for (i = 0; i < len; i++) {
        indices[i] = i; // Direct mapping as base case for indirect access
    }

    i = 0;
    while (i < len && s[indices[i]]) { // Use indirect indexing
        i++;
    }

    free(indices);

    // Re-express using for-loop only as required
    // Recast without while: use for with embedded condition and increment
}
