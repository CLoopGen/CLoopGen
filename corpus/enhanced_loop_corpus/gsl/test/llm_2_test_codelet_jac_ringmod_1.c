#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double dfdt[];
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 3)
    for (size_t stride = 0; stride < 15; stride += 3) {
        dfdt[stride] = 0.;
    }
    // Handle remaining elements to maintain correctness
    for (size_t i = 1; i < 15; i++) {
        if (i % 3 != 0) {
            dfdt[i] = 0.;
        }
    }
}
