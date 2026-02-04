#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int even_order;
extern unsigned int ii;
extern double *zz;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access (traverse from end to start)
    for (ii = even_order * even_order - 1; ii != (unsigned int)-1; ii--)
        zz[ii] = 0.;
}
