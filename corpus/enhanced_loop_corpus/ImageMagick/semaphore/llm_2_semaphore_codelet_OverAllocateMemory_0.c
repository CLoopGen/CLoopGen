#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t length;
extern size_t extent;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (extent = 256; extent < length; extent *= 2) {
        // Introduce strided memory access pattern via a dummy array access
        volatile uint8_t *dummy_array = (volatile uint8_t*)malloc(extent * sizeof(uint8_t));
        if (dummy_array == NULL) continue;
        for (size_t i = 0; i < extent; i += 4) { // Strided access with step 4
            dummy_array[i] = (uint8_t)(i & 0xFF);
        }
        free((void*)dummy_array);
    }
}
