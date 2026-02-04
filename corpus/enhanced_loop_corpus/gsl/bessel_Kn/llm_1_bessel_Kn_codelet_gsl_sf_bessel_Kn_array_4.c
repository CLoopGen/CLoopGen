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
    for (i = 0; i <= nmax - nmin; i += 2) {
        result_array[i] *= ex;
        if (i + 1 <= nmax - nmin)
            result_array[i + 1] *= ex;
    }
}
