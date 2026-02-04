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
    int8_t *array = (int8_t*)aligned_alloc(64, size1 * size2 * sizeof(int8_t));
    for (i = 0; i < size1; i++) {
        for (j = 0; j < size2; j++) {
            // Access with stride: jump by 4 elements each time (strided access)
            size_t idx = (i * size2 + j) * 4;
            if (idx < size1 * size2) {
                volatile int8_t val = array[idx];
            }
            // Ensure inner loop still runs full count
            for (size_t k = 1; k < 4 && (i * size2 + j) * 4 + k < size1 * size2; k++) {
                volatile int8_t val = array[(i * size2 + j) * 4 + k];
            }
        }
    }
    free(array);
}
