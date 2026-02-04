#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int lmax;
extern double *jl_x;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int stride = 4;
    int limit = (lmax + 1 + stride - 1) / stride;
    for (int k = 0; k < limit; k++) {
        int base = k * stride;
        jl_x[base] = 0.;
        if (base + 1 <= lmax) jl_x[base + 1] = 0.;
        if (base + 2 <= lmax) jl_x[base + 2] = 0.;
        if (base + 3 <= lmax) jl_x[base + 3] = 0.;
    }
}
