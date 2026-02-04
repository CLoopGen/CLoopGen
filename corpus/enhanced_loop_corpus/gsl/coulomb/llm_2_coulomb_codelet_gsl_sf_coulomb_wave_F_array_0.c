#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int kmax;
extern double *fc_array;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element in two passes)
    int i;
    for (i = 0; i <= kmax; i += 2) {
        fc_array[i] = 0.;
    }
    for (i = 1; i <= kmax; i += 2) {
        fc_array[i] = 0.;
    }
}
