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
    int i;
    for (j = 0; j <= nmax - nmin; j++) {
        result_array[j] = 0.;
        for (i = 1; i <= 5; i++) {
            result_array[j] += (double)(i * j) / 2.0;
        }
    }
}
