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
    int step = 2;
    for (ii = 0; ii < (nmax - nmin + 1) * 3; ii += step) {
        result_array[ii % (nmax - nmin + 1)] = (double)(ii % 100) / 2.0;
    }
}
