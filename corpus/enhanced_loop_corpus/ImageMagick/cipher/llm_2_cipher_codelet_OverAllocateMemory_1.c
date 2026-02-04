#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t length;
extern size_t extent;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (extent = 256; extent < length; extent *= 2) {
        // Introduce strided memory access via a dummy array to modify access pattern
        volatile char *dummy_array = (volatile char*)malloc(extent * sizeof(char));
        if (dummy_array == NULL) continue;
        // Strided access: step by 4 bytes instead of 1
        for (size_t i = 0; i < extent; i += 4) {
            dummy_array[i] = dummy_array[i] + 1;
        }
        free((void*)dummy_array);
    }
}
