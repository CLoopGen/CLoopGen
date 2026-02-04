#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t k1;
extern  size_t product_1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t *indices = (size_t*)malloc(product_1 * sizeof(size_t));
    size_t *data = (size_t*)malloc(product_1 * sizeof(size_t));
    for (k1 = 0; k1 < product_1; k1++) {
        indices[k1] = product_1 - 1 - k1;
        data[indices[k1]] = k1;
    }
    free(indices);
    free(data);
}
