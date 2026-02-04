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

    // Precompute indirect indices (simple sequential mapping, could be rearranged in real use cases)
    for (size_t j = 0; j < len; j++)
        indices[j] = j;

    // Traverse using indirect addressing
    for (i = 0; i < len; i++) {
        if (!s[indices[i]]) break;
    }

    free(indices);
}
