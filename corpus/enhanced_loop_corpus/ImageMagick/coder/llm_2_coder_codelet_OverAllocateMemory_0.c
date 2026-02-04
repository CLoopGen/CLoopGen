#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t length;
extern size_t extent;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (extent = 256; extent < length; extent *= 2) {
        // Introduce strided memory access pattern via dummy array indexing with stride equal to current extent
        volatile uint8_t *dummy_array = (volatile uint8_t*)malloc(extent * sizeof(uint8_t));
        if (dummy_array != NULL) {
            for (size_t i = 0; i < extent; i += 16) { // Strided access: step by 16 bytes (cache-conscious)
                dummy_array[i] += 1;
            }
            free((void*)dummy_array);
        }
    }
}
