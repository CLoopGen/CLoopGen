#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int nmin;
extern int nmax;
extern double *result_array;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with additional arithmetic operations and reduced trip count
    for (n = nmax; n >= nmin; n -= 2) {
        double x = (double)(n - nmin);
        result_array[n - nmin] = x * x + 2.0 * x + 1.0; // Quadratic expression
        if (n - 1 >= nmin) {
            result_array[n - 1 - nmin] = (x - 1.0) * (x - 1.0) + 2.0 * (x - 1.0) + 1.0;
        }
    }
}
