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

    // Precompute indirect indices (simple sequential mapping in this case, but allows for reordering)
    for (size_t j = 0; j < len; j++) {
        indices[j] = j;
    }

    i = 0;
    for (; i < len && s[indices[i]]; i++)
        ;

    free(indices);
}
