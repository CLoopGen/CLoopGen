#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int lmax;
extern double *jl_x;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp = 0.0;
    for (j = 1; j <= lmax; j++) {
        temp = jl_x[j] + temp;
        jl_x[j] = 0.;
    }
}
