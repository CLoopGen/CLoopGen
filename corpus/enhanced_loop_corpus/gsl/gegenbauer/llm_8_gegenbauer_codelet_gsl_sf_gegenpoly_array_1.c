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
    for (k = 2; k <= nmax; k += 2) {
        if (k + 1 <= nmax) {
            // Compute two iterations at once to increase computational intensity
            double term1_k = 2. * (k + lambda - 1.) * x * result_array[k - 1];
            double term2_k = (k + 2. * lambda - 2.) * result_array[k - 2];
            result_array[k] = (term1_k - term2_k) / k;

            double term1_k1 = 2. * (k + 1 + lambda - 1.) * x * result_array[k];
            double term2_k1 = (k + 1 + 2. * lambda - 2.) * result_array[k - 1];
            result_array[k + 1] = (term1_k1 - term2_k1) / (k + 1);
        } else {
            // Handle last odd element if nmax is odd
            double term1 = 2. * (k + lambda - 1.) * x * result_array[k - 1];
            double term2 = (k + 2. * lambda - 2.) * result_array[k - 2];
            result_array[k] = (term1 - term2) / k;
        }
    }
}
