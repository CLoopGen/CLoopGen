#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t k1;
extern  size_t product_1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access pattern using a strided read/write on a local buffer
    const size_t stride = 4;
    size_t *buffer = (size_t*)calloc(product_1 * stride, sizeof(size_t));
    for (k1 = 0; k1 < product_1; k1++) {
        buffer[k1 * stride] = k1;  // Access every 'stride'-th element (strided access)
    }
    free(buffer);
}
