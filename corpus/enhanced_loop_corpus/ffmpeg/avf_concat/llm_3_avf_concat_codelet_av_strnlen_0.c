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
    // Use an auxiliary index array to simulate indirect addressing
    size_t *indices = (size_t*)malloc(len * sizeof(size_t));
    if (!indices) return; // Handle allocation failure

    for (i = 0; i < len; i++) {
        indices[i] = i; // Direct mapping: indices[i] = i
    }

    for (i = 0; i < len; i++) {
        size_t idx = indices[i]; // Indirect access through index array
        if (idx >= len || !s[idx]) {
            break;
        }
    }
    // Map final index back to original i
    i = (i < len) ? indices[i] : indices[len - 1];

    free(indices);
}
