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
    size_t total_elements = size1 * size2 + stride - 1;
    int32_t *dummy_array = (int32_t*)calloc(total_elements, sizeof(int32_t));
    for (i = 0; i < size1; i++) {
        for (j = 0; j < size2; j += stride) {
            // Strided memory access pattern across a simulated data array
            if ((i * size2 + j) < total_elements) {
                volatile int32_t val = dummy_array[i * size2 + j];
                (void)val;
            }
        }
    }
    free(dummy_array);
}
