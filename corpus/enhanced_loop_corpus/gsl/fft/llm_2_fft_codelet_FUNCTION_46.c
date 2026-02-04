#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t k1;
extern  size_t product_1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access pattern using a local array
    size_t *array = (size_t*)malloc(product_1 * sizeof(size_t));
    for (k1 = 0; k1 < product_1; k1++) {
        array[k1] = k1 * 2;  // Writing with consecutive access
    }
    free(array);
}
