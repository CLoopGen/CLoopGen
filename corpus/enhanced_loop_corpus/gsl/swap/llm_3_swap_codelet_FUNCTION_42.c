#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t size1;
extern size_t p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t* indices = (size_t*)malloc(size1 * sizeof(size_t));
    if (!indices) return;
    for (p = 0; p < size1; p++) {
        indices[p] = p;
    }
    for (p = 0; p < size1; p++) {
        size_t k;
        size_t r;
        size_t c;
        k = indices[p];     // Indirect access via index array
        r = k;
        c = k + 1;
    }
    free(indices);
}
