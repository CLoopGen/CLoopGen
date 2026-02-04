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
    double prev = result_array[0];
    double curr = result_array[1];
    for (k = 2; k <= nmax; k++) {
        double next = (2. * (k + lambda - 1.) * x * curr - (k + 2. * lambda - 2.) * prev) / k;
        result_array[k] = next;
        prev = curr;
        curr = next;
    }
}
