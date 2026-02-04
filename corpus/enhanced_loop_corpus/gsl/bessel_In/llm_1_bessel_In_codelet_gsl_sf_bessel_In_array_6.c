#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int nmin;
extern  int nmax;
extern double *result_array;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int outer_j;
    for (outer_j = 0; outer_j <= nmax - nmin; outer_j++) {
        int inner_j = outer_j;
        result_array[inner_j] = 0.;
    }
}
