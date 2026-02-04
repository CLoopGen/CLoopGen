#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t length;
extern size_t extent;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (extent = 256; extent < length; extent *= 2) {
        // Introduce strided memory access via a dummy array access pattern
        volatile char *dummy_array = (volatile char *)malloc(extent * sizeof(char));
        if (dummy_array != NULL) {
            for (size_t i = 0; i < extent; i += 4) { // Strided access with stride of 4
                dummy_array[i] = (char)(i & 0xFF);
            }
            free((void*)dummy_array);
        }
    }
}
