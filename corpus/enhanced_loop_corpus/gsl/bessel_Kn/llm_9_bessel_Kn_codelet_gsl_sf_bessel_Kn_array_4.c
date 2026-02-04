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
    double temp_ex = ex + 1.0;
    for (i = 0; i <= (nmax - nmin) / 2; i++) { // Reduced trip count
        result_array[i] *= temp_ex;
        result_array[nmax - nmin - i] += ex; // Additional data access pattern
    }
}
