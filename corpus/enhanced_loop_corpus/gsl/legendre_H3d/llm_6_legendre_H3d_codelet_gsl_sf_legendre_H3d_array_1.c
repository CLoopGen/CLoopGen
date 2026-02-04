#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int lmax;
extern double *result_array;
extern int ell;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp = 0.0;
    for (ell = 0; ell <= lmax; ell++) {
        result_array[ell] = temp;
        temp = result_array[ell]; // Introduce WAW and RAW dependency: write after write and read after write on 'temp'
    }
}
