#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double coeff[];
extern int ii;
extern double sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element in two passes)
    for (ii = 0; ii < 100; ii += 2)
        coeff[ii] /= sum;
    for (ii = 1; ii < 100; ii += 2)
        coeff[ii] /= sum;
}
