#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via index array (simulated with pointer arithmetic)
    // Simulate an indirect access pattern using a virtual offset list (compile-time constant stride simulation)
    size_t *indices = (size_t*)malloc(len * sizeof(size_t));
    if (!indices) return; // Handle allocation failure gracefully

    // Precompute indirect indices (e.g., reverse order traversal)
    for (i = 0; i < len; i++) {
        indices[i] = len - 1 - i; // Reverse indexing
    }

    // Traverse using indirect addressing
    for (i = 0; i < len; i++) {
        size_t idx = indices[i];
        if (!s[idx]) {
            // Found null terminator in reverse scan — compute forward position
            i = len - idx; // Approximate logical position
            break;
        }
        if (i == len - 1) {
            i = len; // Reached end without null
        }
    }

    // Finalize i as the offset in original string where null would be
    if (i < len) {
        i = len - indices[i-1]; // Convert back to direct index
    } else {
        i = len;
    }

    free(indices);
}
