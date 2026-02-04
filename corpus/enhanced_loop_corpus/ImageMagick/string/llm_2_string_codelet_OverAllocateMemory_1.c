#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t length;
extern size_t extent;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (extent = 256; extent < length; extent *= 2) {
        // Introduce strided memory access pattern via an array using extent as index with stride of 4
        volatile uint8_t *dummy_array = (volatile uint8_t*)malloc(extent * 4 * sizeof(uint8_t));
        if (dummy_array != NULL) {
            for (size_t i = 0; i < extent; i++) {
                dummy_array[i * 4] += 1; // Strided access: every 4th element
            }
            free((void*)dummy_array);
        }
    }
}
