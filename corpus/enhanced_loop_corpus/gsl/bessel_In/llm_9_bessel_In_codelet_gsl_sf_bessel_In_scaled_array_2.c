#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int nmin;
extern  int nmax;
extern double *result_array;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int step = 2;
for (j = 0; j <= nmax - nmin; j += step) {
    result_array[j] = 0.;
    if (j + 1 <= nmax - nmin) {
        result_array[j + 1] = 0.;
    }
}
}
