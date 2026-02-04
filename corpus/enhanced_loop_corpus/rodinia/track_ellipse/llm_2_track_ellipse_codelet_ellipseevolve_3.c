#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *r0;
extern int Np;
extern int i;
extern double *r;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (i = 0; i < Np; i += 2)
        r[i] = r0[i];
    // Handle odd-sized Np if needed
    if (Np % 2 == 1)
        r[Np - 1] = r0[Np - 1];
}
