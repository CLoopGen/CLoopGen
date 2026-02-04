#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int nmin;
extern  int nmax;
extern double *result_array;
extern int j;
extern double eax;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp_eax = eax * eax;
    for (j = 0; j <= (nmax - nmin) / 2; j++) {
        result_array[2*j]     *= temp_eax;
        result_array[2*j + 1] *= temp_eax;
    }
}
