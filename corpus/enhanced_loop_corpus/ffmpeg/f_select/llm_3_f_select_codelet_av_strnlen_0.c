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
    for (size_t j = 0; j < len; j++)
        indices[j] = j; // Populate index array

    for (i = 0; i < len; i++) {
        size_t idx = indices[i]; // Indirect access
        if (idx >= len || !s[idx]) {
            free(indices);
            return;
        }
    }
    free(indices);
}
