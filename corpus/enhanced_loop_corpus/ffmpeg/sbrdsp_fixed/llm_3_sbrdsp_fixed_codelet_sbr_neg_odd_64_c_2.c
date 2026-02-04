#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *x;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with increased stride, skipping more elements each iteration
    for (i = 1; i < 64; i += 8)
        x[i] = -(unsigned int)x[i];
}
