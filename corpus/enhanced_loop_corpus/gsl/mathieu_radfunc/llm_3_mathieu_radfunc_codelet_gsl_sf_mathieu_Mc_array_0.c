#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int nmin;
extern int nmax;
extern double result_array[];
extern int ii;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access (backward traversal)
    int len = nmax - nmin + 1;
    for (ii = len - 1; ii >= 0; ii--) {
        result_array[ii] = 0.;
    }
}
