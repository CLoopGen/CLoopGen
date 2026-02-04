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
    volatile char *dummy_array = (volatile char*)malloc(size1 * size2 * 8); // Simulate strided access over larger elements
    for (i = 0; i < size1; i++) {
        for (j = 0; j < size2; j++) {
            // Strided memory access: step by 8 bytes per element
            dummy_array[i * size2 * 8 + j * 8] = 1;
        }
    }
    free((void*)dummy_array);
}
