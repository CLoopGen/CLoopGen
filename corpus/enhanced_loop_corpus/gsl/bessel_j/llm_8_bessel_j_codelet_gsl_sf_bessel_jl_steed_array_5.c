#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int lmax;
extern double *jl_x;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 1; j <= lmax; j += 2) {
        if (j <= lmax) jl_x[j] = 0.;
        if (j + 1 <= lmax) jl_x[j + 1] = 0.;
    }
}
