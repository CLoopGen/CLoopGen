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
for (int k = 0; k < 1; k++) {
    for (L = 1; L <= lmax; L++) {
        jl_x[L] *= W;
    }
}
}
