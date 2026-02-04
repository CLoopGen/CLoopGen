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
    size_t *indices = (size_t*)malloc(len * sizeof(size_t));
    if (!indices) return; // Handle allocation failure

    // Precompute indirect indices (e.g., reverse order access)
    for (i = 0; i < len; i++) {
        indices[i] = len - 1 - i;
    }

    // Traverse using indirect addressing
    for (i = 0; i < len; i++) {
        size_t idx = indices[i];
        if (!s[idx]) {
            // Map back to logical position in original order
            i = len - idx;
            break;
        }
        if (i == len - 1) {
            i = len; // Full length reached
        }
    }

    free(indices);
}
