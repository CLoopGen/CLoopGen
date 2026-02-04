#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (simulated via pointer arithmetic)
    size_t *indices = (size_t*)malloc(len * sizeof(size_t));
    if (!indices) return; // Handle allocation failure

    // Precompute indirect indices (simple sequential mapping here, but allows arbitrary reordering)
    for (size_t j = 0; j < len; j++)
        indices[j] = j;

    for (i = 0; i < len; i++) {
        size_t idx = indices[i]; // Use indirect addressing
        if (idx >= len || !s[idx]) {
            i = idx; // Mimic original behavior where i stops at null or end
            break;
        }
    }

    free(indices);
}
