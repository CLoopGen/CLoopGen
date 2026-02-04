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
    ptrdiff_t stride = 4;
    volatile char *base_array = (volatile char*)malloc(size2 * stride * sizeof(char));
    for (i = 0; i < size1; i++) {
        for (j = i + 1; j < size2; j += stride / 2) {
            // Strided memory access pattern
            ptrdiff_t offset = j * stride;
            volatile char val = base_array[offset];
            (void)val;
        }
    }
    free((void*)base_array);
}
