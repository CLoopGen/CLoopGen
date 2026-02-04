#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t length;
extern size_t extent;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (extent = 256; extent < length; extent *= 2) {
        // Introduce strided memory access via an array using extent as index with stride of 2
        volatile uint8_t *dummy_array = (volatile uint8_t*)malloc(extent * 2);
        if (dummy_array != NULL) {
            for (size_t i = 0; i < extent; i += 2) { // Strided access: step by 2
                dummy_array[i] = (uint8_t)(i & 0xFF);
            }
            free((void*)dummy_array);
        }
    }
}
