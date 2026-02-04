#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern u_int dim;
extern u_int i;
extern double *b_ve;
extern double *out_ve;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    u_int temp_index = 0;
    for (i = 0; i < dim; i++) {
        temp_index = i; // Introduce temporary to create WAW-like dependency on temp_index, though local
        if (b_ve[temp_index] != 0.)
            break;
        else
            out_ve[temp_index] = 0.;
    }
}
