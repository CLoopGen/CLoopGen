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
        indices[i] = i; // Populate direct index mapping
    }
    i = 0;
    for (size_t j = 0; j < len; j++) {
        size_t idx = indices[j];
        if (idx < len && !s[idx]) break;
        i = idx + 1;
    }
    free(indices);
}
