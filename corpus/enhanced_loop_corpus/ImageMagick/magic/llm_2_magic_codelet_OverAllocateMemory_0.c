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
        volatile uint8_t dummy_array[1024];
        size_t stride = 4;
        for (size_t i = 0; i < 256; i += stride) {
            dummy_array[i] += 1;
        }
    }
}
