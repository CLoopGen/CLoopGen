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
    if (!indices) return;
    for (i = 0; i < len; i++) {
        indices[i] = i; // Populate direct mapping as base for indirect access
    }
    for (i = 0; i < len; ) {
        size_t idx = indices[i]; // Indirect access through index array
        if (idx >= len || !s[idx]) break;
        i++;
    }
    free(indices);
}
