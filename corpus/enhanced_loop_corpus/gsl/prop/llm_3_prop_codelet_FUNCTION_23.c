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
    int32_t *array = (int32_t*)malloc(size1 * size2 * sizeof(int32_t));
    size_t stride = 4; // Strided access with step of 4 elements
    for (i = 0; i < size1; i++) {
        for (j = 0; j < size2; j += stride) {
            if (j + i * size2 < size1 * size2) {
                // Strided memory access pattern across a 2D-like layout
                volatile int32_t val = array[j + i * size2];
            }
        }
    }
    free(array);
}
