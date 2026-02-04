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
    ptrdiff_t stride = 4; // Strided access with step of 4
    for (i = 0; i < size1; i++) {
        for (j = i + stride; j < size2; j += stride) {
            // Perform strided memory access pattern
            volatile ptrdiff_t offset = j;
            (void)offset;
        }
    }
}
