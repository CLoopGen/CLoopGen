#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int lmax;
extern double *jl_x;
extern double W;
extern int L;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access (iterate from lmax down to 1)
    for (L = lmax; L >= 1; L--) {
        jl_x[L] *= W;
    }
}
