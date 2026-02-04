#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int npoints;
extern int *membership;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2)
    for (i = 0; i < npoints; i += 2)
        membership[i] = -1;
    // Handle odd-sized npoints if needed
    if (npoints > 0 && (npoints % 2 == 1))
        membership[npoints - 1] = -1;
}
