#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *p;
extern int i0;
extern int i1;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with fixed step through pointer arithmetic
    float *ptr = p + 2 * ((i0 >> 1) - 1);
    int num_iters = ((i1 >> 1) + 1) - ((i0 >> 1) - 1);
    for (int j = 0; j < num_iters; j++) {
        ptr[1] -= 0.882911086F * (ptr[0] + ptr[2]);
        ptr += 2; // Stride of 2 in index corresponds to step of 2 elements
    }
}
