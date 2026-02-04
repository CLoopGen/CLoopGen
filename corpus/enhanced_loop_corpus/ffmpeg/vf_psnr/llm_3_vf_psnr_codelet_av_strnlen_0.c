#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via pointer arithmetic with offset array (simulated stride pattern)
    // Simulate indirect access using a virtual index map (conceptually, without extra storage)
    size_t step = 1;
    for (i = 0; i < len; i += step) {
        // Use dereferenced value through base pointer with direct indexing (but logically indirect pattern)
        char val = *(s + i); // Equivalent to s[i], but emphasizes pointer arithmetic
        step = 1; // Reset step in case modified later (maintains forward progress)
        if (!val) {
            break;
        }
    }
}
