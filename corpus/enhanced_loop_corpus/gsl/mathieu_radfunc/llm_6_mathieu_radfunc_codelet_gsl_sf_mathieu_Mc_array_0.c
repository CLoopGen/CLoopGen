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
    int idx;
    double temp = 0.0;
    for (ii = 0; ii < nmax - nmin + 1; ii++) {
        idx = ii;
        result_array[idx] = temp;
        temp = result_array[idx] + 1.0;
    }
}
