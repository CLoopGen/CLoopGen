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
    if (!indices) return;
    for (size_t j = 0; j < len; j++) {
        indices[j] = j; // Direct mapping: indirect access through indices
    }
    for (i = 0; i < len; i++) {
        size_t idx = indices[i];
        if (!s[idx]) break;
    }
    free(indices);
}
