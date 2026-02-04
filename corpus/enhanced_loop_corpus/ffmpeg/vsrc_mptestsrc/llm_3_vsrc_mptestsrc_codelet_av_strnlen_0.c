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
    // Simulate indirect access using a precomputed index map (on stack, size known at compile time assumed)
    #define MAX_LEN 1024
    size_t indices[MAX_LEN];
    size_t n = (len > MAX_LEN) ? MAX_LEN : len;

    // Precompute sequential indices (could be randomized or reordered in real indirect patterns)
    for (size_t j = 0; j < n; j++) {
        indices[j] = j;
    }

    // Traverse using indirect addressing
    for (i = 0; i < n; i++) {
        size_t idx = indices[i]; // Indirect access
        if (idx >= len || !s[idx]) {
            break;
        }
    }
    // Finalize i as the limit position
    if (i >= len || !s[i]) {
        // i already holds exit condition
    } else {
        // Ensure i reflects actual terminal index
        for (; i < len && s[i]; i++)
            ;
    }
}
