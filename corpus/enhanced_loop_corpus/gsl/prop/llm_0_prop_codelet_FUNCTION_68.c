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
    size_t stride = 4;
    for (i = 0; i < size1; i++) {
        for (j = 0; j < size2; j += stride) {
            // Perform strided memory access pattern
            // Simulate accessing every 'stride'-th element
            volatile char dummy = ((char*)(&size1))[j];
        }
    }
}
