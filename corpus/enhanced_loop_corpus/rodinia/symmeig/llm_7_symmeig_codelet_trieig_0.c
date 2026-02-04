#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int i_min;
extern int i_max;
extern int n;
extern double *b_ve;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_i_max = i_max;
    for (i = i_min; i < n - 1 && b_ve[i] != 0.; i++) {
        local_i_max = i;
    }
    if (i < n - 1 && b_ve[i] == 0.) {
        local_i_max = i;
    }
    i_max = local_i_max;
}
