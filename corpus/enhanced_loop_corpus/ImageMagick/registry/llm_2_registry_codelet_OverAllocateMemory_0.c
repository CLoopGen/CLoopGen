#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t length;
extern size_t extent;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (extent = 256; extent < length; extent *= 2) {
        // Introduce a strided memory access pattern via an array using extent as index with stride of 2
        volatile uint8_t dummy;
        uint8_t *array = (uint8_t*)malloc(length * sizeof(uint8_t));
        if (array == NULL) continue;
        for (size_t i = 0; i < length; i += 2) {
            dummy = array[i];  // Strided access: every second element
        }
        free(array);
    }
}
