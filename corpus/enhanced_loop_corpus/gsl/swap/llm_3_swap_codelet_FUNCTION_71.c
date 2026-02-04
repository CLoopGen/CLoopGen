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
    char *base_array = (char*)malloc(size2 * stride * sizeof(char));
    for (i = 0; i < size1; i++) {
        for (j = i + 1; j < size2; j += stride) {
            // Strided memory access pattern
            volatile char val = base_array[j * stride];
            (void)val;
        }
    }
    free(base_array);
}
