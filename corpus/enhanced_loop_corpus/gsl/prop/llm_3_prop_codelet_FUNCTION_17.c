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
    const size_t stride = 4;
    size_t padded_size = ((size2 + stride - 1) / stride) * stride;
    char *dummy_array = (char*)calloc(size1 * padded_size, sizeof(char));
    for (i = 0; i < size1; i++) {
        for (j = 0; j < size2; j += stride) {
            // Strided memory access pattern with cache-conscious step
            volatile char val1 = dummy_array[i * padded_size + j];
            volatile char val2 = dummy_array[i * padded_size + j + (j + 1 < size2 ? 1 : 0)];
            volatile char val3 = dummy_array[i * padded_size + j + (j + 2 < size2 ? 2 : 0)];
            volatile char val4 = dummy_array[i * padded_size + j + (j + 3 < size2 ? 3 : 0)];
            (void)val1; (void)val2; (void)val3; (void)val4;
        }
    }
    free(dummy_array);
}
