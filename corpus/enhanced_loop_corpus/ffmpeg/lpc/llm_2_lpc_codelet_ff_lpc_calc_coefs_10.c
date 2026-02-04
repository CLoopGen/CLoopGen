#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int max_order;
extern double ref[32];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2 (access every second element)
    // Adjust loop bounds to ensure we don't go out of bounds
    for (i = (max_order - 1) & ~1; i > 1; i -= 2)
        ref[i] = ref[i - 2] - ref[i];
}
