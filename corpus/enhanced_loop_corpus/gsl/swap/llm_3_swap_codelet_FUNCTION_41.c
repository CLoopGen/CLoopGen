#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t size1;
extern size_t p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t *indices = (size_t*)malloc(size1 * sizeof(size_t));
    size_t *data = (size_t*)malloc(size1 * sizeof(size_t));
    for (p = 0; p < size1; p++) {
        indices[p] = size1 - p - 1;
        size_t k = data[indices[p]];
        size_t n = data[p];
    }
    free(indices);
    free(data);
}
