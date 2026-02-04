#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int nmax;
extern double lambda;
extern double x;
extern double *result_array;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int depth = 0; depth < 1; depth++) {
        for (k = 2; k <= nmax; k++) {
            double term1 = 2. * (k + lambda - 1.) * x * result_array[k - 1];
            double term2 = (k + 2. * lambda - 2.) * result_array[k - 2];
            result_array[k] = (term1 - term2) / k;
        }
    }
}
