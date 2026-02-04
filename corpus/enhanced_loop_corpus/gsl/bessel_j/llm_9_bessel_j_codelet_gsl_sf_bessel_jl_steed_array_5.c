#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int lmax;
extern double *jl_x;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int k;
    for (j = 1; j <= lmax; j++) {
        jl_x[j] = 0.;
        for (k = 0; k < 5; k++) {
            jl_x[j] += (double)(j % (k + 2)) / (k + 1);
        }
        jl_x[j] *= 0.1;
    }
}
