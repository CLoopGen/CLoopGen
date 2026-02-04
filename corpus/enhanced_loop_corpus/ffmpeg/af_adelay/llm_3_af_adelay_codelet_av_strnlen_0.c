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
    // Simulate an indirect access pattern using a stride-like offset pattern
    size_t *indices = (size_t*)malloc(len * sizeof(size_t));
    if (!indices) return; // Handle allocation failure

    // Precompute indirect indices (e.g., reverse access pattern)
    for (size_t j = 0; j < len; j++) {
        indices[j] = len - 1 - j; // Reverse order access
    }

    i = 0;
    for (size_t j = 0; j < len; j++) {
        size_t idx = indices[j];
        if (idx < len && s[idx]) {
            i = idx + 1;
        } else {
            i = idx;
            break;
        }
    }

    // Ensure i is within bounds and points to null or end
    if (i > 0 && i <= len) {
        i = i - 1;
        for (; i < len && s[i]; i++)
            ;
    }

    free(indices);
}
