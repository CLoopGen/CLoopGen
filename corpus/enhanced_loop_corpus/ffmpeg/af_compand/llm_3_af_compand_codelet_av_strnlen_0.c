#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via pointer arithmetic with intermediate index array
    // Simulate indirect access using a virtual index sequence
    size_t *indices = (size_t*)malloc(len * sizeof(size_t));
    if (!indices) return; // Handle allocation failure
    for (size_t j = 0; j < len; j++) {
        indices[j] = j; // Identity mapping for indirect access
    }
    i = 0;
    for (; i < len; i++) {
        if (!s[indices[i]]) break;
    }
    free(indices);
}
