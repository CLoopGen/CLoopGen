#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t src_size1;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access pattern
    // Assuming an array 'data' of size src_size1, access every 4th element
    int *data = (int*)malloc(src_size1 * sizeof(int));
    for (i = 0; i < src_size1; i += 4) {
        data[i] = data[i] + 1;
    }
    free(data);
}
