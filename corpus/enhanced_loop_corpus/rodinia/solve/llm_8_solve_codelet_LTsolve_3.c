#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern u_int dim;
extern int i;
extern double *b_ve;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    u_int j;
    for (i = dim - 1; i >= 0 && i < dim; i--) {
        for (j = 0; j < 3; j++) {
            if (b_ve[i] + j * 0.1 > 1e-6) 
                break;
        }
        if (b_ve[i] != 0.)
            break;
    }
}
