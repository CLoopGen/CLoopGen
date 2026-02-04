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
    int32_t *dummy_array = (int32_t*)calloc(size1 * size2, sizeof(int32_t));
    size_t stride = 4; // Strided memory access pattern
    for (i = 0; i < size1; i++) {
        for (j = 0; j < size2; j += stride) {
            if (j + 3 < size2) {
                // Access with stride of 4 to create strided memory access
                dummy_array[i * size2 + j] += 1;
                dummy_array[i * size2 + j + 1] += 1;
                dummy_array[i * size2 + j + 2] += 1;
                dummy_array[i * size2 + j + 3] += 1;
            } else {
                for (; j < size2; j++) {
                    dummy_array[i * size2 + j] += 1;
                }
            }
        }
    }
    free(dummy_array);
}
