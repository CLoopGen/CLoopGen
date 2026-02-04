#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern u_int dim;
extern int i;
extern double *b_ve;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    u_int temp_index = dim;
    for (i = dim - 1; i >= 0; i--) {
        temp_index = i;
        if (b_ve[i] != 0.)
            break;
    }
    i = temp_index == dim ? -1 : temp_index;
}
