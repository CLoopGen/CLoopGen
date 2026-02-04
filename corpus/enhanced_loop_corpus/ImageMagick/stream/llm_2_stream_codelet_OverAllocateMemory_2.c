#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t length;
extern size_t extent;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (extent = 256; extent < length; extent *= 2) {
        // Introduce a strided memory access pattern using a dummy array
        volatile uint8_t *dummy_array = (volatile uint8_t*)malloc(extent * 8);
        if (dummy_array == NULL) continue;
        for (size_t i = 0; i < extent; i += 4) { // Stride of 4
            dummy_array[i * 8] += 1;
        }
        free((void*)dummy_array);
    }
}
