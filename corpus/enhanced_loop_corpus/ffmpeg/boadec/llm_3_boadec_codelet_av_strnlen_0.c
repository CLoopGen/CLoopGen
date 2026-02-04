#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via pointer arithmetic with offset array (simulated indirect pattern)
    size_t *indices = (size_t*)malloc(len * sizeof(size_t));
    if (!indices) return;
    for (i = 0; i < len; i++) {
        indices[i] = i; // Populate direct index map (could be randomized in real indirect scenarios)
    }
    i = 0;
    for (; i < len; i++) {
        size_t idx = indices[i];
        if (idx >= len || !s[idx]) {
            break;
        }
    }
    free(indices);
}
