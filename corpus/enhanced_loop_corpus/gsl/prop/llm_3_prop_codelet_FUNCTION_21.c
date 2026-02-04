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
    // Precompute strided access pattern: j * 4 as stride
    for (j = 0; j < size2; j++) {
        indices[j] = j * 4;
    }
    for (i = 0; i < size1; i++) {
        for (j = 0; j < size2; j++) {
            size_t offset = indices[j];
            // Simulate strided memory access
            volatile size_t dummy = offset + i;
        }
    }
    free(indices);
}
