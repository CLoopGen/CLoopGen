#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t size1;
extern  size_t size2;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t *indices = (size_t*)malloc(size2 * sizeof(size_t));
    if (!indices) return;
    // Precompute indirect access indices
    for (size_t idx = 0; idx < size2; idx++) {
        indices[idx] = (idx * 7) % size2; // pseudo-random scatter pattern
    }
    for (i = 0; i < size1; i++) {
        for (j = 0; j < size2; j++) {
            // Indirect (gather/scatter-like) memory access via index array
            volatile size_t val = indices[j];
        }
    }
    free(indices);
}
