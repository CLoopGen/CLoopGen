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
    double temp = 1.0;
    for (L = 1; L <= lmax; L++) {
        temp *= W;
        jl_x[L] *= temp;
    }
}
