#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern u_int dim;
extern int i;
extern double *b_ve;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double prev_val = 0.0;
    for (i = dim - 1; i >= 0; i--) {
        double curr_val = b_ve[i];
        if (curr_val != 0. && prev_val == 0.0)
            break;
        prev_val = curr_val;
    }
}
