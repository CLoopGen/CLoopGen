#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int lmax;
extern double *result_array;
extern int ell;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (lmax >= 0) {
        ell = 0;
        for (; ell <= lmax; ell++)
            result_array[ell] = 0.;
    }
}
