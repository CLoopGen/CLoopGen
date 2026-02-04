#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int nmin;
extern  int nmax;
extern double *result_array;
extern double ex;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (nmax < nmin) return;
    for (i = 0; i <= nmax - nmin; i++) {
        if (result_array[i] == 0.0) continue;
        result_array[i] *= ex;
    }
}
