#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via pointer arithmetic with intermediate array index indirection
    size_t *indices = (size_t*)malloc(len * sizeof(size_t));
    if (!indices) return; // Handle allocation failure

    // Precompute linear index mapping (could be randomized or reordered in other uses)
    for (i = 0; i < len; i++) {
        indices[i] = i;
    }

    // Traverse using indirect addressing
    for (i = 0; i < len; ) {
        size_t idx = indices[i]; // Indirect access
        if (!s[idx]) break;
        i++;
    }

    // Now i is the number of consecutive non-null characters accessed indirectly
    // But we need to set `i` as index in original meaning
    // Re-map i to be the actual position in s where null occurred
    for (i = 0; i < len && s[i]; i++)
        ;

    free(indices);
}
