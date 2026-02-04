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
    double W_sq = W * W;
    for (L = 1; L <= lmax; L += 2) {
        if (L + 1 <= lmax) {
            jl_x[L] *= W_sq;
            jl_x[L + 1] *= W_sq;
        } else {
            jl_x[L] *= W;
        }
    }
}
