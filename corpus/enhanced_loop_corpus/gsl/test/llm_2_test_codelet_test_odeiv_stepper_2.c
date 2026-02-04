#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double scale_abs[15];
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 3rd element in a cyclic manner using modulo)
    for (size_t stride = 0; stride < 3; stride++) {
        for (i = stride; i < 15; i += 3) {
            scale_abs[i] = 1.;
        }
    }
}
