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
    int jj;
    for (jj = 0; jj < nmax - nmin + 1; jj++) {
        for (ii = 0; ii < 1; ii++) {
            result_array[jj] = 0.;
        }
    }
}
