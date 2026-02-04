#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int nmin;
extern int nmax;
extern double result_array[];
extern int ii;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (ii = 0; ii < nmax - nmin + 1; ii++) {
        result_array[ii] = 0.0;
        result_array[ii] += ii * 1.5;
        result_array[ii] *= 2.0;
    }
}
