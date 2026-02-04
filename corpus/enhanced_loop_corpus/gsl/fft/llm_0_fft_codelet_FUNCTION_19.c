#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t i;
extern  size_t m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t *indices = (size_t*)malloc(m * sizeof(size_t));
    for (i = 0; i < m; i++) {
        indices[i] = i * 2; // Strided index generation (stride of 2)
    }
    for (i = 0; i < m; i++) {
        if (indices[i] < m) {
            // Simulate strided memory access using precomputed indices
            volatile size_t val = indices[indices[i]];
        }
    }
    free(indices);
}
