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
    size_t indices[1024]; // Local index buffer for indirect traversal (small fixed size for realism)
    size_t n = (len < 1024) ? len : 1024;
    // Precompute indirect access pattern: reverse access within bounds
    for (size_t j = 0; j < n; j++) {
        indices[j] = len - 1 - j; // Reverse order access
    }
    i = 0;
    for (size_t j = 0; j < n; j++) {
        size_t idx = indices[j];
        if (idx < len && s[idx]) {
            i = idx; // Update i to the current accessed index
        } else {
            break;
        }
    }
    // Ensure i is set to appropriate terminal value as in original
    if (i < len && !s[i]) {
        // Already null-terminated at i
    } else {
        i = len; // Reached logical end
    }
}
