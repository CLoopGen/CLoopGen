#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int even_order;
extern unsigned int ii;
extern double *zz;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (ii = 0; ii < even_order * even_order; ii += 2)
        zz[ii] = 0.;
    // Handle odd-sized arrays by filling the last element if needed
    if ((even_order * even_order) % 2 != 0)
        zz[even_order * even_order - 1] = 0.;
}
