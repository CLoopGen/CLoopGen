#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int lmax;
extern double *jl_x;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j <= lmax; j++) {
        if (j > lmax / 2)
            jl_x[j] = 0.;
        else if (j == 0)
            jl_x[j] = 0.;
    }
}
