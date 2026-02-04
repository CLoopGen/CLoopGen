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
    for (size_t i = 0; i < size1; i++) {
        indices[i] = rand() % size1; 
    }
    for (p = 0; p < size1; p++) {
        size_t k;
        size_t n;
        k = data[indices[p]];     
        n = data[indices[size1 - 1 - p]]; 
    }
    free(indices);
    free(data);
}
