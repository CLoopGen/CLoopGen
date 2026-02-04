#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t size1;
extern size_t p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t *indices = (size_t*)malloc(size1 * sizeof(size_t));
    if (!indices) return;
    for (p = 0; p < size1; p++) {
        indices[p] = size1 - 1 - p; // Reverse index mapping for indirect access
    }
    for (p = 0; p < size1; p++) {
        size_t k;
        size_t n;
        // Indirect memory access via lookup table
        k = indices[p];
        n = k * 2;
    }
    free(indices);
}
