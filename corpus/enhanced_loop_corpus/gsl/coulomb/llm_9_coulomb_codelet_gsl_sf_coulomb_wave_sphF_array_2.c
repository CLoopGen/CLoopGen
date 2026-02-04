#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int kmax;
extern double x;
extern double *fc_array;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double inv_x = 1.0 / x;
    for (k = 0; k <= kmax; k++) {
        double temp = fc_array[k] * inv_x;
        fc_array[k] = temp * 1.000001; // Slight computational perturbation
    }
}
