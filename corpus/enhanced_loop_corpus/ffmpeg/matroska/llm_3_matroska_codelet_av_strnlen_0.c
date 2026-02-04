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
    // Use a virtual "indirect" pattern by accessing through an offset list conceptually
    size_t *indices = (size_t*)malloc(len * sizeof(size_t));
    if (!indices) return; // Handle allocation failure

    // Precompute indirect indices (reversed access order as example of irregular pattern)
    for (size_t j = 0; j < len; j++) {
        indices[j] = len - 1 - j;
    }

    i = 0;
    for (size_t idx = 0; idx < len; idx++) {
        size_t pos = indices[idx];
        if (pos < len && s[pos] == 0) {
            i = pos;
            break;
        }
        i = pos + 1;
    }

    free(indices);
}
