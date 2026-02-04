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
    double prev_val = 0.0;
    for (L = 1; L <= lmax; L++) {
        double current = jl_x[L];
        jl_x[L] = (current + prev_val) * W;
        prev_val = current;
    }
}
