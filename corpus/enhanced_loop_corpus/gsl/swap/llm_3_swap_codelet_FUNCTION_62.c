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
    // Precompute indirect access pattern
    for (size_t i = 0; i < size1; i++) {
        indices[i] = size1 - 1 - i; // Reverse order access
    }
    for (p = 0; p < size1; p++) {
        size_t k = indices[p]; // Indirect access via index array
        size_t n = k % size1;
        volatile size_t dummy = n;
    }
    free(indices);
}
