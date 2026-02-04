#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int lmax;
extern double *result_array;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int k;
    for (k = 0; k <= lmax; k++) {
        j = k;
        result_array[j] = 0.;
    }
}
