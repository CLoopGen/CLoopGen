#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t ord;
extern double pc[];
extern double *ordp2coeff;
extern size_t i;
extern int s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double accum = 0.0;
    int local_s = 1;
    for (i = 0; i < ord + 1; i++) {
        accum += local_s * pc[i] / (i + 2);
        local_s = -local_s;
    }
    *ordp2coeff += accum;
}
