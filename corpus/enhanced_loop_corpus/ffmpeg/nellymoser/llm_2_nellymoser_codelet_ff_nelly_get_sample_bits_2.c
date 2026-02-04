#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *bits;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2)
    for (; i < 124; i += 2)
        bits[i] = 0;
    // Handle remaining index if i started odd or to cover all elements
    if ((i - 1) < 124 && (i - 1) >= 0)
        bits[i - 1] = 0;
}
