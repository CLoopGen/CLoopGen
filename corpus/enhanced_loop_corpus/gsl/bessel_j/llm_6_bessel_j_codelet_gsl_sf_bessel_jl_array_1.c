#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int lmax;
extern double *result_array;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp = 0.0;
    for (j = 0; j <= lmax; j++) {
        temp += result_array[j];
        result_array[j] = 0.;
    }
    // Introduces a temporary reduction variable, creating a local RAW dependency within the iteration.
    // No loop-carried dependency on result_array initialization, but adds a false dependency via 'temp' that does not affect final result.
}
